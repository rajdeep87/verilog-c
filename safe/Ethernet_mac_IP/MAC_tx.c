//#include <stdio.h>
#define TRUE 1
#define FALSE 0

#include "CRC_gen.c"
#include "flow_ctrl.c"
#include "MAC_tx_addr_add.c"
#include "MAC_tx_ctrl.c"
#include "MAC_tx_FF.c"
#include "Random_gen.c"

void MAC_tx(_Bool Reset, _Bool Clk, _Bool Clk_user, unsigned char *TxD, _Bool *TxEn, _Bool CRS, unsigned char *Tx_pkt_type_rmon, unsigned short int *Tx_pkt_length_rmon, _Bool *Tx_apply_rmon, unsigned char *Tx_pkt_err_type_rmon, _Bool *Tx_mac_wa, _Bool Tx_mac_wr, unsigned int Tx_mac_data, unsigned char Tx_mac_BE, _Bool Tx_mac_sop, _Bool Tx_mac_eop, unsigned char Tx_Hwmark, unsigned char Tx_Lwmark, _Bool pause_frame_send_en, unsigned short int pause_quanta_set, _Bool MAC_tx_add_en, _Bool FullDuplex, unsigned char MaxRetry, unsigned char IFGset, unsigned char MAC_add_prom_data, unsigned char MAC_add_prom_add, _Bool MAC_add_prom_wr, _Bool tx_pause_en, _Bool xoff_cpu, _Bool xon_cpu, unsigned short int pause_quanta, _Bool pause_quanta_val)
{
  _Bool CRC_init;
  unsigned char Frame_data;
  _Bool Data_en;
  _Bool CRC_rd;
  _Bool CRC_end;
  unsigned char CRC_out;
  _Bool Random_init;
  unsigned char RetryCnt;
  _Bool Random_time_meet;
  _Bool pause_apply;
  _Bool pause_quanta_sub;
  _Bool xoff_gen;
  _Bool xoff_gen_complete;
  _Bool xon_gen;
  _Bool xon_gen_complete;
  unsigned char Fifo_data;
  _Bool Fifo_rd;
  _Bool Fifo_eop;
  _Bool Fifo_da;
  _Bool Fifo_rd_finish;
  _Bool Fifo_rd_retry;
  _Bool Fifo_ra;
  _Bool Fifo_data_err_empty;
  _Bool Fifo_data_err_full;
  _Bool MAC_tx_addr_init;
  _Bool MAC_tx_addr_rd;
  unsigned char MAC_tx_addr_data;

  MAC_tx_ctrl(Reset, Clk, &CRC_init, &Frame_data, &Data_en, &CRC_rd, CRC_end, CRC_out, &Random_init, &RetryCnt, Random_time_meet, pause_apply, &pause_quanta_sub, xoff_gen, &xoff_gen_complete, xon_gen, &xon_gen_complete, Fifo_data, &Fifo_rd, Fifo_eop, Fifo_da, &Fifo_rd_finish, &Fifo_rd_retry, Fifo_ra, Fifo_data_err_empty, Fifo_data_err_full, &TxD, &TxEn, CRS, &MAC_tx_addr_init, &MAC_tx_addr_rd, MAC_tx_addr_data, &Tx_pkt_type_rmon, &Tx_pkt_length_rmon, &Tx_apply_rmon, &Tx_pkt_err_type_rmon, pause_frame_send_en, pause_quanta_set, MAC_tx_add_en, FullDuplex, MaxRetry, IFGset);

 CRC_gen(Reset, Clk, CRC_init, Frame_data, Data_en, CRC_rd, &CRC_out, &CRC_end);

 flow_ctrl(Reset, Clk, tx_pause_en, xoff_cpu, xon_cpu, pause_quanta, pause_quanta_val, &pause_apply, pause_quanta_sub, &xoff_gen, xoff_gen_complete, &xon_gen, xon_gen_complete);

 MAC_tx_addr_add(Reset, Clk, MAC_tx_addr_rd, MAC_tx_addr_init, &MAC_tx_addr_data, MAC_add_prom_data, MAC_add_prom_add, MAC_add_prom_wr);

 MAC_tx_FF(Reset, Clk, Clk_user, &Fifo_data, Fifo_rd, Fifo_rd_finish, Fifo_rd_retry, &Fifo_eop, &Fifo_da, &Fifo_ra, &Fifo_data_err_empty, &Fifo_data_err_full, &Tx_mac_wa, Tx_mac_wr, Tx_mac_data, Tx_mac_BE, Tx_mac_sop, Tx_mac_eop, FullDuplex, Tx_Hwmark, Tx_Lwmark);

 Random_gen(Reset, Clk, Random_init, RetryCnt, &Random_time_meet);

}

/*
void main() {

_Bool Reset;
_Bool Clk;
_Bool Clk_user;
unsigned char TxD;
_Bool TxEn;
_Bool CRS;
unsigned char Tx_pkt_type_rmon;
unsigned short int Tx_pkt_length_rmon;
_Bool Tx_apply_rmon;
unsigned char Tx_pkt_err_type_rmon;
_Bool Tx_mac_wa;
_Bool Tx_mac_wr;
unsigned int Tx_mac_data;
unsigned char Tx_mac_BE;
_Bool Tx_mac_sop;
_Bool Tx_mac_eop;
unsigned char Tx_Hwmark;
unsigned char Tx_Lwmark;
_Bool pause_frame_send_en;
unsigned short int pause_quanta_set;
_Bool MAC_tx_add_en;
_Bool FullDuplex;
unsigned char MaxRetry;
unsigned char IFGset;
unsigned char MAC_add_prom_data;
unsigned char MAC_add_prom_add;
_Bool MAC_add_prom_wr;
_Bool tx_pause_en;
_Bool xoff_cpu;
_Bool xon_cpu;
unsigned short int pause_quanta;
_Bool pause_quanta_val;

MAC_tx(Reset, Clk, Clk_user, &TxD, &TxEn, CRS, &Tx_pkt_type_rmon, &Tx_pkt_length_rmon, &Tx_apply_rmon, &Tx_pkt_err_type_rmon, &Tx_mac_wa, Tx_mac_wr, Tx_mac_data, Tx_mac_BE, Tx_mac_sop, Tx_mac_eop, Tx_Hwmark, Tx_Lwmark, pause_frame_send_en, pause_quanta_set, MAC_tx_add_en, FullDuplex, MaxRetry, IFGset, MAC_add_prom_data, MAC_add_prom_add, MAC_add_prom_wr, tx_pause_en, xoff_cpu, xon_cpu, pause_quanta, pause_quanta_val);
}*/
