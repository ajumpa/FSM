// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFSM.h for the primary calling header

#include "VFSM.h"
#include "VFSM__Syms.h"

//==========

VL_CTOR_IMP(VFSM) {
    VFSM__Syms* __restrict vlSymsp = __VlSymsp = new VFSM__Syms(this, name());
    VFSM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VFSM::__Vconfigure(VFSM__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VFSM::~VFSM() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VFSM::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VFSM::eval\n"); );
    VFSM__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VFSM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("FSM.v", 98, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VFSM::_eval_initial_loop(VFSM__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("FSM.v", 98, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VFSM::_combo__TOP__1(VFSM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM::_combo__TOP__1\n"); );
    VFSM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FSM__DOT__next_log__DOT__add = ((IData)(vlTOPp->left) 
                                            | (IData)(vlTOPp->right));
}

void VFSM::_settle__TOP__2(VFSM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM::_settle__TOP__2\n"); );
    VFSM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FSM__DOT__next_log__DOT__add = ((IData)(vlTOPp->left) 
                                            | (IData)(vlTOPp->right));
    if ((8U & vlTOPp->FSM__DOT__s_reg[1U])) {
        if ((1U & vlTOPp->FSM__DOT__s_reg[1U])) {
            vlTOPp->outputs = (8U | (IData)(vlTOPp->outputs));
        }
        if ((2U & vlTOPp->FSM__DOT__s_reg[1U])) {
            vlTOPp->outputs = (0x10U | (IData)(vlTOPp->outputs));
        }
        if ((4U & vlTOPp->FSM__DOT__s_reg[1U])) {
            vlTOPp->outputs = (0x20U | (IData)(vlTOPp->outputs));
        }
    } else {
        if (VL_UNLIKELY((0U != vlTOPp->FSM__DOT__s_reg
                         [1U]))) {
            VL_WRITEF("right\n");
            if ((1U & vlTOPp->FSM__DOT__s_reg[1U])) {
                vlTOPp->outputs = (4U | (IData)(vlTOPp->outputs));
            }
            if ((2U & vlTOPp->FSM__DOT__s_reg[1U])) {
                vlTOPp->outputs = (2U | (IData)(vlTOPp->outputs));
            }
            if ((4U & vlTOPp->FSM__DOT__s_reg[1U])) {
                vlTOPp->outputs = (1U | (IData)(vlTOPp->outputs));
            }
        }
    }
    VL_WRITEF("%b %b %b %b\n",1,(1U & (vlTOPp->FSM__DOT__s_reg
                                       [1U] >> 3U)),
              1,(1U & (vlTOPp->FSM__DOT__s_reg[1U] 
                       >> 2U)),1,(1U & (vlTOPp->FSM__DOT__s_reg
                                        [1U] >> 1U)),
              1,(1U & vlTOPp->FSM__DOT__s_reg[1U]));
    VL_WRITEF("%b %b %b %b %b %b\n",1,(1U & ((IData)(vlTOPp->outputs) 
                                             >> 5U)),
              1,(1U & ((IData)(vlTOPp->outputs) >> 4U)),
              1,(1U & ((IData)(vlTOPp->outputs) >> 3U)),
              1,(1U & ((IData)(vlTOPp->outputs) >> 2U)),
              1,(1U & ((IData)(vlTOPp->outputs) >> 1U)),
              1,(1U & (IData)(vlTOPp->outputs)));
    if (((0x38U == (IData)(vlTOPp->outputs)) | (7U 
                                                == (IData)(vlTOPp->outputs)))) {
        vlTOPp->outputs = 0U;
    }
    vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = ((6U & (IData)(vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4)) 
           | ((IData)(vlTOPp->FSM__DOT__next_log__DOT__add) 
              & (~ vlTOPp->FSM__DOT__s_reg[1U])));
    vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a01 
        = ((IData)(vlTOPp->FSM__DOT__next_log__DOT__add) 
           & vlTOPp->FSM__DOT__s_reg[1U]);
    vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = ((5U & (IData)(vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4)) 
           | (((IData)(vlTOPp->FSM__DOT__next_log__DOT__add) 
               << 1U) & ((((IData)(vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a01) 
                           & (~ (vlTOPp->FSM__DOT__s_reg
                                 [1U] >> 1U))) << 1U) 
                         | (0xfffffffeU & (((~ (IData)(vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a01)) 
                                            << 1U) 
                                           & vlTOPp->FSM__DOT__s_reg
                                           [1U])))));
    vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a12 
        = ((IData)(vlTOPp->FSM__DOT__next_log__DOT__add) 
           & ((IData)(vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a01) 
              & (vlTOPp->FSM__DOT__s_reg[1U] >> 1U)));
    vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = ((3U & (IData)(vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4)) 
           | (((IData)(vlTOPp->FSM__DOT__next_log__DOT__add) 
               << 2U) & ((((IData)(vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a12) 
                           & (~ (vlTOPp->FSM__DOT__s_reg
                                 [1U] >> 2U))) << 2U) 
                         | (0xfffffffcU & (((~ (IData)(vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a12)) 
                                            << 2U) 
                                           & vlTOPp->FSM__DOT__s_reg
                                           [1U])))));
    vlTOPp->FSM__DOT__inter = ((8U & (IData)(vlTOPp->FSM__DOT__inter)) 
                               | (IData)(vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4));
    vlTOPp->FSM__DOT__next_log__DOT__unnamedblk1__DOT__state 
        = (7U & (IData)(vlTOPp->FSM__DOT__inter));
    if ((VL_LTS_III(1,32,32, 4U, vlTOPp->FSM__DOT__next_log__DOT__unnamedblk1__DOT__state) 
         | ((IData)(vlTOPp->FSM__DOT__next_log__DOT__add) 
            & ((IData)(vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a12) 
               & (vlTOPp->FSM__DOT__s_reg[1U] >> 2U))))) {
        vlTOPp->FSM__DOT__inter = 0U;
    } else {
        if (vlTOPp->left) {
            vlTOPp->FSM__DOT__inter = (8U | (IData)(vlTOPp->FSM__DOT__inter));
        } else {
            if (vlTOPp->right) {
                vlTOPp->FSM__DOT__inter = (7U & (IData)(vlTOPp->FSM__DOT__inter));
            }
        }
    }
}

VL_INLINE_OPT void VFSM::_sequent__TOP__3(VFSM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM::_sequent__TOP__3\n"); );
    VFSM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__FSM__DOT__s_reg__v0;
    CData/*3:0*/ __Vdlyvval__FSM__DOT__s_reg__v1;
    CData/*0:0*/ __Vdlyvset__FSM__DOT__s_reg__v1;
    // Body
    __Vdlyvset__FSM__DOT__s_reg__v0 = 0U;
    __Vdlyvset__FSM__DOT__s_reg__v1 = 0U;
    if (vlTOPp->reset) {
        __Vdlyvset__FSM__DOT__s_reg__v0 = 1U;
    } else {
        __Vdlyvval__FSM__DOT__s_reg__v1 = vlTOPp->FSM__DOT__inter;
        __Vdlyvset__FSM__DOT__s_reg__v1 = 1U;
    }
    if (__Vdlyvset__FSM__DOT__s_reg__v0) {
        vlTOPp->FSM__DOT__s_reg[0U] = 0U;
    }
    if (__Vdlyvset__FSM__DOT__s_reg__v1) {
        vlTOPp->FSM__DOT__s_reg[1U] = __Vdlyvval__FSM__DOT__s_reg__v1;
    }
    if ((8U & vlTOPp->FSM__DOT__s_reg[1U])) {
        if ((1U & vlTOPp->FSM__DOT__s_reg[1U])) {
            vlTOPp->outputs = (8U | (IData)(vlTOPp->outputs));
        }
        if ((2U & vlTOPp->FSM__DOT__s_reg[1U])) {
            vlTOPp->outputs = (0x10U | (IData)(vlTOPp->outputs));
        }
        if ((4U & vlTOPp->FSM__DOT__s_reg[1U])) {
            vlTOPp->outputs = (0x20U | (IData)(vlTOPp->outputs));
        }
    } else {
        if (VL_UNLIKELY((0U != vlTOPp->FSM__DOT__s_reg
                         [1U]))) {
            VL_WRITEF("right\n");
            if ((1U & vlTOPp->FSM__DOT__s_reg[1U])) {
                vlTOPp->outputs = (4U | (IData)(vlTOPp->outputs));
            }
            if ((2U & vlTOPp->FSM__DOT__s_reg[1U])) {
                vlTOPp->outputs = (2U | (IData)(vlTOPp->outputs));
            }
            if ((4U & vlTOPp->FSM__DOT__s_reg[1U])) {
                vlTOPp->outputs = (1U | (IData)(vlTOPp->outputs));
            }
        }
    }
    VL_WRITEF("%b %b %b %b\n",1,(1U & (vlTOPp->FSM__DOT__s_reg
                                       [1U] >> 3U)),
              1,(1U & (vlTOPp->FSM__DOT__s_reg[1U] 
                       >> 2U)),1,(1U & (vlTOPp->FSM__DOT__s_reg
                                        [1U] >> 1U)),
              1,(1U & vlTOPp->FSM__DOT__s_reg[1U]));
    VL_WRITEF("%b %b %b %b %b %b\n",1,(1U & ((IData)(vlTOPp->outputs) 
                                             >> 5U)),
              1,(1U & ((IData)(vlTOPp->outputs) >> 4U)),
              1,(1U & ((IData)(vlTOPp->outputs) >> 3U)),
              1,(1U & ((IData)(vlTOPp->outputs) >> 2U)),
              1,(1U & ((IData)(vlTOPp->outputs) >> 1U)),
              1,(1U & (IData)(vlTOPp->outputs)));
    if (((0x38U == (IData)(vlTOPp->outputs)) | (7U 
                                                == (IData)(vlTOPp->outputs)))) {
        vlTOPp->outputs = 0U;
    }
}

VL_INLINE_OPT void VFSM::_combo__TOP__4(VFSM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM::_combo__TOP__4\n"); );
    VFSM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = ((6U & (IData)(vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4)) 
           | ((IData)(vlTOPp->FSM__DOT__next_log__DOT__add) 
              & (~ vlTOPp->FSM__DOT__s_reg[1U])));
    vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a01 
        = ((IData)(vlTOPp->FSM__DOT__next_log__DOT__add) 
           & vlTOPp->FSM__DOT__s_reg[1U]);
    vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = ((5U & (IData)(vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4)) 
           | (((IData)(vlTOPp->FSM__DOT__next_log__DOT__add) 
               << 1U) & ((((IData)(vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a01) 
                           & (~ (vlTOPp->FSM__DOT__s_reg
                                 [1U] >> 1U))) << 1U) 
                         | (0xfffffffeU & (((~ (IData)(vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a01)) 
                                            << 1U) 
                                           & vlTOPp->FSM__DOT__s_reg
                                           [1U])))));
    vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a12 
        = ((IData)(vlTOPp->FSM__DOT__next_log__DOT__add) 
           & ((IData)(vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a01) 
              & (vlTOPp->FSM__DOT__s_reg[1U] >> 1U)));
    vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4 
        = ((3U & (IData)(vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4)) 
           | (((IData)(vlTOPp->FSM__DOT__next_log__DOT__add) 
               << 2U) & ((((IData)(vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a12) 
                           & (~ (vlTOPp->FSM__DOT__s_reg
                                 [1U] >> 2U))) << 2U) 
                         | (0xfffffffcU & (((~ (IData)(vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a12)) 
                                            << 2U) 
                                           & vlTOPp->FSM__DOT__s_reg
                                           [1U])))));
    vlTOPp->FSM__DOT__inter = ((8U & (IData)(vlTOPp->FSM__DOT__inter)) 
                               | (IData)(vlTOPp->FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4));
    vlTOPp->FSM__DOT__next_log__DOT__unnamedblk1__DOT__state 
        = (7U & (IData)(vlTOPp->FSM__DOT__inter));
    if ((VL_LTS_III(1,32,32, 4U, vlTOPp->FSM__DOT__next_log__DOT__unnamedblk1__DOT__state) 
         | ((IData)(vlTOPp->FSM__DOT__next_log__DOT__add) 
            & ((IData)(vlTOPp->FSM__DOT__next_log__DOT__adder__DOT__a12) 
               & (vlTOPp->FSM__DOT__s_reg[1U] >> 2U))))) {
        vlTOPp->FSM__DOT__inter = 0U;
    } else {
        if (vlTOPp->left) {
            vlTOPp->FSM__DOT__inter = (8U | (IData)(vlTOPp->FSM__DOT__inter));
        } else {
            if (vlTOPp->right) {
                vlTOPp->FSM__DOT__inter = (7U & (IData)(vlTOPp->FSM__DOT__inter));
            }
        }
    }
}

void VFSM::_eval(VFSM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM::_eval\n"); );
    VFSM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void VFSM::_eval_initial(VFSM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM::_eval_initial\n"); );
    VFSM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void VFSM::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM::final\n"); );
    // Variables
    VFSM__Syms* __restrict vlSymsp = this->__VlSymsp;
    VFSM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFSM::_eval_settle(VFSM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM::_eval_settle\n"); );
    VFSM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VFSM::_change_request(VFSM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM::_change_request\n"); );
    VFSM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->FSM__DOT__inter ^ vlTOPp->__Vchglast__TOP__FSM__DOT__inter));
    VL_DEBUG_IF( if(__req && ((vlTOPp->FSM__DOT__inter ^ vlTOPp->__Vchglast__TOP__FSM__DOT__inter))) VL_DBG_MSGF("        CHANGE: FSM.v:105: FSM.inter\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__FSM__DOT__inter = vlTOPp->FSM__DOT__inter;
    return __req;
}

#ifdef VL_DEBUG
void VFSM::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((left & 0xfeU))) {
        Verilated::overWidthError("left");}
    if (VL_UNLIKELY((right & 0xfeU))) {
        Verilated::overWidthError("right");}
}
#endif  // VL_DEBUG

void VFSM::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFSM::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    left = VL_RAND_RESET_I(1);
    right = VL_RAND_RESET_I(1);
    outputs = VL_RAND_RESET_I(6);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            FSM__DOT__s_reg[__Vi0] = VL_RAND_RESET_I(4);
    }}
    FSM__DOT__inter = VL_RAND_RESET_I(4);
    FSM__DOT__next_log__DOT__add = VL_RAND_RESET_I(1);
    FSM__DOT__next_log__DOT____Vcellout__adder____pinNumber4 = VL_RAND_RESET_I(3);
    FSM__DOT__next_log__DOT__unnamedblk1__DOT__state = VL_RAND_RESET_I(32);
    FSM__DOT__next_log__DOT__adder__DOT__a01 = VL_RAND_RESET_I(1);
    FSM__DOT__next_log__DOT__adder__DOT__a12 = VL_RAND_RESET_I(1);
    __Vchglast__TOP__FSM__DOT__inter = VL_RAND_RESET_I(4);
}
