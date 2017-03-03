//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_MAC_rx_FF{
unsigned short int Add_rd_gray;
unsigned short int Add_rd_gray_dl1;
unsigned short int Add_rd_ungray;
unsigned long int Din;
unsigned long int Din_tmp;
unsigned long int Din_tmp_reg;
_Bool Wr_en;
_Bool Wr_en_tmp;
_Bool Wr_en_ptr;
_Bool Full;
_Bool Almost_full;
_Bool Empty;
unsigned char Current_state;
unsigned char Next_state;
unsigned char Fifo_data_byte0;
unsigned char Fifo_data_byte1;
unsigned char Fifo_data_byte2;
unsigned char Fifo_data_byte3;
_Bool Fifo_data_en_dl1;
unsigned char Fifo_data_dl1;
_Bool Rx_mac_sop_tmp;
unsigned char Current_state_SYS;
unsigned char Next_state_SYS;
unsigned char Packet_number_inFF;
_Bool Packet_number_sub;
_Bool Packet_number_add_dl1;
_Bool Packet_number_add_dl2;
_Bool Packet_number_add;
_Bool Packet_number_add_tmp;
_Bool Packet_number_add_tmp_dl1;
_Bool Packet_number_add_tmp_dl2;
_Bool Rx_mac_sop_tmp_dl1;
unsigned long int Dout_dl1;
unsigned char Fifo_data_count;
_Bool Rx_mac_pa_tmp;
_Bool Add_wr_jump_tmp;
_Bool Add_wr_jump_tmp_pl1;
_Bool Add_wr_jump;
_Bool Add_wr_jump_rd_pl1;
_Bool Rx_mac_ra;
unsigned char Rx_Hwmark_pl;
unsigned char Rx_Lwmark_pl;
_Bool Addr_freshed_ptr;
_Bool Rx_mac_pa;
_Bool Rx_mac_sop;
unsigned short int Add_wr;
unsigned short int Add_wr_ungray;
unsigned short int Add_wr_gray;
unsigned short int Add_wr_gray_dl1;
unsigned short int Add_wr_reg;
unsigned short int Add_rd;
unsigned short int Add_rd_pl1;
};

