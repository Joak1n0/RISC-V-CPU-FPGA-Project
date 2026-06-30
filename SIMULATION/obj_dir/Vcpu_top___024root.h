// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcpu_top.h for the primary calling header

#ifndef VERILATED_VCPU_TOP___024ROOT_H_
#define VERILATED_VCPU_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vcpu_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vcpu_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*3:0*/ cpu_top__DOT__alu_op;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(instr,31,0);
    VL_OUT(pc,31,0);
    IData/*31:0*/ cpu_top__DOT__alu_result;
    IData/*31:0*/ cpu_top__DOT__data_out;
    IData/*31:0*/ cpu_top__DOT__dm__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 256> cpu_top__DOT__dm__DOT__mem;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vcpu_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcpu_top___024root(Vcpu_top__Syms* symsp, const char* v__name);
    ~Vcpu_top___024root();
    VL_UNCOPYABLE(Vcpu_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
