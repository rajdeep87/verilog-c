//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_MAC_rx_ctrl{
_Bool broadcast_ptr;
unsigned short int pause_quanta;
unsigned char Current_state;
_Bool pause_quanta_val;
unsigned char Next_state;
unsigned char Pause_current;
unsigned char Pause_next;
_Bool Fifo_data_en;
unsigned char IFG_counter;
_Bool Fifo_data_err;
_Bool Crs_dv;
_Bool Fifo_data_end;
unsigned char RxD;
unsigned char RxD_dl1;
_Bool RxErr;
_Bool Rx_apply_rmon;
unsigned short int Frame_length_counter;
_Bool Too_long;
unsigned char Rx_pkt_err_type_rmon;
_Bool Too_short;
unsigned char Rx_pkt_type_rmon;
_Bool Rx_apply_rmon_tmp;
_Bool Rx_apply_rmon_tmp_pl1;
unsigned char pause_quanta_h;
_Bool pause_quanta_val_tmp;
_Bool pause_frame_ptr;
_Bool CRC_en;
_Bool CRC_init;
_Bool MAC_add_en;
};
struct state_elements_MAC_rx_ctrl  sMAC_rx_ctrl;

void MAC_rx_ctrl(_Bool Reset, _Bool Clk, _Bool MCrs_dv, unsigned char MRxD, _Bool MRxErr, _Bool *CRC_en, _Bool *CRC_init, _Bool CRC_err, _Bool *MAC_add_en, _Bool MAC_rx_add_chk_err, _Bool *broadcast_ptr, _Bool broadcast_drop, unsigned short int *pause_quanta, _Bool *pause_quanta_val, unsigned char *Fifo_data, _Bool *Fifo_data_en, _Bool *Fifo_data_err, _Bool *Fifo_data_end, _Bool Fifo_full, unsigned short int *Rx_pkt_length_rmon, _Bool *Rx_apply_rmon, unsigned char *Rx_pkt_err_type_rmon, unsigned char *Rx_pkt_type_rmon, unsigned char RX_IFG_SET, unsigned short int RX_MAX_LENGTH, unsigned char RX_MIN_LENGTH)
{
  _Bool tmp51;
  _Bool tmp50;
  _Bool tmp49;
  _Bool tmp48;
  _Bool tmp47;
  _Bool tmp46;
  _Bool tmp45;
  _Bool tmp44;
  _Bool tmp43;
  unsigned short int tmp42;
  unsigned short int tmp41;
  unsigned char tmp40;
  unsigned char tmp39;
  unsigned char tmp38;
  unsigned char tmp37;
  _Bool tmp36;
  _Bool tmp35;
  _Bool tmp34;
  _Bool tmp33;
  _Bool tmp32;
  unsigned char tmp31;
  unsigned char tmp30;
  unsigned char tmp29;
  unsigned char tmp28;
  unsigned char tmp27;
  unsigned char tmp26;
  unsigned char tmp25;
  unsigned char tmp24;
  _Bool tmp23;
  _Bool tmp22;
  _Bool tmp21;
  _Bool tmp20;
  _Bool tmp19;
  _Bool tmp18;
  _Bool tmp17;
  _Bool tmp16;
  unsigned short int tmp15;
  unsigned short int tmp14;
  unsigned short int tmp13;
  unsigned char tmp12;
  unsigned char tmp11;
  unsigned char tmp10;
  unsigned char tmp9;
  unsigned char tmp8;
  unsigned char tmp7;
  unsigned char tmp6;
  _Bool tmp5;
  unsigned char tmp4;
  _Bool tmp3;
  _Bool tmp2;
  unsigned char tmp1;
  _Bool tmp0;
  int State_idle;
  State_idle = 0;
  int State_preamble;
  State_preamble = 1;
  int State_SFD;
  State_SFD = 2;
  int State_data;
  State_data = 3;
  int State_checkCRC;
  State_checkCRC = 4;
  int State_OkEnd;
  State_OkEnd = 7;
  int State_drop;
  State_drop = 8;
  int State_ErrEnd;
  State_ErrEnd = 9;
  int State_CRCErrEnd;
  State_CRCErrEnd = 10;
  int State_FFFullDrop;
  State_FFFullDrop = 11;
  int State_FFFullErrEnd;
  State_FFFullErrEnd = 12;
  int State_IFG;
  State_IFG = 13;
  int Pause_idle;
  Pause_idle = 0;
  int Pause_pre_syn;
  Pause_pre_syn = 1;
  int Pause_quanta_hi;
  Pause_quanta_hi = 2;
  int Pause_quanta_lo;
  Pause_quanta_lo = 3;
  int Pause_syn;
  Pause_syn = 4;
  if(Reset)
  {
    tmp0 = FALSE;
    tmp1 = 0;
    tmp2 = FALSE;
  }

  else
  {
    tmp3 = MCrs_dv;
    tmp4 = MRxD;
    tmp5 = MRxErr;
  }
  if(Reset)
    tmp6 = 0;

  else
    tmp7 = sMAC_rx_ctrl.RxD;
  if(Reset)
    tmp8 = State_idle;

  else
    tmp9 = sMAC_rx_ctrl.Next_state;
  if(sMAC_rx_ctrl.Current_state == State_idle)
    if(sMAC_rx_ctrl.Crs_dv && sMAC_rx_ctrl.RxD == 85)
      sMAC_rx_ctrl.Next_state = State_preamble;

    else
      sMAC_rx_ctrl.Next_state = sMAC_rx_ctrl.Current_state;

  else
    if(sMAC_rx_ctrl.Current_state == State_preamble)
      if(!sMAC_rx_ctrl.Crs_dv)
        sMAC_rx_ctrl.Next_state = State_ErrEnd;

      else
        if(sMAC_rx_ctrl.RxErr)
          sMAC_rx_ctrl.Next_state = State_drop;

        else
          if(sMAC_rx_ctrl.RxD == 213)
            sMAC_rx_ctrl.Next_state = State_SFD;

          else
            if(sMAC_rx_ctrl.RxD == 85)
              sMAC_rx_ctrl.Next_state = sMAC_rx_ctrl.Current_state;

            else
              sMAC_rx_ctrl.Next_state = State_drop;

    else
      if(sMAC_rx_ctrl.Current_state == State_SFD)
        if(!sMAC_rx_ctrl.Crs_dv)
          sMAC_rx_ctrl.Next_state = State_ErrEnd;

        else
          if(sMAC_rx_ctrl.RxErr)
            sMAC_rx_ctrl.Next_state = State_drop;

          else
            sMAC_rx_ctrl.Next_state = State_data;

      else
        if(sMAC_rx_ctrl.Current_state == State_data)
          if(!sMAC_rx_ctrl.Crs_dv && !sMAC_rx_ctrl.Too_short && !sMAC_rx_ctrl.Too_long)
            sMAC_rx_ctrl.Next_state = State_checkCRC;

          else
            if(!sMAC_rx_ctrl.Crs_dv && (sMAC_rx_ctrl.Too_short || sMAC_rx_ctrl.Too_long))
              sMAC_rx_ctrl.Next_state = State_ErrEnd;

            else
              if(Fifo_full)
                sMAC_rx_ctrl.Next_state = State_FFFullErrEnd;

              else
                if(sMAC_rx_ctrl.RxErr || MAC_rx_add_chk_err || sMAC_rx_ctrl.Too_long || broadcast_drop)
                  sMAC_rx_ctrl.Next_state = State_drop;

                else
                  sMAC_rx_ctrl.Next_state = State_data;

        else
          if(sMAC_rx_ctrl.Current_state == State_checkCRC)
            if(CRC_err)
              sMAC_rx_ctrl.Next_state = State_CRCErrEnd;

            else
              sMAC_rx_ctrl.Next_state = State_OkEnd;

          else
            if(sMAC_rx_ctrl.Current_state == State_drop)
              if(!sMAC_rx_ctrl.Crs_dv)
                sMAC_rx_ctrl.Next_state = State_ErrEnd;

              else
                sMAC_rx_ctrl.Next_state = sMAC_rx_ctrl.Current_state;

            else
              if(sMAC_rx_ctrl.Current_state == State_OkEnd)
                sMAC_rx_ctrl.Next_state = State_IFG;

              else
                if(sMAC_rx_ctrl.Current_state == State_ErrEnd)
                  sMAC_rx_ctrl.Next_state = State_IFG;

                else
                  if(sMAC_rx_ctrl.Current_state == State_CRCErrEnd)
                    sMAC_rx_ctrl.Next_state = State_IFG;

                  else
                    if(sMAC_rx_ctrl.Current_state == State_FFFullDrop)
                      if(!sMAC_rx_ctrl.Crs_dv)
                        sMAC_rx_ctrl.Next_state = State_IFG;

                      else
                        sMAC_rx_ctrl.Next_state = sMAC_rx_ctrl.Current_state;

                    else
                      if(sMAC_rx_ctrl.Current_state == State_FFFullErrEnd)
                        sMAC_rx_ctrl.Next_state = State_FFFullDrop;

                      else
                        if(sMAC_rx_ctrl.Current_state == State_IFG)
                          if((unsigned int)sMAC_rx_ctrl.IFG_counter == (unsigned int)RX_IFG_SET - 4)
                            sMAC_rx_ctrl.Next_state = State_idle;

                          else
                            sMAC_rx_ctrl.Next_state = sMAC_rx_ctrl.Current_state;

                        else
                          if(TRUE)
                            sMAC_rx_ctrl.Next_state = State_idle;

  if(Reset)
    tmp10 = 0;

  else
    if(sMAC_rx_ctrl.Current_state != State_IFG)
      tmp11 = 0;

    else
      tmp12 = (unsigned char)(unsigned int)sMAC_rx_ctrl.IFG_counter + 1;
  *Fifo_data = sMAC_rx_ctrl.RxD_dl1;
  *Fifo_data = sMAC_rx_ctrl.RxD_dl1;
  if(sMAC_rx_ctrl.Current_state == State_data)
  {
    sMAC_rx_ctrl.Fifo_data_en = TRUE;
    *Fifo_data_en = TRUE;
  }

  else
  {
    sMAC_rx_ctrl.Fifo_data_en = FALSE;
    *Fifo_data_en = FALSE;
  }
  if(sMAC_rx_ctrl.Current_state == State_ErrEnd || sMAC_rx_ctrl.Current_state == State_OkEnd || sMAC_rx_ctrl.Current_state == State_CRCErrEnd || sMAC_rx_ctrl.Current_state == State_FFFullErrEnd)
  {
    sMAC_rx_ctrl.Fifo_data_end = TRUE;
    *Fifo_data_end = TRUE;
  }

  else
  {
    sMAC_rx_ctrl.Fifo_data_end = FALSE;
    *Fifo_data_end = FALSE;
  }
  if(sMAC_rx_ctrl.Current_state == State_ErrEnd || sMAC_rx_ctrl.Current_state == State_CRCErrEnd || sMAC_rx_ctrl.Current_state == State_FFFullErrEnd)
  {
    sMAC_rx_ctrl.Fifo_data_err = TRUE;
    *Fifo_data_err = TRUE;
  }

  else
  {
    sMAC_rx_ctrl.Fifo_data_err = FALSE;
    *Fifo_data_err = FALSE;
  }
  if(sMAC_rx_ctrl.Current_state == State_data)
  {
    sMAC_rx_ctrl.CRC_en = TRUE;
    *CRC_en = TRUE;
  }

  else
  {
    sMAC_rx_ctrl.CRC_en = FALSE;
    *CRC_en = FALSE;
  }
  if(sMAC_rx_ctrl.Current_state == State_SFD)
  {
    sMAC_rx_ctrl.CRC_init = TRUE;
    *CRC_init = TRUE;
  }

  else
  {
    sMAC_rx_ctrl.CRC_init = FALSE;
    *CRC_init = FALSE;
  }
  if(Reset)
    tmp13 = 0;

  else
    if(sMAC_rx_ctrl.Current_state == State_SFD)
      tmp14 = 1;

    else
      if(sMAC_rx_ctrl.Current_state == State_data)
        tmp15 = sMAC_rx_ctrl.Frame_length_counter + 1;

  if(sMAC_rx_ctrl.Frame_length_counter < (unsigned short int)RX_MIN_LENGTH)
    sMAC_rx_ctrl.Too_short = TRUE;

  else
    sMAC_rx_ctrl.Too_short = FALSE;
  if(sMAC_rx_ctrl.Frame_length_counter > RX_MAX_LENGTH)
    sMAC_rx_ctrl.Too_long = TRUE;

  else
    sMAC_rx_ctrl.Too_long = FALSE;
  *Rx_pkt_length_rmon = sMAC_rx_ctrl.Frame_length_counter - 1;
  *Rx_pkt_length_rmon = sMAC_rx_ctrl.Frame_length_counter - 1;
  if(Reset)
    tmp16 = FALSE;

  else
    if(sMAC_rx_ctrl.Current_state == State_OkEnd || sMAC_rx_ctrl.Current_state == State_ErrEnd || sMAC_rx_ctrl.Current_state == State_CRCErrEnd || sMAC_rx_ctrl.Current_state == State_FFFullErrEnd)
      tmp17 = TRUE;

    else
      tmp18 = FALSE;
  if(Reset)
    tmp19 = FALSE;

  else
    tmp20 = sMAC_rx_ctrl.Rx_apply_rmon_tmp;
  if(Reset)
    tmp21 = FALSE;

  else
    if(sMAC_rx_ctrl.Current_state == State_OkEnd || sMAC_rx_ctrl.Current_state == State_ErrEnd || sMAC_rx_ctrl.Current_state == State_CRCErrEnd || sMAC_rx_ctrl.Current_state == State_FFFullErrEnd)
      tmp22 = TRUE;

    else
      if(sMAC_rx_ctrl.Rx_apply_rmon_tmp_pl1)
        tmp23 = FALSE;

  if(Reset)
    tmp24 = 0;

  else
    if(sMAC_rx_ctrl.Current_state == State_CRCErrEnd)
      tmp25 = 1;

    else
      if(sMAC_rx_ctrl.Current_state == State_FFFullErrEnd)
        tmp26 = 2;

      else
        if(sMAC_rx_ctrl.Current_state == State_ErrEnd)
          tmp27 = 3;

        else
          if(sMAC_rx_ctrl.Current_state == State_OkEnd)
            tmp28 = 4;

  if(Reset)
    tmp29 = 0;

  else
    if(sMAC_rx_ctrl.Current_state == State_OkEnd && sMAC_rx_ctrl.pause_frame_ptr)
      tmp30 = 4;

    else
      if(sMAC_rx_ctrl.Current_state == State_SFD && sMAC_rx_ctrl.Next_state == State_data)
        tmp31 = (0x0 | MRxD >> 6 & 3);

  if(Reset)
    tmp32 = FALSE;

  else
    if(sMAC_rx_ctrl.Current_state == State_IFG)
      tmp33 = FALSE;

    else
      if(sMAC_rx_ctrl.Current_state == State_SFD && sMAC_rx_ctrl.Next_state == State_data && MRxD >> 6 & 3 == 3)
        tmp34 = TRUE;

  if((unsigned int)sMAC_rx_ctrl.Frame_length_counter >= 1 && (unsigned int)sMAC_rx_ctrl.Frame_length_counter <= 6)
    tmp35 = sMAC_rx_ctrl.Fifo_data_en;

  else
    tmp36 = FALSE;
  if(Reset)
    tmp37 = Pause_idle;

  else
    tmp38 = sMAC_rx_ctrl.Pause_next;
  if(sMAC_rx_ctrl.Pause_current == Pause_idle)
    if(sMAC_rx_ctrl.Current_state == State_SFD)
      sMAC_rx_ctrl.Pause_next = Pause_pre_syn;

    else
      sMAC_rx_ctrl.Pause_next = sMAC_rx_ctrl.Pause_current;

  else
    if(sMAC_rx_ctrl.Pause_current == Pause_pre_syn)
    {
      if(sMAC_rx_ctrl.Frame_length_counter == 1)
        if(sMAC_rx_ctrl.RxD_dl1 == 1)
          sMAC_rx_ctrl.Pause_next = sMAC_rx_ctrl.Pause_current;

        else
          sMAC_rx_ctrl.Pause_next = Pause_idle;

      else
        if(sMAC_rx_ctrl.Frame_length_counter == 2)
          if(sMAC_rx_ctrl.RxD_dl1 == 128)
            sMAC_rx_ctrl.Pause_next = sMAC_rx_ctrl.Pause_current;

          else
            sMAC_rx_ctrl.Pause_next = Pause_idle;

        else
          if(sMAC_rx_ctrl.Frame_length_counter == 3)
            if(sMAC_rx_ctrl.RxD_dl1 == 194)
              sMAC_rx_ctrl.Pause_next = sMAC_rx_ctrl.Pause_current;

            else
              sMAC_rx_ctrl.Pause_next = Pause_idle;

          else
            if(sMAC_rx_ctrl.Frame_length_counter == 4)
              if(sMAC_rx_ctrl.RxD_dl1 == 0)
                sMAC_rx_ctrl.Pause_next = sMAC_rx_ctrl.Pause_current;

              else
                sMAC_rx_ctrl.Pause_next = Pause_idle;

            else
              if(sMAC_rx_ctrl.Frame_length_counter == 5)
                if(sMAC_rx_ctrl.RxD_dl1 == 0)
                  sMAC_rx_ctrl.Pause_next = sMAC_rx_ctrl.Pause_current;

                else
                  sMAC_rx_ctrl.Pause_next = Pause_idle;

              else
                if(sMAC_rx_ctrl.Frame_length_counter == 6)
                  if(sMAC_rx_ctrl.RxD_dl1 == 1)
                    sMAC_rx_ctrl.Pause_next = sMAC_rx_ctrl.Pause_current;

                  else
                    sMAC_rx_ctrl.Pause_next = Pause_idle;

                else
                  if(sMAC_rx_ctrl.Frame_length_counter == 13)
                    if(sMAC_rx_ctrl.RxD_dl1 == 136)
                      sMAC_rx_ctrl.Pause_next = sMAC_rx_ctrl.Pause_current;

                    else
                      sMAC_rx_ctrl.Pause_next = Pause_idle;

                  else
                    if(sMAC_rx_ctrl.Frame_length_counter == 14)
                      if(sMAC_rx_ctrl.RxD_dl1 == 8)
                        sMAC_rx_ctrl.Pause_next = sMAC_rx_ctrl.Pause_current;

                      else
                        sMAC_rx_ctrl.Pause_next = Pause_idle;

                    else
                      if(sMAC_rx_ctrl.Frame_length_counter == 15)
                        if(sMAC_rx_ctrl.RxD_dl1 == 0)
                          sMAC_rx_ctrl.Pause_next = sMAC_rx_ctrl.Pause_current;

                        else
                          sMAC_rx_ctrl.Pause_next = Pause_idle;

                      else
                        if(sMAC_rx_ctrl.Frame_length_counter == 16)
                          if(sMAC_rx_ctrl.RxD_dl1 == 1)
                            sMAC_rx_ctrl.Pause_next = Pause_quanta_hi;

                          else
                            sMAC_rx_ctrl.Pause_next = Pause_idle;

                        else
                          if(TRUE)
                            sMAC_rx_ctrl.Pause_next = sMAC_rx_ctrl.Pause_current;

    }

    else
      if(sMAC_rx_ctrl.Pause_current == Pause_quanta_hi)
        sMAC_rx_ctrl.Pause_next = Pause_quanta_lo;

      else
        if(sMAC_rx_ctrl.Pause_current == Pause_quanta_lo)
          sMAC_rx_ctrl.Pause_next = Pause_syn;

        else
          if(sMAC_rx_ctrl.Pause_current == Pause_syn)
            if(sMAC_rx_ctrl.Current_state == State_IFG)
              sMAC_rx_ctrl.Pause_next = Pause_idle;

            else
              sMAC_rx_ctrl.Pause_next = sMAC_rx_ctrl.Pause_current;

          else
            if(TRUE)
              sMAC_rx_ctrl.Pause_next = Pause_idle;

  if(Reset)
    tmp39 = 0;

  else
    if(sMAC_rx_ctrl.Pause_current == Pause_quanta_hi)
      tmp40 = sMAC_rx_ctrl.RxD_dl1;

  if(Reset)
    tmp41 = 0;

  else
    if(sMAC_rx_ctrl.Pause_current == Pause_quanta_lo)
      tmp42 = (sMAC_rx_ctrl.pause_quanta_h & 0xFF << 8) | (sMAC_rx_ctrl.RxD_dl1 & 0xFF);

  if(Reset)
    tmp43 = FALSE;

  else
    if(sMAC_rx_ctrl.Current_state == State_OkEnd && sMAC_rx_ctrl.Pause_current == Pause_syn)
      tmp44 = TRUE;

    else
      tmp45 = FALSE;
  if(Reset)
    tmp46 = FALSE;

  else
    if(sMAC_rx_ctrl.Current_state == State_OkEnd && sMAC_rx_ctrl.Pause_current == Pause_syn || sMAC_rx_ctrl.pause_quanta_val_tmp)
      tmp47 = TRUE;

    else
      tmp48 = FALSE;
  if(Reset)
    tmp49 = FALSE;

  else
    if(sMAC_rx_ctrl.Pause_current == Pause_syn)
      tmp50 = TRUE;

    else
      tmp51 = FALSE;
  if(Reset)
  {
    sMAC_rx_ctrl.Crs_dv = tmp0;
    sMAC_rx_ctrl.RxD = tmp1;
    sMAC_rx_ctrl.RxErr = tmp2;
  }

  else
  {
    sMAC_rx_ctrl.Crs_dv = tmp3;
    sMAC_rx_ctrl.RxD = tmp4;
    sMAC_rx_ctrl.RxErr = tmp5;
  }
  if(Reset)
    sMAC_rx_ctrl.RxD_dl1 = tmp6;

  else
    sMAC_rx_ctrl.RxD_dl1 = tmp7;
  if(Reset)
    sMAC_rx_ctrl.Current_state = tmp8;

  else
    sMAC_rx_ctrl.Current_state = tmp9;
  if(Reset)
    sMAC_rx_ctrl.IFG_counter = tmp10;

  else
    if(sMAC_rx_ctrl.Current_state != State_IFG)
      sMAC_rx_ctrl.IFG_counter = tmp11;

    else
      sMAC_rx_ctrl.IFG_counter = tmp12;
  if(Reset)
    sMAC_rx_ctrl.Frame_length_counter = tmp13;

  else
    if(sMAC_rx_ctrl.Current_state == State_SFD)
      sMAC_rx_ctrl.Frame_length_counter = tmp14;

    else
      if(sMAC_rx_ctrl.Current_state == State_data)
        sMAC_rx_ctrl.Frame_length_counter = tmp15;

  if(Reset)
    sMAC_rx_ctrl.Rx_apply_rmon_tmp = tmp16;

  else
    if(sMAC_rx_ctrl.Current_state == State_OkEnd || sMAC_rx_ctrl.Current_state == State_ErrEnd || sMAC_rx_ctrl.Current_state == State_CRCErrEnd || sMAC_rx_ctrl.Current_state == State_FFFullErrEnd)
      sMAC_rx_ctrl.Rx_apply_rmon_tmp = tmp17;

    else
      sMAC_rx_ctrl.Rx_apply_rmon_tmp = tmp18;
  if(Reset)
    sMAC_rx_ctrl.Rx_apply_rmon_tmp_pl1 = tmp19;

  else
    sMAC_rx_ctrl.Rx_apply_rmon_tmp_pl1 = tmp20;
  if(Reset)
  {
    sMAC_rx_ctrl.Rx_apply_rmon = tmp21;
    *Rx_apply_rmon = tmp21;
  }

  else
    if(sMAC_rx_ctrl.Current_state == State_OkEnd || sMAC_rx_ctrl.Current_state == State_ErrEnd || sMAC_rx_ctrl.Current_state == State_CRCErrEnd || sMAC_rx_ctrl.Current_state == State_FFFullErrEnd)
    {
      sMAC_rx_ctrl.Rx_apply_rmon = tmp22;
      *Rx_apply_rmon = tmp22;
    }

    else
      if(sMAC_rx_ctrl.Rx_apply_rmon_tmp_pl1)
      {
        sMAC_rx_ctrl.Rx_apply_rmon = tmp23;
        *Rx_apply_rmon = tmp23;
      }

  if(Reset)
  {
    sMAC_rx_ctrl.Rx_pkt_err_type_rmon = tmp24;
    *Rx_pkt_err_type_rmon = tmp24;
  }

  else
    if(sMAC_rx_ctrl.Current_state == State_CRCErrEnd)
    {
      sMAC_rx_ctrl.Rx_pkt_err_type_rmon = tmp25;
      *Rx_pkt_err_type_rmon = tmp25;
    }

    else
      if(sMAC_rx_ctrl.Current_state == State_FFFullErrEnd)
      {
        sMAC_rx_ctrl.Rx_pkt_err_type_rmon = tmp26;
        *Rx_pkt_err_type_rmon = tmp26;
      }

      else
        if(sMAC_rx_ctrl.Current_state == State_ErrEnd)
        {
          sMAC_rx_ctrl.Rx_pkt_err_type_rmon = tmp27;
          *Rx_pkt_err_type_rmon = tmp27;
        }

        else
          if(sMAC_rx_ctrl.Current_state == State_OkEnd)
          {
            sMAC_rx_ctrl.Rx_pkt_err_type_rmon = tmp28;
            *Rx_pkt_err_type_rmon = tmp28;
          }

  if(Reset)
  {
    sMAC_rx_ctrl.Rx_pkt_type_rmon = tmp29;
    *Rx_pkt_type_rmon = tmp29;
  }

  else
    if(sMAC_rx_ctrl.Current_state == State_OkEnd && sMAC_rx_ctrl.pause_frame_ptr)
    {
      sMAC_rx_ctrl.Rx_pkt_type_rmon = tmp30;
      *Rx_pkt_type_rmon = tmp30;
    }

    else
      if(sMAC_rx_ctrl.Current_state == State_SFD && sMAC_rx_ctrl.Next_state == State_data)
      {
        sMAC_rx_ctrl.Rx_pkt_type_rmon = tmp31;
        *Rx_pkt_type_rmon = tmp31;
      }

  if(Reset)
  {
    sMAC_rx_ctrl.broadcast_ptr = tmp32;
    *broadcast_ptr = tmp32;
  }

  else
    if(sMAC_rx_ctrl.Current_state == State_IFG)
    {
      sMAC_rx_ctrl.broadcast_ptr = tmp33;
      *broadcast_ptr = tmp33;
    }

    else
      if(sMAC_rx_ctrl.Current_state == State_SFD && sMAC_rx_ctrl.Next_state == State_data && MRxD >> 6 & 3 == 3)
      {
        sMAC_rx_ctrl.broadcast_ptr = tmp34;
        *broadcast_ptr = tmp34;
      }

  if((unsigned int)sMAC_rx_ctrl.Frame_length_counter >= 1 && (unsigned int)sMAC_rx_ctrl.Frame_length_counter <= 6)
  {
    sMAC_rx_ctrl.MAC_add_en = tmp35;
    *MAC_add_en = tmp35;
  }

  else
  {
    sMAC_rx_ctrl.MAC_add_en = tmp36;
    *MAC_add_en = tmp36;
  }
  if(Reset)
    sMAC_rx_ctrl.Pause_current = tmp37;

  else
    sMAC_rx_ctrl.Pause_current = tmp38;
  if(Reset)
    sMAC_rx_ctrl.pause_quanta_h = tmp39;

  else
    if(sMAC_rx_ctrl.Pause_current == Pause_quanta_hi)
      sMAC_rx_ctrl.pause_quanta_h = tmp40;

  if(Reset)
  {
    sMAC_rx_ctrl.pause_quanta = tmp41;
    *pause_quanta = tmp41;
  }

  else
    if(sMAC_rx_ctrl.Pause_current == Pause_quanta_lo)
    {
      sMAC_rx_ctrl.pause_quanta = tmp42;
      *pause_quanta = tmp42;
    }

  if(Reset)
    sMAC_rx_ctrl.pause_quanta_val_tmp = tmp43;

  else
    if(sMAC_rx_ctrl.Current_state == State_OkEnd && sMAC_rx_ctrl.Pause_current == Pause_syn)
      sMAC_rx_ctrl.pause_quanta_val_tmp = tmp44;

    else
      sMAC_rx_ctrl.pause_quanta_val_tmp = tmp45;
  if(Reset)
  {
    sMAC_rx_ctrl.pause_quanta_val = tmp46;
    *pause_quanta_val = tmp46;
  }

  else
    if(sMAC_rx_ctrl.Current_state == State_OkEnd && sMAC_rx_ctrl.Pause_current == Pause_syn || sMAC_rx_ctrl.pause_quanta_val_tmp)
    {
      sMAC_rx_ctrl.pause_quanta_val = tmp47;
      *pause_quanta_val = tmp47;
    }

    else
    {
      sMAC_rx_ctrl.pause_quanta_val = tmp48;
      *pause_quanta_val = tmp48;
    }
  if(Reset)
    sMAC_rx_ctrl.pause_frame_ptr = tmp49;

  else
    if(sMAC_rx_ctrl.Pause_current == Pause_syn)
      sMAC_rx_ctrl.pause_frame_ptr = tmp50;

    else
      sMAC_rx_ctrl.pause_frame_ptr = tmp51;
}

