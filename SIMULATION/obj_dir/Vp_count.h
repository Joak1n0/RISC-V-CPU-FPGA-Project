// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VP_COUNT_H_
#define VERILATED_VP_COUNT_H_  // guard

#include "verilated.h"

class Vp_count__Syms;
class Vp_count___024root;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vp_count VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vp_count__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&p_count__02Eclk,0,0);
    VL_IN8(&instr_mem__02Eclk,0,0);
    VL_IN8(&reg_file__02Eclk,0,0);
    VL_IN8(&cpu_top__02Eclk,0,0);
    VL_IN8(&p_count__02Erst,0,0);
    VL_IN8(&instr_mem__02Erst,0,0);
    VL_IN8(&we,0,0);
    VL_IN8(&rs1,4,0);
    VL_IN8(&rs2,4,0);
    VL_IN8(&rd,4,0);
    VL_IN8(&imm_gen__02Eclk,0,0);
    VL_IN8(&cpu_top__02Erst,0,0);
    VL_IN(&n_pc,31,0);
    VL_OUT(&p_count__02Epc,31,0);
    VL_IN(&addr,31,0);
    VL_OUT(&instr_mem__02Einstr,31,0);
    VL_IN(&wd,31,0);
    VL_OUT(&rd1,31,0);
    VL_OUT(&rd2,31,0);
    VL_IN(&imm_gen__02Einstr,31,0);
    VL_OUT(&imm,31,0);
    VL_IN(&cpu_top__02Einstr,31,0);
    VL_OUT(&cpu_top__02Epc,31,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vp_count___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vp_count(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vp_count(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vp_count();
  private:
    VL_UNCOPYABLE(Vp_count);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
};

#endif  // guard
