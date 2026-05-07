// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VP_COUNT__SYMS_H_
#define VERILATED_VP_COUNT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vp_count.h"

// INCLUDE MODULE CLASSES
#include "Vp_count___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vp_count__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vp_count* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vp_count___024root             TOP;

    // CONSTRUCTORS
    Vp_count__Syms(VerilatedContext* contextp, const char* namep, Vp_count* modelp);
    ~Vp_count__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
