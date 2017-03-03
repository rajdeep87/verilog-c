//#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct state_elements_MAC_tx_ctrl{
_Bool Fifo_rd_finish;
_Bool Fifo_rd_retry;
unsigned char TxD;
_Bool TxEn;
unsigned char Current_state;
_Bool MAC_tx_addr_init;
unsigned char Next_state;
unsigned char IFG_counter;
_Bool MAC_tx_addr_rd;
unsigned char Preamble_counter;
unsigned char Tx_pkt_type_rmon;
unsigned char TxD_tmp;
_Bool TxEn_tmp;
_Bool Tx_apply_rmon_tmp;
unsigned short int Tx_pkt_length_rmon;
_Bool Tx_apply_rmon_tmp_pl1;
_Bool Tx_apply_rmon;
unsigned char Tx_pkt_err_type_rmon;
_Bool MAC_header_slot;
_Bool MAC_header_slot_tmp;
_Bool Src_MAC_ptr;
unsigned char IPLengthCounter;
unsigned char PADCounter;
unsigned char JamCounter;
_Bool PktDrpEvenPtr;
_Bool CRC_init;
unsigned char pause_counter;
_Bool pause_frame_send_en_dl1;
unsigned short int pause_quanta_set_dl1;
_Bool Data_en;
_Bool CRC_rd;
_Bool Random_init;
unsigned char RetryCnt;
_Bool pause_quanta_sub;
_Bool xoff_gen_complete;
_Bool xon_gen_complete;
_Bool Fifo_rd;
};
struct state_elements_MAC_tx_ctrl  sMAC_tx_ctrl;

