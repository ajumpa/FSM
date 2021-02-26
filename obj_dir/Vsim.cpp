// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim.h"
#include "Vsim__Syms.h"

//==========

VL_CTOR_IMP(Vsim) {
    Vsim__Syms* __restrict vlSymsp = __VlSymsp = new Vsim__Syms(this, name());
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vsim::__Vconfigure(Vsim__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vsim::~Vsim() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vsim::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsim::eval\n"); );
    Vsim__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sim.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vsim::_eval_initial_loop(Vsim__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sim.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vsim::_settle__TOP__1(Vsim__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_settle__TOP__1\n"); );
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add 
        = (1U & ((~ (IData)(vlTOPp->sim__DOT__left)) 
                 & (~ (IData)(vlTOPp->sim__DOT__right))));
    vlTOPp->sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4 
        = ((8U & (IData)(vlTOPp->sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4)) 
           | (IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4));
    vlTOPp->sim__DOT__dut__DOT__s_reg[1U] = vlTOPp->sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4;
    vlTOPp->sim__DOT__dut__DOT__out_log__DOT__one = 
        (1U & vlTOPp->sim__DOT__dut__DOT__s_reg[1U]);
    vlTOPp->sim__DOT__dut__DOT__out_log__DOT__two = 
        (1U & (vlTOPp->sim__DOT__dut__DOT__s_reg[1U] 
               >> 1U));
    vlTOPp->sim__DOT__dut__DOT__out_log__DOT__three 
        = (1U & (vlTOPp->sim__DOT__dut__DOT__s_reg[1U] 
                 >> 2U));
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = ((6U & (IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4)) 
           | ((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add) 
              & (~ vlTOPp->sim__DOT__dut__DOT__s_reg
                 [0U])));
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a01 
        = ((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add) 
           & vlTOPp->sim__DOT__dut__DOT__s_reg[0U]);
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = ((5U & (IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4)) 
           | (((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add) 
               << 1U) & ((((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a01) 
                           & (~ (vlTOPp->sim__DOT__dut__DOT__s_reg
                                 [0U] >> 1U))) << 1U) 
                         | (0xfffffffeU & (((~ (IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a01)) 
                                            << 1U) 
                                           & vlTOPp->sim__DOT__dut__DOT__s_reg
                                           [0U])))));
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a12 
        = ((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add) 
           & ((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a01) 
              & (vlTOPp->sim__DOT__dut__DOT__s_reg[0U] 
                 >> 1U)));
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = ((3U & (IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4)) 
           | (((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add) 
               << 2U) & ((((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a12) 
                           & (~ (vlTOPp->sim__DOT__dut__DOT__s_reg
                                 [0U] >> 2U))) << 2U) 
                         | (0xfffffffcU & (((~ (IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a12)) 
                                            << 2U) 
                                           & vlTOPp->sim__DOT__dut__DOT__s_reg
                                           [0U])))));
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT__co = 
        ((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add) 
         & ((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a12) 
            & (vlTOPp->sim__DOT__dut__DOT__s_reg[0U] 
               >> 2U)));
}

VL_INLINE_OPT void Vsim::_combo__TOP__2(Vsim__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_combo__TOP__2\n"); );
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4 
        = ((8U & (IData)(vlTOPp->sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4)) 
           | (IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4));
}

VL_INLINE_OPT void Vsim::_sequent__TOP__3(Vsim__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_sequent__TOP__3\n"); );
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->sim__DOT__dut__DOT__next_log__DOT__co) {
        vlTOPp->sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4 
            = (8U & (IData)(vlTOPp->sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4));
    }
    if (vlTOPp->sim__DOT__left) {
        vlTOPp->sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4 
            = (8U | (IData)(vlTOPp->sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4));
    } else {
        if (vlTOPp->sim__DOT__right) {
            vlTOPp->sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4 
                = (7U & (IData)(vlTOPp->sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4));
        }
    }
}

VL_INLINE_OPT void Vsim::_sequent__TOP__4(Vsim__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_sequent__TOP__4\n"); );
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((8U & vlTOPp->sim__DOT__dut__DOT__s_reg[1U])) {
        if (vlTOPp->sim__DOT__dut__DOT__out_log__DOT__one) {
            vlTOPp->sim__DOT__outputs = (8U | (IData)(vlTOPp->sim__DOT__outputs));
        }
    }
    if (vlTOPp->sim__DOT__dut__DOT__out_log__DOT__two) {
        vlTOPp->sim__DOT__outputs = (0x10U | (IData)(vlTOPp->sim__DOT__outputs));
    }
    if (vlTOPp->sim__DOT__dut__DOT__out_log__DOT__three) {
        vlTOPp->sim__DOT__outputs = (0x20U | (IData)(vlTOPp->sim__DOT__outputs));
    } else {
        if (vlTOPp->sim__DOT__dut__DOT__out_log__DOT__one) {
            vlTOPp->sim__DOT__outputs = (1U | (IData)(vlTOPp->sim__DOT__outputs));
        }
    }
    if (vlTOPp->sim__DOT__dut__DOT__out_log__DOT__two) {
        vlTOPp->sim__DOT__outputs = (2U | (IData)(vlTOPp->sim__DOT__outputs));
    }
    if (vlTOPp->sim__DOT__dut__DOT__out_log__DOT__three) {
        vlTOPp->sim__DOT__outputs = (4U | (IData)(vlTOPp->sim__DOT__outputs));
    }
    VL_WRITEF("%b %b %b %b %b %b\n",1,(1U & (IData)(vlTOPp->sim__DOT__outputs)),
              1,(1U & ((IData)(vlTOPp->sim__DOT__outputs) 
                       >> 1U)),1,(1U & ((IData)(vlTOPp->sim__DOT__outputs) 
                                        >> 2U)),1,(1U 
                                                   & ((IData)(vlTOPp->sim__DOT__outputs) 
                                                      >> 3U)),
              1,(1U & ((IData)(vlTOPp->sim__DOT__outputs) 
                       >> 4U)),1,(1U & ((IData)(vlTOPp->sim__DOT__outputs) 
                                        >> 5U)));
}

VL_INLINE_OPT void Vsim::_sequent__TOP__5(Vsim__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_sequent__TOP__5\n"); );
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdlyvval__sim__DOT__dut__DOT__s_reg__v0;
    // Body
    __Vdlyvval__sim__DOT__dut__DOT__s_reg__v0 = ((IData)(vlTOPp->sim__DOT__reset)
                                                  ? 0U
                                                  : 
                                                 vlTOPp->sim__DOT__dut__DOT__s_reg
                                                 [0U]);
    vlTOPp->sim__DOT__dut__DOT__s_reg[1U] = __Vdlyvval__sim__DOT__dut__DOT__s_reg__v0;
}

void Vsim::_initial__TOP__6(Vsim__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_initial__TOP__6\n"); );
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF("%x\n",6,vlTOPp->sim__DOT__outputs);
    VL_WRITEF("%x\n",6,vlTOPp->sim__DOT__outputs);
    VL_WRITEF("%x\n",6,vlTOPp->sim__DOT__outputs);
    VL_WRITEF("%x\n",6,vlTOPp->sim__DOT__outputs);
    VL_WRITEF("%x\n",6,vlTOPp->sim__DOT__outputs);
    vlTOPp->sim__DOT__reset = 0U;
    vlTOPp->sim__DOT__clk = 1U;
    vlTOPp->sim__DOT__left = 1U;
    vlTOPp->sim__DOT__right = 0U;
    VL_WRITEF("%x\n",6,vlTOPp->sim__DOT__outputs);
}

VL_INLINE_OPT void Vsim::_combo__TOP__7(Vsim__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_combo__TOP__7\n"); );
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sim__DOT__dut__DOT__s_reg[1U] = vlTOPp->sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4;
    vlTOPp->sim__DOT__dut__DOT__out_log__DOT__one = 
        (1U & vlTOPp->sim__DOT__dut__DOT__s_reg[1U]);
    vlTOPp->sim__DOT__dut__DOT__out_log__DOT__two = 
        (1U & (vlTOPp->sim__DOT__dut__DOT__s_reg[1U] 
               >> 1U));
    vlTOPp->sim__DOT__dut__DOT__out_log__DOT__three 
        = (1U & (vlTOPp->sim__DOT__dut__DOT__s_reg[1U] 
                 >> 2U));
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = ((6U & (IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4)) 
           | ((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add) 
              & (~ vlTOPp->sim__DOT__dut__DOT__s_reg
                 [0U])));
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a01 
        = ((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add) 
           & vlTOPp->sim__DOT__dut__DOT__s_reg[0U]);
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = ((5U & (IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4)) 
           | (((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add) 
               << 1U) & ((((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a01) 
                           & (~ (vlTOPp->sim__DOT__dut__DOT__s_reg
                                 [0U] >> 1U))) << 1U) 
                         | (0xfffffffeU & (((~ (IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a01)) 
                                            << 1U) 
                                           & vlTOPp->sim__DOT__dut__DOT__s_reg
                                           [0U])))));
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a12 
        = ((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add) 
           & ((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a01) 
              & (vlTOPp->sim__DOT__dut__DOT__s_reg[0U] 
                 >> 1U)));
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = ((3U & (IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4)) 
           | (((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add) 
               << 2U) & ((((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a12) 
                           & (~ (vlTOPp->sim__DOT__dut__DOT__s_reg
                                 [0U] >> 2U))) << 2U) 
                         | (0xfffffffcU & (((~ (IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a12)) 
                                            << 2U) 
                                           & vlTOPp->sim__DOT__dut__DOT__s_reg
                                           [0U])))));
    vlTOPp->sim__DOT__dut__DOT__next_log__DOT__co = 
        ((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__add) 
         & ((IData)(vlTOPp->sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a12) 
            & (vlTOPp->sim__DOT__dut__DOT__s_reg[0U] 
               >> 2U)));
}

void Vsim::_eval(Vsim__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_eval\n"); );
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((((IData)(vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__next_log__DOT__co) 
           & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__next_log__DOT__co))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__sim__DOT__left) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__left)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__sim__DOT__right) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__right))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((((IData)(vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__one) 
           & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__one))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__three) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__three)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__two) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__two))))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__sim__DOT__clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__sim__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__reset))))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__next_log__DOT__co 
        = vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__next_log__DOT__co;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__left 
        = vlTOPp->__VinpClk__TOP__sim__DOT__left;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__right 
        = vlTOPp->__VinpClk__TOP__sim__DOT__right;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__one 
        = vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__one;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__three 
        = vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__three;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__two 
        = vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__two;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__clk 
        = vlTOPp->__VinpClk__TOP__sim__DOT__clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__reset 
        = vlTOPp->__VinpClk__TOP__sim__DOT__reset;
    vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__next_log__DOT__co 
        = vlTOPp->sim__DOT__dut__DOT__next_log__DOT__co;
    vlTOPp->__VinpClk__TOP__sim__DOT__left = vlTOPp->sim__DOT__left;
    vlTOPp->__VinpClk__TOP__sim__DOT__right = vlTOPp->sim__DOT__right;
    vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__one 
        = vlTOPp->sim__DOT__dut__DOT__out_log__DOT__one;
    vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__three 
        = vlTOPp->sim__DOT__dut__DOT__out_log__DOT__three;
    vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__two 
        = vlTOPp->sim__DOT__dut__DOT__out_log__DOT__two;
    vlTOPp->__VinpClk__TOP__sim__DOT__clk = vlTOPp->sim__DOT__clk;
    vlTOPp->__VinpClk__TOP__sim__DOT__reset = vlTOPp->sim__DOT__reset;
}

