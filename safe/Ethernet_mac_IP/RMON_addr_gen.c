//#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct state_elements_RMON_addr_gen{
_Bool Apply_rmon_dl2;
_Bool Apply_rmon_pulse;
unsigned char Pkt_type_rmon_dl1;
unsigned char Reg_addr;
unsigned short int Pkt_length_rmon_dl1;
unsigned short int Reg_data;
unsigned char Pkt_err_type_rmon_dl1;
_Bool Reg_drop_apply;
unsigned char CurrentState;
unsigned char NextState;
unsigned char PktTypeReg;
unsigned short int PktLengthReg;
unsigned char PktErrTypeReg;
_Bool Apply_rmon_dl1;
_Bool Reg_apply;
};
void RMON_addr_gen(_Bool Clk, _Bool Reset, unsigned char Pkt_type_rmon, unsigned short int Pkt_length_rmon, _Bool Apply_rmon, unsigned char Pkt_err_type_rmon, _Bool *Reg_apply, unsigned char *Reg_addr, unsigned short int *Reg_data, _Bool Reg_next, _Bool *Reg_drop_apply)
{
  struct state_elements_RMON_addr_gen  sRMON_addr_gen;
  unsigned char tmp100, tmp101, tmp102, tmp103, tmp104, tmp105,
  tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120 ;
  _Bool tmp21;
  _Bool tmp20;
  _Bool tmp19;
  unsigned char tmp18;
  unsigned char tmp17;
  unsigned char tmp16;
  unsigned char tmp15;
  unsigned short int tmp14;
  unsigned char tmp13;
  unsigned char tmp12;
  unsigned short int tmp11;
  unsigned char tmp10;
  _Bool tmp9;
  _Bool tmp8;
  _Bool tmp7;
  _Bool tmp6;
  unsigned char tmp5;
  unsigned short int tmp4;
  unsigned char tmp3;
  unsigned char tmp2;
  unsigned short int tmp1;
  unsigned char tmp0;
  int StateIdle;
  StateIdle = 0;
  int StatePktLength;
  StatePktLength = 1;
  int StatePktNumber;
  StatePktNumber = 2;
  int StatePktType;
  StatePktType = 3;
  int StatePktRange;
  StatePktRange = 4;
  if(Reset)
  {
    tmp0 = 0;
    tmp1 = 0;
    tmp2 = 0;
  }

  else
  {
    tmp3 = Pkt_type_rmon;
    tmp4 = Pkt_length_rmon;
    tmp5 = Pkt_err_type_rmon;
  }
  if(Reset)
  {
    tmp6 = FALSE;
    tmp7 = FALSE;
  }

  else
  {
    tmp8 = Apply_rmon;
    tmp9 = sRMON_addr_gen.Apply_rmon_dl1;
  }
  if(sRMON_addr_gen.Apply_rmon_dl1 && !sRMON_addr_gen.Apply_rmon_dl2)
    sRMON_addr_gen.Apply_rmon_pulse = TRUE;

  else
    sRMON_addr_gen.Apply_rmon_pulse = FALSE;
  if(Reset)
  {
    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
  }

  else
    if(sRMON_addr_gen.Apply_rmon_pulse && sRMON_addr_gen.CurrentState == StateIdle)
    {
      tmp13 = sRMON_addr_gen.Pkt_type_rmon_dl1;
      tmp14 = sRMON_addr_gen.Pkt_length_rmon_dl1;
      tmp15 = sRMON_addr_gen.Pkt_err_type_rmon_dl1;
    }

  if(Reset)
    tmp16 = StateIdle;

  else
    tmp17 = sRMON_addr_gen.NextState;
  if(sRMON_addr_gen.CurrentState == StateIdle)
    if(sRMON_addr_gen.Apply_rmon_pulse)
      sRMON_addr_gen.NextState = StatePktLength;

    else
      sRMON_addr_gen.NextState = StateIdle;

  else
    if(sRMON_addr_gen.CurrentState == StatePktLength)
      if(Reg_next)
        sRMON_addr_gen.NextState = StatePktNumber;

      else
        sRMON_addr_gen.NextState = sRMON_addr_gen.CurrentState;

    else
      if(sRMON_addr_gen.CurrentState == StatePktNumber)
        if(Reg_next)
          sRMON_addr_gen.NextState = StatePktType;

        else
          sRMON_addr_gen.NextState = sRMON_addr_gen.CurrentState;

      else
        if(sRMON_addr_gen.CurrentState == StatePktType)
          if(Reg_next)
            sRMON_addr_gen.NextState = StatePktRange;

          else
            sRMON_addr_gen.NextState = sRMON_addr_gen.CurrentState;

        else
          if(sRMON_addr_gen.CurrentState == StatePktRange)
            if(Reg_next)
              sRMON_addr_gen.NextState = StateIdle;

            else
              sRMON_addr_gen.NextState = sRMON_addr_gen.CurrentState;

          else
            if(TRUE)
              sRMON_addr_gen.NextState = StateIdle;

  if(sRMON_addr_gen.CurrentState == StatePktLength || sRMON_addr_gen.CurrentState == StatePktNumber || sRMON_addr_gen.CurrentState == StatePktType || sRMON_addr_gen.CurrentState == StatePktRange)
  {
    sRMON_addr_gen.Reg_apply = TRUE;
    *Reg_apply = TRUE;
  }

  else
  {
    sRMON_addr_gen.Reg_apply = FALSE;
    *Reg_apply = FALSE;
  }
  
  // Reg_addr
  if(Reset)
    tmp18 = 0;
  else 
  if(sRMON_addr_gen.CurrentState == StatePktLength)
  {
     tmp100 = 0x00 & 0x1F;
  }

  else
    if(sRMON_addr_gen.CurrentState == StatePktNumber)
    {
      tmp101 = 0x01 & 0x1F;
    }
  else
    if(sRMON_addr_gen.CurrentState == StatePktType)
    {
      if(sRMON_addr_gen.PktTypeReg == 3)
         tmp102 = 0x2 & 0x1F;
      if(sRMON_addr_gen.PktTypeReg == 3)
         tmp103 = 0x3 & 0x1F;
      if(sRMON_addr_gen.PktTypeReg == 3)
         tmp104 = 0x10 & 0x1F;
      else
         tmp105 = 0x4 & 0x1F;
    }
  else
    if(sRMON_addr_gen.CurrentState == StatePktRange)
    {
      if(sRMON_addr_gen.PktErrTypeReg == 1)
         tmp106 = 0x5 & 0x1F;
      if(sRMON_addr_gen.PktErrTypeReg == 2)
         tmp107 = 0x6 & 0x1F;
      if(sRMON_addr_gen.PktErrTypeReg == 3)
         tmp108 = 0x7 & 0x1F;
      if(sRMON_addr_gen.PktErrTypeReg == 4)
      {
        if(sRMON_addr_gen.PktLengthReg < 64)  
           tmp109 = 0x8 & 0x1F;
        if(sRMON_addr_gen.PktLengthReg == 64)  
           tmp110 = 0x9 & 0x1F;
        if(sRMON_addr_gen.PktLengthReg < 128)  
           tmp111 = 0xA & 0x1F;
        if(sRMON_addr_gen.PktLengthReg < 256)  
           tmp112 = 0xB & 0x1F;
        if(sRMON_addr_gen.PktLengthReg < 512)  
           tmp113 = 0xC & 0x1F;
        if(sRMON_addr_gen.PktLengthReg < 1024)  
           tmp114 = 0xD & 0x1F;
        if(sRMON_addr_gen.PktLengthReg < 1519)  
           tmp115 = 0xE & 0x1F;
        else
          tmp116 = 0x5 & 0x1F;
      }
      else 
         tmp117 = 0x5 & 0x1F;
    }
  
    else 
         tmp118 = 0x5 & 0x1F;
 
  if(sRMON_addr_gen.CurrentState == StatePktLength)
  {
    sRMON_addr_gen.Reg_data = sRMON_addr_gen.PktLengthReg;
    *Reg_data = sRMON_addr_gen.PktLengthReg;
  }

  else
    if(sRMON_addr_gen.CurrentState == StatePktNumber)
    {
      sRMON_addr_gen.Reg_data = 1;
      *Reg_data = 1;
    }

    else
      if(sRMON_addr_gen.CurrentState == StatePktType)
      {
        sRMON_addr_gen.Reg_data = 1;
        *Reg_data = 1;
      }

      else
        if(sRMON_addr_gen.CurrentState == StatePktRange)
        {
          sRMON_addr_gen.Reg_data = 1;
          *Reg_data = 1;
        }

        else
          if(TRUE)
          {
            sRMON_addr_gen.Reg_data = 0;
            *Reg_data = 0;
          }

  if(Reset)
    tmp19 = FALSE;

  else
    if(sRMON_addr_gen.CurrentState != StateIdle && sRMON_addr_gen.Apply_rmon_pulse)
      tmp20 = TRUE;

    else
      tmp21 = FALSE;
  if(Reset)
  {
    sRMON_addr_gen.Pkt_type_rmon_dl1 = tmp0;
    sRMON_addr_gen.Pkt_length_rmon_dl1 = tmp1;
    sRMON_addr_gen.Pkt_err_type_rmon_dl1 = tmp2;
  }

  else
  {
    sRMON_addr_gen.Pkt_type_rmon_dl1 = tmp3;
    sRMON_addr_gen.Pkt_length_rmon_dl1 = tmp4;
    sRMON_addr_gen.Pkt_err_type_rmon_dl1 = tmp5;
  }
  if(Reset)
  {
    sRMON_addr_gen.Apply_rmon_dl1 = tmp6;
    sRMON_addr_gen.Apply_rmon_dl2 = tmp7;
  }

  else
  {
    sRMON_addr_gen.Apply_rmon_dl1 = tmp8;
    sRMON_addr_gen.Apply_rmon_dl2 = tmp9;
  }
  if(Reset)
  {
    sRMON_addr_gen.PktTypeReg = tmp10;
    sRMON_addr_gen.PktLengthReg = tmp11;
    sRMON_addr_gen.PktErrTypeReg = tmp12;
  }

  else
    if(sRMON_addr_gen.Apply_rmon_pulse && sRMON_addr_gen.CurrentState == StateIdle)
    {
      sRMON_addr_gen.PktTypeReg = tmp13;
      sRMON_addr_gen.PktLengthReg = tmp14;
      sRMON_addr_gen.PktErrTypeReg = tmp15;
    }

  if(Reset)
    sRMON_addr_gen.CurrentState = tmp16;

  else
    sRMON_addr_gen.CurrentState = tmp17;
  
  if(Reset)
  {
    sRMON_addr_gen.Reg_addr = tmp18;
    *Reg_addr = tmp18;
  }
  else 
  if(sRMON_addr_gen.CurrentState == StatePktLength)
  {
     
    sRMON_addr_gen.Reg_addr = tmp100;
    *Reg_addr = tmp100;
  }

  else
    if(sRMON_addr_gen.CurrentState == StatePktNumber)
    {
      sRMON_addr_gen.Reg_addr = tmp101;
      *Reg_addr = tmp101;
    }
  else
    if(sRMON_addr_gen.CurrentState == StatePktType)
    {
      if(sRMON_addr_gen.PktTypeReg == 3)
      {
        sRMON_addr_gen.Reg_addr = tmp102;
        *Reg_addr = tmp102;
      }  
      if(sRMON_addr_gen.PktTypeReg == 3)
      {
        sRMON_addr_gen.Reg_addr = tmp103;
        *Reg_addr = tmp103;
      }
      if(sRMON_addr_gen.PktTypeReg == 3)
      {
        sRMON_addr_gen.Reg_addr = tmp104;
        *Reg_addr = tmp104;
      }
      else {
        sRMON_addr_gen.Reg_addr = tmp105;
        *Reg_addr = tmp105;
      }
    }
  else
    if(sRMON_addr_gen.CurrentState == StatePktRange)
    {
      if(sRMON_addr_gen.PktErrTypeReg == 1)
      {
        sRMON_addr_gen.Reg_addr = tmp106;
        *Reg_addr = tmp106;
      }
      if(sRMON_addr_gen.PktErrTypeReg == 2)
      {
        sRMON_addr_gen.Reg_addr = tmp107;
        *Reg_addr = tmp107;
      }
      if(sRMON_addr_gen.PktErrTypeReg == 3)
      {
        sRMON_addr_gen.Reg_addr = tmp108;
        *Reg_addr = tmp108;
      }
      if(sRMON_addr_gen.PktErrTypeReg == 4)
      {
        if(sRMON_addr_gen.PktLengthReg < 64)  
        {
          sRMON_addr_gen.Reg_addr = tmp109;
          *Reg_addr = tmp109;
        }
        if(sRMON_addr_gen.PktLengthReg == 64)  
        {
          sRMON_addr_gen.Reg_addr = tmp110;
          *Reg_addr = tmp110;
        }
        if(sRMON_addr_gen.PktLengthReg < 128)  
        {
          sRMON_addr_gen.Reg_addr = tmp111;
          *Reg_addr = tmp111;
        }
        if(sRMON_addr_gen.PktLengthReg < 256)  
        {
          sRMON_addr_gen.Reg_addr = tmp112;
          *Reg_addr = tmp112;
        }
        if(sRMON_addr_gen.PktLengthReg < 512)  
        {
          sRMON_addr_gen.Reg_addr = tmp113;
          *Reg_addr = tmp113;
        }
        if(sRMON_addr_gen.PktLengthReg < 1024)  
        {
          sRMON_addr_gen.Reg_addr = tmp114;
          *Reg_addr = tmp114;
        }
        if(sRMON_addr_gen.PktLengthReg < 1519)  
        {
         sRMON_addr_gen.Reg_addr = tmp115;
         *Reg_addr = tmp115;
        }
        else {
         sRMON_addr_gen.Reg_addr = tmp116;
         *Reg_addr = tmp116;
        }
      }
      else  {
       sRMON_addr_gen.Reg_addr = tmp117;
       *Reg_addr = tmp117;
      }
    }
    else {
       sRMON_addr_gen.Reg_addr = tmp118;
       *Reg_addr = tmp118;
    }

  if(Reset)
  {
    sRMON_addr_gen.Reg_drop_apply = tmp19;
    *Reg_drop_apply = tmp19;
  }

  else
    if(sRMON_addr_gen.CurrentState != StateIdle && sRMON_addr_gen.Apply_rmon_pulse)
    {
      sRMON_addr_gen.Reg_drop_apply = tmp20;
      *Reg_drop_apply = tmp20;
    }

    else
    {
      sRMON_addr_gen.Reg_drop_apply = tmp21;
      *Reg_drop_apply = tmp21;
    }
}

/*
void main() {
_Bool Clk;
_Bool Reset;
unsigned char Pkt_type_rmon;
unsigned short int Pkt_length_rmon;
_Bool Apply_rmon;
unsigned char Pkt_err_type_rmon;
_Bool Reg_apply;
unsigned char Reg_addr;
unsigned short int Reg_data;
_Bool Reg_next;
_Bool Reg_drop_apply;
while(1) {
RMON_addr_gen(Clk, Reset, Pkt_type_rmon, Pkt_length_rmon, Apply_rmon, Pkt_err_type_rmon, &Reg_apply, &Reg_addr, &Reg_data, Reg_next, &Reg_drop_apply);
}
}
*/
