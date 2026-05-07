// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vp_count.h for the primary calling header

#include "Vp_count__pch.h"
#include "Vp_count___024root.h"

VL_INLINE_OPT void Vp_count___024root___ico_sequent__TOP__0(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->imm = ((0x40U & vlSelf->imm_gen__02Einstr)
                    ? ((0x20U & vlSelf->imm_gen__02Einstr)
                        ? ((0x10U & vlSelf->imm_gen__02Einstr)
                            ? 0U : ((8U & vlSelf->imm_gen__02Einstr)
                                     ? ((4U & vlSelf->imm_gen__02Einstr)
                                         ? ((2U & vlSelf->imm_gen__02Einstr)
                                             ? ((1U 
                                                 & vlSelf->imm_gen__02Einstr)
                                                 ? 
                                                (((- (IData)(
                                                             (vlSelf->imm_gen__02Einstr 
                                                              >> 0x1fU))) 
                                                  << 0x14U) 
                                                 | ((0xff000U 
                                                     & vlSelf->imm_gen__02Einstr) 
                                                    | ((0x800U 
                                                        & (vlSelf->imm_gen__02Einstr 
                                                           >> 9U)) 
                                                       | (0x7feU 
                                                          & (vlSelf->imm_gen__02Einstr 
                                                             >> 0x14U)))))
                                                 : 0U)
                                             : 0U) : 0U)
                                     : ((4U & vlSelf->imm_gen__02Einstr)
                                         ? 0U : ((2U 
                                                  & vlSelf->imm_gen__02Einstr)
                                                  ? 
                                                 ((1U 
                                                   & vlSelf->imm_gen__02Einstr)
                                                   ? 
                                                  ((0xfe0U 
                                                    & (vlSelf->imm_gen__02Einstr 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlSelf->imm_gen__02Einstr 
                                                         >> 7U)))
                                                   : 0U)
                                                  : 0U))))
                        : 0U) : ((0x20U & vlSelf->imm_gen__02Einstr)
                                  ? ((0x10U & vlSelf->imm_gen__02Einstr)
                                      ? ((8U & vlSelf->imm_gen__02Einstr)
                                          ? 0U : ((4U 
                                                   & vlSelf->imm_gen__02Einstr)
                                                   ? 
                                                  ((2U 
                                                    & vlSelf->imm_gen__02Einstr)
                                                    ? 
                                                   ((1U 
                                                     & vlSelf->imm_gen__02Einstr)
                                                     ? 
                                                    (vlSelf->imm_gen__02Einstr 
                                                     >> 0xcU)
                                                     : 0U)
                                                    : 0U)
                                                   : 0U))
                                      : ((8U & vlSelf->imm_gen__02Einstr)
                                          ? 0U : ((4U 
                                                   & vlSelf->imm_gen__02Einstr)
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & vlSelf->imm_gen__02Einstr)
                                                    ? 
                                                   ((1U 
                                                     & vlSelf->imm_gen__02Einstr)
                                                     ? 
                                                    VL_EXTENDS_II(32,12, 
                                                                  ((0xfe0U 
                                                                    & (vlSelf->imm_gen__02Einstr 
                                                                       >> 0x14U)) 
                                                                   | (0x1fU 
                                                                      & (vlSelf->imm_gen__02Einstr 
                                                                         >> 7U))))
                                                     : 0U)
                                                    : 0U))))
                                  : ((0x10U & vlSelf->imm_gen__02Einstr)
                                      ? ((8U & vlSelf->imm_gen__02Einstr)
                                          ? 0U : ((4U 
                                                   & vlSelf->imm_gen__02Einstr)
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & vlSelf->imm_gen__02Einstr)
                                                    ? 
                                                   ((1U 
                                                     & vlSelf->imm_gen__02Einstr)
                                                     ? 
                                                    (((1U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->imm_gen__02Einstr 
                                                           >> 0xcU))) 
                                                      || (5U 
                                                          == 
                                                          (7U 
                                                           & (vlSelf->imm_gen__02Einstr 
                                                              >> 0xcU))))
                                                      ? 
                                                     VL_EXTENDS_II(32,5, 
                                                                   (0x1fU 
                                                                    & (vlSelf->imm_gen__02Einstr 
                                                                       >> 0x14U)))
                                                      : 
                                                     VL_EXTENDS_II(32,12, 
                                                                   (vlSelf->imm_gen__02Einstr 
                                                                    >> 0x14U)))
                                                     : 0U)
                                                    : 0U)))
                                      : ((8U & vlSelf->imm_gen__02Einstr)
                                          ? 0U : ((4U 
                                                   & vlSelf->imm_gen__02Einstr)
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & vlSelf->imm_gen__02Einstr)
                                                    ? 
                                                   ((1U 
                                                     & vlSelf->imm_gen__02Einstr)
                                                     ? 
                                                    (((- (IData)(
                                                                 (vlSelf->imm_gen__02Einstr 
                                                                  >> 0x1fU))) 
                                                      << 0xcU) 
                                                     | (vlSelf->imm_gen__02Einstr 
                                                        >> 0x14U))
                                                     : 0U)
                                                    : 0U))))));
    vlSelf->rd1 = ((0U == (IData)(vlSelf->rs1)) ? 0U
                    : vlSelf->reg_file__DOT__regs[vlSelf->rs1]);
    vlSelf->rd2 = ((0U == (IData)(vlSelf->rs2)) ? 0U
                    : vlSelf->reg_file__DOT__regs[vlSelf->rs2]);
}