void Vsim::_eval_initial(Vsim__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_eval_initial\n"); );
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__next_log__DOT__co 
        = vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__next_log__DOT__co;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__left 
        = vlTOPp->__VinpClk__TOP__sim__DOT__left;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__right 
        = vlTOPp->__VinpClk__TOP__sim__DOT__right;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__one 
        = vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__one;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__three 
        = vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__three;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__two 
        = vlTOPp->__VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__two;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__clk 
        = vlTOPp->__VinpClk__TOP__sim__DOT__clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sim__DOT__reset 
        = vlTOPp->__VinpClk__TOP__sim__DOT__reset;
    vlTOPp->_initial__TOP__6(vlSymsp);
}

void Vsim::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::final\n"); );
    // Variables
    Vsim__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsim::_eval_settle(Vsim__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_eval_settle\n"); );
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vsim::_change_request(Vsim__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_change_request\n"); );
    Vsim* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->sim__DOT__reset ^ vlTOPp->__Vchglast__TOP__sim__DOT__reset)
         | (vlTOPp->sim__DOT__left ^ vlTOPp->__Vchglast__TOP__sim__DOT__left)
         | (vlTOPp->sim__DOT__right ^ vlTOPp->__Vchglast__TOP__sim__DOT__right)
         | (vlTOPp->sim__DOT__clk ^ vlTOPp->__Vchglast__TOP__sim__DOT__clk)
         | (vlTOPp->sim__DOT__dut__DOT__next_log__DOT__co ^ vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__next_log__DOT__co)
         | (vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4 ^ vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4)
         | (vlTOPp->sim__DOT__dut__DOT__out_log__DOT__one ^ vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__one)
         | (vlTOPp->sim__DOT__dut__DOT__out_log__DOT__two ^ vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__two)
         | (vlTOPp->sim__DOT__dut__DOT__out_log__DOT__three ^ vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__three));
    VL_DEBUG_IF( if(__req && ((vlTOPp->sim__DOT__reset ^ vlTOPp->__Vchglast__TOP__sim__DOT__reset))) VL_DBG_MSGF("        CHANGE: sim.v:2: sim.reset\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->sim__DOT__left ^ vlTOPp->__Vchglast__TOP__sim__DOT__left))) VL_DBG_MSGF("        CHANGE: sim.v:3: sim.left\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->sim__DOT__right ^ vlTOPp->__Vchglast__TOP__sim__DOT__right))) VL_DBG_MSGF("        CHANGE: sim.v:4: sim.right\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->sim__DOT__clk ^ vlTOPp->__Vchglast__TOP__sim__DOT__clk))) VL_DBG_MSGF("        CHANGE: sim.v:5: sim.clk\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->sim__DOT__dut__DOT__next_log__DOT__co ^ vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__next_log__DOT__co))) VL_DBG_MSGF("        CHANGE: FSM.v:50: sim.dut.next_log.co\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4 ^ vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4))) VL_DBG_MSGF("        CHANGE: FSM.v:33: sim.dut.next_log.__Vcellout__adder____pinNumber4\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->sim__DOT__dut__DOT__out_log__DOT__one ^ vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__one))) VL_DBG_MSGF("        CHANGE: FSM.v:67: sim.dut.out_log.one\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->sim__DOT__dut__DOT__out_log__DOT__two ^ vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__two))) VL_DBG_MSGF("        CHANGE: FSM.v:68: sim.dut.out_log.two\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->sim__DOT__dut__DOT__out_log__DOT__three ^ vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__three))) VL_DBG_MSGF("        CHANGE: FSM.v:69: sim.dut.out_log.three\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__sim__DOT__reset = vlTOPp->sim__DOT__reset;
    vlTOPp->__Vchglast__TOP__sim__DOT__left = vlTOPp->sim__DOT__left;
    vlTOPp->__Vchglast__TOP__sim__DOT__right = vlTOPp->sim__DOT__right;
    vlTOPp->__Vchglast__TOP__sim__DOT__clk = vlTOPp->sim__DOT__clk;
    vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__next_log__DOT__co 
        = vlTOPp->sim__DOT__dut__DOT__next_log__DOT__co;
    vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = vlTOPp->sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4;
    vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__one 
        = vlTOPp->sim__DOT__dut__DOT__out_log__DOT__one;
    vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__two 
        = vlTOPp->sim__DOT__dut__DOT__out_log__DOT__two;
    vlTOPp->__Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__three 
        = vlTOPp->sim__DOT__dut__DOT__out_log__DOT__three;
    return __req;
}

