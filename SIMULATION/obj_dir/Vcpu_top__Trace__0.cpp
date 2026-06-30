// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu_top__Syms.h"


void Vcpu_top___024root__trace_chg_0_sub_0(Vcpu_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vcpu_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root__trace_chg_0\n"); );
    // Init
    Vcpu_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu_top___024root*>(voidSelf);
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vcpu_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vcpu_top___024root__trace_chg_0_sub_0(Vcpu_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->cpu_top__DOT__alu_op),4);
        bufp->chgIData(oldp+1,(vlSelf->cpu_top__DOT__alu_result),32);
        bufp->chgIData(oldp+2,(vlSelf->cpu_top__DOT__data_out),32);
        bufp->chgIData(oldp+3,(vlSelf->cpu_top__DOT__dm__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+4,(vlSelf->clk));
    bufp->chgBit(oldp+5,(vlSelf->rst));
    bufp->chgIData(oldp+6,(vlSelf->instr),32);
    bufp->chgIData(oldp+7,(vlSelf->pc),32);
}

void Vcpu_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top___024root__trace_cleanup\n"); );
    // Init
    Vcpu_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu_top___024root*>(voidSelf);
    Vcpu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
