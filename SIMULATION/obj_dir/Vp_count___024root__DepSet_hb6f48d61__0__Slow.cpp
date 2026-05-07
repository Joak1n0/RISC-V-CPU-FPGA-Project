// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vp_count.h for the primary calling header

#include "Vp_count__pch.h"
#include "Vp_count___024root.h"

VL_ATTR_COLD void Vp_count___024root___eval_static(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vp_count___024root___eval_initial(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__p_count__02Eclk__0 
        = vlSelf->p_count__02Eclk;
    vlSelf->__Vtrigprevexpr___TOP__instr_mem__02Eclk__0 
        = vlSelf->instr_mem__02Eclk;
    vlSelf->__Vtrigprevexpr___TOP__reg_file__02Eclk__0 
        = vlSelf->reg_file__02Eclk;
    vlSelf->__Vtrigprevexpr___TOP__cpu_top__02Eclk__0 
        = vlSelf->cpu_top__02Eclk;
}

VL_ATTR_COLD void Vp_count___024root___eval_final(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vp_count___024root___dump_triggers__stl(Vp_count___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vp_count___024root___eval_phase__stl(Vp_count___024root* vlSelf);

VL_ATTR_COLD void Vp_count___024root___eval_settle(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vp_count___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../RTL/p_count.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vp_count___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vp_count___024root___dump_triggers__stl(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vp_count___024root___ico_sequent__TOP__0(Vp_count___024root* vlSelf);

VL_ATTR_COLD void Vp_count___024root___eval_stl(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vp_count___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vp_count___024root___eval_triggers__stl(Vp_count___024root* vlSelf);

VL_ATTR_COLD bool Vp_count___024root___eval_phase__stl(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vp_count___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vp_count___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vp_count___024root___dump_triggers__ico(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vp_count___024root___dump_triggers__act(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge p_count.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge instr_mem.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge reg_file.clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge cpu_top.clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vp_count___024root___dump_triggers__nba(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge p_count.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge instr_mem.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge reg_file.clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge cpu_top.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vp_count___024root___ctor_var_reset(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->p_count__02Eclk = VL_RAND_RESET_I(1);
    vlSelf->p_count__02Erst = VL_RAND_RESET_I(1);
    vlSelf->n_pc = VL_RAND_RESET_I(32);
    vlSelf->p_count__02Epc = VL_RAND_RESET_I(32);
    vlSelf->instr_mem__02Eclk = VL_RAND_RESET_I(1);
    vlSelf->instr_mem__02Erst = VL_RAND_RESET_I(1);
    vlSelf->addr = VL_RAND_RESET_I(32);
    vlSelf->instr_mem__02Einstr = VL_RAND_RESET_I(32);
    vlSelf->reg_file__02Eclk = VL_RAND_RESET_I(1);
    vlSelf->we = VL_RAND_RESET_I(1);
    vlSelf->rs1 = VL_RAND_RESET_I(5);
    vlSelf->rs2 = VL_RAND_RESET_I(5);
    vlSelf->rd = VL_RAND_RESET_I(5);
    vlSelf->wd = VL_RAND_RESET_I(32);
    vlSelf->rd1 = VL_RAND_RESET_I(32);
    vlSelf->rd2 = VL_RAND_RESET_I(32);
    vlSelf->imm_gen__02Eclk = VL_RAND_RESET_I(1);
    vlSelf->imm_gen__02Einstr = VL_RAND_RESET_I(32);
    vlSelf->imm = VL_RAND_RESET_I(32);
    vlSelf->cpu_top__02Eclk = VL_RAND_RESET_I(1);
    vlSelf->cpu_top__02Erst = VL_RAND_RESET_I(1);
    vlSelf->cpu_top__02Einstr = VL_RAND_RESET_I(32);
    vlSelf->cpu_top__02Epc = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->instr_mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->reg_file__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vtrigprevexpr___TOP__p_count__02Eclk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__instr_mem__02Eclk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reg_file__02Eclk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__cpu_top__02Eclk__0 = VL_RAND_RESET_I(1);
}
