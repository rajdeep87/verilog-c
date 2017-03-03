//#include <stdio.h>
#define TRUE 1
#define FALSE 0
struct state_elements_MAC_tx_addr_add{
unsigned char add_rd;
_Bool MAC_add_prom_wr_dl1;
_Bool MAC_add_prom_wr_dl2;
};
void MAC_tx_addr_add(_Bool Reset, _Bool Clk, _Bool MAC_tx_addr_rd, _Bool MAC_tx_addr_init, unsigned char *MAC_tx_addr_data, unsigned char MAC_add_prom_data, unsigned char MAC_add_prom_add, _Bool MAC_add_prom_wr)
{
  struct state_elements_MAC_tx_addr_add  sMAC_tx_addr_add;
  unsigned char tmp6;
  unsigned char tmp5;
  unsigned char tmp4;
  _Bool tmp3;
  _Bool tmp2;
  _Bool tmp1;
  _Bool tmp0;
  unsigned char add_wr;
  unsigned char din;
  unsigned char dout;
  _Bool wr_en;
  if(Reset)
  {
    tmp0 = FALSE;
    tmp1 = FALSE;
  }

  else
  {
    tmp2 = MAC_add_prom_wr;
    tmp3 = sMAC_tx_addr_add.MAC_add_prom_wr_dl1;
  }
  wr_en = sMAC_tx_addr_add.MAC_add_prom_wr_dl1 && !sMAC_tx_addr_add.MAC_add_prom_wr_dl2;
  add_wr = MAC_add_prom_add;
  din = MAC_add_prom_data;
  if(Reset)
    tmp4 = 0;

  else
    if(MAC_tx_addr_init)
      tmp5 = 0;

    else
      if(MAC_tx_addr_rd)
        tmp6 = (unsigned char)(unsigned int)sMAC_tx_addr_add.add_rd + 1;

  *MAC_tx_addr_data = dout;
  *MAC_tx_addr_data = dout;
  if(Reset)
  {
    sMAC_tx_addr_add.MAC_add_prom_wr_dl1 = tmp0;
    sMAC_tx_addr_add.MAC_add_prom_wr_dl2 = tmp1;
  }

  else
  {
    sMAC_tx_addr_add.MAC_add_prom_wr_dl1 = tmp2;
    sMAC_tx_addr_add.MAC_add_prom_wr_dl2 = tmp3;
  }
  if(Reset)
    sMAC_tx_addr_add.add_rd = tmp4;

  else
    if(MAC_tx_addr_init)
      sMAC_tx_addr_add.add_rd = tmp5;

    else
      if(MAC_tx_addr_rd)
        sMAC_tx_addr_add.add_rd = tmp6;

}
/*
void main() {
_Bool Reset;
_Bool Clk;
_Bool MAC_tx_addr_rd;
_Bool MAC_tx_addr_init;
unsigned char MAC_tx_addr_data;
unsigned char MAC_add_prom_data;
unsigned char MAC_add_prom_add;
_Bool MAC_add_prom_wr;
while(1) {
MAC_tx_addr_add(Reset, Clk, MAC_tx_addr_rd, MAC_tx_addr_init, &MAC_tx_addr_data, MAC_add_prom_data, MAC_add_prom_add, MAC_add_prom_wr);
}
}*/
