//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_MAC_tx_FF{
unsigned short int Add_rd_reg_dl1;
_Bool Full;
_Bool AlmostFull;
_Bool Empty;
_Bool Tx_mac_wr_dl1;
unsigned int Tx_mac_data_dl1;
unsigned char Tx_mac_BE_dl1;
_Bool Tx_mac_sop_dl1;
_Bool Tx_mac_eop_dl1;
_Bool FF_FullErr;
unsigned long int Dout_reg;
_Bool Packet_number_sub_dl1;
unsigned char Fifo_data;
_Bool Packet_number_sub_dl2;
_Bool Packet_number_sub_edge;
_Bool Packet_number_add;
unsigned char Fifo_data_count;
_Bool Fifo_eop;
_Bool Fifo_rd_dl1;
_Bool Fifo_da;
_Bool Fifo_ra_tmp;
_Bool Fifo_ra;
_Bool Fifo_data_err_empty;
unsigned char Packet_number_inFF;
_Bool Tx_mac_wa;
unsigned char Packet_number_inFF_reg;
_Bool Pkt_sub_apply_tmp;
_Bool Pkt_sub_apply;
_Bool Add_rd_reg_rdy_tmp;
_Bool Add_rd_reg_rdy;
_Bool Add_rd_reg_rdy_dl1;
_Bool Add_rd_reg_rdy_dl2;
unsigned char Tx_Hwmark_pl;
unsigned char Tx_Lwmark_pl;
_Bool Add_rd_jump_tmp;
_Bool Add_rd_jump_tmp_pl1;
_Bool Add_rd_jump;
_Bool Add_rd_jump_wr_pl1;
_Bool Tx_mac_eop_gen;
unsigned long int Dout_dl1;
_Bool Dout_reg_en;
_Bool Add_rd_add;
unsigned char Current_state_MAC;
unsigned char Current_state_MAC_reg;
unsigned char Next_state_MAC;
unsigned char Current_state_SYS;
unsigned char Next_state_SYS;
unsigned short int Add_wr;
unsigned short int Add_wr_ungray;
unsigned short int Add_wr_gray;
unsigned short int Add_wr_gray_dl1;
unsigned short int Add_rd;
unsigned short int Add_rd_reg;
unsigned short int Add_rd_gray;
unsigned short int Add_rd_gray_dl1;
unsigned short int Add_rd_ungray;
_Bool Wr_en;
};
void MAC_tx_FF(_Bool Reset, _Bool Clk_MAC, _Bool Clk_SYS, unsigned char *Fifo_data, _Bool Fifo_rd, _Bool Fifo_rd_finish, _Bool Fifo_rd_retry, _Bool *Fifo_eop, _Bool *Fifo_da, _Bool *Fifo_ra, _Bool *Fifo_data_err_empty, _Bool *Fifo_data_err_full, _Bool *Tx_mac_wa, _Bool Tx_mac_wr, unsigned int Tx_mac_data, unsigned char Tx_mac_BE, _Bool Tx_mac_sop, _Bool Tx_mac_eop, _Bool FullDuplex, unsigned char Tx_Hwmark, unsigned char Tx_Lwmark)
{
  struct state_elements_MAC_tx_FF  sMAC_tx_FF;
  _Bool tmp108;
  _Bool tmp107;
  _Bool tmp106;
  unsigned char tmp105;
  unsigned char tmp104;
  _Bool tmp103;
  _Bool tmp102;
  _Bool tmp101;
  _Bool tmp100;
  _Bool tmp99;
  _Bool tmp98;
  _Bool tmp97;
  _Bool tmp96;
  _Bool tmp95;
  _Bool tmp94;
  _Bool tmp93;
  _Bool tmp92;
  _Bool tmp91;
  unsigned short int tmp90;
  unsigned short int tmp89;
  unsigned short int tmp88;
  _Bool tmp87;
  _Bool tmp86;
  _Bool tmp85;
  _Bool tmp84;
  _Bool tmp83;
  _Bool tmp82;
  unsigned short int tmp81;
  unsigned short int tmp80;
  _Bool tmp79;
  _Bool tmp78;
  _Bool tmp77;
  _Bool tmp76;
  _Bool tmp75;
  _Bool tmp74;
  _Bool tmp73;
  _Bool tmp72;
  _Bool tmp71;
  _Bool tmp70;
  _Bool tmp69;
  unsigned short int tmp68;
  unsigned short int tmp67;
  _Bool tmp66;
  _Bool tmp65;
  unsigned short int tmp64;
  unsigned char tmp63;
  unsigned char tmp62;
  unsigned long int tmp61;
  unsigned long int tmp60;
  unsigned long int tmp59;
  unsigned long int tmp58;
  _Bool tmp57;
  _Bool tmp56;
  _Bool tmp55;
  unsigned char tmp54;
  unsigned char tmp53;
  unsigned char tmp52;
  unsigned char tmp51;
  _Bool tmp50;
  _Bool tmp49;
  _Bool tmp48;
  unsigned char tmp47;
  unsigned char tmp46;
  unsigned char tmp45;
  unsigned short int tmp44;
  unsigned short int tmp43;
  _Bool tmp42;
  _Bool tmp41;
  _Bool tmp40;
  _Bool tmp39;
  unsigned char tmp38;
  unsigned char tmp37;
  unsigned char tmp36;
  unsigned char tmp35;
  unsigned char tmp34;
  _Bool tmp33;
  _Bool tmp32;
  _Bool tmp31;
  _Bool tmp30;
  _Bool tmp29;
  _Bool tmp28;
  _Bool tmp27;
  _Bool tmp26;
  _Bool tmp25;
  _Bool tmp24;
  unsigned short int tmp23;
  unsigned short int tmp22;
  _Bool tmp21;
  _Bool tmp20;
  _Bool tmp19;
  _Bool tmp18;
  _Bool tmp17;
  unsigned short int tmp16;
  unsigned short int tmp15;
  _Bool tmp14;
  _Bool tmp13;
  unsigned short int tmp12;
  _Bool tmp11;
  _Bool tmp10;
  unsigned char tmp9;
  unsigned int tmp8;
  _Bool tmp7;
  _Bool tmp6;
  _Bool tmp5;
  unsigned char tmp4;
  unsigned int tmp3;
  _Bool tmp2;
  unsigned char tmp1;
  unsigned char tmp0;
  int i;

  int MAC_byte3;
  MAC_byte3 = 0;
  int MAC_byte2;
  MAC_byte2 = 1;
  int MAC_byte1;
  MAC_byte1 = 2;
  int MAC_byte0;
  MAC_byte0 = 3;
  int MAC_wait_finish;
  MAC_wait_finish = 4;
  int MAC_retry;
  MAC_retry = 8;
  int MAC_idle;
  MAC_idle = 9;
  int MAC_FFEmpty;
  MAC_FFEmpty = 10;
  int MAC_FFEmpty_drop;
  MAC_FFEmpty_drop = 11;
  int MAC_pkt_sub;
  MAC_pkt_sub = 12;
  int MAC_FF_Err;
  MAC_FF_Err = 13;
  int SYS_idle;
  SYS_idle = 0;
  int SYS_WaitSop;
  SYS_WaitSop = 1;
  int SYS_SOP;
  SYS_SOP = 2;
  int SYS_MOP;
  SYS_MOP = 3;
  int SYS_DROP;
  SYS_DROP = 4;
  int SYS_EOP_ok;
  SYS_EOP_ok = 5;
  int SYS_FFEmpty;
  SYS_FFEmpty = 6;
  int SYS_EOP_err;
  SYS_EOP_err = 7;
  int SYS_SOP_err;
  SYS_SOP_err = 8;
  unsigned short int Add_wr_gray_tmp;
  unsigned short int Add_rd_gray_tmp;
  unsigned long int Din;
  unsigned long int Dout;
  unsigned short int Add_wr_pluse;
  unsigned short int Add_wr_pluse_pluse;
  unsigned short int Add_rd_pluse;
  unsigned char Dout_BE;
  _Bool Dout_eop;
  _Bool Dout_err;
  unsigned int Dout_data;
  if(Reset)
    tmp0 = SYS_idle;

  else
    tmp1 = sMAC_tx_FF.Next_state_SYS;
  if(sMAC_tx_FF.Current_state_SYS == SYS_idle)
    if(Tx_mac_wr && Tx_mac_sop && !sMAC_tx_FF.Full)
      sMAC_tx_FF.Next_state_SYS = SYS_SOP;

    else
      sMAC_tx_FF.Next_state_SYS = sMAC_tx_FF.Current_state_SYS;

  else
    if(sMAC_tx_FF.Current_state_SYS == SYS_SOP)
      sMAC_tx_FF.Next_state_SYS = SYS_MOP;

    else
      if(sMAC_tx_FF.Current_state_SYS == SYS_MOP)
        if(sMAC_tx_FF.AlmostFull)
          sMAC_tx_FF.Next_state_SYS = SYS_DROP;

        else
          if(Tx_mac_wr && Tx_mac_sop)
            sMAC_tx_FF.Next_state_SYS = SYS_SOP_err;

          else
            if(Tx_mac_wr && Tx_mac_eop)
              sMAC_tx_FF.Next_state_SYS = SYS_EOP_ok;

            else
              sMAC_tx_FF.Next_state_SYS = sMAC_tx_FF.Current_state_SYS;

      else
        if(sMAC_tx_FF.Current_state_SYS == SYS_EOP_ok)
          if(Tx_mac_wr && Tx_mac_sop)
            sMAC_tx_FF.Next_state_SYS = SYS_SOP;

          else
            sMAC_tx_FF.Next_state_SYS = SYS_idle;

        else
          if(sMAC_tx_FF.Current_state_SYS == SYS_EOP_err)
            if(Tx_mac_wr && Tx_mac_sop)
              sMAC_tx_FF.Next_state_SYS = SYS_SOP;

            else
              sMAC_tx_FF.Next_state_SYS = SYS_idle;

          else
            if(sMAC_tx_FF.Current_state_SYS == SYS_SOP_err)
              sMAC_tx_FF.Next_state_SYS = SYS_DROP;

            else
              if(sMAC_tx_FF.Current_state_SYS == SYS_DROP)
                if(Tx_mac_wr && Tx_mac_eop)
                  sMAC_tx_FF.Next_state_SYS = SYS_EOP_err;

                else
                  sMAC_tx_FF.Next_state_SYS = sMAC_tx_FF.Current_state_SYS;

              else
                if(TRUE)
                  sMAC_tx_FF.Next_state_SYS = SYS_idle;

  if(Reset)
  {
    tmp2 = FALSE;
    tmp3 = 0;
    tmp4 = 0;
    tmp5 = FALSE;
    tmp6 = FALSE;
  }

  else
  {
    tmp7 = Tx_mac_wr;
    tmp8 = Tx_mac_data;
    tmp9 = Tx_mac_BE;
    tmp10 = Tx_mac_sop;
    tmp11 = Tx_mac_eop;
  }
  if(sMAC_tx_FF.Current_state_SYS == SYS_EOP_err)
    sMAC_tx_FF.FF_FullErr = TRUE;

  else
    sMAC_tx_FF.FF_FullErr = FALSE;
  if(sMAC_tx_FF.Current_state_SYS == SYS_EOP_err || sMAC_tx_FF.Current_state_SYS == SYS_EOP_ok)
    sMAC_tx_FF.Tx_mac_eop_gen = TRUE;

  else
    sMAC_tx_FF.Tx_mac_eop_gen = FALSE;
  Din = sMAC_tx_FF.Tx_mac_eop_gen << 35 | sMAC_tx_FF.FF_FullErr << 34 | sMAC_tx_FF.Tx_mac_BE_dl1 << 32 | sMAC_tx_FF.Tx_mac_data_dl1;
  if((sMAC_tx_FF.Current_state_SYS == SYS_SOP || sMAC_tx_FF.Current_state_SYS == SYS_EOP_ok || sMAC_tx_FF.Current_state_SYS == SYS_MOP || sMAC_tx_FF.Current_state_SYS == SYS_EOP_err) && sMAC_tx_FF.Tx_mac_wr_dl1)
    sMAC_tx_FF.Wr_en = TRUE;

  else
    sMAC_tx_FF.Wr_en = FALSE;
  if(Reset)
    tmp12 = 0;

  else
  {
    tmp13 = sMAC_tx_FF.Add_wr >> 8 & 1;
    for(i = 0; i <= 7; i = i + 1)
      tmp14 = sMAC_tx_FF.Add_wr >> (i + 1) ^ sMAC_tx_FF.Add_wr >> i;
  }
  if(Reset)
    tmp15 = 0;

  else
    tmp16 = sMAC_tx_FF.Add_rd_gray;
  if(Reset)
    tmp17 = FALSE;

  else
    tmp18 = sMAC_tx_FF.Add_rd_jump;
  if(Reset)
    sMAC_tx_FF.Add_rd_ungray = 0;

  else
    if(!sMAC_tx_FF.Add_rd_jump_wr_pl1)
    {
      sMAC_tx_FF.Add_rd_ungray = sMAC_tx_FF.Add_rd_ungray | (sMAC_tx_FF.Add_rd_gray_dl1 >> 8 & 1) << 8;
      for(i = 0; i <= 7; i = i + 1)
        sMAC_tx_FF.Add_rd_ungray = sMAC_tx_FF.Add_rd_ungray >> i + 1 & 1 && sMAC_tx_FF.Add_rd_gray_dl1 >> i & 1;
    }

  Add_wr_pluse = (unsigned short int)(unsigned int)sMAC_tx_FF.Add_wr + 1;
  Add_wr_pluse_pluse = (unsigned short int)(unsigned int)sMAC_tx_FF.Add_wr + 4;
  if(Add_wr_pluse == sMAC_tx_FF.Add_rd_ungray)
    sMAC_tx_FF.Full = TRUE;

  else
    sMAC_tx_FF.Full = FALSE;
  if(Reset)
    tmp19 = FALSE;

  else
    if(Add_wr_pluse_pluse == sMAC_tx_FF.Add_rd_ungray)
      tmp20 = TRUE;

    else
      tmp21 = FALSE;
  if(Reset)
    tmp22 = 0;

  else
    if(sMAC_tx_FF.Wr_en && !sMAC_tx_FF.Full)
      tmp23 = (unsigned short int)(unsigned int)sMAC_tx_FF.Add_wr + 1;

  if(Reset)
  {
    tmp24 = FALSE;
    tmp25 = FALSE;
  }

  else
  {
    tmp26 = sMAC_tx_FF.Pkt_sub_apply;
    tmp27 = sMAC_tx_FF.Packet_number_sub_dl1;
  }
  if(Reset)
    tmp28 = FALSE;

  else
    if(sMAC_tx_FF.Packet_number_sub_dl1 && !sMAC_tx_FF.Packet_number_sub_dl2)
      tmp29 = TRUE;

    else
      tmp30 = FALSE;
  if(Reset)
    tmp31 = FALSE;

  else
    if(sMAC_tx_FF.Current_state_SYS == SYS_EOP_ok || sMAC_tx_FF.Current_state_SYS == SYS_EOP_err)
      tmp32 = TRUE;

    else
      tmp33 = FALSE;
  if(Reset)
    tmp34 = 0;

  else
    if(sMAC_tx_FF.Packet_number_add && !sMAC_tx_FF.Packet_number_sub_edge)
      tmp35 = sMAC_tx_FF.Packet_number_inFF + 1;

    else
      if(!sMAC_tx_FF.Packet_number_add && sMAC_tx_FF.Packet_number_sub_edge)
        tmp36 = sMAC_tx_FF.Packet_number_inFF - 1;

  if(Reset)
    tmp37 = 0;

  else
    tmp38 = sMAC_tx_FF.Packet_number_inFF;
  if(Reset)
  {
    tmp39 = FALSE;
    tmp40 = FALSE;
  }

  else
  {
    tmp41 = sMAC_tx_FF.Add_rd_reg_rdy;
    tmp42 = sMAC_tx_FF.Add_rd_reg_rdy_dl1;
  }
  if(Reset)
    tmp43 = 0;

  else
    if(sMAC_tx_FF.Add_rd_reg_rdy_dl1 && !sMAC_tx_FF.Add_rd_reg_rdy_dl2)
      tmp44 = sMAC_tx_FF.Add_rd_reg;

  if(Reset)
    tmp45 = 0;

  else
    if(FullDuplex)
      tmp46 = (sMAC_tx_FF.Add_wr >> 4 & 0x1F) - (sMAC_tx_FF.Add_rd_ungray >> 4 & 0x1F);

    else
      tmp47 = (sMAC_tx_FF.Add_wr >> 4 & 1) - (sMAC_tx_FF.Add_rd_reg_dl1 >> 4 & 1);
  if(Reset)
    tmp48 = FALSE;

  else
    if((unsigned int)sMAC_tx_FF.Packet_number_inFF_reg >= 1 || sMAC_tx_FF.Fifo_data_count >= Tx_Lwmark)
      tmp49 = TRUE;

    else
      tmp50 = FALSE;
  if(Reset)
  {
    tmp51 = 0;
    tmp52 = 0;
  }

  else
  {
    tmp53 = Tx_Hwmark;
    tmp54 = Tx_Lwmark;
  }
  if(Reset)
    tmp55 = FALSE;

  else
    if(sMAC_tx_FF.Fifo_data_count >= sMAC_tx_FF.Tx_Hwmark_pl)
      tmp56 = FALSE;

    else
      if(sMAC_tx_FF.Fifo_data_count < sMAC_tx_FF.Tx_Lwmark_pl)
        tmp57 = TRUE;

  if(Reset)
    tmp58 = 0;

  else
    tmp59 = Dout;
  if((sMAC_tx_FF.Current_state_MAC == MAC_idle || sMAC_tx_FF.Current_state_MAC == MAC_byte0) && sMAC_tx_FF.Next_state_MAC == MAC_byte3)
    sMAC_tx_FF.Dout_reg_en = TRUE;

  else
    sMAC_tx_FF.Dout_reg_en = FALSE;
  if(Reset)
    tmp60 = 0;

  else
    if(sMAC_tx_FF.Dout_reg_en)
      tmp61 = sMAC_tx_FF.Dout_dl1;

  Dout_eop = sMAC_tx_FF.Dout_reg & 0x800000000;
  Dout_err = sMAC_tx_FF.Dout_reg & 0x400000000;
  Dout_BE = sMAC_tx_FF.Dout_reg & 0x300000000;
  Dout_data = sMAC_tx_FF.Dout_reg & 0x0FFFFFFFF;
  if(Reset)
    tmp62 = MAC_idle;

  else
    tmp63 = sMAC_tx_FF.Next_state_MAC;
  if(sMAC_tx_FF.Current_state_MAC == MAC_idle)
    if(sMAC_tx_FF.Empty && Fifo_rd)
      sMAC_tx_FF.Next_state_MAC = MAC_FF_Err;

    else
      if(Fifo_rd)
        sMAC_tx_FF.Next_state_MAC = MAC_byte3;

      else
        sMAC_tx_FF.Next_state_MAC = sMAC_tx_FF.Current_state_MAC;

  else
    if(sMAC_tx_FF.Current_state_MAC == MAC_byte3)
      if(Fifo_rd_retry)
        sMAC_tx_FF.Next_state_MAC = MAC_retry;

      else
        if(sMAC_tx_FF.Fifo_eop)
          sMAC_tx_FF.Next_state_MAC = MAC_wait_finish;

        else
          if(Fifo_rd && !sMAC_tx_FF.Fifo_eop)
            sMAC_tx_FF.Next_state_MAC = MAC_byte2;

          else
            sMAC_tx_FF.Next_state_MAC = sMAC_tx_FF.Current_state_MAC;

    else
      if(sMAC_tx_FF.Current_state_MAC == MAC_byte2)
        if(Fifo_rd_retry)
          sMAC_tx_FF.Next_state_MAC = MAC_retry;

        else
          if(sMAC_tx_FF.Fifo_eop)
            sMAC_tx_FF.Next_state_MAC = MAC_wait_finish;

          else
            if(Fifo_rd && !sMAC_tx_FF.Fifo_eop)
              sMAC_tx_FF.Next_state_MAC = MAC_byte1;

            else
              sMAC_tx_FF.Next_state_MAC = sMAC_tx_FF.Current_state_MAC;

      else
        if(sMAC_tx_FF.Current_state_MAC == MAC_byte1)
          if(Fifo_rd_retry)
            sMAC_tx_FF.Next_state_MAC = MAC_retry;

          else
            if(sMAC_tx_FF.Fifo_eop)
              sMAC_tx_FF.Next_state_MAC = MAC_wait_finish;

            else
              if(Fifo_rd && !sMAC_tx_FF.Fifo_eop)
                sMAC_tx_FF.Next_state_MAC = MAC_byte0;

              else
                sMAC_tx_FF.Next_state_MAC = sMAC_tx_FF.Current_state_MAC;

        else
          if(sMAC_tx_FF.Current_state_MAC == MAC_byte0)
            if(sMAC_tx_FF.Empty && Fifo_rd && !sMAC_tx_FF.Fifo_eop)
              sMAC_tx_FF.Next_state_MAC = MAC_FFEmpty;

            else
              if(Fifo_rd_retry)
                sMAC_tx_FF.Next_state_MAC = MAC_retry;

              else
                if(sMAC_tx_FF.Fifo_eop)
                  sMAC_tx_FF.Next_state_MAC = MAC_wait_finish;

                else
                  if(Fifo_rd && !sMAC_tx_FF.Fifo_eop)
                    sMAC_tx_FF.Next_state_MAC = MAC_byte3;

                  else
                    sMAC_tx_FF.Next_state_MAC = sMAC_tx_FF.Current_state_MAC;

          else
            if(sMAC_tx_FF.Current_state_MAC == MAC_retry)
              sMAC_tx_FF.Next_state_MAC = MAC_idle;

            else
              if(sMAC_tx_FF.Current_state_MAC == MAC_wait_finish)
                if(Fifo_rd_finish)
                  sMAC_tx_FF.Next_state_MAC = MAC_pkt_sub;

                else
                  sMAC_tx_FF.Next_state_MAC = sMAC_tx_FF.Current_state_MAC;

              else
                if(sMAC_tx_FF.Current_state_MAC == MAC_pkt_sub)
                  sMAC_tx_FF.Next_state_MAC = MAC_idle;

                else
                  if(sMAC_tx_FF.Current_state_MAC == MAC_FFEmpty)
                    if(!sMAC_tx_FF.Empty)
                      sMAC_tx_FF.Next_state_MAC = MAC_byte3;

                    else
                      sMAC_tx_FF.Next_state_MAC = sMAC_tx_FF.Current_state_MAC;

                  else
                    if(sMAC_tx_FF.Current_state_MAC == MAC_FF_Err)
                      sMAC_tx_FF.Next_state_MAC = sMAC_tx_FF.Current_state_MAC;

                    else
                      if(TRUE)
                        sMAC_tx_FF.Next_state_MAC = MAC_idle;

  if(Reset)
    tmp64 = 0;

  else
  {
    tmp65 = sMAC_tx_FF.Add_rd >> 8 & 1;
    for(i = 0; i <= 7; i = i + 1)
      tmp66 = sMAC_tx_FF.Add_rd >> (i + 1) ^ sMAC_tx_FF.Add_rd >> i;
  }
  if(Reset)
    tmp67 = 0;

  else
    tmp68 = sMAC_tx_FF.Add_wr_gray;
  if(Reset)
    sMAC_tx_FF.Add_wr_ungray = 0;

  else
  {
    sMAC_tx_FF.Add_wr_ungray = sMAC_tx_FF.Add_wr_ungray | (sMAC_tx_FF.Add_wr_gray_dl1 >> 8 & 1) << 8;
    for(i = 0; i <= 7; i = i + 1)
      sMAC_tx_FF.Add_wr_ungray = sMAC_tx_FF.Add_wr_ungray >> (i + 1) & 1 && sMAC_tx_FF.Add_wr_gray_dl1 >> i & 1;
  }
  if(Reset)
    tmp69 = TRUE;

  else
    if(sMAC_tx_FF.Add_rd == sMAC_tx_FF.Add_wr_ungray)
      tmp70 = TRUE;

    else
      tmp71 = FALSE;
  if(Reset)
    tmp72 = FALSE;

  else
    tmp73 = sMAC_tx_FF.Fifo_ra_tmp;
  if(Reset)
    tmp74 = FALSE;

  else
    if(sMAC_tx_FF.Current_state_MAC == MAC_pkt_sub)
      tmp75 = TRUE;

    else
      tmp76 = FALSE;
  if(Reset)
    tmp77 = FALSE;

  else
    if(sMAC_tx_FF.Current_state_MAC == MAC_pkt_sub || sMAC_tx_FF.Pkt_sub_apply_tmp)
      tmp78 = TRUE;

    else
      tmp79 = FALSE;
  if(Reset)
    tmp80 = 0;

  else
    if(Fifo_rd_finish)
      tmp81 = sMAC_tx_FF.Add_rd;

  if(Reset)
    tmp82 = FALSE;

  else
    if(Fifo_rd_finish)
      tmp83 = TRUE;

    else
      tmp84 = FALSE;
  if(Reset)
    tmp85 = FALSE;

  else
    if(Fifo_rd_finish || sMAC_tx_FF.Add_rd_reg_rdy_tmp)
      tmp86 = TRUE;

    else
      tmp87 = FALSE;
  if((sMAC_tx_FF.Current_state_MAC == MAC_idle || sMAC_tx_FF.Current_state_MAC == MAC_byte0) && sMAC_tx_FF.Next_state_MAC == MAC_byte3)
    sMAC_tx_FF.Add_rd_add = TRUE;

  else
    sMAC_tx_FF.Add_rd_add = FALSE;
  if(Reset)
    tmp88 = 0;

  else
    if(sMAC_tx_FF.Current_state_MAC == MAC_retry)
      tmp89 = sMAC_tx_FF.Add_rd_reg;

    else
      if(sMAC_tx_FF.Add_rd_add)
        tmp90 = (unsigned int)sMAC_tx_FF.Add_rd + 1;

  if(Reset)
    tmp91 = FALSE;

  else
    if(sMAC_tx_FF.Current_state_MAC == MAC_retry)
      tmp92 = TRUE;

    else
      tmp93 = FALSE;
  if(Reset)
    tmp94 = FALSE;

  else
    tmp95 = sMAC_tx_FF.Add_rd_jump_tmp;
  if(Reset)
    tmp96 = FALSE;

  else
    if(sMAC_tx_FF.Current_state_MAC == MAC_retry)
      tmp97 = TRUE;

    else
      if(sMAC_tx_FF.Add_rd_jump_tmp_pl1)
        tmp98 = FALSE;

  if(sMAC_tx_FF.Current_state_MAC == MAC_byte3)
  {
    sMAC_tx_FF.Fifo_data = Dout_data >> 24 & 255;
    *Fifo_data = Dout_data >> 24 & 255;
  }

  else
    if(sMAC_tx_FF.Current_state_MAC == MAC_byte2)
    {
      sMAC_tx_FF.Fifo_data = Dout_data >> 16 & 255;
      *Fifo_data = Dout_data >> 16 & 255;
    }

    else
      if(sMAC_tx_FF.Current_state_MAC == MAC_byte1)
      {
        sMAC_tx_FF.Fifo_data = Dout_data >> 8 & 255;
        *Fifo_data = Dout_data >> 8 & 255;
      }

      else
        if(sMAC_tx_FF.Current_state_MAC == MAC_byte0)
        {
          sMAC_tx_FF.Fifo_data = Dout_data >> 0 & 255;
          *Fifo_data = Dout_data >> 0 & 255;
        }

        else
          if(TRUE)
          {
            sMAC_tx_FF.Fifo_data = 0;
            *Fifo_data = 0;
          }

  if(Reset)
    tmp99 = FALSE;

  else
    tmp100 = Fifo_rd;
  if(Reset)
    tmp101 = FALSE;

  else
    if((sMAC_tx_FF.Current_state_MAC == MAC_byte0 || sMAC_tx_FF.Current_state_MAC == MAC_byte1 || sMAC_tx_FF.Current_state_MAC == MAC_byte2 || sMAC_tx_FF.Current_state_MAC == MAC_byte3) && Fifo_rd && !sMAC_tx_FF.Fifo_eop)
      tmp102 = TRUE;

    else
      tmp103 = FALSE;
  *Fifo_data_err_full = Dout_err;
  *Fifo_data_err_full = Dout_err;
  if(Reset)
    tmp104 = 0;

  else
    tmp105 = sMAC_tx_FF.Current_state_MAC;
  if(Reset)
    tmp106 = FALSE;

  else
    if(sMAC_tx_FF.Current_state_MAC_reg == MAC_FFEmpty)
      tmp107 = TRUE;

    else
      tmp108 = FALSE;
  if(sMAC_tx_FF.Current_state_MAC_reg == MAC_FF_Err)
  {
  }

  if((sMAC_tx_FF.Current_state_MAC == MAC_byte0 && Dout_BE == 0 || sMAC_tx_FF.Current_state_MAC == MAC_byte1 && Dout_BE == 3 || sMAC_tx_FF.Current_state_MAC == MAC_byte2 && Dout_BE == 2 || sMAC_tx_FF.Current_state_MAC == MAC_byte3 && Dout_BE == 1) && Dout_eop)
  {
    sMAC_tx_FF.Fifo_eop = TRUE;
    *Fifo_eop = TRUE;
  }

  else
  {
    sMAC_tx_FF.Fifo_eop = FALSE;
    *Fifo_eop = FALSE;
  }
  if(Reset)
    sMAC_tx_FF.Current_state_SYS = tmp0;

  else
    sMAC_tx_FF.Current_state_SYS = tmp1;
  if(Reset)
  {
    sMAC_tx_FF.Tx_mac_wr_dl1 = tmp2;
    sMAC_tx_FF.Tx_mac_data_dl1 = tmp3;
    sMAC_tx_FF.Tx_mac_BE_dl1 = tmp4;
    sMAC_tx_FF.Tx_mac_sop_dl1 = tmp5;
    sMAC_tx_FF.Tx_mac_eop_dl1 = tmp6;
  }

  else
  {
    sMAC_tx_FF.Tx_mac_wr_dl1 = tmp7;
    sMAC_tx_FF.Tx_mac_data_dl1 = tmp8;
    sMAC_tx_FF.Tx_mac_BE_dl1 = tmp9;
    sMAC_tx_FF.Tx_mac_sop_dl1 = tmp10;
    sMAC_tx_FF.Tx_mac_eop_dl1 = tmp11;
  }
  if(Reset)
    sMAC_tx_FF.Add_wr_gray = tmp12;

  else
  {
    sMAC_tx_FF.Add_wr_gray = sMAC_tx_FF.Add_wr_gray | tmp13 << 8;
    for(i = 0; i <= 7; i = i + 1)
      sMAC_tx_FF.Add_wr_gray = sMAC_tx_FF.Add_wr_gray | tmp14 << i;
  }
  if(Reset)
    sMAC_tx_FF.Add_rd_gray_dl1 = tmp15;

  else
    sMAC_tx_FF.Add_rd_gray_dl1 = tmp16;
  if(Reset)
    sMAC_tx_FF.Add_rd_jump_wr_pl1 = tmp17;

  else
    sMAC_tx_FF.Add_rd_jump_wr_pl1 = tmp18;
  if(Reset)
    sMAC_tx_FF.AlmostFull = tmp19;

  else
    if(Add_wr_pluse_pluse == sMAC_tx_FF.Add_rd_ungray)
      sMAC_tx_FF.AlmostFull = tmp20;

    else
      sMAC_tx_FF.AlmostFull = tmp21;
  if(Reset)
    sMAC_tx_FF.Add_wr = tmp22;

  else
    if(sMAC_tx_FF.Wr_en && !sMAC_tx_FF.Full)
      sMAC_tx_FF.Add_wr = tmp23;

  if(Reset)
  {
    sMAC_tx_FF.Packet_number_sub_dl1 = tmp24;
    sMAC_tx_FF.Packet_number_sub_dl2 = tmp25;
  }

  else
  {
    sMAC_tx_FF.Packet_number_sub_dl1 = tmp26;
    sMAC_tx_FF.Packet_number_sub_dl2 = tmp27;
  }
  if(Reset)
    sMAC_tx_FF.Packet_number_sub_edge = tmp28;

  else
    if(sMAC_tx_FF.Packet_number_sub_dl1 && !sMAC_tx_FF.Packet_number_sub_dl2)
      sMAC_tx_FF.Packet_number_sub_edge = tmp29;

    else
      sMAC_tx_FF.Packet_number_sub_edge = tmp30;
  if(Reset)
    sMAC_tx_FF.Packet_number_add = tmp31;

  else
    if(sMAC_tx_FF.Current_state_SYS == SYS_EOP_ok || sMAC_tx_FF.Current_state_SYS == SYS_EOP_err)
      sMAC_tx_FF.Packet_number_add = tmp32;

    else
      sMAC_tx_FF.Packet_number_add = tmp33;
  if(Reset)
    sMAC_tx_FF.Packet_number_inFF = tmp34;

  else
    if(sMAC_tx_FF.Packet_number_add && !sMAC_tx_FF.Packet_number_sub_edge)
      sMAC_tx_FF.Packet_number_inFF = tmp35;

    else
      if(!sMAC_tx_FF.Packet_number_add && sMAC_tx_FF.Packet_number_sub_edge)
        sMAC_tx_FF.Packet_number_inFF = tmp36;

  if(Reset)
    sMAC_tx_FF.Packet_number_inFF_reg = tmp37;

  else
    sMAC_tx_FF.Packet_number_inFF_reg = tmp38;
  if(Reset)
  {
    sMAC_tx_FF.Add_rd_reg_rdy_dl1 = tmp39;
    sMAC_tx_FF.Add_rd_reg_rdy_dl2 = tmp40;
  }

  else
  {
    sMAC_tx_FF.Add_rd_reg_rdy_dl1 = tmp41;
    sMAC_tx_FF.Add_rd_reg_rdy_dl2 = tmp42;
  }
  if(Reset)
    sMAC_tx_FF.Add_rd_reg_dl1 = tmp43;

  else
    if(sMAC_tx_FF.Add_rd_reg_rdy_dl1 && !sMAC_tx_FF.Add_rd_reg_rdy_dl2)
      sMAC_tx_FF.Add_rd_reg_dl1 = tmp44;

  if(Reset)
    sMAC_tx_FF.Fifo_data_count = tmp45;

  else
    if(FullDuplex)
      sMAC_tx_FF.Fifo_data_count = tmp46;

    else
      sMAC_tx_FF.Fifo_data_count = tmp47;
  if(Reset)
    sMAC_tx_FF.Fifo_ra_tmp = tmp48;

  else
    if((unsigned int)sMAC_tx_FF.Packet_number_inFF_reg >= 1 || sMAC_tx_FF.Fifo_data_count >= Tx_Lwmark)
      sMAC_tx_FF.Fifo_ra_tmp = tmp49;

    else
      sMAC_tx_FF.Fifo_ra_tmp = tmp50;
  if(Reset)
  {
    sMAC_tx_FF.Tx_Hwmark_pl = tmp51;
    sMAC_tx_FF.Tx_Lwmark_pl = tmp52;
  }

  else
  {
    sMAC_tx_FF.Tx_Hwmark_pl = tmp53;
    sMAC_tx_FF.Tx_Lwmark_pl = tmp54;
  }
  if(Reset)
  {
    sMAC_tx_FF.Tx_mac_wa = tmp55;
    *Tx_mac_wa = tmp55;
  }

  else
    if(sMAC_tx_FF.Fifo_data_count >= sMAC_tx_FF.Tx_Hwmark_pl)
    {
      sMAC_tx_FF.Tx_mac_wa = tmp56;
      *Tx_mac_wa = tmp56;
    }

    else
      if(sMAC_tx_FF.Fifo_data_count < sMAC_tx_FF.Tx_Lwmark_pl)
      {
        sMAC_tx_FF.Tx_mac_wa = tmp57;
        *Tx_mac_wa = tmp57;
      }

  if(Reset)
    sMAC_tx_FF.Dout_dl1 = tmp58;

  else
    sMAC_tx_FF.Dout_dl1 = tmp59;
  if(Reset)
    sMAC_tx_FF.Dout_reg = tmp60;

  else
    if(sMAC_tx_FF.Dout_reg_en)
      sMAC_tx_FF.Dout_reg = tmp61;

  if(Reset)
    sMAC_tx_FF.Current_state_MAC = tmp62;

  else
    sMAC_tx_FF.Current_state_MAC = tmp63;
  if(Reset)
    sMAC_tx_FF.Add_rd_gray = tmp64;

  else
  {
    sMAC_tx_FF.Add_rd_gray = sMAC_tx_FF.Add_rd | tmp65 << 8;
    for(i = 0; i <= 7; i = i + 1)
      sMAC_tx_FF.Add_rd_gray = sMAC_tx_FF.Add_rd_gray | tmp66 << i;
  }
  if(Reset)
    sMAC_tx_FF.Add_wr_gray_dl1 = tmp67;

  else
    sMAC_tx_FF.Add_wr_gray_dl1 = tmp68;
  if(Reset)
    sMAC_tx_FF.Empty = tmp69;

  else
    if(sMAC_tx_FF.Add_rd == sMAC_tx_FF.Add_wr_ungray)
      sMAC_tx_FF.Empty = tmp70;

    else
      sMAC_tx_FF.Empty = tmp71;
  if(Reset)
  {
    sMAC_tx_FF.Fifo_ra = tmp72;
    *Fifo_ra = tmp72;
  }

  else
  {
    sMAC_tx_FF.Fifo_ra = tmp73;
    *Fifo_ra = tmp73;
  }
  if(Reset)
    sMAC_tx_FF.Pkt_sub_apply_tmp = tmp74;

  else
    if(sMAC_tx_FF.Current_state_MAC == MAC_pkt_sub)
      sMAC_tx_FF.Pkt_sub_apply_tmp = tmp75;

    else
      sMAC_tx_FF.Pkt_sub_apply_tmp = tmp76;
  if(Reset)
    sMAC_tx_FF.Pkt_sub_apply = tmp77;

  else
    if(sMAC_tx_FF.Current_state_MAC == MAC_pkt_sub || sMAC_tx_FF.Pkt_sub_apply_tmp)
      sMAC_tx_FF.Pkt_sub_apply = tmp78;

    else
      sMAC_tx_FF.Pkt_sub_apply = tmp79;
  if(Reset)
    sMAC_tx_FF.Add_rd_reg = tmp80;

  else
    if(Fifo_rd_finish)
      sMAC_tx_FF.Add_rd_reg = tmp81;

  if(Reset)
    sMAC_tx_FF.Add_rd_reg_rdy_tmp = tmp82;

  else
    if(Fifo_rd_finish)
      sMAC_tx_FF.Add_rd_reg_rdy_tmp = tmp83;

    else
      sMAC_tx_FF.Add_rd_reg_rdy_tmp = tmp84;
  if(Reset)
    sMAC_tx_FF.Add_rd_reg_rdy = tmp85;

  else
    if(Fifo_rd_finish || sMAC_tx_FF.Add_rd_reg_rdy_tmp)
      sMAC_tx_FF.Add_rd_reg_rdy = tmp86;

    else
      sMAC_tx_FF.Add_rd_reg_rdy = tmp87;
  if(Reset)
    sMAC_tx_FF.Add_rd = tmp88;

  else
    if(sMAC_tx_FF.Current_state_MAC == MAC_retry)
      sMAC_tx_FF.Add_rd = tmp89;

    else
      if(sMAC_tx_FF.Add_rd_add)
        sMAC_tx_FF.Add_rd = tmp90;

  if(Reset)
    sMAC_tx_FF.Add_rd_jump_tmp = tmp91;

  else
    if(sMAC_tx_FF.Current_state_MAC == MAC_retry)
      sMAC_tx_FF.Add_rd_jump_tmp = tmp92;

    else
      sMAC_tx_FF.Add_rd_jump_tmp = tmp93;
  if(Reset)
    sMAC_tx_FF.Add_rd_jump_tmp_pl1 = tmp94;

  else
    sMAC_tx_FF.Add_rd_jump_tmp_pl1 = tmp95;
  if(Reset)
    sMAC_tx_FF.Add_rd_jump = tmp96;

  else
    if(sMAC_tx_FF.Current_state_MAC == MAC_retry)
      sMAC_tx_FF.Add_rd_jump = tmp97;

    else
      if(sMAC_tx_FF.Add_rd_jump_tmp_pl1)
        sMAC_tx_FF.Add_rd_jump = tmp98;

  if(Reset)
    sMAC_tx_FF.Fifo_rd_dl1 = tmp99;

  else
    sMAC_tx_FF.Fifo_rd_dl1 = tmp100;
  if(Reset)
  {
    sMAC_tx_FF.Fifo_da = tmp101;
    *Fifo_da = tmp101;
  }

  else
    if((sMAC_tx_FF.Current_state_MAC == MAC_byte0 || sMAC_tx_FF.Current_state_MAC == MAC_byte1 || sMAC_tx_FF.Current_state_MAC == MAC_byte2 || sMAC_tx_FF.Current_state_MAC == MAC_byte3) && Fifo_rd && !sMAC_tx_FF.Fifo_eop)
    {
      sMAC_tx_FF.Fifo_da = tmp102;
      *Fifo_da = tmp102;
    }

    else
    {
      sMAC_tx_FF.Fifo_da = tmp103;
      *Fifo_da = tmp103;
    }
  if(Reset)
    sMAC_tx_FF.Current_state_MAC_reg = tmp104;

  else
    sMAC_tx_FF.Current_state_MAC_reg = tmp105;
  if(Reset)
  {
    sMAC_tx_FF.Fifo_data_err_empty = tmp106;
    *Fifo_data_err_empty = tmp106;
  }

  else
    if(sMAC_tx_FF.Current_state_MAC_reg == MAC_FFEmpty)
    {
      sMAC_tx_FF.Fifo_data_err_empty = tmp107;
      *Fifo_data_err_empty = tmp107;
    }

    else
    {
      sMAC_tx_FF.Fifo_data_err_empty = tmp108;
      *Fifo_data_err_empty = tmp108;
    }

    // check that the property is true here
/*
  assert(!(sMAC_tx_FF.Current_state_MAC == MAC_byte3) ||
         (sMAC_tx_FF.Fifo_data == Dout_data >> 24 & 255));

  assert(!(sMAC_tx_FF.Current_state_MAC == MAC_byte2)
      ||(sMAC_tx_FF.Fifo_data == Dout_data >> 16 & 255));

  assert(!(sMAC_tx_FF.Current_state_MAC == MAC_byte1)
        || (sMAC_tx_FF.Fifo_data == Dout_data >> 8 & 255));

  assert(!(sMAC_tx_FF.Current_state_MAC == MAC_byte0)
        || (sMAC_tx_FF.Fifo_data == Dout_data >> 0 & 255));


  // check for data error empty
  assert(!(sMAC_tx_FF.Current_state_MAC_reg == MAC_FFEmpty) 
         || (sMAC_tx_FF.Fifo_data_err_empty == 1));
  
  assert((sMAC_tx_FF.Current_state_MAC_reg == MAC_FFEmpty) 
        || (sMAC_tx_FF.Fifo_data_err_empty == 0));
*/        
}

