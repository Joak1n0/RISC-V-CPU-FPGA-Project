// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_top.h for the primary calling header

#include "Vcpu_top__pch.h"
#include "Vcpu_top___024root.h"

void Vcpu_top___024root___eval_act(Vcpu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_act\n"); );
}

extern const VlUnpacked<IData/*31:0*/, 32> Vcpu_top__ConstPool__TABLE_h2f0e2386_0;

VL_INLINE_OPT void Vcpu_top___024root___nba_sequent__TOP__0(Vcpu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    IData/*31:0*/ __Vilp;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__dm__DOT__mem__v0;
    __Vdlyvset__cpu_top__DOT__dm__DOT__mem__v0 = 0;
    // Body
    __Vdlyvset__cpu_top__DOT__dm__DOT__mem__v0 = 0U;
    if ((1U & (~ (IData)(vlSelf->rst)))) {
        vlSelf->cpu_top__DOT__data_out = vlSelf->cpu_top__DOT__dm__DOT__mem
            [(0xffU & (vlSelf->cpu_top__DOT__alu_result 
                       >> 2U))];
    }
    if (vlSelf->rst) {
        vlSelf->cpu_top__DOT__dm__DOT__unnamedblk1__DOT__i = 0x100U;
        __Vdlyvset__cpu_top__DOT__dm__DOT__mem__v0 = 1U;
    }
    if (__Vdlyvset__cpu_top__DOT__dm__DOT__mem__v0) {
        __Vilp = 0U;
        while ((__Vilp <= 0xffU)) {
            vlSelf->cpu_top__DOT__dm__DOT__mem[__Vilp] = 0U;
            __Vilp = ((IData)(1U) + __Vilp);
        }
    }
    __Vtableidx1 = (((IData)(vlSelf->cpu_top__DOT__alu_op) 
                     << 1U) | (IData)(vlSelf->rst));
    if (vlSelf->rst) {
        vlSelf->pc = 0U;
        vlSelf->cpu_top__DOT__alu_op = 0U;
    } else {
        vlSelf->pc = ((IData)(4U) + vlSelf->pc);
        vlSelf->cpu_top__DOT__alu_op = ((0U == (vlSelf->instr 
                                                >> 0x1aU))
                                         ? ((0x20U 
                                             & vlSelf->instr)
                                             ? ((0x10U 
                                                 & vlSelf->instr)
                                                 ? 0U
                                                 : 
                                                ((8U 
                                                  & vlSelf->instr)
                                                  ? 0U
                                                  : 
                                                 ((4U 
                                                   & vlSelf->instr)
                                                   ? 
                                                  ((2U 
                                                    & vlSelf->instr)
                                                    ? 
                                                   ((1U 
                                                     & vlSelf->instr)
                                                     ? 0U
                                                     : 4U)
                                                    : 
                                                   ((1U 
                                                     & vlSelf->instr)
                                                     ? 3U
                                                     : 2U))
                                                   : 
                                                  ((2U 
                                                    & vlSelf->instr)
                                                    ? 
                                                   ((1U 
                                                     & vlSelf->instr)
                                                     ? 0U
                                                     : 1U)
                                                    : 0U))))
                                             : 0U) : 0U);
    }
    vlSelf->cpu_top__DOT__alu_result = Vcpu_top__ConstPool__TABLE_h2f0e2386_0
        [__Vtableidx1];
}

void Vcpu_top___024root___eval_nba(Vcpu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vcpu_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vcpu_top___024root___eval_triggers__act(Vcpu_top___024root* vlSelf);

bool Vcpu_top___024root___eval_phase__act(Vcpu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vcpu_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vcpu_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vcpu_top___024root___eval_phase__nba(Vcpu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vcpu_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_top___024root___dump_triggers__nba(Vcpu_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_top___024root___dump_triggers__act(Vcpu_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vcpu_top___024root___eval(Vcpu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vcpu_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../RTL/cpu_top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vcpu_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../RTL/cpu_top.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vcpu_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vcpu_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vcpu_top___024root___eval_debug_assertions(Vcpu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
