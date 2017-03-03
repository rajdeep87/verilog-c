#include "eth_clockgen.c"
#include "eth_outputcontrol.c"
#include "eth_shiftreg.c"

//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_eth_miim{
_Bool LatchByte1_d;
_Bool LatchByte0_d;
unsigned char LatchByte;
_Bool Busy;
_Bool Nvalid;
_Bool WCtrlDataStart;
_Bool RStatStart;
_Bool UpdateMIIRX_DATAReg;
_Bool EndBusy_d;
_Bool EndBusy;
_Bool WCtrlData_q1;
_Bool WCtrlData_q2;
_Bool WCtrlData_q3;
_Bool WCtrlDataStart_q;
_Bool WCtrlDataStart_q1;
_Bool WCtrlDataStart_q2;
_Bool RStat_q1;
_Bool RStat_q2;
_Bool RStat_q3;
_Bool RStatStart_q1;
_Bool RStatStart_q2;
_Bool ScanStat_q1;
_Bool ScanStat_q2;
_Bool SyncStatMdcEn;
_Bool InProgress;
_Bool InProgress_q1;
_Bool InProgress_q2;
_Bool InProgress_q3;
_Bool WriteOp;
unsigned char BitCounter;
};
struct state_elements_eth_miim  seth_miim;

void eth_miim(_Bool Clk, _Bool Reset, unsigned char Divider, unsigned short int CtrlData, unsigned char Rgad, unsigned char Fiad, _Bool NoPre, _Bool WCtrlData, _Bool RStat, _Bool ScanStat, _Bool *Mdo, _Bool *MdoEn, _Bool Mdi, _Bool *Mdc, _Bool *Busy, _Bool *LinkFail, _Bool *Nvalid, unsigned short int *Prsd, _Bool *WCtrlDataStart, _Bool *RStatStart, _Bool *UpdateMIIRX_DATAReg)
{
  unsigned char tmp69;
  unsigned char tmp68;
  unsigned char tmp67;
  unsigned char tmp66;
  _Bool tmp65;
  _Bool tmp64;
  _Bool tmp63;
  _Bool tmp62;
  _Bool tmp61;
  _Bool tmp60;
  _Bool tmp59;
  _Bool tmp58;
  _Bool tmp57;
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
  _Bool tmp46;
  unsigned char tmp45;
  _Bool tmp44;
  _Bool tmp43;
  _Bool tmp42;
  _Bool tmp41;
  _Bool tmp40;
  _Bool tmp39;
  _Bool tmp38;
  _Bool tmp37;
  _Bool tmp36;
  _Bool tmp35;
  _Bool tmp34;
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
  _Bool tmp23;
  _Bool tmp22;
  _Bool tmp21;
  _Bool tmp20;
  _Bool tmp19;
  _Bool tmp18;
  _Bool tmp17;
  _Bool tmp16;
  _Bool tmp15;
  _Bool tmp14;
  _Bool tmp13;
  _Bool tmp12;
  _Bool tmp11;
  _Bool tmp10;
  _Bool tmp9;
  _Bool tmp8;
  _Bool tmp7;
  _Bool tmp6;
  _Bool tmp5;
  _Bool tmp4;
  _Bool tmp3;
  _Bool tmp2;
  _Bool tmp1;
  _Bool tmp0;
  int Tp;
  Tp = 1;
  _Bool WriteDataOp;
  _Bool ReadStatusOp;
  _Bool ScanStatusOp;
  _Bool StartOp;
  _Bool EndOp;
  _Bool MdcFrame;
  unsigned char ByteSelect;
  _Bool MdcEn;
  _Bool ShiftedBit;
  _Bool LatchByte1_d2;
  _Bool LatchByte0_d2;

  // arguments passed to other functions
  _Bool MdcEn_n, WriteOp, InProgress;
  unsigned char LatchByte, BitCounter;


  if(Reset)
  {
    tmp0 = FALSE;
    tmp1 = FALSE;
  }

  else
  {
    tmp2 = !seth_miim.InProgress_q2 && seth_miim.InProgress_q3;
    tmp3 = seth_miim.EndBusy_d;
  }
  if(Reset)
    tmp4 = FALSE;

  else
    if(seth_miim.EndBusy && !seth_miim.WCtrlDataStart_q)
      tmp5 = TRUE;

    else
      tmp6 = FALSE;
  if(Reset)
  {
    tmp7 = FALSE;
    tmp8 = FALSE;
    tmp9 = FALSE;
    tmp10 = FALSE;
    tmp11 = FALSE;
    tmp12 = FALSE;
    tmp13 = FALSE;
    tmp14 = FALSE;
    tmp15 = FALSE;
  }

  else
  {
    tmp16 = WCtrlData;
    tmp17 = seth_miim.WCtrlData_q1;
    tmp18 = seth_miim.WCtrlData_q2;
    tmp19 = RStat;
    tmp20 = seth_miim.RStat_q1;
    tmp21 = seth_miim.RStat_q2;
    tmp22 = ScanStat;
    tmp23 = seth_miim.ScanStat_q1;
    if(MdcEn)
      tmp24 = seth_miim.ScanStat_q2;

  }
  if(Reset)
  {
    tmp25 = FALSE;
    tmp26 = FALSE;
    tmp27 = FALSE;
  }

  else
  {
    if(seth_miim.EndBusy)
    {
      tmp28 = FALSE;
      tmp29 = FALSE;
    }

    else
    {
      if(seth_miim.WCtrlData_q2 && !seth_miim.WCtrlData_q3)
        tmp30 = TRUE;

      if(seth_miim.RStat_q2 && !seth_miim.RStat_q3)
        tmp31 = TRUE;

      tmp32 = seth_miim.WCtrlDataStart;
    }
  }
  if(Reset)
    tmp33 = FALSE;

  else
  {
    if(!seth_miim.InProgress_q2 && seth_miim.InProgress_q3)
    {
      tmp34 = FALSE;
    }

    else
    {
      if(seth_miim.ScanStat_q2 && !seth_miim.SyncStatMdcEn)
        tmp35 = TRUE;

    }
  }
  if(Reset)
  {
    tmp36 = FALSE;
    tmp37 = FALSE;
    tmp38 = FALSE;
    tmp39 = FALSE;
    tmp40 = FALSE;
    tmp41 = FALSE;
    tmp42 = FALSE;
    tmp43 = FALSE;
    tmp44 = FALSE;
    tmp45 = 0;
  }

  else
  {
    if(MdcEn)
    {
      tmp46 = seth_miim.WCtrlDataStart;
      tmp47 = seth_miim.WCtrlDataStart_q1;
      tmp48 = seth_miim.RStatStart;
      tmp49 = seth_miim.RStatStart_q1;
      tmp50 = seth_miim.LatchByte0_d;
      tmp51 = seth_miim.LatchByte1_d;
      tmp52 = LatchByte0_d2;
      tmp53 = LatchByte1_d2;
      tmp54 = seth_miim.InProgress;
      tmp55 = seth_miim.InProgress_q1;
      tmp56 = seth_miim.InProgress_q2;
    }

  }
  if(Reset)
    tmp57 = FALSE;

  else
    if(WCtrlData || seth_miim.WCtrlDataStart || RStat || seth_miim.RStatStart || seth_miim.SyncStatMdcEn || seth_miim.EndBusy || seth_miim.InProgress || seth_miim.InProgress_q3 || seth_miim.Nvalid)
      tmp58 = TRUE;

    else
      tmp59 = FALSE;
  if(Reset)
  {
    tmp60 = FALSE;
    tmp61 = FALSE;
  }

  else
  {
    if(MdcEn)
    {
      if(StartOp)
      {
        if(!seth_miim.InProgress)
          tmp62 = WriteDataOp;

        tmp63 = TRUE;
      }

      else
      {
        if(EndOp)
        {
          tmp64 = FALSE;
          tmp65 = FALSE;
        }

      }
    }

  }
  if(Reset)
    tmp66 = 0;

  else
  {
    if(MdcEn)
    {
      if(seth_miim.InProgress)
      {
        if(NoPre && seth_miim.BitCounter == 0)
          tmp67 = 33;

        else
          tmp68 = seth_miim.BitCounter & 0x7F + 1;
      }

      else
        tmp69 = 0;
    }

  }
 
  if(Reset)
  {
    seth_miim.EndBusy_d = tmp0;
    seth_miim.EndBusy = tmp1;
  }

  else
  {
    seth_miim.EndBusy_d = tmp2;
    seth_miim.EndBusy = tmp3;
  }
  if(Reset)
  {
    seth_miim.UpdateMIIRX_DATAReg = tmp4;
    *UpdateMIIRX_DATAReg = tmp4;
  }

  else
    if(seth_miim.EndBusy && !seth_miim.WCtrlDataStart_q)
    {
      seth_miim.UpdateMIIRX_DATAReg = tmp5;
      *UpdateMIIRX_DATAReg = tmp5;
    }

    else
    {
      seth_miim.UpdateMIIRX_DATAReg = tmp6;
      *UpdateMIIRX_DATAReg = tmp6;
    }
  if(Reset)
  {
    seth_miim.WCtrlData_q1 = tmp7;
    seth_miim.WCtrlData_q2 = tmp8;
    seth_miim.WCtrlData_q3 = tmp9;
    seth_miim.RStat_q1 = tmp10;
    seth_miim.RStat_q2 = tmp11;
    seth_miim.RStat_q3 = tmp12;
    seth_miim.ScanStat_q1 = tmp13;
    seth_miim.ScanStat_q2 = tmp14;
    seth_miim.SyncStatMdcEn = tmp15;
  }

  else
  {
    seth_miim.WCtrlData_q1 = tmp16;
    seth_miim.WCtrlData_q2 = tmp17;
    seth_miim.WCtrlData_q3 = tmp18;
    seth_miim.RStat_q1 = tmp19;
    seth_miim.RStat_q2 = tmp20;
    seth_miim.RStat_q3 = tmp21;
    seth_miim.ScanStat_q1 = tmp22;
    seth_miim.ScanStat_q2 = tmp23;
    if(MdcEn)
      seth_miim.SyncStatMdcEn = tmp24;

  }
  if(Reset)
  {
    {
      seth_miim.WCtrlDataStart = tmp25;
      *WCtrlDataStart = tmp25;
    }
    seth_miim.WCtrlDataStart_q = tmp26;
    {
      seth_miim.RStatStart = tmp27;
      *RStatStart = tmp27;
    }
  }

  else
  {
    if(seth_miim.EndBusy)
    {
      {
        seth_miim.WCtrlDataStart = tmp28;
        *WCtrlDataStart = tmp28;
      }
      {
        seth_miim.RStatStart = tmp29;
        *RStatStart = tmp29;
      }
    }

    else
    {
      if(seth_miim.WCtrlData_q2 && !seth_miim.WCtrlData_q3)
      {
        seth_miim.WCtrlDataStart = tmp30;
        *WCtrlDataStart = tmp30;
      }

      if(seth_miim.RStat_q2 && !seth_miim.RStat_q3)
      {
        seth_miim.RStatStart = tmp31;
        *RStatStart = tmp31;
      }

      seth_miim.WCtrlDataStart_q = tmp32;
    }
  }
  if(Reset)
  {
    seth_miim.Nvalid = tmp33;
    *Nvalid = tmp33;
  }

  else
  {
    if(!seth_miim.InProgress_q2 && seth_miim.InProgress_q3)
    {
      {
        seth_miim.Nvalid = tmp34;
        *Nvalid = tmp34;
      }
    }

    else
    {
      if(seth_miim.ScanStat_q2 && !seth_miim.SyncStatMdcEn)
      {
        seth_miim.Nvalid = tmp35;
        *Nvalid = tmp35;
      }

    }
  }
  if(Reset)
  {
    seth_miim.WCtrlDataStart_q1 = tmp36;
    seth_miim.WCtrlDataStart_q2 = tmp37;
    seth_miim.RStatStart_q1 = tmp38;
    seth_miim.RStatStart_q2 = tmp39;
    seth_miim.InProgress_q1 = tmp40;
    seth_miim.InProgress_q2 = tmp41;
    seth_miim.InProgress_q3 = tmp42;
    seth_miim.LatchByte0_d = tmp43;
    seth_miim.LatchByte1_d = tmp44;
    seth_miim.LatchByte = tmp45;
  }

  else
  {
    if(MdcEn)
    {
      seth_miim.WCtrlDataStart_q1 = tmp46;
      seth_miim.WCtrlDataStart_q2 = tmp47;
      seth_miim.RStatStart_q1 = tmp48;
      seth_miim.RStatStart_q2 = tmp49;
      seth_miim.LatchByte = tmp50;
      seth_miim.LatchByte = seth_miim.LatchByte | tmp51 << 1;
      seth_miim.LatchByte0_d = tmp52;
      seth_miim.LatchByte1_d = tmp53;
      seth_miim.InProgress_q1 = tmp54;
      seth_miim.InProgress_q2 = tmp55;
      seth_miim.InProgress_q3 = tmp56;
    }

  }
  if(Reset)
  {
    seth_miim.Busy = tmp57;
    *Busy = tmp57;
  }

  else
    if(WCtrlData || seth_miim.WCtrlDataStart || RStat || seth_miim.RStatStart || seth_miim.SyncStatMdcEn || seth_miim.EndBusy || seth_miim.InProgress || seth_miim.InProgress_q3 || seth_miim.Nvalid)
    {
      seth_miim.Busy = tmp58;
      *Busy = tmp58;
    }

    else
    {
      seth_miim.Busy = tmp59;
      *Busy = tmp59;
    }
  if(Reset)
  {
    seth_miim.InProgress = tmp60;
    seth_miim.WriteOp = tmp61;
  }

  else
  {
    if(MdcEn)
    {
      if(StartOp)
      {
        if(!seth_miim.InProgress)
          seth_miim.WriteOp = tmp62;

        seth_miim.InProgress = tmp63;
      }

      else
      {
        if(EndOp)
        {
          seth_miim.InProgress = tmp64;
          seth_miim.WriteOp = tmp65;
        }

      }
    }

  }
  if(Reset)
    seth_miim.BitCounter = tmp66 & 0x7F;

  else
  {
    if(MdcEn)
    {
      if(seth_miim.InProgress)
      {
        if(NoPre && seth_miim.BitCounter == 0)
          seth_miim.BitCounter = tmp67 & 0x7F;

        else
          seth_miim.BitCounter = tmp68 & 0x7F;
      }

      else
        seth_miim.BitCounter = tmp69 & 0x7F;
    }

  }

   // continuous assignment statement 
  WriteDataOp = seth_miim.WCtrlDataStart_q1 && !seth_miim.WCtrlDataStart_q2;
  ReadStatusOp = seth_miim.RStatStart_q1 && !seth_miim.RStatStart_q2;
  ScanStatusOp = seth_miim.SyncStatMdcEn && !seth_miim.InProgress && !seth_miim.InProgress_q1 && !seth_miim.InProgress_q2;
  StartOp = WriteDataOp || ReadStatusOp || ScanStatusOp;

  EndOp = (unsigned int)seth_miim.BitCounter == 63;
  ByteSelect = ByteSelect | (seth_miim.InProgress && (NoPre && seth_miim.BitCounter == 0 || !NoPre && seth_miim.BitCounter == 32)) << 0;
  ByteSelect = ByteSelect | (seth_miim.InProgress && seth_miim.BitCounter == 40) << 1;
  ByteSelect = ByteSelect | (seth_miim.InProgress && seth_miim.WriteOp && seth_miim.BitCounter == 48) << 2;
  ByteSelect = ByteSelect | (seth_miim.InProgress && seth_miim.WriteOp && seth_miim.BitCounter == 56) << 3;
  LatchByte1_d2 = seth_miim.InProgress && !seth_miim.WriteOp && seth_miim.BitCounter == 55;
  LatchByte0_d2 = seth_miim.InProgress && !seth_miim.WriteOp && seth_miim.BitCounter == 63;
  
    // Call to external functions
    unsigned char arg = Divider & 0xFF;
    eth_clockgen(Clk, Reset, arg, &Mdc, &MdcEn, &MdcEn_n);
    eth_shiftreg(Clk, Reset, MdcEn_n, Mdi, Fiad, Rgad, CtrlData, WriteOp, ByteSelect, LatchByte, &ShiftedBit, &Prsd, &LinkFail);
    eth_outputcontrol(Clk, Reset, WriteOp, NoPre, InProgress, ShiftedBit, BitCounter, MdcEn_n, &Mdo, &MdoEn);

}

/*
void main() {
_Bool Clk;
_Bool Reset;
unsigned char Divider;
unsigned short int CtrlData;
unsigned char Rgad;
unsigned char Fiad;
_Bool NoPre;
_Bool WCtrlData;
_Bool RStat;
_Bool ScanStat;
_Bool Mdo;
_Bool MdoEn;
_Bool Mdi;
_Bool Mdc;
_Bool Busy;
_Bool LinkFail;
_Bool Nvalid;
unsigned short int Prsd;
_Bool WCtrlDataStart;
_Bool RStatStart;
_Bool UpdateMIIRX_DATAReg;
while(1) {
eth_miim(Clk, Reset, Divider, CtrlData, Rgad, Fiad, NoPre, WCtrlData, RStat, ScanStat, &Mdo, &MdoEn, Mdi, &Mdc, &Busy, &LinkFail, &Nvalid, &Prsd, &WCtrlDataStart, &RStatStart, &UpdateMIIRX_DATAReg);
}
}
*/
