//#include <stdio.h>

#include "RMON_addr_gen.c"
#include "RMON_dpram.c"
#include "RMON_ctrl.c"

#define TRUE 1
#define FALSE 0
void RMON(_Bool Clk, _Bool Reset, unsigned char Tx_pkt_type_rmon, unsigned short int Tx_pkt_length_rmon, _Bool Tx_apply_rmon, unsigned char Tx_pkt_err_type_rmon, unsigned char Rx_pkt_type_rmon, unsigned short int Rx_pkt_length_rmon, _Bool Rx_apply_rmon, unsigned char Rx_pkt_err_type_rmon, unsigned char CPU_rd_addr, _Bool CPU_rd_apply, _Bool *CPU_rd_grant, unsigned int *CPU_rd_dout)
{
  _Bool Reg_apply_0;
  unsigned char Reg_addr_0;
  unsigned short int Reg_data_0;
  _Bool Reg_next_0;
  _Bool Reg_apply_1;
  unsigned char Reg_addr_1;
  unsigned short int Reg_data_1;
  _Bool Reg_next_1;
  unsigned char Addra;
  unsigned int Dina;
  unsigned int Douta;
  _Bool Wea;
  _Bool RxAddrb;
  _Bool TxAddrb;
  _Bool Reg_drop_apply;
  
  RMON_addr_gen(Clk, Reset, Rx_pkt_type_rmon, Rx_pkt_length_rmon, Rx_apply_rmon, Rx_pkt_err_type_rmon, &Reg_apply_0, &Reg_addr_0, &Reg_data_0, Reg_next_0, &Reg_drop_apply);


  RMON_addr_gen(Clk, Reset, Tx_pkt_type_rmon, Tx_pkt_length_rmon, Tx_apply_rmon, Tx_pkt_err_type_rmon, &Reg_apply_1, &Reg_addr_1, &Reg_data_1, Reg_next_1, &Reg_drop_apply);

  RMON_CTRL(Clk, Reset, Reg_apply_0, Reg_addr_0, Reg_data_0, &Reg_next_0, Reg_apply_1, Reg_addr_1, Reg_data_1, &Reg_next_1, &Addra, &Dina, Douta, &Wea, CPU_rd_addr, CPU_rd_apply, &CPU_rd_grant, &CPU_rd_dout);

  RMON_dpram(Reset, Clk, Addra, Dina, &Douta, Wea, Addra, &Douta);

  RxAddrb = FALSE;
  TxAddrb = FALSE;
}

/*
void main() {
_Bool Clk;
_Bool Reset;
unsigned char Tx_pkt_type_rmon;
unsigned short int Tx_pkt_length_rmon;
_Bool Tx_apply_rmon;
unsigned char Tx_pkt_err_type_rmon;
unsigned char Rx_pkt_type_rmon;
unsigned short int Rx_pkt_length_rmon;
_Bool Rx_apply_rmon;
unsigned char Rx_pkt_err_type_rmon;
unsigned char CPU_rd_addr;
_Bool CPU_rd_apply;
_Bool CPU_rd_grant;
unsigned int CPU_rd_dout;

RMON(Clk, Reset, Tx_pkt_type_rmon, Tx_pkt_length_rmon, Tx_apply_rmon, Tx_pkt_err_type_rmon, Rx_pkt_type_rmon, Rx_pkt_length_rmon, Rx_apply_rmon, Rx_pkt_err_type_rmon, CPU_rd_addr, CPU_rd_apply, &CPU_rd_grant, &CPU_rd_dout);

}*/
