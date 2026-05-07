// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vp_count__pch.h"

//============================================================
// Constructors

Vp_count::Vp_count(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vp_count__Syms(contextp(), _vcname__, this)}
    , p_count__02Eclk{vlSymsp->TOP.p_count__02Eclk}
    , instr_mem__02Eclk{vlSymsp->TOP.instr_mem__02Eclk}
    , reg_file__02Eclk{vlSymsp->TOP.reg_file__02Eclk}
    , cpu_top__02Eclk{vlSymsp->TOP.cpu_top__02Eclk}
    , p_count__02Erst{vlSymsp->TOP.p_count__02Erst}
    , instr_mem__02Erst{vlSymsp->TOP.instr_mem__02Erst}
    , we{vlSymsp->TOP.we}
    , rs1{vlSymsp->TOP.rs1}
    , rs2{vlSymsp->TOP.rs2}
    , rd{vlSymsp->TOP.rd}
    , imm_gen__02Eclk{vlSymsp->TOP.imm_gen__02Eclk}
    , cpu_top__02Erst{vlSymsp->TOP.cpu_top__02Erst}
    , n_pc{vlSymsp->TOP.n_pc}
    , p_count__02Epc{vlSymsp->TOP.p_count__02Epc}
    , addr{vlSymsp->TOP.addr}
    , instr_mem__02Einstr{vlSymsp->TOP.instr_mem__02Einstr}
    , wd{vlSymsp->TOP.wd}
    , rd1{vlSymsp->TOP.rd1}
    , rd2{vlSymsp->TOP.rd2}
    , imm_gen__02Einstr{vlSymsp->TOP.imm_gen__02Einstr}
    , imm{vlSymsp->TOP.imm}
    , cpu_top__02Einstr{vlSymsp->TOP.cpu_top__02Einstr}
    , cpu_top__02Epc{vlSymsp->TOP.cpu_top__02Epc}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vp_count::Vp_count(const char* _vcname__)
    : Vp_count(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vp_count::~Vp_count() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vp_count___024root___eval_debug_assertions(Vp_count___024root* vlSelf);
#endif  // VL_DEBUG
void Vp_count___024root___eval_static(Vp_count___024root* vlSelf);
void Vp_count___024root___eval_initial(Vp_count___024root* vlSelf);
void Vp_count___024root___eval_settle(Vp_count___024root* vlSelf);
void Vp_count___024root___eval(Vp_count___024root* vlSelf);

void Vp_count::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vp_count::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vp_count___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vp_count___024root___eval_static(&(vlSymsp->TOP));
        Vp_count___024root___eval_initial(&(vlSymsp->TOP));
        Vp_count___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vp_count___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vp_count::eventsPending() { return false; }

uint64_t Vp_count::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vp_count::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vp_count___024root___eval_final(Vp_count___024root* vlSelf);

VL_ATTR_COLD void Vp_count::final() {
    Vp_count___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vp_count::hierName() const { return vlSymsp->name(); }
const char* Vp_count::modelName() const { return "Vp_count"; }
unsigned Vp_count::threads() const { return 1; }
void Vp_count::prepareClone() const { contextp()->prepareClone(); }
void Vp_count::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vp_count::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vp_count::trace()' called on model that was Verilated without --trace option");
}
