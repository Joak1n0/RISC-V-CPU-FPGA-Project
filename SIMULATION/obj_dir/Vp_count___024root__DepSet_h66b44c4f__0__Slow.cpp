// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vp_count.h for the primary calling header

#include "Vp_count__pch.h"
#include "Vp_count__Syms.h"
#include "Vp_count___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vp_count___024root___dump_triggers__stl(Vp_count___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vp_count___024root___eval_triggers__stl(Vp_count___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vp_count__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vp_count___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vp_count___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
