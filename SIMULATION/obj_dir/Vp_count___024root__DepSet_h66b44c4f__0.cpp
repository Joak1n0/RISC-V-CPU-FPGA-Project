// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vp_count.h for the primary calling header

#include "Vp_count__pch.h"
#include "Vp_count__Syms.h"
#include "Vp_count___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vp_count___024root___dump_triggers__ico(Vp_count___024root* vlSelf);
#endif  // VL_DEBUG

void Vp_count___024root___eval_triggers__ico(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vp_count___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vp_count___024root___dump_triggers__act(Vp_count___024root* vlSelf);
#endif  // VL_DEBUG

void Vp_count___024root___eval_triggers__act(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->p_count__02Eclk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__p_count__02Eclk__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->instr_mem__02Eclk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__instr_mem__02Eclk__0))));
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->reg_file__02Eclk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__reg_file__02Eclk__0))));
    vlSelf->__VactTriggered.set(3U, ((IData)(vlSelf->cpu_top__02Eclk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__cpu_top__02Eclk__0))));
    vlSelf->__Vtrigprevexpr___TOP__p_count__02Eclk__0 
        = vlSelf->p_count__02Eclk;
    vlSelf->__Vtrigprevexpr___TOP__instr_mem__02Eclk__0 
        = vlSelf->instr_mem__02Eclk;
    vlSelf->__Vtrigprevexpr___TOP__reg_file__02Eclk__0 
        = vlSelf->reg_file__02Eclk;
    vlSelf->__Vtrigprevexpr___TOP__cpu_top__02Eclk__0 
        = vlSelf->cpu_top__02Eclk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vp_count___024root___dump_triggers__act(vlSelf);
    }
#endif
}
