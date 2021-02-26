// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VFSM__SYMS_H_
#define _VFSM__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "VFSM.h"

// SYMS CLASS
class VFSM__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VFSM*                          TOPp;
    
    // CREATORS
    VFSM__Syms(VFSM* topp, const char* namep);
    ~VFSM__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
