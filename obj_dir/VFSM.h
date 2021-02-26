// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFSM_H_
#define _VFSM_H_  // guard

#include "verilated_heavy.h"

//==========

class VFSM__Syms;

//----------

VL_MODULE(VFSM) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(left,0,0);
    VL_IN8(right,0,0);
    VL_OUT8(outputs,5,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*3:0*/ FSM__DOT__inter;
    CData/*0:0*/ FSM__DOT__next_log__DOT__add;
    CData/*0:0*/ FSM__DOT__next_log__DOT__adder__DOT__a01;
    CData/*0:0*/ FSM__DOT__next_log__DOT__adder__DOT__a12;
    IData/*31:0*/ FSM__DOT__next_log__DOT__unnamedblk1__DOT__state;
    CData/*3:0*/ FSM__DOT__s_reg[2];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*2:0*/ FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    CData/*3:0*/ __Vchglast__TOP__FSM__DOT__inter;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VFSM__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VFSM);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VFSM(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VFSM();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VFSM__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VFSM__Syms* symsp, bool first);
  private:
    static QData _change_request(VFSM__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(VFSM__Syms* __restrict vlSymsp);
    static void _combo__TOP__4(VFSM__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VFSM__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VFSM__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VFSM__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(VFSM__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VFSM__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