/*
void main() {
_Bool Reset;
_Bool Clk;
_Bool MCrs_dv;
unsigned char MRxD;
_Bool MRxErr;
_Bool CRC_en;
_Bool CRC_init;
_Bool CRC_err;
_Bool MAC_add_en;
_Bool MAC_rx_add_chk_err;
_Bool broadcast_ptr;
_Bool broadcast_drop;
unsigned short int pause_quanta;
_Bool pause_quanta_val;
unsigned char Fifo_data;
_Bool Fifo_data_en;
_Bool Fifo_data_err;
_Bool Fifo_data_end;
_Bool Fifo_full;
unsigned short int Rx_pkt_length_rmon;
_Bool Rx_apply_rmon;
unsigned char Rx_pkt_err_type_rmon;
unsigned char Rx_pkt_type_rmon;
unsigned char RX_IFG_SET;
unsigned short int RX_MAX_LENGTH;
unsigned char RX_MIN_LENGTH;
while(1) {
MAC_rx_ctrl(Reset, Clk, MCrs_dv, MRxD, MRxErr, &CRC_en, &CRC_init, CRC_err, &MAC_add_en, MAC_rx_add_chk_err, &broadcast_ptr, broadcast_drop, &pause_quanta, &pause_quanta_val, &Fifo_data, &Fifo_data_en, &Fifo_data_err, &Fifo_data_end, Fifo_full, &Rx_pkt_length_rmon, &Rx_apply_rmon, &Rx_pkt_err_type_rmon, &Rx_pkt_type_rmon, RX_IFG_SET, RX_MAX_LENGTH, RX_MIN_LENGTH);
}
}*/