void Vp_count___024root___eval_ico(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vp_count___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vp_count___024root___eval_triggers__ico(Vp_count___024root* vlSelf);

bool Vp_count___024root___eval_phase__ico(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vp_count___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vp_count___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vp_count___024root___eval_act(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vp_count___024root___nba_sequent__TOP__0(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__instr_mem__DOT__mem__v0;
    __Vdlyvset__instr_mem__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vilp;
    // Body
    __Vdlyvset__instr_mem__DOT__mem__v0 = 0U;
    if (vlSelf->instr_mem__02Erst) {
        __Vdlyvset__instr_mem__DOT__mem__v0 = 1U;
    }
    if ((1U & (~ (IData)(vlSelf->instr_mem__02Erst)))) {
        vlSelf->instr_mem__02Einstr = vlSelf->instr_mem__DOT__mem
            [(0x3fU & (vlSelf->addr >> 2U))];
    }
    if (__Vdlyvset__instr_mem__DOT__mem__v0) {
        __Vilp = 0U;
        while ((__Vilp <= 0xffU)) {
            vlSelf->instr_mem__DOT__mem[__Vilp] = 0U;
            __Vilp = ((IData)(1U) + __Vilp);
        }
    }
}

VL_INLINE_OPT void Vp_count___024root___nba_sequent__TOP__1(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->cpu_top__02Epc = ((IData)(vlSelf->cpu_top__02Erst)
                               ? 0U : ((IData)(4U) 
                                       + vlSelf->cpu_top__02Epc));
}

VL_INLINE_OPT void Vp_count___024root___nba_sequent__TOP__2(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__reg_file__DOT__regs__v0;
    __Vdlyvdim0__reg_file__DOT__regs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__reg_file__DOT__regs__v0;
    __Vdlyvval__reg_file__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__reg_file__DOT__regs__v0;
    __Vdlyvset__reg_file__DOT__regs__v0 = 0;
    // Body
    __Vdlyvset__reg_file__DOT__regs__v0 = 0U;
    if (((IData)(vlSelf->we) & (0U != (IData)(vlSelf->rd)))) {
        __Vdlyvval__reg_file__DOT__regs__v0 = vlSelf->wd;
        __Vdlyvset__reg_file__DOT__regs__v0 = 1U;
        __Vdlyvdim0__reg_file__DOT__regs__v0 = vlSelf->rd;
    }
    if (__Vdlyvset__reg_file__DOT__regs__v0) {
        vlSelf->reg_file__DOT__regs[__Vdlyvdim0__reg_file__DOT__regs__v0] 
            = __Vdlyvval__reg_file__DOT__regs__v0;
    }
    vlSelf->rd1 = ((0U == (IData)(vlSelf->rs1)) ? 0U
                    : vlSelf->reg_file__DOT__regs[vlSelf->rs1]);
    vlSelf->rd2 = ((0U == (IData)(vlSelf->rs2)) ? 0U
                    : vlSelf->reg_file__DOT__regs[vlSelf->rs2]);
}

VL_INLINE_OPT void Vp_count___024root___nba_sequent__TOP__3(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->p_count__02Epc = ((IData)(vlSelf->p_count__02Erst)
                               ? 0U : vlSelf->n_pc);
}

void Vp_count___024root___eval_nba(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vp_count___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vp_count___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vp_count___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vp_count___024root___nba_sequent__TOP__3(vlSelf);
    }
}

void Vp_count___024root___eval_triggers__act(Vp_count___024root* vlSelf);

bool Vp_count___024root___eval_phase__act(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vp_count___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vp_count___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vp_count___024root___eval_phase__nba(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vp_count___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vp_count___024root___dump_triggers__ico(Vp_count___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vp_count___024root___dump_triggers__nba(Vp_count___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vp_count___024root___dump_triggers__act(Vp_count___024root* vlSelf);
#endif  // VL_DEBUG

void Vp_count___024root___eval(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vp_count___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../RTL/p_count.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vp_count___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vp_count___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../RTL/p_count.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vp_count___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../RTL/p_count.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vp_count___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vp_count___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vp_count___024root___eval_debug_assertions(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->p_count__02Eclk & 0xfeU))) {
        Verilated::overWidthError("p_count.clk");}
    if (VL_UNLIKELY((vlSelf->p_count__02Erst & 0xfeU))) {
        Verilated::overWidthError("p_count.rst");}
    if (VL_UNLIKELY((vlSelf->instr_mem__02Eclk & 0xfeU))) {
        Verilated::overWidthError("instr_mem.clk");}
    if (VL_UNLIKELY((vlSelf->instr_mem__02Erst & 0xfeU))) {
        Verilated::overWidthError("instr_mem.rst");}
    if (VL_UNLIKELY((vlSelf->reg_file__02Eclk & 0xfeU))) {
        Verilated::overWidthError("reg_file.clk");}
    if (VL_UNLIKELY((vlSelf->we & 0xfeU))) {
        Verilated::overWidthError("we");}
    if (VL_UNLIKELY((vlSelf->rs1 & 0xe0U))) {
        Verilated::overWidthError("rs1");}
    if (VL_UNLIKELY((vlSelf->rs2 & 0xe0U))) {
        Verilated::overWidthError("rs2");}
    if (VL_UNLIKELY((vlSelf->rd & 0xe0U))) {
        Verilated::overWidthError("rd");}
    if (VL_UNLIKELY((vlSelf->imm_gen__02Eclk & 0xfeU))) {
        Verilated::overWidthError("imm_gen.clk");}
    if (VL_UNLIKELY((vlSelf->cpu_top__02Eclk & 0xfeU))) {
        Verilated::overWidthError("cpu_top.clk");}
    if (VL_UNLIKELY((vlSelf->cpu_top__02Erst & 0xfeU))) {
        Verilated::overWidthError("cpu_top.rst");}
}
#endif  // VL_DEBUG