void MAC_rx_FF(_Bool Reset, _Bool Clk_MAC, _Bool Clk_SYS, unsigned char Fifo_data, _Bool Fifo_data_en, _Bool *Fifo_full, _Bool Fifo_data_err, _Bool Fifo_data_end, _Bool RX_APPEND_CRC, unsigned char Rx_Hwmark, unsigned char Rx_Lwmark, _Bool *Rx_mac_ra, _Bool Rx_mac_rd, unsigned int *Rx_mac_data, unsigned char *Rx_mac_BE, _Bool *Rx_mac_pa, _Bool *Rx_mac_sop, _Bool *Rx_mac_eop)
{
  struct state_elements_MAC_rx_FF  sMAC_rx_FF;
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
  unsigned long int tmp90;
  unsigned long int tmp89;
  _Bool tmp88;
  _Bool tmp87;
  _Bool tmp86;
  _Bool tmp85;
  _Bool tmp84;
  unsigned short int tmp83;
  unsigned short int tmp82;
  _Bool tmp81;
  _Bool tmp80;
  unsigned short int tmp79;
  unsigned short int tmp78;
  unsigned short int tmp77;
  unsigned short int tmp76;
  unsigned short int tmp75;
  _Bool tmp74;
  _Bool tmp73;
  _Bool tmp72;
  unsigned char tmp71;
  unsigned char tmp70;
  unsigned char tmp69;
  unsigned char tmp68;
  unsigned char tmp67;
  unsigned char tmp66;
  unsigned char tmp65;
  unsigned char tmp64;
  unsigned char tmp63;
  _Bool tmp62;
  _Bool tmp61;
  _Bool tmp60;
  _Bool tmp59;
  unsigned char tmp58;
  unsigned char tmp57;
  _Bool tmp56;
  _Bool tmp55;
  _Bool tmp54;
  _Bool tmp53;
  _Bool tmp52;
  _Bool tmp51;
  _Bool tmp50;
  _Bool tmp49;
  _Bool tmp48;
  _Bool tmp47;
  unsigned long int tmp46;
  _Bool tmp45;
  unsigned long int tmp44;
  _Bool tmp43;
  unsigned long int tmp42;
  _Bool tmp41;
  _Bool tmp40;
  _Bool tmp39;
  _Bool tmp38;
  unsigned long int tmp37;
  unsigned long int tmp36;
  unsigned char tmp35;
  unsigned char tmp34;
  unsigned char tmp33;
  unsigned char tmp32;
  unsigned char tmp31;
  unsigned char tmp30;
  unsigned char tmp29;
  unsigned char tmp28;
  _Bool tmp27;
  _Bool tmp26;
  _Bool tmp25;
  _Bool tmp24;
  _Bool tmp23;
  _Bool tmp22;
  _Bool tmp21;
  _Bool tmp20;
  _Bool tmp19;
  _Bool tmp18;
  unsigned short int tmp17;
  unsigned short int tmp16;
  unsigned short int tmp15;
  _Bool tmp14;
  _Bool tmp13;
  _Bool tmp12;
  _Bool tmp11;
  _Bool tmp10;
  _Bool tmp9;
  unsigned short int tmp8;
  unsigned short int tmp7;
  _Bool tmp6;
  _Bool tmp5;
  unsigned short int tmp4;
  unsigned short int tmp3;
  unsigned short int tmp2;
  unsigned char tmp1;
  unsigned char tmp0;
  int State_byte3;

  State_byte3 = 0;
  int State_byte2;
  State_byte2 = 1;
  int State_byte1;
  State_byte1 = 2;
  int State_byte0;
  State_byte0 = 3;
  int State_be0;
  State_be0 = 4;
  int State_be3;
  State_be3 = 5;
  int State_be2;
  State_be2 = 6;
  int State_be1;
  State_be1 = 7;
  int State_err_end;
  State_err_end = 8;
  int State_idle;
  State_idle = 9;
  int SYS_read;
  SYS_read = 0;
  int SYS_pause;
  SYS_pause = 1;
  int SYS_wait_end;
  SYS_wait_end = 2;
  int SYS_idle;
  SYS_idle = 3;
  int FF_emtpy_err;
  FF_emtpy_err = 4;
  unsigned long int Dout;
  unsigned short int Add_wr_pluse;
  unsigned short int Add_wr_pluse4;
  unsigned short int Add_wr_pluse3;
  unsigned short int Add_wr_pluse2;
  _Bool Packet_number_add_edge;
  int i;
  if(Reset)
    tmp0 = State_idle;

  else
    tmp1 = sMAC_rx_FF.Next_state;
  if(sMAC_rx_FF.Current_state == State_idle)
    if(Fifo_data_en)
      sMAC_rx_FF.Next_state = State_byte3;

    else
      sMAC_rx_FF.Next_state = sMAC_rx_FF.Current_state;

  else
    if(sMAC_rx_FF.Current_state == State_byte3)
      if(Fifo_data_en)
        sMAC_rx_FF.Next_state = State_byte2;

      else
        if(Fifo_data_err)
          sMAC_rx_FF.Next_state = State_err_end;

        else
          if(Fifo_data_end)
            sMAC_rx_FF.Next_state = State_be1;

          else
            sMAC_rx_FF.Next_state = sMAC_rx_FF.Current_state;

    else
      if(sMAC_rx_FF.Current_state == State_byte2)
        if(Fifo_data_en)
          sMAC_rx_FF.Next_state = State_byte1;

        else
          if(Fifo_data_err)
            sMAC_rx_FF.Next_state = State_err_end;

          else
            if(Fifo_data_end)
              sMAC_rx_FF.Next_state = State_be2;

            else
              sMAC_rx_FF.Next_state = sMAC_rx_FF.Current_state;

      else
        if(sMAC_rx_FF.Current_state == State_byte1)
          if(Fifo_data_en)
            sMAC_rx_FF.Next_state = State_byte0;

          else
            if(Fifo_data_err)
              sMAC_rx_FF.Next_state = State_err_end;

            else
              if(Fifo_data_end)
                sMAC_rx_FF.Next_state = State_be3;

              else
                sMAC_rx_FF.Next_state = sMAC_rx_FF.Current_state;

        else
          if(sMAC_rx_FF.Current_state == State_byte0)
            if(Fifo_data_en)
              sMAC_rx_FF.Next_state = State_byte3;

            else
              if(Fifo_data_err)
                sMAC_rx_FF.Next_state = State_err_end;

              else
                if(Fifo_data_end)
                  sMAC_rx_FF.Next_state = State_be0;

                else
                  sMAC_rx_FF.Next_state = sMAC_rx_FF.Current_state;

          else
            if(sMAC_rx_FF.Current_state == State_be1)
              sMAC_rx_FF.Next_state = State_idle;

            else
              if(sMAC_rx_FF.Current_state == State_be2)
                sMAC_rx_FF.Next_state = State_idle;

              else
                if(sMAC_rx_FF.Current_state == State_be3)
                  sMAC_rx_FF.Next_state = State_idle;

                else
                  if(sMAC_rx_FF.Current_state == State_be0)
                    sMAC_rx_FF.Next_state = State_idle;

                  else
                    if(sMAC_rx_FF.Current_state == State_err_end)
                      sMAC_rx_FF.Next_state = State_idle;

                    else
                      if(TRUE)
                        sMAC_rx_FF.Next_state = State_idle;

  if(Reset)
    tmp2 = 0;

  else
    if(sMAC_rx_FF.Current_state == State_idle)
      tmp3 = sMAC_rx_FF.Add_wr;

  if(Reset)
    tmp4 = 0;

  else
  {
    tmp5 = sMAC_rx_FF.Add_wr >> 8 & 1;
    for(i = 0; i <= 9 - 2; i = i + 1)
      tmp6 = (sMAC_rx_FF.Add_wr >> (i + 1) & 1) ^ (sMAC_rx_FF.Add_wr >> i & 1);
  }
  if(Reset)
    tmp7 = 0;

  else
    tmp8 = sMAC_rx_FF.Add_rd_gray;
  if(Reset)
    sMAC_rx_FF.Add_rd_ungray = 0;

  else
  {
    sMAC_rx_FF.Add_rd_ungray = sMAC_rx_FF.Add_rd_ungray | (sMAC_rx_FF.Add_rd_gray_dl1 >> 8 & 1) << 8;
    for(i = 0; i <= 7; i = i + 1)
      sMAC_rx_FF.Add_rd_ungray = (sMAC_rx_FF.Add_rd_ungray >> (i + 1) & 1) && (sMAC_rx_FF.Add_rd_gray_dl1 >> i & 1);
  }
  Add_wr_pluse = (unsigned short int)(unsigned int)sMAC_rx_FF.Add_wr + 1;
  Add_wr_pluse4 = (unsigned short int)(unsigned int)sMAC_rx_FF.Add_wr + 4;
  Add_wr_pluse3 = (unsigned short int)(unsigned int)sMAC_rx_FF.Add_wr + 3;
  Add_wr_pluse2 = (unsigned short int)(unsigned int)sMAC_rx_FF.Add_wr + 2;
  if(Reset)
    tmp9 = FALSE;

  else
    if(Add_wr_pluse == sMAC_rx_FF.Add_rd_ungray)
      tmp10 = TRUE;

    else
      tmp11 = FALSE;
  if(Reset)
    tmp12 = FALSE;

  else
    if(Add_wr_pluse4 == sMAC_rx_FF.Add_rd_ungray || Add_wr_pluse3 == sMAC_rx_FF.Add_rd_ungray || Add_wr_pluse2 == sMAC_rx_FF.Add_rd_ungray || Add_wr_pluse == sMAC_rx_FF.Add_rd_ungray)
      tmp13 = TRUE;

    else
      tmp14 = FALSE;
  *Fifo_full = sMAC_rx_FF.Almost_full;
  *Fifo_full = sMAC_rx_FF.Almost_full;
  if(Reset)
    tmp15 = 0;

  else
    if(sMAC_rx_FF.Current_state == State_err_end)
      tmp16 = sMAC_rx_FF.Add_wr_reg;

    else
      if(sMAC_rx_FF.Wr_en && !sMAC_rx_FF.Full)
        tmp17 = (unsigned short int)(unsigned int)sMAC_rx_FF.Add_wr + 1;

  if(Reset)
    tmp18 = FALSE;

  else
    if(sMAC_rx_FF.Current_state == State_err_end)
      tmp19 = TRUE;

    else
      tmp20 = FALSE;
  if(Reset)
    tmp21 = FALSE;

  else
    tmp22 = sMAC_rx_FF.Add_wr_jump_tmp;
  if(Reset)
    tmp23 = FALSE;

  else
    if(sMAC_rx_FF.Current_state == State_err_end)
      tmp24 = TRUE;

    else
      if(sMAC_rx_FF.Add_wr_jump_tmp_pl1)
        tmp25 = FALSE;

  if(Reset)
    tmp26 = FALSE;

  else
    tmp27 = Fifo_data_en;
  if(Reset)
    tmp28 = 0;

  else
    tmp29 = Fifo_data;
  if(Reset)
    tmp30 = 0;

  else
    if(sMAC_rx_FF.Current_state == State_byte3 && sMAC_rx_FF.Fifo_data_en_dl1)
      tmp31 = sMAC_rx_FF.Fifo_data_dl1;

  if(Reset)
    tmp32 = 0;

  else
    if(sMAC_rx_FF.Current_state == State_byte2 && sMAC_rx_FF.Fifo_data_en_dl1)
      tmp33 = sMAC_rx_FF.Fifo_data_dl1;

  if(Reset)
    tmp34 = 0;

  else
    if(sMAC_rx_FF.Current_state == State_byte1 && sMAC_rx_FF.Fifo_data_en_dl1)
      tmp35 = sMAC_rx_FF.Fifo_data_dl1;

  if(sMAC_rx_FF.Current_state == State_be0)
    sMAC_rx_FF.Din_tmp = 0x8 << 32 | (sMAC_rx_FF.Fifo_data_byte3 & 0xFF << 24) | (sMAC_rx_FF.Fifo_data_byte2 & 0xFF << 16) | (sMAC_rx_FF.Fifo_data_byte1 & 0xFF << 8) | (sMAC_rx_FF.Fifo_data_dl1 & 0xFF);

  else
    if(sMAC_rx_FF.Current_state == State_be1)
      sMAC_rx_FF.Din_tmp = 0x9 << 32 | (sMAC_rx_FF.Fifo_data_byte3 & 0xFF << 24) | (0x000000);

    else
      if(sMAC_rx_FF.Current_state == State_be2)
        sMAC_rx_FF.Din_tmp = 0x10 << 32 | (sMAC_rx_FF.Fifo_data_byte3 & 0xFF << 24) | (sMAC_rx_FF.Fifo_data_byte2 & 0xFF << 16) | 0x0000;


      else
        if(sMAC_rx_FF.Current_state == State_be3)
          sMAC_rx_FF.Din_tmp = 0x11 << 32 | (sMAC_rx_FF.Fifo_data_byte3 & 0xFF << 24) | (sMAC_rx_FF.Fifo_data_byte2 & 0xFF << 16) | (sMAC_rx_FF.Fifo_data_byte1 & 0xFF << 8) | (0xFF);


        else
          if(TRUE)
            sMAC_rx_FF.Din_tmp = 0x0 << 32 | (sMAC_rx_FF.Fifo_data_byte3 & 0xFF << 24) | (sMAC_rx_FF.Fifo_data_byte2 & 0xFF << 16) | (sMAC_rx_FF.Fifo_data_byte1 & 0xFF << 8) | (sMAC_rx_FF.Fifo_data_dl1 & 0xFF);


  if(sMAC_rx_FF.Current_state == State_be0 || sMAC_rx_FF.Current_state == State_be1 || sMAC_rx_FF.Current_state == State_be2 || sMAC_rx_FF.Current_state == State_be3 || sMAC_rx_FF.Current_state == State_byte0 && Fifo_data_en)
    sMAC_rx_FF.Wr_en_tmp = TRUE;

  else
    sMAC_rx_FF.Wr_en_tmp = FALSE;
  if(Reset)
    tmp36 = 0;

  else
    if(sMAC_rx_FF.Wr_en_tmp)
      tmp37 = sMAC_rx_FF.Din_tmp;

  if(Reset)
    tmp38 = FALSE;

  else
    if(sMAC_rx_FF.Current_state == State_idle)
      tmp39 = FALSE;

    else
      if(sMAC_rx_FF.Wr_en_tmp)
        tmp40 = TRUE;

  if(Reset)
  {
    tmp41 = FALSE;
    tmp42 = 0;
  }

  else
    if(RX_APPEND_CRC)
    {
      tmp43 = sMAC_rx_FF.Wr_en_tmp;
      tmp44 = sMAC_rx_FF.Din_tmp;
    }

    else
    {
      tmp45 = sMAC_rx_FF.Wr_en_tmp && sMAC_rx_FF.Wr_en_ptr;
      tmp46 = sMAC_rx_FF.Din_tmp_reg >> 0 & 4294967295;
    }
  if(Reset)
    tmp47 = FALSE;

  else
    if(sMAC_rx_FF.Current_state == State_be0 || sMAC_rx_FF.Current_state == State_be1 || sMAC_rx_FF.Current_state == State_be2 || sMAC_rx_FF.Current_state == State_be3)
      tmp48 = TRUE;

    else
      tmp49 = FALSE;
  if(Reset)
  {
    tmp50 = FALSE;
    tmp51 = FALSE;
  }

  else
  {
    tmp52 = sMAC_rx_FF.Packet_number_add_tmp;
    tmp53 = sMAC_rx_FF.Packet_number_add_tmp_dl1;
  }
  if(Reset)
    tmp54 = FALSE;

  else
    if(sMAC_rx_FF.Packet_number_add_tmp_dl1 || sMAC_rx_FF.Packet_number_add_tmp_dl2)
      tmp55 = TRUE;

    else
      tmp56 = FALSE;
  if(Reset)
    tmp57 = SYS_idle;

  else
    tmp58 = sMAC_rx_FF.Next_state_SYS;
  if(sMAC_rx_FF.Current_state_SYS == SYS_idle)
    if(Rx_mac_rd && sMAC_rx_FF.Rx_mac_ra && !sMAC_rx_FF.Empty)
      sMAC_rx_FF.Next_state_SYS = SYS_read;

    else
      if(Rx_mac_rd && sMAC_rx_FF.Rx_mac_ra && sMAC_rx_FF.Empty)
        sMAC_rx_FF.Next_state_SYS = FF_emtpy_err;

      else
        sMAC_rx_FF.Next_state_SYS = sMAC_rx_FF.Current_state_SYS;

  else
    if(sMAC_rx_FF.Current_state_SYS == SYS_read)
      if(Dout >> 35 & 1)
        sMAC_rx_FF.Next_state_SYS = SYS_wait_end;

      else
        if(!Rx_mac_rd)
          sMAC_rx_FF.Next_state_SYS = SYS_pause;

        else
          if(sMAC_rx_FF.Empty)
            sMAC_rx_FF.Next_state_SYS = FF_emtpy_err;

          else
            sMAC_rx_FF.Next_state_SYS = sMAC_rx_FF.Current_state_SYS;

    else
      if(sMAC_rx_FF.Current_state_SYS == SYS_pause)
        if(Rx_mac_rd)
          sMAC_rx_FF.Next_state_SYS = SYS_read;

        else
          sMAC_rx_FF.Next_state_SYS = sMAC_rx_FF.Current_state_SYS;

      else
        if(sMAC_rx_FF.Current_state_SYS == FF_emtpy_err)
          if(!sMAC_rx_FF.Empty)
            sMAC_rx_FF.Next_state_SYS = SYS_read;

          else
            sMAC_rx_FF.Next_state_SYS = sMAC_rx_FF.Current_state_SYS;

        else
          if(sMAC_rx_FF.Current_state_SYS == SYS_wait_end)
            if(!Rx_mac_rd)
              sMAC_rx_FF.Next_state_SYS = SYS_idle;

            else
              sMAC_rx_FF.Next_state_SYS = sMAC_rx_FF.Current_state_SYS;

          else
            if(TRUE)
              sMAC_rx_FF.Next_state_SYS = SYS_idle;

  if(Reset)
  {
    tmp59 = FALSE;
    tmp60 = FALSE;
  }

  else
  {
    tmp61 = sMAC_rx_FF.Packet_number_add;
    tmp62 = sMAC_rx_FF.Packet_number_add_dl1;
  }
  Packet_number_add_edge = sMAC_rx_FF.Packet_number_add_dl1 && !sMAC_rx_FF.Packet_number_add_dl2;
  if(sMAC_rx_FF.Current_state_SYS == SYS_read && sMAC_rx_FF.Next_state_SYS == SYS_wait_end)
    sMAC_rx_FF.Packet_number_sub = TRUE;

  else
    sMAC_rx_FF.Packet_number_sub = FALSE;
  if(Reset)
    tmp63 = 0;

  else
    if(Packet_number_add_edge && !sMAC_rx_FF.Packet_number_sub)
      tmp64 = (unsigned char)(unsigned int)sMAC_rx_FF.Packet_number_inFF + 1;

    else
      if(!Packet_number_add_edge && sMAC_rx_FF.Packet_number_sub && (unsigned int)sMAC_rx_FF.Packet_number_inFF != 0)
        tmp65 = (unsigned char)(unsigned int)sMAC_rx_FF.Packet_number_inFF - 1;

  if(Reset)
    tmp66 = 0;

  else
    tmp67 = (sMAC_rx_FF.Add_wr_ungray >> 4 & 0x1F) - (sMAC_rx_FF.Add_rd >> 4 & 0x1F);
  if(Reset)
  {
    tmp68 = 0;
    tmp69 = 0;
  }

  else
  {
    tmp70 = Rx_Hwmark;
    tmp71 = Rx_Lwmark;
  }
  if(Reset)
    tmp72 = FALSE;

  else
    if((unsigned int)sMAC_rx_FF.Packet_number_inFF == 0 && sMAC_rx_FF.Fifo_data_count <= sMAC_rx_FF.Rx_Lwmark_pl)
      tmp73 = FALSE;

    else
      if((unsigned int)sMAC_rx_FF.Packet_number_inFF >= 1 || sMAC_rx_FF.Fifo_data_count >= sMAC_rx_FF.Rx_Hwmark_pl)
        tmp74 = TRUE;

  if(Reset)
    tmp75 = 0;

  else
    if(sMAC_rx_FF.Current_state_SYS == SYS_read && !((Dout >> 35 & 1) && sMAC_rx_FF.Addr_freshed_ptr))
      tmp76 = (unsigned short int)(unsigned int)sMAC_rx_FF.Add_rd + 1;

  if(Reset)
    tmp77 = 0;

  else
    tmp78 = sMAC_rx_FF.Add_rd;
  if(sMAC_rx_FF.Add_rd_pl1 == sMAC_rx_FF.Add_rd)
    sMAC_rx_FF.Addr_freshed_ptr = FALSE;

  else
    sMAC_rx_FF.Addr_freshed_ptr = TRUE;
  if(Reset)
    tmp79 = 0;

  else
  {
    tmp80 = sMAC_rx_FF.Add_rd >> 8 & 1;
    for(i = 0; i <= 7; i = i + 1)
      tmp81 = ((sMAC_rx_FF.Add_rd >> (i + 1) & 1) ^ (sMAC_rx_FF.Add_rd >> i & 1));
  }
  if(Reset)
    tmp82 = 0;

  else
    tmp83 = sMAC_rx_FF.Add_wr_gray;
  if(Reset)
    tmp84 = FALSE;

  else
    tmp85 = sMAC_rx_FF.Add_wr_jump;
  if(Reset)
    sMAC_rx_FF.Add_wr_ungray = 0;

  else
    if(!sMAC_rx_FF.Add_wr_jump_rd_pl1)
    {
      sMAC_rx_FF.Add_wr_ungray = sMAC_rx_FF.Add_wr_ungray | (sMAC_rx_FF.Add_wr_gray_dl1 >> 8 & 1) << 8;
      for(i = 0; i <= 7; i = i + 1)
        sMAC_rx_FF.Add_wr_ungray = (sMAC_rx_FF.Add_wr_ungray >> (i + 1) & 1) && (sMAC_rx_FF.Add_wr_gray_dl1 >> i & 1);
    }

  if(Reset)
    tmp86 = TRUE;

  else
    if(sMAC_rx_FF.Add_rd == sMAC_rx_FF.Add_wr_ungray)
      tmp87 = TRUE;

    else
      tmp88 = FALSE;
  if(Reset)
    tmp89 = 0;

  else
    tmp90 = Dout;
  *Rx_mac_data = sMAC_rx_FF.Dout_dl1 >> 0 & 4294967295;
  *Rx_mac_data = sMAC_rx_FF.Dout_dl1 >> 0 & 4294967295;
  *Rx_mac_BE = sMAC_rx_FF.Dout_dl1 >> 32 & 3;
  *Rx_mac_BE = sMAC_rx_FF.Dout_dl1 >> 32 & 3;
  *Rx_mac_eop = sMAC_rx_FF.Dout_dl1 >> 35 & 1;
  *Rx_mac_eop = sMAC_rx_FF.Dout_dl1 >> 35 & 1;
  if(Reset)
    tmp91 = FALSE;

  else
    if(sMAC_rx_FF.Current_state_SYS == SYS_read && !((Dout >> 35 & 1) && sMAC_rx_FF.Addr_freshed_ptr))
      tmp92 = TRUE;

    else
      tmp93 = FALSE;
  if(Reset)
    tmp94 = FALSE;

  else
    tmp95 = sMAC_rx_FF.Rx_mac_pa_tmp;
  if(Reset)
    tmp96 = FALSE;

  else
    if(sMAC_rx_FF.Current_state_SYS == SYS_idle && sMAC_rx_FF.Next_state_SYS == SYS_read)
      tmp97 = TRUE;

    else
      tmp98 = FALSE;
  if(Reset)
  {
    tmp99 = FALSE;
    tmp100 = FALSE;
  }

  else
  {
    tmp101 = sMAC_rx_FF.Rx_mac_sop_tmp;
    tmp102 = sMAC_rx_FF.Rx_mac_sop_tmp_dl1;
  }
  if(Reset)
    sMAC_rx_FF.Current_state = tmp0;

  else
    sMAC_rx_FF.Current_state = tmp1;
  if(Reset)
    sMAC_rx_FF.Add_wr_reg = tmp2;

  else
    if(sMAC_rx_FF.Current_state == State_idle)
      sMAC_rx_FF.Add_wr_reg = tmp3;

  if(Reset)
    sMAC_rx_FF.Add_wr_gray = tmp4;

  else
  {
    sMAC_rx_FF.Add_wr_gray = sMAC_rx_FF.Add_wr | (tmp5 << 8);
    for(i = 0; i <= 7; i = i + 1)
      sMAC_rx_FF.Add_wr_gray = sMAC_rx_FF.Add_wr_gray | tmp6 << i;
  }
  if(Reset)
    sMAC_rx_FF.Add_rd_gray_dl1 = tmp7;

  else
    sMAC_rx_FF.Add_rd_gray_dl1 = tmp8;
  if(Reset)
    sMAC_rx_FF.Full = tmp9;

  else
    if(Add_wr_pluse == sMAC_rx_FF.Add_rd_ungray)
      sMAC_rx_FF.Full = tmp10;

    else
      sMAC_rx_FF.Full = tmp11;
  if(Reset)
    sMAC_rx_FF.Almost_full = tmp12;

  else
    if(Add_wr_pluse4 == sMAC_rx_FF.Add_rd_ungray || Add_wr_pluse3 == sMAC_rx_FF.Add_rd_ungray || Add_wr_pluse2 == sMAC_rx_FF.Add_rd_ungray || Add_wr_pluse == sMAC_rx_FF.Add_rd_ungray)
      sMAC_rx_FF.Almost_full = tmp13;

    else
      sMAC_rx_FF.Almost_full = tmp14;
  if(Reset)
    sMAC_rx_FF.Add_wr = tmp15;

  else
    if(sMAC_rx_FF.Current_state == State_err_end)
      sMAC_rx_FF.Add_wr = tmp16;

    else
      if(sMAC_rx_FF.Wr_en && !sMAC_rx_FF.Full)
        sMAC_rx_FF.Add_wr = tmp17;

  if(Reset)
    sMAC_rx_FF.Add_wr_jump_tmp = tmp18;

  else
    if(sMAC_rx_FF.Current_state == State_err_end)
      sMAC_rx_FF.Add_wr_jump_tmp = tmp19;

    else
      sMAC_rx_FF.Add_wr_jump_tmp = tmp20;
  if(Reset)
    sMAC_rx_FF.Add_wr_jump_tmp_pl1 = tmp21;

  else
    sMAC_rx_FF.Add_wr_jump_tmp_pl1 = tmp22;
  if(Reset)
    sMAC_rx_FF.Add_wr_jump = tmp23;

  else
    if(sMAC_rx_FF.Current_state == State_err_end)
      sMAC_rx_FF.Add_wr_jump = tmp24;

    else
      if(sMAC_rx_FF.Add_wr_jump_tmp_pl1)
        sMAC_rx_FF.Add_wr_jump = tmp25;

  if(Reset)
    sMAC_rx_FF.Fifo_data_en_dl1 = tmp26;

  else
    sMAC_rx_FF.Fifo_data_en_dl1 = tmp27;
  if(Reset)
    sMAC_rx_FF.Fifo_data_dl1 = tmp28;

  else
    sMAC_rx_FF.Fifo_data_dl1 = tmp29;
  if(Reset)
    sMAC_rx_FF.Fifo_data_byte3 = tmp30;

  else
    if(sMAC_rx_FF.Current_state == State_byte3 && sMAC_rx_FF.Fifo_data_en_dl1)
      sMAC_rx_FF.Fifo_data_byte3 = tmp31;

  if(Reset)
    sMAC_rx_FF.Fifo_data_byte2 = tmp32;

  else
    if(sMAC_rx_FF.Current_state == State_byte2 && sMAC_rx_FF.Fifo_data_en_dl1)
      sMAC_rx_FF.Fifo_data_byte2 = tmp33;

  if(Reset)
    sMAC_rx_FF.Fifo_data_byte1 = tmp34;

  else
    if(sMAC_rx_FF.Current_state == State_byte1 && sMAC_rx_FF.Fifo_data_en_dl1)
      sMAC_rx_FF.Fifo_data_byte1 = tmp35;

  if(Reset)
    sMAC_rx_FF.Din_tmp_reg = tmp36;

  else
    if(sMAC_rx_FF.Wr_en_tmp)
      sMAC_rx_FF.Din_tmp_reg = tmp37;

  if(Reset)
    sMAC_rx_FF.Wr_en_ptr = tmp38;

  else
    if(sMAC_rx_FF.Current_state == State_idle)
      sMAC_rx_FF.Wr_en_ptr = tmp39;

    else
      if(sMAC_rx_FF.Wr_en_tmp)
        sMAC_rx_FF.Wr_en_ptr = tmp40;

  if(Reset)
  {
    sMAC_rx_FF.Wr_en = tmp41;
    sMAC_rx_FF.Din = tmp42;
  }

  else
    if(RX_APPEND_CRC)
    {
      sMAC_rx_FF.Wr_en = tmp43;
      sMAC_rx_FF.Din = tmp44;
    }

    else
    {
      sMAC_rx_FF.Wr_en = tmp45;
      sMAC_rx_FF.Din = tmp46;
    }
  if(Reset)
    sMAC_rx_FF.Packet_number_add_tmp = tmp47;

  else
    if(sMAC_rx_FF.Current_state == State_be0 || sMAC_rx_FF.Current_state == State_be1 || sMAC_rx_FF.Current_state == State_be2 || sMAC_rx_FF.Current_state == State_be3)
      sMAC_rx_FF.Packet_number_add_tmp = tmp48;

    else
      sMAC_rx_FF.Packet_number_add_tmp = tmp49;
  if(Reset)
  {
    sMAC_rx_FF.Packet_number_add_tmp_dl1 = tmp50;
    sMAC_rx_FF.Packet_number_add_tmp_dl2 = tmp51;
  }

  else
  {
    sMAC_rx_FF.Packet_number_add_tmp_dl1 = tmp52;
    sMAC_rx_FF.Packet_number_add_tmp_dl2 = tmp53;
  }
  if(Reset)
    sMAC_rx_FF.Packet_number_add = tmp54;

  else
    if(sMAC_rx_FF.Packet_number_add_tmp_dl1 || sMAC_rx_FF.Packet_number_add_tmp_dl2)
      sMAC_rx_FF.Packet_number_add = tmp55;

    else
      sMAC_rx_FF.Packet_number_add = tmp56;
  if(Reset)
    sMAC_rx_FF.Current_state_SYS = tmp57;

  else
    sMAC_rx_FF.Current_state_SYS = tmp58;
  if(Reset)
  {
    sMAC_rx_FF.Packet_number_add_dl1 = tmp59;
    sMAC_rx_FF.Packet_number_add_dl2 = tmp60;
  }

  else
  {
    sMAC_rx_FF.Packet_number_add_dl1 = tmp61;
    sMAC_rx_FF.Packet_number_add_dl2 = tmp62;
  }
  if(Reset)
    sMAC_rx_FF.Packet_number_inFF = tmp63;

  else
    if(Packet_number_add_edge && !sMAC_rx_FF.Packet_number_sub)
      sMAC_rx_FF.Packet_number_inFF = tmp64;

    else
      if(!Packet_number_add_edge && sMAC_rx_FF.Packet_number_sub && (unsigned int)sMAC_rx_FF.Packet_number_inFF != 0)
        sMAC_rx_FF.Packet_number_inFF = tmp65;

  if(Reset)
    sMAC_rx_FF.Fifo_data_count = tmp66;

  else
    sMAC_rx_FF.Fifo_data_count = tmp67;
  if(Reset)
  {
    sMAC_rx_FF.Rx_Hwmark_pl = tmp68;
    sMAC_rx_FF.Rx_Lwmark_pl = tmp69;
  }

  else
  {
    sMAC_rx_FF.Rx_Hwmark_pl = tmp70;
    sMAC_rx_FF.Rx_Lwmark_pl = tmp71;
  }
  if(Reset)
  {
    sMAC_rx_FF.Rx_mac_ra = tmp72;
    *Rx_mac_ra = tmp72;
  }

  else
    if((unsigned int)sMAC_rx_FF.Packet_number_inFF == 0 && sMAC_rx_FF.Fifo_data_count <= sMAC_rx_FF.Rx_Lwmark_pl)
    {
      sMAC_rx_FF.Rx_mac_ra = tmp73;
      *Rx_mac_ra = tmp73;
    }

    else
      if((unsigned int)sMAC_rx_FF.Packet_number_inFF >= 1 || sMAC_rx_FF.Fifo_data_count >= sMAC_rx_FF.Rx_Hwmark_pl)
      {
        sMAC_rx_FF.Rx_mac_ra = tmp74;
        *Rx_mac_ra = tmp74;
      }

  if(Reset)
    sMAC_rx_FF.Add_rd = tmp75;

  else
    if(sMAC_rx_FF.Current_state_SYS == SYS_read && !((Dout >> 35 & 1) && sMAC_rx_FF.Addr_freshed_ptr))
      sMAC_rx_FF.Add_rd = tmp76;

  if(Reset)
    sMAC_rx_FF.Add_rd_pl1 = tmp77;

  else
    sMAC_rx_FF.Add_rd_pl1 = tmp78;
  if(Reset)
    sMAC_rx_FF.Add_rd_gray = tmp79;

  else
  {
    sMAC_rx_FF.Add_rd_gray  = sMAC_rx_FF.Add_rd_gray | (tmp80 << 8);
    for(i = 0; i <= 7; i = i + 1)
      sMAC_rx_FF.Add_rd_gray = (sMAC_rx_FF.Add_rd_gray) | (tmp81 << i);
  }
  if(Reset)
    sMAC_rx_FF.Add_wr_gray_dl1 = tmp82;

  else
    sMAC_rx_FF.Add_wr_gray_dl1 = tmp83;
  if(Reset)
    sMAC_rx_FF.Add_wr_jump_rd_pl1 = tmp84;

  else
    sMAC_rx_FF.Add_wr_jump_rd_pl1 = tmp85;
  if(Reset)
    sMAC_rx_FF.Empty = tmp86;

  else
    if(sMAC_rx_FF.Add_rd == sMAC_rx_FF.Add_wr_ungray)
      sMAC_rx_FF.Empty = tmp87;

    else
      sMAC_rx_FF.Empty = tmp88;
  if(Reset)
    sMAC_rx_FF.Dout_dl1 = tmp89;

  else
    sMAC_rx_FF.Dout_dl1 = tmp90;
  if(Reset)
    sMAC_rx_FF.Rx_mac_pa_tmp = tmp91;

  else
    if(sMAC_rx_FF.Current_state_SYS == SYS_read && !((Dout >> 35 & 1) && sMAC_rx_FF.Addr_freshed_ptr))
      sMAC_rx_FF.Rx_mac_pa_tmp = tmp92;

    else
      sMAC_rx_FF.Rx_mac_pa_tmp = tmp93;
  if(Reset)
  {
    sMAC_rx_FF.Rx_mac_pa = tmp94;
    *Rx_mac_pa = tmp94;
  }

  else
  {
    sMAC_rx_FF.Rx_mac_pa = tmp95;
    *Rx_mac_pa = tmp95;
  }
  if(Reset)
    sMAC_rx_FF.Rx_mac_sop_tmp = tmp96;

  else
    if(sMAC_rx_FF.Current_state_SYS == SYS_idle && sMAC_rx_FF.Next_state_SYS == SYS_read)
      sMAC_rx_FF.Rx_mac_sop_tmp = tmp97;

    else
      sMAC_rx_FF.Rx_mac_sop_tmp = tmp98;
  if(Reset)
  {
    sMAC_rx_FF.Rx_mac_sop_tmp_dl1 = tmp99;
    {
      sMAC_rx_FF.Rx_mac_sop = tmp100;
      *Rx_mac_sop = tmp100;
    }
  }

  else
  {
    sMAC_rx_FF.Rx_mac_sop_tmp_dl1 = tmp101;
    {
      sMAC_rx_FF.Rx_mac_sop = tmp102;
      *Rx_mac_sop = tmp102;
    }
  }
}

/*
void main() {
_Bool Reset;
_Bool Clk_MAC;
_Bool Clk_SYS;
unsigned char Fifo_data;
_Bool Fifo_data_en;
_Bool Fifo_full;
_Bool Fifo_data_err;
_Bool Fifo_data_end;
_Bool RX_APPEND_CRC;
unsigned char Rx_Hwmark;
unsigned char Rx_Lwmark;
_Bool Rx_mac_ra;
_Bool Rx_mac_rd;
unsigned int Rx_mac_data;
unsigned char Rx_mac_BE;
_Bool Rx_mac_pa;
_Bool Rx_mac_sop;
_Bool Rx_mac_eop;
while(1) {
MAC_rx_FF(Reset, Clk_MAC, Clk_SYS, Fifo_data, Fifo_data_en, &Fifo_full, Fifo_data_err, Fifo_data_end, RX_APPEND_CRC, Rx_Hwmark, Rx_Lwmark, &Rx_mac_ra, Rx_mac_rd, &Rx_mac_data, &Rx_mac_BE, &Rx_mac_pa, &Rx_mac_sop, &Rx_mac_eop);
}
}*/
