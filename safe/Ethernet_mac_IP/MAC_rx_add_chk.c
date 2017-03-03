//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_MAC_rx_add_chk{
_Bool MAC_add_prom_wr_dl1;
_Bool MAC_add_prom_wr_dl2;
unsigned char data_dl1;
_Bool MAC_add_en_dl1;
unsigned char addr_rd;
_Bool MAC_rx_add_chk_err;
};
void MAC_rx_add_chk(_Bool Reset, _Bool Clk, _Bool Init, unsigned char data, _Bool MAC_add_en, _Bool *MAC_rx_add_chk_err, _Bool MAC_rx_add_chk_en, unsigned char MAC_add_prom_data, unsigned char MAC_add_prom_add, _Bool MAC_add_prom_wr)
{
  struct state_elements_MAC_rx_add_chk  sMAC_rx_add_chk;
  _Bool tmp13;
  _Bool tmp12;
  _Bool tmp11;
  unsigned char tmp10;
  unsigned char tmp9;
  unsigned char tmp8;
  _Bool tmp7;
  _Bool tmp6;
  _Bool tmp5;
  _Bool tmp4;
  _Bool tmp3;
  unsigned char tmp2;
  _Bool tmp1;
  unsigned char tmp0;
  unsigned char addr_wr;
  unsigned char din;
  unsigned char dout;
  _Bool wr_en;
  if(Reset)
  {
    tmp0 = 0;
    tmp1 = FALSE;
  }

  else
  {
    tmp2 = data;
    tmp3 = MAC_add_en;
  }
  if(Reset)
  {
    tmp4 = FALSE;
    tmp5 = FALSE;
  }

  else
  {
    tmp6 = MAC_add_prom_wr;
    tmp7 = sMAC_rx_add_chk.MAC_add_prom_wr_dl1;
  }
  wr_en = sMAC_rx_add_chk.MAC_add_prom_wr_dl1 && !sMAC_rx_add_chk.MAC_add_prom_wr_dl2;
  addr_wr = MAC_add_prom_add;
  din = MAC_add_prom_data;
  if(Reset)
    tmp8 = 0;

  else
    if(Init)
      tmp9 = 0;

    else
      if(MAC_add_en)
        tmp10 = (unsigned char)(unsigned int)sMAC_rx_add_chk.addr_rd + 1;

  if(Reset)
    tmp11 = FALSE;

  else
    if(Init)
      tmp12 = FALSE;

    else
      if(MAC_rx_add_chk_en && sMAC_rx_add_chk.MAC_add_en_dl1 && dout != sMAC_rx_add_chk.data_dl1)
        tmp13 = TRUE;

  if(Reset)
  {
    sMAC_rx_add_chk.data_dl1 = tmp0;
    sMAC_rx_add_chk.MAC_add_en_dl1 = tmp1;
  }

  else
  {
    sMAC_rx_add_chk.data_dl1 = tmp2;
    sMAC_rx_add_chk.MAC_add_en_dl1 = tmp3;
  }
  if(Reset)
  {
    sMAC_rx_add_chk.MAC_add_prom_wr_dl1 = tmp4;
    sMAC_rx_add_chk.MAC_add_prom_wr_dl2 = tmp5;
  }

  else
  {
    sMAC_rx_add_chk.MAC_add_prom_wr_dl1 = tmp6;
    sMAC_rx_add_chk.MAC_add_prom_wr_dl2 = tmp7;
  }
  if(Reset)
    sMAC_rx_add_chk.addr_rd = tmp8;

  else
    if(Init)
      sMAC_rx_add_chk.addr_rd = tmp9;

    else
      if(MAC_add_en)
        sMAC_rx_add_chk.addr_rd = tmp10;

  if(Reset)
  {
    sMAC_rx_add_chk.MAC_rx_add_chk_err = tmp11;
    *MAC_rx_add_chk_err = tmp11;
  }

  else
    if(Init)
    {
      sMAC_rx_add_chk.MAC_rx_add_chk_err = tmp12;
      *MAC_rx_add_chk_err = tmp12;
    }

    else
      if(MAC_rx_add_chk_en && sMAC_rx_add_chk.MAC_add_en_dl1 && dout != sMAC_rx_add_chk.data_dl1)
      {
        sMAC_rx_add_chk.MAC_rx_add_chk_err = tmp13;
        *MAC_rx_add_chk_err = tmp13;
      }

}

/*
void main() {
_Bool Reset;
_Bool Clk;
_Bool Init;
unsigned char data;
_Bool MAC_add_en;
_Bool MAC_rx_add_chk_err;
_Bool MAC_rx_add_chk_en;
unsigned char MAC_add_prom_data;
unsigned char MAC_add_prom_add;
_Bool MAC_add_prom_wr;
while(1) {
MAC_rx_add_chk(Reset, Clk, Init, data, MAC_add_en, &MAC_rx_add_chk_err, MAC_rx_add_chk_en, MAC_add_prom_data, MAC_add_prom_add, MAC_add_prom_wr);
}
}*/
