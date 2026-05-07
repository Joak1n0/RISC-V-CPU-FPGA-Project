// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vp_count.h for the primary calling header

#ifndef VERILATED_VP_COUNT___024ROOT_H_
#define VERILATED_VP_COUNT___024ROOT_H_  // guard

#include "verilated.h"


class Vp_count__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vp_count___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(p_count__02Eclk,0,0);
    VL_IN8(instr_mem__02Eclk,0,0);
    VL_IN8(reg_file__02Eclk,0,0);
    VL_IN8(cpu_top__02Eclk,0,0);
    VL_IN8(p_count__02Erst,0,0);
    VL_IN8(instr_mem__02Erst,0,0);
    VL_IN8(we,0,0);
    VL_IN8(rs1,4,0);
    VL_IN8(rs2,4,0);
    VL_IN8(rd,4,0);
    VL_IN8(imm_gen__02Eclk,0,0);
    VL_IN8(cpu_top__02Erst,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__p_count__02Eclk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__instr_mem__02Eclk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reg_file__02Eclk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__cpu_top__02Eclk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(n_pc,31,0);
    VL_OUT(p_count__02Epc,31,0);
    VL_IN(addr,31,0);
    VL_OUT(instr_mem__02Einstr,31,0);
    VL_IN(wd,31,0);
    VL_OUT(rd1,31,0);
    VL_OUT(rd2,31,0);
    VL_IN(imm_gen__02Einstr,31,0);
    VL_OUT(imm,31,0);
    VL_IN(cpu_top__02Einstr,31,0);
    VL_OUT(cpu_top__02Epc,31,0);
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 256> instr_mem__DOT__mem;
    VlUnpacked<IData/*31:0*/, 32> reg_file__DOT__regs;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vp_count__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vp_count___024root(Vp_count__Syms* symsp, const char* v__name);
    ~Vp_count___024root();
    VL_UNCOPYABLE(Vp_count___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