#ifdef VL_DEBUG
void Vsim::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

void Vsim::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim::_ctor_var_reset\n"); );
    // Body
    sim__DOT__reset = VL_RAND_RESET_I(1);
    sim__DOT__left = VL_RAND_RESET_I(1);
    sim__DOT__right = VL_RAND_RESET_I(1);
    sim__DOT__clk = VL_RAND_RESET_I(1);
    sim__DOT__outputs = VL_RAND_RESET_I(6);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            sim__DOT__dut__DOT__s_reg[__Vi0] = VL_RAND_RESET_I(4);
    }}
    sim__DOT__dut__DOT____Vcellout__next_log____pinNumber4 = VL_RAND_RESET_I(4);
    sim__DOT__dut__DOT__next_log__DOT__co = VL_RAND_RESET_I(1);
    sim__DOT__dut__DOT__next_log__DOT__add = VL_RAND_RESET_I(1);
    sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4 = VL_RAND_RESET_I(3);
    sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a01 = VL_RAND_RESET_I(1);
    sim__DOT__dut__DOT__next_log__DOT__adder__DOT__a12 = VL_RAND_RESET_I(1);
    sim__DOT__dut__DOT__out_log__DOT__one = VL_RAND_RESET_I(1);
    sim__DOT__dut__DOT__out_log__DOT__two = VL_RAND_RESET_I(1);
    sim__DOT__dut__DOT__out_log__DOT__three = VL_RAND_RESET_I(1);
    __VinpClk__TOP__sim__DOT__dut__DOT__next_log__DOT__co = VL_RAND_RESET_I(1);
    __VinpClk__TOP__sim__DOT__left = VL_RAND_RESET_I(1);
    __VinpClk__TOP__sim__DOT__right = VL_RAND_RESET_I(1);
    __VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__one = VL_RAND_RESET_I(1);
    __VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__three = VL_RAND_RESET_I(1);
    __VinpClk__TOP__sim__DOT__dut__DOT__out_log__DOT__two = VL_RAND_RESET_I(1);
    __VinpClk__TOP__sim__DOT__clk = VL_RAND_RESET_I(1);
    __VinpClk__TOP__sim__DOT__reset = VL_RAND_RESET_I(1);
    __Vchglast__TOP__sim__DOT__reset = VL_RAND_RESET_I(1);
    __Vchglast__TOP__sim__DOT__left = VL_RAND_RESET_I(1);
    __Vchglast__TOP__sim__DOT__right = VL_RAND_RESET_I(1);
    __Vchglast__TOP__sim__DOT__clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__sim__DOT__dut__DOT__next_log__DOT__co = VL_RAND_RESET_I(1);
    __Vchglast__TOP__sim__DOT__dut__DOT__next_log__DOT____Vcellout__adder____pinNumber4 = VL_RAND_RESET_I(3);
    __Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__one = VL_RAND_RESET_I(1);
    __Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__two = VL_RAND_RESET_I(1);
    __Vchglast__TOP__sim__DOT__dut__DOT__out_log__DOT__three = VL_RAND_RESET_I(1);
}
