//#include <stdio.h>

#include "CRC_chk.c"
#include "MAC_rx_add_chk.c"
#include "MAC_rx_ctrl.c"
#include "MAC_rx_FF.c"
#include "Broadcast_filter.c"

#define TRUE 1
#define FALSE 0

void MAC_rx(_Bool Reset, _Bool Clk_user, _Bool Clk, _Bool MCrs_dv, unsigned char MRxD, _Bool MRxErr, unsigned short int *pause_quanta, _Bool *pause_quanta_val, _Bool *Rx_mac_ra, _Bool Rx_mac_rd, unsigned int *Rx_mac_data, unsigned char *Rx_mac_BE, _Bool *Rx_mac_pa, _Bool *Rx_mac_sop, _Bool *Rx_mac_eop, _Bool MAC_rx_add_chk_en, unsigned char MAC_add_prom_data, unsigned char MAC_add_prom_add, _Bool MAC_add_prom_wr, _Bool broadcast_filter_en, unsigned short int broadcast_bucket_depth, unsigned short int broadcast_bucket_interval, _Bool RX_APPEND_CRC, unsigned char Rx_Hwmark, unsigned char Rx_Lwmark, _Bool CRC_chk_en, unsigned char RX_IFG_SET, unsigned short int RX_MAX_LENGTH, unsigned char RX_MIN_LENGTH, unsigned short int *Rx_pkt_length_rmon, _Bool *Rx_apply_rmon, unsigned char *Rx_pkt_err_type_rmon, unsigned char *Rx_pkt_type_rmon)
{
  _Bool CRC_en;
  _Bool CRC_init;
  _Bool CRC_err;
  _Bool MAC_add_en;
  _Bool MAC_rx_add_chk_err;
  _Bool broadcast_ptr;
  _Bool broadcast_drop;
  unsigned char Fifo_data;
  _Bool Fifo_data_en;
  _Bool Fifo_full;
  _Bool Fifo_data_err;
  _Bool Fifo_data_end;

  MAC_rx_ctrl(Reset, Clk, MCrs_dv, MRxD, MRxErr, &CRC_en, &CRC_init, CRC_err, &MAC_add_en, MAC_rx_add_chk_err, &broadcast_ptr, broadcast_drop, &pause_quanta, &pause_quanta_val, &Fifo_data, &Fifo_data_en, &Fifo_data_err, &Fifo_data_end, Fifo_full, &Rx_pkt_length_rmon, &Rx_apply_rmon, &Rx_pkt_err_type_rmon, &Rx_pkt_type_rmon, RX_IFG_SET, RX_MAX_LENGTH, RX_MIN_LENGTH);

 MAC_rx_FF(Reset, Clk, Clk_user, Fifo_data, Fifo_data_en, &Fifo_full, Fifo_data_err, Fifo_data_end, RX_APPEND_CRC, Rx_Hwmark, Rx_Lwmark, &Rx_mac_ra, Rx_mac_rd, &Rx_mac_data, &Rx_mac_BE, &Rx_mac_pa, &Rx_mac_sop, &Rx_mac_eop);

 Broadcast_filter(Reset, Clk, broadcast_ptr, &broadcast_drop, broadcast_filter_en, broadcast_bucket_depth, broadcast_bucket_interval);

 CRC_chk(Reset, Clk, Fifo_data, CRC_init, CRC_en, CRC_chk_en, &CRC_err);

 MAC_rx_add_chk(Reset, Clk, CRC_init, Fifo_data, MAC_add_en, &MAC_rx_add_chk_err, MAC_rx_add_chk_en, MAC_add_prom_data, MAC_add_prom_add, MAC_add_prom_wr);

}


/*
void main() {

_Bool Reset;
_Bool Clk_user;
_Bool Clk;
_Bool MCrs_dv;
unsigned char MRxD;
_Bool MRxErr;
unsigned short int pause_quanta;
_Bool pause_quanta_val;
_Bool Rx_mac_ra;
_Bool Rx_mac_rd;
unsigned int Rx_mac_data;
unsigned char Rx_mac_BE;
_Bool Rx_mac_pa;
_Bool Rx_mac_sop;
_Bool Rx_mac_eop;
_Bool MAC_rx_add_chk_en;
unsigned char MAC_add_prom_data;
unsigned char MAC_add_prom_add;
_Bool MAC_add_prom_wr;
_Bool broadcast_filter_en;
unsigned short int broadcast_bucket_depth;
unsigned short int broadcast_bucket_interval;
_Bool RX_APPEND_CRC;
unsigned char Rx_Hwmark;
unsigned char Rx_Lwmark;
_Bool CRC_chk_en;
unsigned char RX_IFG_SET;
unsigned short int RX_MAX_LENGTH;
unsigned char RX_MIN_LENGTH;
unsigned short int Rx_pkt_length_rmon;
_Bool Rx_apply_rmon;
unsigned char Rx_pkt_err_type_rmon;
unsigned char Rx_pkt_type_rmon;

MAC_rx(Reset, Clk_user, Clk, MCrs_dv, MRxD, MRxErr, &pause_quanta, &pause_quanta_val, &Rx_mac_ra, Rx_mac_rd, &Rx_mac_data, &Rx_mac_BE, &Rx_mac_pa, &Rx_mac_sop, &Rx_mac_eop, MAC_rx_add_chk_en, MAC_add_prom_data, MAC_add_prom_add, MAC_add_prom_wr, broadcast_filter_en, broadcast_bucket_depth, broadcast_bucket_interval, RX_APPEND_CRC, Rx_Hwmark, Rx_Lwmark, CRC_chk_en, RX_IFG_SET, RX_MAX_LENGTH, RX_MIN_LENGTH, &Rx_pkt_length_rmon, &Rx_apply_rmon, &Rx_pkt_err_type_rmon, &Rx_pkt_type_rmon);

}*/
