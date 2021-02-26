// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSIM_H_
#define _VSIM_H_  // guard

#include "verilated_heavy.h"

//==========

class Vsim__Syms;

//----------

VL_MODULE(Vsim) {
  public:
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ sim__DOT__reset;
    CData/*0:0*/ sim__DOT__left;
    CData/*0:0*/ sim__DOT__right;
    CData/*0:0*/ sim__DOT__clk;
    CData/*0:0*/ sim__DOT__dut__DOT__next_log__DOT__co;
    CData/*0:0*/ sim__DOT__dut__DOT__out_log__DOT__one;
    CData/*0:0*/ sim__DOT__dut__DOT__out_log__DOT__two;
    CData/*0:0*/ sim__DOT__dut__DOT__out_log__DOT__three;
    CData/*5:0*/ sim__DOT__outputs;
    CData/*0:0*/ sim__DOT__dut__DOT__next_log__DOT__add;
    CData/*0:0*/ sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a01;
    CData/*0:0*/ sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a12;
    CData/*3:0*/ sim__DOT__dut__DOT__s_reg[2];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*3:0*/ sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4;
    CData/*2:0*/ sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4;
    CData/*0:0*/ __VinpClk__TOP__sim__DOT__dut__DOT__next_log__DOT__co;
    CData/*0:0*/ __VinpClk__TOP__sim__DOT__left;
    CData/*0:0*/ __VinpClk__TOP__sim__DOT__right;
    CData/*0:0*/ __VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__one;
    CData/*0:0*/ __VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__three;
    CData/*0:0*/ __VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__two;
    CData/*0:0*/ __VinpClk__TOP__sim__DOT__clk;
    CData/*0:0*/ __VinpClk__TOP__sim__DOT__reset;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__next_log__DOT__co;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__sim__DOT__left;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__sim__DOT__right;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__one;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__three;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__two;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__sim__DOT__clk;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__sim__DOT__reset;
    CData/*0:0*/ __Vchglast__TOP__sim__DOT__reset;
    CData/*0:0*/ __Vchglast__TOP__sim__DOT__left;
    CData/*0:0*/ __Vchglast__TOP__sim__DOT__right;
    CData/*0:0*/ __Vchglast__TOP__sim__DOT__clk;
    CData/*0:0*/ __Vchglast__TOP__sim__DOT__dut__DOT__next_log__DOT__co;
    CData/*2:0*/ __Vchglast__TOP__sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4;
    CData/*0:0*/ __Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__one;
    CData/*0:0*/ __Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__two;
    CData/*0:0*/ __Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__three;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vsim__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vsim);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vsim(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vsim();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vsim__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vsim__Syms* symsp, bool first);
  private:
    static QData _change_request(Vsim__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vsim__Syms* __restrict vlSymsp);
    static void _combo__TOP__7(Vsim__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vsim__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vsim__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vsim__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__6(Vsim__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vsim__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vsim__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vsim__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(Vsim__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
