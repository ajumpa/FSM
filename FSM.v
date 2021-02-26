/**
  This FSM uses the most significant bit as to determine which
  sequence(left of right) is in progress.
  The least significant three are used to determine which state
  the sequence is in.
  The sequence resets on the reset flag, the current and next state
  are stored in the register s_reg.

  Module Next() takes left, right and s_reg inputs and based on the current state
  determines the next state

  Module Output() takes the current state from s_reg and determines what the
  output should be.
**/
module Output(input reg [3:0] state_p, 
              output [5:0] outputs);

  wire one = state_p[0];
  wire two = state_p[1];
  wire three = state_p[2];

  always @ (one or two or three) begin
    // Left sequence
    if (state_p[3]) begin
      if (one)
        outputs[3] = 1;
      if (two)
        outputs[4] = 1;
      if (three)
        outputs[5] = 1;
    end
    // Right sequence
    else if(state_p != 4'b0000) begin
      $display("right");
      if (one)
        outputs[2] = 1;
      if (two)
        outputs[1] = 1;
      if (three)
        outputs[0] = 1;
    end
    $display("%b %b %b %b", state_p[3], three, two, one);
    $display("%b %b %b %b %b %b", outputs[5], outputs[4], outputs[3], outputs[2], outputs[1], outputs[0]);
    if (outputs == 6'b111000 | outputs == 6'b000111)
      outputs = 6'b000000;
  end
endmodule

module FullAdder(input add, 
                 input a, 
                 input b, 
                 input ci, 
                 output s, 
                 output co);

  assign co = add & (a & b | ci&(~a&b | a&~b));
  assign s = add & ((ci & (~a & ~b | a & b)) |
              (~ci & (~a & b | a & ~b)));

endmodule

module ThreeBitAdder(
                    input add,
                    input [2:0] a, 
                    input [2:0] b, 
                    output [2:0] s,
                    output co);

    wire a01, a12;
    
    FullAdder FA0(add, a[0], b[0], 0, s[0], a01);
    FullAdder FA1(add, a[1], b[1], a01, s[1], a12);
    FullAdder FA2(add, a[2], b[2], a12, s[2], co);
    
endmodule

module Next(
            input left, 
            input right, 
            input reg [2:0] state_p,
            output reg [3:0] inter);

  wire co;
  wire add = left | right;
  ThreeBitAdder adder (add, state_p[2:0], 3'b001, inter[2:0], co);

  always @ (left or right or co) begin
    integer state = inter[2:0];
    if (state > 4 | co)
      inter[3:0] = 4'b0000;
    else if (left)
      inter[3] = 1;
    else if (right)
      inter[3] = 0;
  end
endmodule

module FSM(input clk, 
           input reset, 
           input left, 
           input right,
           output [5:0] outputs);

  reg [3:0] s_reg [1:0];
  reg [3:0] inter;
  Next next_log(left, right, s_reg[1][2:0], inter);
  Output out_log(s_reg[1], outputs);

  always @ (posedge clk or posedge reset) begin
    // If reset, go to state 0
    if (reset) begin
      s_reg[0] <= 4'b0000;
    end
    // Assign current state to next state
    else
      s_reg[1] <= inter;
  end
endmodule