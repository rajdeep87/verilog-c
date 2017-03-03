//#include <stdio.h>
#define TRUE 1
#define FALSE 0
struct state_elements_Phy_int{
unsigned char MTxD_dl1;
_Bool MTxEn_dl1;
_Bool Tx_odd_data_ptr;
_Bool Rx_odd_data_ptr;
_Bool MCrs_dv;
_Bool Rx_er_dl1;
_Bool Rx_dv_dl1;
_Bool Rx_dv_dl2;
unsigned char Rxd_dl1;
unsigned char MRxD;
unsigned char Rxd_dl2;
_Bool Crs_dl1;
_Bool Col_dl1;
_Bool Tx_en;
unsigned char Txd;
};
void Phy_int(_Bool Reset, _Bool MAC_rx_clk, _Bool MAC_tx_clk, _Bool *MCrs_dv, unsigned char *MRxD, _Bool *MRxErr, unsigned char MTxD, _Bool MTxEn, _Bool *MCRS, _Bool *Tx_er, _Bool *Tx_en, unsigned char *Txd, _Bool Rx_er, _Bool Rx_dv, unsigned char Rxd, _Bool Crs, _Bool Col, _Bool Line_loop_en, unsigned char Speed)
{
  struct state_elements_Phy_int  sPhy_int;
  unsigned char tmp39;
  unsigned char tmp38;
  unsigned char tmp37;
  unsigned char tmp36;
  _Bool tmp35;
  _Bool tmp34;
  _Bool tmp33;
  _Bool tmp32;
  _Bool tmp31;
  _Bool tmp30;
  _Bool tmp29;
  _Bool tmp28;
  _Bool tmp27;
  unsigned char tmp26;
  unsigned char tmp25;
  _Bool tmp24;
  _Bool tmp23;
  _Bool tmp22;
  _Bool tmp21;
  _Bool tmp20;
  unsigned char tmp19;
  unsigned char tmp18;
  _Bool tmp17;
  _Bool tmp16;
  _Bool tmp15;
  _Bool tmp14;
  _Bool tmp13;
  _Bool tmp12;
  unsigned char tmp11;
  unsigned char tmp10;
  unsigned char tmp9;
  unsigned char tmp8;
  unsigned char tmp7;
  _Bool tmp6;
  _Bool tmp5;
  _Bool tmp4;
  _Bool tmp3;
  unsigned char tmp2;
  _Bool tmp1;
  unsigned char tmp0;
  if(Reset)
  {
    tmp0 = 0;
    tmp1 = FALSE;
  }

  else
  {
    tmp2 = MTxD;
    tmp3 = MTxEn;
  }
  if(Reset)
    tmp4 = FALSE;

  else
    if(!((_Bool)sPhy_int.MTxD_dl1))
      tmp5 = FALSE;

    else
      tmp6 = !sPhy_int.Tx_odd_data_ptr;
  if(Reset)
    tmp7 = 0;

  else
    if((Speed >> 2 & 1) && sPhy_int.MTxEn_dl1)
      tmp8 = sPhy_int.MTxD_dl1;

    else
      if(sPhy_int.MTxEn_dl1 && !sPhy_int.Tx_odd_data_ptr)
        tmp9 = sPhy_int.MTxD_dl1 >> 0 & 15;

      else
        if(sPhy_int.MTxEn_dl1 && sPhy_int.Tx_odd_data_ptr)
          tmp10 = sPhy_int.MTxD_dl1 >> 4 & 15;

        else
          tmp11 = 0;
  if(Reset)
    tmp12 = FALSE;

  else
    if(sPhy_int.MTxEn_dl1)
      tmp13 = TRUE;

    else
      tmp14 = FALSE;
  *Tx_er = FALSE;
  *Tx_er = FALSE;
  if(Reset)
  {
    tmp15 = FALSE;
    tmp16 = FALSE;
    tmp17 = FALSE;
    tmp18 = 0;
    tmp19 = 0;
    tmp20 = FALSE;
    tmp21 = FALSE;
  }

  else
  {
    tmp22 = Rx_er;
    tmp23 = Rx_dv;
    tmp24 = sPhy_int.Rx_dv_dl1;
    tmp25 = Rxd;
    tmp26 = sPhy_int.Rxd_dl1;
    tmp27 = Crs;
    tmp28 = Col;
  }
  *MRxErr = sPhy_int.Rx_er_dl1;
  *MRxErr = sPhy_int.Rx_er_dl1;
  *MCRS = sPhy_int.Crs_dl1;
  *MCRS = sPhy_int.Crs_dl1;
  if(Reset)
    tmp29 = FALSE;

  else
    if(Line_loop_en)
      tmp30 = sPhy_int.Tx_en;

    else
      if(sPhy_int.Rx_dv_dl2)
        tmp31 = TRUE;

      else
        tmp32 = FALSE;
  if(Reset)
    tmp33 = FALSE;

  else
    if(!sPhy_int.Rx_dv_dl1)
      tmp34 = FALSE;

    else
      tmp35 = !sPhy_int.Rx_odd_data_ptr;
  if(Reset)
    tmp36 = 0;

  else
    if(Line_loop_en)
      tmp37 = sPhy_int.Txd;

    else
      if((Speed >> 2 & 1) && sPhy_int.Rx_dv_dl2)
        tmp38 = sPhy_int.Rxd_dl2;

      else
        if(sPhy_int.Rx_dv_dl1 && sPhy_int.Rx_odd_data_ptr)
          tmp39 = sPhy_int.Rxd_dl2 >> 0 & 15;

  if(Reset)
  {
    sPhy_int.MTxD_dl1 = tmp0;
    sPhy_int.MTxEn_dl1 = tmp1;
  }

  else
  {
    sPhy_int.MTxD_dl1 = tmp2;
    sPhy_int.MTxEn_dl1 = tmp3;
  }
  if(Reset)
    sPhy_int.Tx_odd_data_ptr = tmp4;

  else
    if(!((_Bool)sPhy_int.MTxD_dl1))
      sPhy_int.Tx_odd_data_ptr = tmp5;

    else
      sPhy_int.Tx_odd_data_ptr = tmp6;
  if(Reset)
  {
    sPhy_int.Txd = tmp7;
    *Txd = tmp7;
  }

  else
    if((Speed >> 2 & 1) && sPhy_int.MTxEn_dl1)
    {
      sPhy_int.Txd = tmp8;
      *Txd = tmp8;
    }

    else
      if(sPhy_int.MTxEn_dl1 && !sPhy_int.Tx_odd_data_ptr)
      {
        sPhy_int.Txd = tmp9;
        *Txd = tmp9;
      }

      else
        if(sPhy_int.MTxEn_dl1 && sPhy_int.Tx_odd_data_ptr)
        {
          sPhy_int.Txd = tmp10;
          *Txd = tmp10;
        }

        else
        {
          sPhy_int.Txd = tmp11;
          *Txd = tmp11;
        }
  if(Reset)
  {
    sPhy_int.Tx_en = tmp12;
    *Tx_en = tmp12;
  }

  else
    if(sPhy_int.MTxEn_dl1)
    {
      sPhy_int.Tx_en = tmp13;
      *Tx_en = tmp13;
    }

    else
    {
      sPhy_int.Tx_en = tmp14;
      *Tx_en = tmp14;
    }
  if(Reset)
  {
    sPhy_int.Rx_er_dl1 = tmp15;
    sPhy_int.Rx_dv_dl1 = tmp16;
    sPhy_int.Rx_dv_dl2 = tmp17;
    sPhy_int.Rxd_dl1 = tmp18;
    sPhy_int.Rxd_dl2 = tmp19;
    sPhy_int.Crs_dl1 = tmp20;
    sPhy_int.Col_dl1 = tmp21;
  }

  else
  {
    sPhy_int.Rx_er_dl1 = tmp22;
    sPhy_int.Rx_dv_dl1 = tmp23;
    sPhy_int.Rx_dv_dl2 = tmp24;
    sPhy_int.Rxd_dl1 = tmp25;
    sPhy_int.Rxd_dl2 = tmp26;
    sPhy_int.Crs_dl1 = tmp27;
    sPhy_int.Col_dl1 = tmp28;
  }
  if(Reset)
  {
    sPhy_int.MCrs_dv = tmp29;
    *MCrs_dv = tmp29;
  }

  else
    if(Line_loop_en)
    {
      sPhy_int.MCrs_dv = tmp30;
      *MCrs_dv = tmp30;
    }

    else
      if(sPhy_int.Rx_dv_dl2)
      {
        sPhy_int.MCrs_dv = tmp31;
        *MCrs_dv = tmp31;
      }

      else
      {
        sPhy_int.MCrs_dv = tmp32;
        *MCrs_dv = tmp32;
      }
  if(Reset)
    sPhy_int.Rx_odd_data_ptr = tmp33;

  else
    if(!sPhy_int.Rx_dv_dl1)
      sPhy_int.Rx_odd_data_ptr = tmp34;

    else
      sPhy_int.Rx_odd_data_ptr = tmp35;
  if(Reset)
  {
    sPhy_int.MRxD = tmp36;
    *MRxD = tmp36;
  }

  else
    if(Line_loop_en)
    {
      sPhy_int.MRxD = tmp37;
      *MRxD = tmp37;
    }

    else
      if((Speed >> 2 & 1) && sPhy_int.Rx_dv_dl2)
      {
        sPhy_int.MRxD = tmp38;
        *MRxD = tmp38;
      }

      else
        if(sPhy_int.Rx_dv_dl1 && sPhy_int.Rx_odd_data_ptr)
        {
          sPhy_int.MRxD = tmp39;
          *MRxD = tmp39;
        }

}

/*
void main() {
_Bool Reset;
_Bool MAC_rx_clk;
_Bool MAC_tx_clk;
_Bool MCrs_dv;
unsigned char MRxD;
_Bool MRxErr;
unsigned char MTxD;
_Bool MTxEn;
_Bool MCRS;
_Bool Tx_er;
_Bool Tx_en;
unsigned char Txd;
_Bool Rx_er;
_Bool Rx_dv;
unsigned char Rxd;
_Bool Crs;
_Bool Col;
_Bool Line_loop_en;
unsigned char Speed;
while(1) {
Phy_int(Reset, MAC_rx_clk, MAC_tx_clk, &MCrs_dv, &MRxD, &MRxErr, MTxD, MTxEn, &MCRS, &Tx_er, &Tx_en, &Txd, Rx_er, Rx_dv, Rxd, Crs, Col, Line_loop_en, Speed);
}
}
*/