void MAC_tx_ctrl(_Bool Reset, _Bool Clk, _Bool *CRC_init, unsigned char *Frame_data, _Bool *Data_en, _Bool *CRC_rd, _Bool CRC_end, unsigned char CRC_out, _Bool *Random_init, unsigned char *RetryCnt, _Bool Random_time_meet, _Bool pause_apply, _Bool *pause_quanta_sub, _Bool xoff_gen, _Bool *xoff_gen_complete, _Bool xon_gen, _Bool *xon_gen_complete, unsigned char Fifo_data, _Bool *Fifo_rd, _Bool Fifo_eop, _Bool Fifo_da, _Bool *Fifo_rd_finish, _Bool *Fifo_rd_retry, _Bool Fifo_ra, _Bool Fifo_data_err_empty, _Bool Fifo_data_err_full, unsigned char *TxD, _Bool *TxEn, _Bool CRS, _Bool *MAC_tx_addr_init, _Bool *MAC_tx_addr_rd, unsigned char MAC_tx_addr_data, unsigned char *Tx_pkt_type_rmon, unsigned short int *Tx_pkt_length_rmon, _Bool *Tx_apply_rmon, unsigned char *Tx_pkt_err_type_rmon, _Bool pause_frame_send_en, unsigned short int pause_quanta_set, _Bool MAC_tx_add_en, _Bool FullDuplex, unsigned char MaxRetry, unsigned char IFGset)
{
  _Bool tmp68;
  _Bool tmp67;
  _Bool tmp66;
  _Bool tmp65;
  _Bool tmp64;
  _Bool tmp63;
  _Bool tmp62;
  _Bool tmp61;
  _Bool tmp60;
  _Bool tmp59;
  _Bool tmp58;
  _Bool tmp57;
  unsigned char tmp56;
  unsigned char tmp55;
  unsigned char tmp54;
  _Bool tmp53;
  _Bool tmp52;
  _Bool tmp51;
  _Bool tmp50;
  _Bool tmp49;
  unsigned char tmp48;
  unsigned char tmp47;
  unsigned char tmp46;
  unsigned char tmp45;
  unsigned char tmp44;
  _Bool tmp43;
  _Bool tmp42;
  _Bool tmp41;
  _Bool tmp40;
  _Bool tmp39;
  _Bool tmp38;
  _Bool tmp37;
  _Bool tmp36;
  unsigned short int tmp35;
  unsigned short int tmp34;
  unsigned short int tmp33;
  _Bool tmp32;
  unsigned char tmp31;
  _Bool tmp30;
  unsigned char tmp29;
  _Bool tmp28;
  _Bool tmp27;
  unsigned char tmp26;
  unsigned char tmp25;
  unsigned char tmp24;
  unsigned char tmp23;
  unsigned char tmp22;
  unsigned char tmp21;
  unsigned char tmp20;
  unsigned char tmp19;
  unsigned char tmp18;
  unsigned char tmp17;
  unsigned char tmp16;
  unsigned char tmp15;
  unsigned char tmp14;
  unsigned char tmp13;
  unsigned char tmp12;
  unsigned char tmp11;
  unsigned char tmp10;
  unsigned char tmp9;
  unsigned char tmp8;
  unsigned char tmp7;
  unsigned char tmp6;
  unsigned char tmp5;
  unsigned char tmp4;
  unsigned short int tmp3;
  _Bool tmp2;
  unsigned short int tmp1;
  _Bool tmp0;
  int StateIdle;
  StateIdle = 0;
  int StatePreamble;
  StatePreamble = 1;
  int StateSFD;
  StateSFD = 2;
  int StateData;
  StateData = 3;
  int StatePause;
  StatePause = 4;
  int StatePAD;
  StatePAD = 5;
  int StateFCS;
  StateFCS = 6;
  int StateIFG;
  StateIFG = 7;
  int StateJam;
  StateJam = 8;
  int StateBackOff;
  StateBackOff = 9;
  int StateJamDrop;
  StateJamDrop = 10;
  int StateFFEmptyDrop;
  StateFFEmptyDrop = 11;
  int StateSwitchNext;
  StateSwitchNext = 12;
  int StateDefer;
  StateDefer = 13;
  int StateSendPauseFrame;
  StateSendPauseFrame = 14;
  _Bool Collision;
  if(Reset)
  {
    tmp0 = FALSE;
    tmp1 = 0;
  }

  else
  {
    tmp2 = pause_frame_send_en;
    tmp3 = pause_quanta_set;
  }
  Collision = sMAC_tx_ctrl.TxEn && CRS;
  if(Reset)
    tmp4 = 0;

  else
    if(sMAC_tx_ctrl.Current_state != StatePause)
      tmp5 = 0;

    else
      tmp6 = (unsigned char)(unsigned int)sMAC_tx_ctrl.pause_counter + 1;
  if(Reset)
    tmp7 = 0;

  else
    if(sMAC_tx_ctrl.Current_state == StateDefer)
      tmp8 = 0;

    else
      if(sMAC_tx_ctrl.IPLengthCounter != 255 && (sMAC_tx_ctrl.Current_state == StateData || sMAC_tx_ctrl.Current_state == StateSendPauseFrame || sMAC_tx_ctrl.Current_state == StatePAD))
        tmp9 = (unsigned char)(unsigned int)sMAC_tx_ctrl.IPLengthCounter + 1;

  if(Reset)
    tmp10 = 0;

  else
    if(sMAC_tx_ctrl.Current_state != StatePAD)
      tmp11 = 0;

    else
      tmp12 = (unsigned char)(unsigned int)sMAC_tx_ctrl.PADCounter + 1;
  if(Reset)
    tmp13 = StateDefer;

  else
    tmp14 = sMAC_tx_ctrl.Next_state;
  if(sMAC_tx_ctrl.Current_state == StateDefer)
    if(FullDuplex || !FullDuplex && !CRS)
      sMAC_tx_ctrl.Next_state = StateIFG;

    else
      sMAC_tx_ctrl.Next_state = sMAC_tx_ctrl.Current_state;

  else
    if(sMAC_tx_ctrl.Current_state == StateIFG)
      if(!FullDuplex && CRS)
        sMAC_tx_ctrl.Next_state = StateDefer;

      else
        if(FullDuplex && (unsigned int)sMAC_tx_ctrl.IFG_counter == (unsigned int)IFGset - 4 || !FullDuplex && !CRS && (unsigned int)sMAC_tx_ctrl.IFG_counter == (unsigned int)IFGset - 4)
          sMAC_tx_ctrl.Next_state = StateIdle;

        else
          sMAC_tx_ctrl.Next_state = sMAC_tx_ctrl.Current_state;

    else
      if(sMAC_tx_ctrl.Current_state == StateIdle)
        if(!FullDuplex && CRS)
          sMAC_tx_ctrl.Next_state = StateDefer;

        else
          if(pause_apply)
            sMAC_tx_ctrl.Next_state = StatePause;

          else
            if(FullDuplex && Fifo_ra || !FullDuplex && !CRS && Fifo_ra || sMAC_tx_ctrl.pause_frame_send_en_dl1 && (xoff_gen || xon_gen))
              sMAC_tx_ctrl.Next_state = StatePreamble;

            else
              sMAC_tx_ctrl.Next_state = sMAC_tx_ctrl.Current_state;

      else
        if(sMAC_tx_ctrl.Current_state == StatePause)
          if((unsigned int)sMAC_tx_ctrl.pause_counter == 512 / 8)
            sMAC_tx_ctrl.Next_state = StateDefer;

          else
            sMAC_tx_ctrl.Next_state = sMAC_tx_ctrl.Current_state;

        else
          if(sMAC_tx_ctrl.Current_state == StatePreamble)
            if(!FullDuplex && Collision)
              sMAC_tx_ctrl.Next_state = StateJam;

            else
              if(FullDuplex && (unsigned int)sMAC_tx_ctrl.Preamble_counter == 6 || !FullDuplex && !Collision && (unsigned int)sMAC_tx_ctrl.Preamble_counter == 6)
                sMAC_tx_ctrl.Next_state = StateSFD;

              else
                sMAC_tx_ctrl.Next_state = sMAC_tx_ctrl.Current_state;

          else
            if(sMAC_tx_ctrl.Current_state == StateSFD)
              if(!FullDuplex && Collision)
                sMAC_tx_ctrl.Next_state = StateJam;

              else
                if(sMAC_tx_ctrl.pause_frame_send_en_dl1 && (xoff_gen || xon_gen))
                  sMAC_tx_ctrl.Next_state = StateSendPauseFrame;

                else
                  sMAC_tx_ctrl.Next_state = StateData;

            else
              if(sMAC_tx_ctrl.Current_state == StateSendPauseFrame)
                if((unsigned int)sMAC_tx_ctrl.IPLengthCounter == 17)
                  sMAC_tx_ctrl.Next_state = StatePAD;

                else
                  sMAC_tx_ctrl.Next_state = sMAC_tx_ctrl.Current_state;

              else
                if(sMAC_tx_ctrl.Current_state == StateData)
                  if(!FullDuplex && Collision)
                    sMAC_tx_ctrl.Next_state = StateJam;

                  else
                    if(Fifo_data_err_empty)
                      sMAC_tx_ctrl.Next_state = StateFFEmptyDrop;

                    else
                      if(Fifo_eop && (unsigned int)sMAC_tx_ctrl.IPLengthCounter >= 59)
                        sMAC_tx_ctrl.Next_state = StateFCS;

                      else
                        if(Fifo_eop)
                          sMAC_tx_ctrl.Next_state = StatePAD;

                        else
                          sMAC_tx_ctrl.Next_state = StateData;

                else
                  if(sMAC_tx_ctrl.Current_state == StatePAD)
                    if(!FullDuplex && Collision)
                      sMAC_tx_ctrl.Next_state = StateJam;

                    else
                      if((unsigned int)sMAC_tx_ctrl.IPLengthCounter >= 59)
                        sMAC_tx_ctrl.Next_state = StateFCS;

                      else
                        sMAC_tx_ctrl.Next_state = sMAC_tx_ctrl.Current_state;

                  else
                    if(sMAC_tx_ctrl.Current_state == StateJam)
                      if(sMAC_tx_ctrl.RetryCnt <= MaxRetry && (unsigned int)sMAC_tx_ctrl.JamCounter == 16)
                        sMAC_tx_ctrl.Next_state = StateBackOff;

                      else
                        if(sMAC_tx_ctrl.RetryCnt > MaxRetry)
                          sMAC_tx_ctrl.Next_state = StateJamDrop;

                        else
                          sMAC_tx_ctrl.Next_state = sMAC_tx_ctrl.Current_state;

                    else
                      if(sMAC_tx_ctrl.Current_state == StateBackOff)
                        if(Random_time_meet)
                          sMAC_tx_ctrl.Next_state = StateDefer;

                        else
                          sMAC_tx_ctrl.Next_state = sMAC_tx_ctrl.Current_state;

                      else
                        if(sMAC_tx_ctrl.Current_state == StateFCS)
                          if(!FullDuplex && Collision)
                            sMAC_tx_ctrl.Next_state = StateJam;

                          else
                            if(CRC_end)
                              sMAC_tx_ctrl.Next_state = StateSwitchNext;

                            else
                              sMAC_tx_ctrl.Next_state = sMAC_tx_ctrl.Current_state;

                        else
                          if(sMAC_tx_ctrl.Current_state == StateFFEmptyDrop)
                            if(Fifo_eop)
                              sMAC_tx_ctrl.Next_state = StateSwitchNext;

                            else
                              sMAC_tx_ctrl.Next_state = sMAC_tx_ctrl.Current_state;

                          else
                            if(sMAC_tx_ctrl.Current_state == StateJamDrop)
                              if(Fifo_eop)
                                sMAC_tx_ctrl.Next_state = StateSwitchNext;

                              else
                                sMAC_tx_ctrl.Next_state = sMAC_tx_ctrl.Current_state;

                            else
                              if(sMAC_tx_ctrl.Current_state == StateSwitchNext)
                                sMAC_tx_ctrl.Next_state = StateDefer;

                              else
                                if(TRUE)
                                  sMAC_tx_ctrl.Next_state = StateDefer;

  if(Reset)
    tmp15 = 0;

  else
    if(sMAC_tx_ctrl.Current_state != StateJam)
      tmp16 = 0;

    else
      if(sMAC_tx_ctrl.Current_state == StateJam)
        tmp17 = (unsigned char)(unsigned int)sMAC_tx_ctrl.JamCounter + 1;

  if(Reset)
    tmp18 = 0;

  else
    if(sMAC_tx_ctrl.Current_state == StateSwitchNext)
      tmp19 = 0;

    else
      if(sMAC_tx_ctrl.Current_state == StateJam && sMAC_tx_ctrl.Next_state == StateBackOff)
        tmp20 = (unsigned char)(unsigned int)sMAC_tx_ctrl.RetryCnt + 1;

  if(Reset)
    tmp21 = 0;

  else
    if(sMAC_tx_ctrl.Current_state != StateIFG)
      tmp22 = 0;

    else
      tmp23 = (unsigned char)(unsigned int)sMAC_tx_ctrl.IFG_counter + 1;
  if(Reset)
    tmp24 = 0;

  else
    if(sMAC_tx_ctrl.Current_state != StatePreamble)
      tmp25 = 0;

    else
      tmp26 = (unsigned char)(unsigned int)sMAC_tx_ctrl.Preamble_counter + 1;
  if(Reset)
    tmp27 = FALSE;

  else
    if(sMAC_tx_ctrl.Current_state == StateJamDrop || sMAC_tx_ctrl.Current_state == StateFFEmptyDrop)
      tmp28 = !sMAC_tx_ctrl.PktDrpEvenPtr;

  if(sMAC_tx_ctrl.Current_state == StateSFD)
  {
    sMAC_tx_ctrl.CRC_init = TRUE;
    *CRC_init = TRUE;
  }

  else
  {
    sMAC_tx_ctrl.CRC_init = FALSE;
    *CRC_init = FALSE;
  }
  *Frame_data = sMAC_tx_ctrl.TxD_tmp;
  *Frame_data = sMAC_tx_ctrl.TxD_tmp;
  if(sMAC_tx_ctrl.Current_state == StateData || sMAC_tx_ctrl.Current_state == StateSendPauseFrame || sMAC_tx_ctrl.Current_state == StatePAD)
  {
    sMAC_tx_ctrl.Data_en = TRUE;
    *Data_en = TRUE;
  }

  else
  {
    sMAC_tx_ctrl.Data_en = FALSE;
    *Data_en = FALSE;
  }
  if(sMAC_tx_ctrl.Current_state == StateFCS)
  {
    sMAC_tx_ctrl.CRC_rd = TRUE;
    *CRC_rd = TRUE;
  }

  else
  {
    sMAC_tx_ctrl.CRC_rd = FALSE;
    *CRC_rd = FALSE;
  }
  if(sMAC_tx_ctrl.Current_state == StateJam && sMAC_tx_ctrl.Next_state == StateBackOff)
  {
    sMAC_tx_ctrl.Random_init = TRUE;
    *Random_init = TRUE;
  }

  else
  {
    sMAC_tx_ctrl.Random_init = FALSE;
    *Random_init = FALSE;
  }
  if(sMAC_tx_ctrl.Current_state == StateData || sMAC_tx_ctrl.Current_state == StateSFD && !(sMAC_tx_ctrl.pause_frame_send_en_dl1 && (xoff_gen || xon_gen)) || sMAC_tx_ctrl.Current_state == StateJamDrop && sMAC_tx_ctrl.PktDrpEvenPtr || sMAC_tx_ctrl.Current_state == StateFFEmptyDrop && sMAC_tx_ctrl.PktDrpEvenPtr)
  {
    sMAC_tx_ctrl.Fifo_rd = TRUE;
    *Fifo_rd = TRUE;
  }

  else
  {
    sMAC_tx_ctrl.Fifo_rd = FALSE;
    *Fifo_rd = FALSE;
  }
  if(sMAC_tx_ctrl.Current_state == StateSwitchNext)
  {
    sMAC_tx_ctrl.Fifo_rd_finish = TRUE;
    *Fifo_rd_finish = TRUE;
  }

  else
  {
    sMAC_tx_ctrl.Fifo_rd_finish = FALSE;
    *Fifo_rd_finish = FALSE;
  }
  if(sMAC_tx_ctrl.Current_state == StateJam)
  {
    sMAC_tx_ctrl.Fifo_rd_retry = TRUE;
    *Fifo_rd_retry = TRUE;
  }

  else
  {
    sMAC_tx_ctrl.Fifo_rd_retry = FALSE;
    *Fifo_rd_retry = FALSE;
  }
  if(sMAC_tx_ctrl.Current_state == StatePreamble || sMAC_tx_ctrl.Current_state == StateSFD || sMAC_tx_ctrl.Current_state == StateData || sMAC_tx_ctrl.Current_state == StateSendPauseFrame || sMAC_tx_ctrl.Current_state == StateFCS || sMAC_tx_ctrl.Current_state == StatePAD || sMAC_tx_ctrl.Current_state == StateJam)
    sMAC_tx_ctrl.TxEn_tmp = TRUE;

  else
    sMAC_tx_ctrl.TxEn_tmp = FALSE;
  if(sMAC_tx_ctrl.Current_state == StatePreamble)
    sMAC_tx_ctrl.TxD_tmp = 85;

  else
    if(sMAC_tx_ctrl.Current_state == StateSFD)
      sMAC_tx_ctrl.TxD_tmp = 213;

    else
      if(sMAC_tx_ctrl.Current_state == StateData)
        if(sMAC_tx_ctrl.Src_MAC_ptr && MAC_tx_add_en)
          sMAC_tx_ctrl.TxD_tmp = MAC_tx_addr_data;

        else
          sMAC_tx_ctrl.TxD_tmp = Fifo_data;

      else
        if(sMAC_tx_ctrl.Current_state == StateSendPauseFrame)
          if(sMAC_tx_ctrl.Src_MAC_ptr && MAC_tx_add_en)
            sMAC_tx_ctrl.TxD_tmp = MAC_tx_addr_data;

          else
          {
            if(sMAC_tx_ctrl.IPLengthCounter == 0)
              sMAC_tx_ctrl.TxD_tmp = 1;

            else
              if(sMAC_tx_ctrl.IPLengthCounter == 1)
                sMAC_tx_ctrl.TxD_tmp = 128;

              else
                if(sMAC_tx_ctrl.IPLengthCounter == 2)
                  sMAC_tx_ctrl.TxD_tmp = 194;

                else
                  if(sMAC_tx_ctrl.IPLengthCounter == 3)
                    sMAC_tx_ctrl.TxD_tmp = 0;

                  else
                    if(sMAC_tx_ctrl.IPLengthCounter == 4)
                      sMAC_tx_ctrl.TxD_tmp = 0;

                    else
                      if(sMAC_tx_ctrl.IPLengthCounter == 5)
                        sMAC_tx_ctrl.TxD_tmp = 1;

                      else
                        if(sMAC_tx_ctrl.IPLengthCounter == 12)
                          sMAC_tx_ctrl.TxD_tmp = 136;

                        else
                          if(sMAC_tx_ctrl.IPLengthCounter == 13)
                            sMAC_tx_ctrl.TxD_tmp = 8;

                          else
                            if(sMAC_tx_ctrl.IPLengthCounter == 14)
                              sMAC_tx_ctrl.TxD_tmp = 0;

                            else
                              if(sMAC_tx_ctrl.IPLengthCounter == 15)
                                sMAC_tx_ctrl.TxD_tmp = 1;

                              else
                                if(sMAC_tx_ctrl.IPLengthCounter == 16)
                                  sMAC_tx_ctrl.TxD_tmp = xon_gen ? 0 : sMAC_tx_ctrl.pause_quanta_set_dl1 >> 8 & 0xFF;

                                else
                                  if(sMAC_tx_ctrl.IPLengthCounter == 17)
                                    sMAC_tx_ctrl.TxD_tmp = xon_gen ? 0 : sMAC_tx_ctrl.pause_quanta_set_dl1 & 0xFF;

                                  else
                                    if(TRUE)
                                      sMAC_tx_ctrl.TxD_tmp = 0;

          }

        else
          if(sMAC_tx_ctrl.Current_state == StatePAD)
            sMAC_tx_ctrl.TxD_tmp = 0;

          else
            if(sMAC_tx_ctrl.Current_state == StateJam)
              sMAC_tx_ctrl.TxD_tmp = 1;

            else
              if(sMAC_tx_ctrl.Current_state == StateFCS)
                sMAC_tx_ctrl.TxD_tmp = CRC_out;

              else
                if(TRUE)
                  sMAC_tx_ctrl.TxD_tmp = 0;

  if(Reset)
  {
    tmp29 = 0;
    tmp30 = FALSE;
  }

  else
  {
    tmp31 = sMAC_tx_ctrl.TxD_tmp;
    tmp32 = sMAC_tx_ctrl.TxEn_tmp;
  }
  if(Reset)
    tmp33 = 0;

  else
    if(sMAC_tx_ctrl.Current_state == StateSFD)
      tmp34 = 0;

    else
      if(sMAC_tx_ctrl.Current_state == StateData || sMAC_tx_ctrl.Current_state == StateSendPauseFrame || sMAC_tx_ctrl.Current_state == StatePAD || sMAC_tx_ctrl.Current_state == StateFCS)
        tmp35 = (unsigned short int)(unsigned int)sMAC_tx_ctrl.Tx_pkt_length_rmon + 1;

  if(Reset)
    tmp36 = FALSE;

  else
    if(Fifo_eop && sMAC_tx_ctrl.Current_state == StateJamDrop || Fifo_eop && sMAC_tx_ctrl.Current_state == StateFFEmptyDrop || CRC_end)
      tmp37 = TRUE;

    else
      tmp38 = FALSE;
  if(Reset)
    tmp39 = FALSE;

  else
    tmp40 = sMAC_tx_ctrl.Tx_apply_rmon_tmp;
  if(Reset)
    tmp41 = FALSE;

  else
    if(Fifo_eop && sMAC_tx_ctrl.Current_state == StateJamDrop || Fifo_eop && sMAC_tx_ctrl.Current_state == StateFFEmptyDrop || CRC_end)
      tmp42 = TRUE;

    else
      if(sMAC_tx_ctrl.Tx_apply_rmon_tmp_pl1)
        tmp43 = FALSE;

  if(Reset)
    tmp44 = 0;

  else
    if(Fifo_eop && sMAC_tx_ctrl.Current_state == StateJamDrop)
      tmp45 = 1;

    else
      if(Fifo_eop && sMAC_tx_ctrl.Current_state == StateFFEmptyDrop)
        tmp46 = 2;

      else
        if(Fifo_eop && Fifo_data_err_full)
          tmp47 = 3;

        else
          if(CRC_end)
            tmp48 = 4;

  if(Reset)
    tmp49 = FALSE;

  else
    if(sMAC_tx_ctrl.Current_state == StateSFD && sMAC_tx_ctrl.Next_state == StateData)
      tmp50 = TRUE;

    else
      tmp51 = FALSE;
  if(Reset)
    tmp52 = FALSE;

  else
    tmp53 = sMAC_tx_ctrl.MAC_header_slot_tmp;
  if(Reset)
    tmp54 = 0;

  else
    if(sMAC_tx_ctrl.Current_state == StateSendPauseFrame)
      tmp55 = 4;

    else
      if(sMAC_tx_ctrl.MAC_header_slot)
        tmp56 = sMAC_tx_ctrl.TxD >> 6 & 3;

  if((unsigned int)sMAC_tx_ctrl.Tx_pkt_length_rmon >= 6 && (unsigned int)sMAC_tx_ctrl.Tx_pkt_length_rmon <= 11)
    sMAC_tx_ctrl.Src_MAC_ptr = TRUE;

  else
    sMAC_tx_ctrl.Src_MAC_ptr = FALSE;
  if(Reset)
    tmp57 = FALSE;

  else
    if((unsigned int)sMAC_tx_ctrl.Tx_pkt_length_rmon >= 4 && (unsigned int)sMAC_tx_ctrl.Tx_pkt_length_rmon <= 9 && (MAC_tx_add_en || sMAC_tx_ctrl.Current_state == StateSendPauseFrame))
      tmp58 = TRUE;

    else
      tmp59 = FALSE;
  if((unsigned int)sMAC_tx_ctrl.Tx_pkt_length_rmon == 3 && sMAC_tx_ctrl.Fifo_rd)
  {
    sMAC_tx_ctrl.MAC_tx_addr_init = TRUE;
    *MAC_tx_addr_init = TRUE;
  }

  else
  {
    sMAC_tx_ctrl.MAC_tx_addr_init = FALSE;
    *MAC_tx_addr_init = FALSE;
  }
  if(Reset)
    tmp60 = FALSE;

  else
    if((unsigned int)sMAC_tx_ctrl.pause_counter == 512 / 8)
      tmp61 = TRUE;

    else
      tmp62 = FALSE;
  if(Reset)
    tmp63 = FALSE;

  else
    if(sMAC_tx_ctrl.Current_state == StateDefer && xoff_gen)
      tmp64 = TRUE;

    else
      tmp65 = FALSE;
  if(Reset)
    tmp66 = FALSE;

  else
    if(sMAC_tx_ctrl.Current_state == StateDefer && xon_gen)
      tmp67 = TRUE;

    else
      tmp68 = FALSE;
  if(Reset)
  {
    sMAC_tx_ctrl.pause_frame_send_en_dl1 = tmp0;
    sMAC_tx_ctrl.pause_quanta_set_dl1 = tmp1;
  }

  else
  {
    sMAC_tx_ctrl.pause_frame_send_en_dl1 = tmp2;
    sMAC_tx_ctrl.pause_quanta_set_dl1 = tmp3;
  }
  if(Reset)
    sMAC_tx_ctrl.pause_counter = tmp4;

  else
    if(sMAC_tx_ctrl.Current_state != StatePause)
      sMAC_tx_ctrl.pause_counter = tmp5;

    else
      sMAC_tx_ctrl.pause_counter = tmp6;
  if(Reset)
    sMAC_tx_ctrl.IPLengthCounter = tmp7;

  else
    if(sMAC_tx_ctrl.Current_state == StateDefer)
      sMAC_tx_ctrl.IPLengthCounter = tmp8;

    else
      if(sMAC_tx_ctrl.IPLengthCounter != 255 && (sMAC_tx_ctrl.Current_state == StateData || sMAC_tx_ctrl.Current_state == StateSendPauseFrame || sMAC_tx_ctrl.Current_state == StatePAD))
        sMAC_tx_ctrl.IPLengthCounter = tmp9;

  if(Reset)
    sMAC_tx_ctrl.PADCounter = tmp10;

  else
    if(sMAC_tx_ctrl.Current_state != StatePAD)
      sMAC_tx_ctrl.PADCounter = tmp11;

    else
      sMAC_tx_ctrl.PADCounter = tmp12;
  if(Reset)
    sMAC_tx_ctrl.Current_state = tmp13;

  else
    sMAC_tx_ctrl.Current_state = tmp14;
  if(Reset)
    sMAC_tx_ctrl.JamCounter = tmp15;

  else
    if(sMAC_tx_ctrl.Current_state != StateJam)
      sMAC_tx_ctrl.JamCounter = tmp16;

    else
      if(sMAC_tx_ctrl.Current_state == StateJam)
        sMAC_tx_ctrl.JamCounter = tmp17;

  if(Reset)
  {
    sMAC_tx_ctrl.RetryCnt = tmp18;
    *RetryCnt = tmp18;
  }

  else
    if(sMAC_tx_ctrl.Current_state == StateSwitchNext)
    {
      sMAC_tx_ctrl.RetryCnt = tmp19;
      *RetryCnt = tmp19;
    }

    else
      if(sMAC_tx_ctrl.Current_state == StateJam && sMAC_tx_ctrl.Next_state == StateBackOff)
      {
        sMAC_tx_ctrl.RetryCnt = tmp20;
        *RetryCnt = tmp20;
      }

  if(Reset)
    sMAC_tx_ctrl.IFG_counter = tmp21;

  else
    if(sMAC_tx_ctrl.Current_state != StateIFG)
      sMAC_tx_ctrl.IFG_counter = tmp22;

    else
      sMAC_tx_ctrl.IFG_counter = tmp23;
  if(Reset)
    sMAC_tx_ctrl.Preamble_counter = tmp24;

  else
    if(sMAC_tx_ctrl.Current_state != StatePreamble)
      sMAC_tx_ctrl.Preamble_counter = tmp25;

    else
      sMAC_tx_ctrl.Preamble_counter = tmp26;
  if(Reset)
    sMAC_tx_ctrl.PktDrpEvenPtr = tmp27;

  else
    if(sMAC_tx_ctrl.Current_state == StateJamDrop || sMAC_tx_ctrl.Current_state == StateFFEmptyDrop)
      sMAC_tx_ctrl.PktDrpEvenPtr = tmp28;

  if(Reset)
  {
    {
      sMAC_tx_ctrl.TxD = tmp29;
      *TxD = tmp29;
    }
    {
      sMAC_tx_ctrl.TxEn = tmp30;
      *TxEn = tmp30;
    }
  }

  else
  {
    {
      sMAC_tx_ctrl.TxD = tmp31;
      *TxD = tmp31;
    }
    {
      sMAC_tx_ctrl.TxEn = tmp32;
      *TxEn = tmp32;
    }
  }
  if(Reset)
  {
    sMAC_tx_ctrl.Tx_pkt_length_rmon = tmp33;
    *Tx_pkt_length_rmon = tmp33;
  }

  else
    if(sMAC_tx_ctrl.Current_state == StateSFD)
    {
      sMAC_tx_ctrl.Tx_pkt_length_rmon = tmp34;
      *Tx_pkt_length_rmon = tmp34;
    }

    else
      if(sMAC_tx_ctrl.Current_state == StateData || sMAC_tx_ctrl.Current_state == StateSendPauseFrame || sMAC_tx_ctrl.Current_state == StatePAD || sMAC_tx_ctrl.Current_state == StateFCS)
      {
        sMAC_tx_ctrl.Tx_pkt_length_rmon = tmp35;
        *Tx_pkt_length_rmon = tmp35;
      }

  if(Reset)
    sMAC_tx_ctrl.Tx_apply_rmon_tmp = tmp36;

  else
    if(Fifo_eop && sMAC_tx_ctrl.Current_state == StateJamDrop || Fifo_eop && sMAC_tx_ctrl.Current_state == StateFFEmptyDrop || CRC_end)
      sMAC_tx_ctrl.Tx_apply_rmon_tmp = tmp37;

    else
      sMAC_tx_ctrl.Tx_apply_rmon_tmp = tmp38;
  if(Reset)
    sMAC_tx_ctrl.Tx_apply_rmon_tmp_pl1 = tmp39;

  else
    sMAC_tx_ctrl.Tx_apply_rmon_tmp_pl1 = tmp40;
  if(Reset)
  {
    sMAC_tx_ctrl.Tx_apply_rmon = tmp41;
    *Tx_apply_rmon = tmp41;
  }

  else
    if(Fifo_eop && sMAC_tx_ctrl.Current_state == StateJamDrop || Fifo_eop && sMAC_tx_ctrl.Current_state == StateFFEmptyDrop || CRC_end)
    {
      sMAC_tx_ctrl.Tx_apply_rmon = tmp42;
      *Tx_apply_rmon = tmp42;
    }

    else
      if(sMAC_tx_ctrl.Tx_apply_rmon_tmp_pl1)
      {
        sMAC_tx_ctrl.Tx_apply_rmon = tmp43;
        *Tx_apply_rmon = tmp43;
      }

  if(Reset)
  {
    sMAC_tx_ctrl.Tx_pkt_err_type_rmon = tmp44;
    *Tx_pkt_err_type_rmon = tmp44;
  }

  else
    if(Fifo_eop && sMAC_tx_ctrl.Current_state == StateJamDrop)
    {
      sMAC_tx_ctrl.Tx_pkt_err_type_rmon = tmp45;
      *Tx_pkt_err_type_rmon = tmp45;
    }

    else
      if(Fifo_eop && sMAC_tx_ctrl.Current_state == StateFFEmptyDrop)
      {
        sMAC_tx_ctrl.Tx_pkt_err_type_rmon = tmp46;
        *Tx_pkt_err_type_rmon = tmp46;
      }

      else
        if(Fifo_eop && Fifo_data_err_full)
        {
          sMAC_tx_ctrl.Tx_pkt_err_type_rmon = tmp47;
          *Tx_pkt_err_type_rmon = tmp47;
        }

        else
          if(CRC_end)
          {
            sMAC_tx_ctrl.Tx_pkt_err_type_rmon = tmp48;
            *Tx_pkt_err_type_rmon = tmp48;
          }

  if(Reset)
    sMAC_tx_ctrl.MAC_header_slot_tmp = tmp49;

  else
    if(sMAC_tx_ctrl.Current_state == StateSFD && sMAC_tx_ctrl.Next_state == StateData)
      sMAC_tx_ctrl.MAC_header_slot_tmp = tmp50;

    else
      sMAC_tx_ctrl.MAC_header_slot_tmp = tmp51;
  if(Reset)
    sMAC_tx_ctrl.MAC_header_slot = tmp52;

  else
    sMAC_tx_ctrl.MAC_header_slot = tmp53;
  if(Reset)
  {
    sMAC_tx_ctrl.Tx_pkt_type_rmon = tmp54;
    *Tx_pkt_type_rmon = tmp54;
  }

  else
    if(sMAC_tx_ctrl.Current_state == StateSendPauseFrame)
    {
      sMAC_tx_ctrl.Tx_pkt_type_rmon = tmp55;
      *Tx_pkt_type_rmon = tmp55;
    }

    else
      if(sMAC_tx_ctrl.MAC_header_slot)
      {
        sMAC_tx_ctrl.Tx_pkt_type_rmon = tmp56;
        *Tx_pkt_type_rmon = tmp56;
      }

  if(Reset)
  {
    sMAC_tx_ctrl.MAC_tx_addr_rd = tmp57;
    *MAC_tx_addr_rd = tmp57;
  }

  else
    if((unsigned int)sMAC_tx_ctrl.Tx_pkt_length_rmon >= 4 && (unsigned int)sMAC_tx_ctrl.Tx_pkt_length_rmon <= 9 && (MAC_tx_add_en || sMAC_tx_ctrl.Current_state == StateSendPauseFrame))
    {
      sMAC_tx_ctrl.MAC_tx_addr_rd = tmp58;
      *MAC_tx_addr_rd = tmp58;
    }

    else
    {
      sMAC_tx_ctrl.MAC_tx_addr_rd = tmp59;
      *MAC_tx_addr_rd = tmp59;
    }
  if(Reset)
  {
    sMAC_tx_ctrl.pause_quanta_sub = tmp60;
    *pause_quanta_sub = tmp60;
  }

  else
    if((unsigned int)sMAC_tx_ctrl.pause_counter == 512 / 8)
    {
      sMAC_tx_ctrl.pause_quanta_sub = tmp61;
      *pause_quanta_sub = tmp61;
    }

    else
    {
      sMAC_tx_ctrl.pause_quanta_sub = tmp62;
      *pause_quanta_sub = tmp62;
    }
  if(Reset)
  {
    sMAC_tx_ctrl.xoff_gen_complete = tmp63;
    *xoff_gen_complete = tmp63;
  }

  else
    if(sMAC_tx_ctrl.Current_state == StateDefer && xoff_gen)
    {
      sMAC_tx_ctrl.xoff_gen_complete = tmp64;
      *xoff_gen_complete = tmp64;
    }

    else
    {
      sMAC_tx_ctrl.xoff_gen_complete = tmp65;
      *xoff_gen_complete = tmp65;
    }
  if(Reset)
  {
    sMAC_tx_ctrl.xon_gen_complete = tmp66;
    *xon_gen_complete = tmp66;
  }

  else
    if(sMAC_tx_ctrl.Current_state == StateDefer && xon_gen)
    {
      sMAC_tx_ctrl.xon_gen_complete = tmp67;
      *xon_gen_complete = tmp67;
    }

    else
    {
      sMAC_tx_ctrl.xon_gen_complete = tmp68;
      *xon_gen_complete = tmp68;
    }
}
/*
void main() {
_Bool Reset;
_Bool Clk;
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
unsigned char TxD;
_Bool TxEn;
_Bool CRS;
_Bool MAC_tx_addr_init;
_Bool MAC_tx_addr_rd;
unsigned char MAC_tx_addr_data;
unsigned char Tx_pkt_type_rmon;
unsigned short int Tx_pkt_length_rmon;
_Bool Tx_apply_rmon;
unsigned char Tx_pkt_err_type_rmon;
_Bool pause_frame_send_en;
unsigned short int pause_quanta_set;
_Bool MAC_tx_add_en;
_Bool FullDuplex;
unsigned char MaxRetry;
unsigned char IFGset;
while(1) {
MAC_tx_ctrl(Reset, Clk, &CRC_init, &Frame_data, &Data_en, &CRC_rd, CRC_end, CRC_out, &Random_init, &RetryCnt, Random_time_meet, pause_apply, &pause_quanta_sub, xoff_gen, &xoff_gen_complete, xon_gen, &xon_gen_complete, Fifo_data, &Fifo_rd, Fifo_eop, Fifo_da, &Fifo_rd_finish, &Fifo_rd_retry, Fifo_ra, Fifo_data_err_empty, Fifo_data_err_full, &TxD, &TxEn, CRS, &MAC_tx_addr_init, &MAC_tx_addr_rd, MAC_tx_addr_data, &Tx_pkt_type_rmon, &Tx_pkt_length_rmon, &Tx_apply_rmon, &Tx_pkt_err_type_rmon, pause_frame_send_en, pause_quanta_set, MAC_tx_add_en, FullDuplex, MaxRetry, IFGset);
}
}*/
