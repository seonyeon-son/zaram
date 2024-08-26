// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_top.h for the primary calling header

#include "Vriscv_top.h"
#include "Vriscv_top__Syms.h"

//==========

void Vriscv_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vriscv_top::eval\n"); );
    Vriscv_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/syson/project/RV32I/core/pipelined/riscv_top.v", 11, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vriscv_top::_eval_initial_loop(Vriscv_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/syson/project/RV32I/core/pipelined/riscv_top.v", 11, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__1(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__1\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__o_pc_d;
    // Body
    vlTOPp->__Vdly__riscv_top__DOT__o_pc_plus_4d = vlTOPp->riscv_top__DOT__o_pc_plus_4d;
    __Vdly__o_pc_d = vlTOPp->o_pc_d;
    vlTOPp->__Vdly__o_instr_d = vlTOPp->o_instr_d;
    if (vlTOPp->i_rstn) {
        vlTOPp->__Vdly__riscv_top__DOT__o_pc_plus_4d 
            = ((IData)(vlTOPp->riscv_top__DOT__o_stall_d)
                ? vlTOPp->riscv_top__DOT__o_pc_plus_4d
                : ((IData)(4U) + vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf));
        __Vdly__o_pc_d = ((IData)(vlTOPp->riscv_top__DOT__o_stall_d)
                           ? vlTOPp->o_pc_d : vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf);
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_17 
            = (0x67U == (0x7fU & vlTOPp->o_instr_d));
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_16 
            = ((0x63U == (0x7fU & vlTOPp->o_instr_d)) 
               & ((0x4000U & vlTOPp->o_instr_d) ? (
                                                   (0x2000U 
                                                    & vlTOPp->o_instr_d)
                                                    ? 
                                                   (~ 
                                                    (vlTOPp->o_instr_d 
                                                     >> 0xcU))
                                                    : 
                                                   (~ 
                                                    (vlTOPp->o_instr_d 
                                                     >> 0xcU)))
                   : ((~ (vlTOPp->o_instr_d >> 0xdU)) 
                      & (vlTOPp->o_instr_d >> 0xcU))));
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_3 
            = (0x6fU == (0x7fU & vlTOPp->o_instr_d));
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_4 
            = (0x63U == (0x7fU & vlTOPp->o_instr_d));
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_2 
            = (1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_2);
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_8 
            = (0xfU & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_18);
        vlTOPp->__Vdly__o_instr_d = ((IData)(vlTOPp->riscv_top__DOT__o_stall_d)
                                      ? vlTOPp->o_instr_d
                                      : vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_imem__DOT__imem_arr
                                     [(0x3fffU & (vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf 
                                                  >> 2U))]);
        vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf 
            = (((((0x1fU & (vlTOPp->o_instr_d >> 0xfU)) 
                  == (0x1fU & (vlTOPp->o_instr_d >> 7U))) 
                 | ((0x1fU & (vlTOPp->o_instr_d >> 0x14U)) 
                    == (0x1fU & (vlTOPp->o_instr_d 
                                 >> 7U)))) & (~ vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_1))
                ? vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf
                : vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr
               [vlTOPp->riscv_top__DOT__o_pc_src_e]);
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5 
            = vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_alu_ctrl_d;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_15 
            = vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_alu_src_d_b;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_6 
            = (0x17U == (0x7fU & vlTOPp->o_instr_d));
        vlTOPp->o_write_data_m = vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_write_data_e;
        vlTOPp->riscv_top__DOT__o_pc_e = vlTOPp->o_pc_d;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_10 
            = (0x1fU & (vlTOPp->o_instr_d >> 0xfU));
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_11 
            = (0x1fU & (vlTOPp->o_instr_d >> 0x14U));
        vlTOPp->riscv_top__DOT__o_rd_1e = vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
            [(0x1fU & (vlTOPp->o_instr_d >> 0xfU))];
        vlTOPp->riscv_top__DOT__o_rd_2e = vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
            [(0x1fU & (vlTOPp->o_instr_d >> 0x14U))];
        vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_1 
            = (3U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_1);
        vlTOPp->riscv_top__DOT__o_read_data_w = ((4U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)
                                                  ? 
                                                 ((2U 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)
                                                    ? 
                                                   (0xffffU 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                    : 
                                                   (0xffU 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                                                  : 
                                                 ((2U 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)
                                                    ? 0U
                                                    : vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                   : 
                                                  ((1U 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9)
                                                    ? 
                                                   ((0xffff0000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                       >> 0xfU)))) 
                                                        << 0x10U)) 
                                                    | (0xffffU 
                                                       & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                                                    : 
                                                   ((0xffffff00U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                       >> 7U)))) 
                                                        << 8U)) 
                                                    | (0xffU 
                                                       & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))));
        vlTOPp->riscv_top__DOT__o_ext_imm_w = vlTOPp->riscv_top__DOT__o_ext_imm_m;
        vlTOPp->riscv_top__DOT__o_pc_plus_4w = (0x1fU 
                                                & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_5);
        vlTOPp->riscv_top__DOT__o_alu_result_w = vlTOPp->o_alu_result_m;
    } else {
        vlTOPp->__Vdly__riscv_top__DOT__o_pc_plus_4d = 0U;
        __Vdly__o_pc_d = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_17 = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_16 = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_3 = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_4 = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_2 = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_8 = 0U;
        vlTOPp->__Vdly__o_instr_d = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5 = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_15 = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_6 = 0U;
        vlTOPp->o_write_data_m = 0U;
        vlTOPp->riscv_top__DOT__o_pc_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_10 = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_11 = 0U;
        vlTOPp->riscv_top__DOT__o_rd_1e = 0U;
        vlTOPp->riscv_top__DOT__o_rd_2e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_1 = 0U;
        vlTOPp->riscv_top__DOT__o_read_data_w = 0U;
        vlTOPp->riscv_top__DOT__o_ext_imm_w = 0U;
        vlTOPp->riscv_top__DOT__o_pc_plus_4w = 0U;
        vlTOPp->riscv_top__DOT__o_alu_result_w = 0U;
    }
    vlTOPp->o_pc_d = __Vdly__o_pc_d;
    vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_2 
        = ((IData)(vlTOPp->i_rstn) ? (0x23U == (0x7fU 
                                                & vlTOPp->o_instr_d))
            : 0U);
    vlTOPp->o_ctrl_mem_byte_sel_m = (0xfU & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_8);
    vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_18 
        = ((IData)(vlTOPp->i_rstn) ? (((3U == (0x7fU 
                                               & vlTOPp->o_instr_d)) 
                                       | (0x23U == 
                                          (0x7fU & vlTOPp->o_instr_d)))
                                       ? ((0x4000U 
                                           & vlTOPp->o_instr_d)
                                           ? ((0x2000U 
                                               & vlTOPp->o_instr_d)
                                               ? 0xfU
                                               : ((0x1000U 
                                                   & vlTOPp->o_instr_d)
                                                   ? 3U
                                                   : 1U))
                                           : ((0x2000U 
                                               & vlTOPp->o_instr_d)
                                               ? 0xfU
                                               : ((0x1000U 
                                                   & vlTOPp->o_instr_d)
                                                   ? 3U
                                                   : 1U)))
                                       : 0xfU) : 0U);
    vlTOPp->__Vtableidx5 = (0xfU & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5);
    if (vlTOPp->__Vtablechg5[vlTOPp->__Vtableidx5]) {
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP 
            = vlTOPp->__Vtable5_riscv_top__DOT__u_riscv_execute__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP
            [vlTOPp->__Vtableidx5];
    }
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_1 
            = (3U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_1);
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9 
            = (7U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_19);
        vlTOPp->riscv_top__DOT__o_ext_imm_m = vlTOPp->riscv_top__DOT__o_ext_imm_e;
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_5 
            = (0x1fU & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_12);
    } else {
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_1 = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_9 = 0U;
        vlTOPp->riscv_top__DOT__o_ext_imm_m = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_5 = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT____Vcellinp__u_mux_writeback__i_mux_concat_data[0U] 
        = vlTOPp->riscv_top__DOT__o_alu_result_w;
    vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT____Vcellinp__u_mux_writeback__i_mux_concat_data[1U] 
        = vlTOPp->riscv_top__DOT__o_read_data_w;
    vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT____Vcellinp__u_mux_writeback__i_mux_concat_data[2U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__o_ext_imm_w)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__o_pc_plus_4w))));
    vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT____Vcellinp__u_mux_writeback__i_mux_concat_data[3U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__o_ext_imm_w)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__o_pc_plus_4w))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT____Vcellinp__u_mux_writeback__i_mux_concat_data[0U];
    vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT____Vcellinp__u_mux_writeback__i_mux_concat_data[1U];
    vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT____Vcellinp__u_mux_writeback__i_mux_concat_data[2U];
    vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr[3U] 
        = vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT____Vcellinp__u_mux_writeback__i_mux_concat_data[3U];
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_1 
            = vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_result_src_d;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_19 
            = (7U & (vlTOPp->o_instr_d >> 0xcU));
        vlTOPp->riscv_top__DOT__o_ext_imm_e = vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_ext_imm_d;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_12 
            = (0x1fU & (vlTOPp->o_instr_d >> 7U));
    } else {
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_1 = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_19 = 0U;
        vlTOPp->riscv_top__DOT__o_ext_imm_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_12 = 0U;
    }
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__2(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__2\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    IData/*31:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    // Body
    if (vlTOPp->o_mem_write_m) {
        vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__i = 4U;
    }
    __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v4 = 0U;
    if (vlTOPp->o_mem_write_m) {
        if ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0 
                = (0xffU & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_wr_data);
            __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 0U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0 
                = (0x3fffU & (vlTOPp->o_alu_result_m 
                              >> 2U));
        }
        if ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1 
                = (0xffU & (vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_wr_data 
                            >> 8U));
            __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 8U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1 
                = (0x3fffU & (vlTOPp->o_alu_result_m 
                              >> 2U));
        }
        if ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2 
                = (0xffU & (vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_wr_data 
                            >> 0x10U));
            __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 0x10U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2 
                = (0x3fffU & (vlTOPp->o_alu_result_m 
                              >> 2U));
        }
        if ((8U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3 
                = (0xffU & (vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_wr_data 
                            >> 0x18U));
            __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 0x18U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3 
                = (0x3fffU & (vlTOPp->o_alu_result_m 
                              >> 2U));
        }
    } else {
        __Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v4 
            = vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr
            [(0x3fffU & (vlTOPp->o_alu_result_m >> 2U))];
        __Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v4 = 1U;
        __Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v4 
            = (0x3fffU & (vlTOPp->o_alu_result_m >> 2U));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0) {
        vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0))) 
                & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v0)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1) {
        vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1))) 
                & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v1)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2) {
        vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2))) 
                & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v2)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3) {
        vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3))) 
                & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v3)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v4) {
        vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v4] 
            = __Vdlyvval__riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    }
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__3(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__3\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers__v0;
    IData/*31:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers__v0;
    // Body
    __Vdlyvval__riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers__v0 
        = ((vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_0 
            & (0U != (0x1fU & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_4)))
            ? vlTOPp->riscv_top__DOT__o_result_w : 
           vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
           [(0x1fU & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_4)]);
    __Vdlyvdim0__riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers__v0 
        = (0x1fU & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_4);
    vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[__Vdlyvdim0__riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers__v0] 
        = __Vdlyvval__riscv_top__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers__v0;
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__6(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__6\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_mem_write_m = (1U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_2);
    vlTOPp->riscv_top__DOT__o_result_w = vlTOPp->riscv_top__DOT__u_riscv_writeback__DOT__u_mux_writeback__DOT__mux_input_arr
        [(3U & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_1)];
    if (vlTOPp->i_rstn) {
        vlTOPp->o_alu_result_m = vlTOPp->riscv_top__DOT__o_alu_data;
        vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_4 
            = vlTOPp->riscv_top__DOT__o_pc_plus_4m;
        vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_0 
            = (1U & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_0);
    } else {
        vlTOPp->o_alu_result_m = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_4 = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_0 = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_wr_data 
        = ((0x1fU >= (0x18U & (vlTOPp->o_alu_result_m 
                               << 3U))) ? (vlTOPp->o_write_data_m 
                                           << (0x18U 
                                               & (vlTOPp->o_alu_result_m 
                                                  << 3U)))
            : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__o_dmem_intf_byte_sel 
        = ((3U >= (3U & vlTOPp->o_alu_result_m)) ? 
           (0xfU & ((IData)(vlTOPp->o_ctrl_mem_byte_sel_m) 
                    << (3U & vlTOPp->o_alu_result_m)))
            : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
        = ((0x1fU >= (0x18U & (vlTOPp->o_alu_result_m 
                               << 3U))) ? (vlTOPp->riscv_top__DOT__u_riscv_memory__DOT__u_riscv_dmem__DOT__dmem_arr
                                           [(0x3fffU 
                                             & (vlTOPp->o_alu_result_m 
                                                >> 2U))] 
                                           >> (0x18U 
                                               & (vlTOPp->o_alu_result_m 
                                                  << 3U)))
            : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_0__i_mux_concat_data[0U] 
        = vlTOPp->riscv_top__DOT__o_rd_1e;
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_0__i_mux_concat_data[1U] 
        = (IData)((((QData)((IData)(vlTOPp->o_alu_result_m)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__o_result_w))));
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_0__i_mux_concat_data[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->o_alu_result_m)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__o_result_w))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_2__i_mux_concat_data[0U] 
        = vlTOPp->riscv_top__DOT__o_rd_2e;
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_2__i_mux_concat_data[1U] 
        = (IData)((((QData)((IData)(vlTOPp->o_alu_result_m)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__o_result_w))));
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_2__i_mux_concat_data[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->o_alu_result_m)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__o_result_w))) 
                   >> 0x20U));
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__o_pc_plus_4m = vlTOPp->riscv_top__DOT__o_pc_plus_4e;
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_0 
            = (1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_0);
    } else {
        vlTOPp->riscv_top__DOT__o_pc_plus_4m = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_0 = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_0__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_0__i_mux_concat_data[0U];
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_0__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_0__i_mux_concat_data[1U];
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_0__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_0__i_mux_concat_data[2U];
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_2__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_2__i_mux_concat_data[0U];
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_2__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_2__i_mux_concat_data[1U];
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_2__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_mux_execute_2__i_mux_concat_data[2U];
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__o_pc_plus_4e = vlTOPp->riscv_top__DOT__o_pc_plus_4d;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_0 
            = (1U & (~ ((0x23U == (0x7fU & vlTOPp->o_instr_d)) 
                        | (0x63U == (0x7fU & vlTOPp->o_instr_d)))));
    } else {
        vlTOPp->riscv_top__DOT__o_pc_plus_4e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_0 = 0U;
    }
    vlTOPp->riscv_top__DOT__o_forward_ae = (((vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_0 
                                              & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_5))) 
                                             & ((0x1fU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_10) 
                                                == 
                                                (0x1fU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_5)))
                                             ? 2U : 
                                            (((vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_0 
                                               & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_4))) 
                                              & ((0x1fU 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_10) 
                                                 == 
                                                 (0x1fU 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_4)))
                                              ? 1U : 0U));
    vlTOPp->riscv_top__DOT__o_forward_be = (((vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_0 
                                              & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_5))) 
                                             & ((0x1fU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_11) 
                                                == 
                                                (0x1fU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellout__u_riscv_register_execute__o_register_q_5)))
                                             ? 2U : 
                                            (((vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_0 
                                               & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_4))) 
                                              & ((0x1fU 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_11) 
                                                 == 
                                                 (0x1fU 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_memory__DOT____Vcellout__u_riscv_register_memory__o_register_q_4)))
                                              ? 1U : 0U));
    vlTOPp->riscv_top__DOT__o_pc_plus_4d = vlTOPp->__Vdly__riscv_top__DOT__o_pc_plus_4d;
    vlTOPp->o_instr_d = vlTOPp->__Vdly__o_instr_d;
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_riscv_mux_1__i_mux_concat_data 
        = (((QData)((IData)(vlTOPp->riscv_top__DOT__o_pc_e)) 
            << 0x20U) | (QData)((IData)(((2U >= (IData)(vlTOPp->riscv_top__DOT__o_forward_ae))
                                          ? vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_0__DOT__mux_input_arr
                                         [vlTOPp->riscv_top__DOT__o_forward_ae]
                                          : 0U))));
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_write_data_e 
        = ((2U >= (IData)(vlTOPp->riscv_top__DOT__o_forward_be))
            ? vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_mux_execute_2__DOT__mux_input_arr
           [vlTOPp->riscv_top__DOT__o_forward_be] : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_alu_ctrl_d 
        = (((0x33U == (0x7fU & vlTOPp->o_instr_d)) 
            | (0x13U == (0x7fU & vlTOPp->o_instr_d)))
            ? ((0x4000U & vlTOPp->o_instr_d) ? ((0x2000U 
                                                 & vlTOPp->o_instr_d)
                                                 ? 
                                                ((0x1000U 
                                                  & vlTOPp->o_instr_d)
                                                  ? 7U
                                                  : 6U)
                                                 : 
                                                ((0x1000U 
                                                  & vlTOPp->o_instr_d)
                                                  ? 
                                                 ((0x40000000U 
                                                   & vlTOPp->o_instr_d)
                                                   ? 0xdU
                                                   : 5U)
                                                  : 4U))
                : ((0x2000U & vlTOPp->o_instr_d) ? 
                   ((0x1000U & vlTOPp->o_instr_d) ? 3U
                     : 2U) : ((0x1000U & vlTOPp->o_instr_d)
                               ? 1U : (((vlTOPp->o_instr_d 
                                         >> 0x1eU) 
                                        & (0x33U == 
                                           (0x7fU & vlTOPp->o_instr_d)))
                                        ? 8U : 0U))))
            : ((0x63U == (0x7fU & vlTOPp->o_instr_d))
                ? ((0x4000U & vlTOPp->o_instr_d) ? 
                   ((0x2000U & vlTOPp->o_instr_d) ? 3U
                     : 2U) : ((0x2000U & vlTOPp->o_instr_d)
                               ? 0xfU : 8U)) : 0U));
    vlTOPp->riscv_top__DOT__o_stall_d = ((((0x1fU & 
                                            (vlTOPp->o_instr_d 
                                             >> 0xfU)) 
                                           == (0x1fU 
                                               & (vlTOPp->o_instr_d 
                                                  >> 7U))) 
                                          | ((0x1fU 
                                              & (vlTOPp->o_instr_d 
                                                 >> 0x14U)) 
                                             == (0x1fU 
                                                 & (vlTOPp->o_instr_d 
                                                    >> 7U)))) 
                                         & (~ vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_1));
    vlTOPp->__Vtableidx2 = (0x7fU & vlTOPp->o_instr_d);
    vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_result_src_d 
        = vlTOPp->__Vtable2_riscv_top__DOT__u_riscv_decode__DOT__o_result_src_d
        [vlTOPp->__Vtableidx2];
    vlTOPp->__Vtableidx3 = (0x7fU & vlTOPp->o_instr_d);
    vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_alu_src_d_b 
        = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_decode__DOT__o_alu_src_d_b
        [vlTOPp->__Vtableidx3];
    vlTOPp->__Vtableidx4 = ((0x400U & (vlTOPp->o_instr_d 
                                       >> 0x14U)) | 
                            ((0x380U & (vlTOPp->o_instr_d 
                                        >> 5U)) | (0x7fU 
                                                   & vlTOPp->o_instr_d)));
    if (vlTOPp->__Vtablechg4[vlTOPp->__Vtableidx4]) {
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR[0U] 
            = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx4][0U];
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR[1U] 
            = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx4][1U];
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR[2U] 
            = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx4][2U];
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR[3U] 
            = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx4][3U];
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR[4U] 
            = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx4][4U];
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR[5U] 
            = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx4][5U];
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR[6U] 
            = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx4][6U];
        vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR[7U] 
            = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_decode__DOT__u_riscv_ctrl_i__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx4][7U];
    }
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->o_instr_d);
    vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_imm_src_d 
        = vlTOPp->__Vtable1_riscv_top__DOT__u_riscv_decode__DOT__o_imm_src_d
        [vlTOPp->__Vtableidx1];
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_1__DOT__mux_input_arr[0U] 
        = (IData)(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_riscv_mux_1__i_mux_concat_data);
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_1__DOT__mux_input_arr[1U] 
        = (IData)((vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_riscv_mux_1__i_mux_concat_data 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_riscv_mux_3__i_mux_concat_data 
        = (((QData)((IData)(vlTOPp->riscv_top__DOT__o_ext_imm_e)) 
            << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_write_data_e)));
    vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_ext_imm_d 
        = ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_imm_src_d))
            ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_imm_src_d))
                ? 0U : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_imm_src_d))
                         ? (0xfffff000U & vlTOPp->o_instr_d)
                         : ((0xfff00000U & ((- (IData)(
                                                       (1U 
                                                        & (vlTOPp->o_instr_d 
                                                           >> 0x1fU)))) 
                                            << 0x14U)) 
                            | ((0xff000U & vlTOPp->o_instr_d) 
                               | ((0x800U & (vlTOPp->o_instr_d 
                                             >> 9U)) 
                                  | (0x7feU & (vlTOPp->o_instr_d 
                                               >> 0x14U)))))))
            : ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_imm_src_d))
                ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_imm_src_d))
                    ? ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->o_instr_d 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       ((0x800U & (vlTOPp->o_instr_d 
                                   << 4U)) | ((0x7e0U 
                                               & (vlTOPp->o_instr_d 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlTOPp->o_instr_d 
                                                    >> 7U)))))
                    : ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->o_instr_d 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       ((0xfe0U & (vlTOPp->o_instr_d 
                                   >> 0x14U)) | (0x1fU 
                                                 & (vlTOPp->o_instr_d 
                                                    >> 7U)))))
                : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_decode__DOT__o_imm_src_d))
                    ? ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->o_instr_d 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       (0xfffU & (vlTOPp->o_instr_d 
                                  >> 0x14U))) : 0U)));
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae 
        = vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_1__DOT__mux_input_arr
        [(1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_6)];
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_3__DOT__mux_input_arr[0U] 
        = (IData)(vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_riscv_mux_3__i_mux_concat_data);
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_3__DOT__mux_input_arr[1U] 
        = (IData)((vlTOPp->riscv_top__DOT__u_riscv_execute__DOT____Vcellinp__u_riscv_mux_3__i_mux_concat_data 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be 
        = vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__u_riscv_mux_3__DOT__mux_input_arr
        [(1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_15)];
    vlTOPp->riscv_top__DOT__o_alu_data = ((8U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                           ? ((4U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                               ? ((2U 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                                    ? 
                                                   VL_SHIFTRS_III(32,32,5, vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae, 
                                                                  (0x1fU 
                                                                   & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be))
                                                    : 0U))
                                               : ((2U 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                                    ? 0U
                                                    : 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae 
                                                    - vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be))))
                                           : ((4U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                               ? ((2U 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                                    ? 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be)
                                                    : 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae 
                                                    | vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be))
                                                   : 
                                                  ((1U 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                                    ? 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae 
                                                    >> 
                                                    (0x1fU 
                                                     & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be))
                                                    : 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae 
                                                    ^ vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be)))
                                               : ((2U 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                                    ? 
                                                   ((vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae 
                                                     < vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be)
                                                     ? 1U
                                                     : 0U)
                                                    : 
                                                   (VL_LTS_III(1,32,32, vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae, vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be)
                                                     ? 1U
                                                     : 0U))
                                                   : 
                                                  ((1U 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_5)
                                                    ? 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae 
                                                    << 
                                                    (0x1fU 
                                                     & vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be))
                                                    : 
                                                   (vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_ae 
                                                    + vlTOPp->riscv_top__DOT__u_riscv_execute__DOT__o_src_be)))));
    vlTOPp->riscv_top__DOT__o_pc_src_e = ((1U & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_17)
                                           ? 3U : (
                                                   (1U 
                                                    & (vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_3 
                                                       | (vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_4 
                                                          & ((1U 
                                                              & vlTOPp->riscv_top__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_register_decode__o_register_q_16)
                                                              ? 
                                                             (0U 
                                                              != vlTOPp->riscv_top__DOT__o_alu_data)
                                                              : 
                                                             (0U 
                                                              == vlTOPp->riscv_top__DOT__o_alu_data)))))
                                                    ? 1U
                                                    : 0U));
    vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT____Vcellinp__u_riscv_mux__i_mux_concat_data[0U] 
        = ((IData)(4U) + vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__i_pcf);
    vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT____Vcellinp__u_riscv_mux__i_mux_concat_data[1U] 
        = (vlTOPp->riscv_top__DOT__o_pc_e + vlTOPp->riscv_top__DOT__o_ext_imm_e);
    vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT____Vcellinp__u_riscv_mux__i_mux_concat_data[2U] 
        = (IData)(((QData)((IData)(vlTOPp->riscv_top__DOT__o_alu_data)) 
                   << 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT____Vcellinp__u_riscv_mux__i_mux_concat_data[3U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__o_alu_data)) 
                    << 0x20U) >> 0x20U));
    vlTOPp->riscv_top__DOT__o_flush_e = (1U & (IData)(vlTOPp->riscv_top__DOT__o_pc_src_e));
    vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT____Vcellinp__u_riscv_mux__i_mux_concat_data[0U];
    vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT____Vcellinp__u_riscv_mux__i_mux_concat_data[1U];
    vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT____Vcellinp__u_riscv_mux__i_mux_concat_data[2U];
    vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT__u_riscv_mux__DOT__mux_input_arr[3U] 
        = vlTOPp->riscv_top__DOT__u_riscv_fetch__DOT____Vcellinp__u_riscv_mux__i_mux_concat_data[3U];
}

void Vriscv_top::_eval(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk))) 
         | ((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->i_clk)) & (IData)(vlTOPp->__Vclklast__TOP__i_clk))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if ((((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk))) 
         | ((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
    vlTOPp->__Vclklast__TOP__i_rstn = vlTOPp->i_rstn;
}

VL_INLINE_OPT QData Vriscv_top::_change_request(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_change_request\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vriscv_top::_change_request_1(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_change_request_1\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vriscv_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((i_rstn & 0xfeU))) {
        Verilated::overWidthError("i_rstn");}
}
#endif  // VL_DEBUG
