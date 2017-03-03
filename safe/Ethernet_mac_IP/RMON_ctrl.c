//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_RMON_CTRL{
unsigned char NextState;
_Bool Reg_next_0;
unsigned char CurrentState_reg;
unsigned char StepCounter;
unsigned int DoutaReg;
_Bool Write;
_Bool Reg_next_1;
_Bool Read;
_Bool Pipeline;
unsigned char Addra;
_Bool CPU_rd_apply_reg;
_Bool CPU_rd_apply_dl1;
unsigned int Dina;
_Bool CPU_rd_apply_dl2;
unsigned int CPU_rd_dout;
unsigned char CurrentState;
};
void RMON_CTRL(_Bool Clk, _Bool Reset, _Bool Reg_apply_0, unsigned char Reg_addr_0, unsigned short int Reg_data_0, _Bool *Reg_next_0, _Bool Reg_apply_1, unsigned char Reg_addr_1, unsigned short int Reg_data_1, _Bool *Reg_next_1, unsigned char *Addra, unsigned int *Dina, unsigned int Douta, _Bool *Wea, unsigned char CPU_rd_addr, _Bool CPU_rd_apply, _Bool *CPU_rd_grant, unsigned int *CPU_rd_dout)
{
  struct state_elements_RMON_CTRL  sRMON_CTRL;
  unsigned int tmp17, tmp20, tmp21, tmp22, tmp23, tmp24;
  unsigned int tmp16;
  _Bool tmp15;
  _Bool tmp14;
  _Bool tmp13;
  _Bool tmp12;
  _Bool tmp11;
  _Bool tmp10;
  _Bool tmp9;
  unsigned int tmp8;
  unsigned int tmp7;
  unsigned char tmp6;
  unsigned char tmp5;
  unsigned char tmp4;
  unsigned char tmp3;
  unsigned char tmp2;
  unsigned char tmp1;
  unsigned char tmp0;
  
  int StateCPU;
  StateCPU = 0;
  int StateMAC0;
  StateMAC0 = 1;
  int StateMAC1;
  StateMAC1 = 2;
  
  if(Reset)
    tmp0 = StateMAC0;

  else
    tmp1 = sRMON_CTRL.NextState;
  if(Reset)
    tmp2 = StateMAC0;

  else
    if(sRMON_CTRL.CurrentState != StateCPU)
      tmp3 = sRMON_CTRL.CurrentState;

  if(sRMON_CTRL.CurrentState == StateMAC0)
    if(!Reg_apply_0 && sRMON_CTRL.CPU_rd_apply_reg)
      sRMON_CTRL.NextState = StateCPU;

    else
      if(!Reg_apply_0)
        sRMON_CTRL.NextState = StateMAC1;

      else
        sRMON_CTRL.NextState = sRMON_CTRL.CurrentState;

  else
    if(sRMON_CTRL.CurrentState == StateMAC1)
      if(!Reg_apply_1 && sRMON_CTRL.CPU_rd_apply_reg)
        sRMON_CTRL.NextState = StateCPU;

      else
        if(!Reg_apply_1)
          sRMON_CTRL.NextState = StateMAC0;

        else
          sRMON_CTRL.NextState = sRMON_CTRL.CurrentState;

    else
      if(sRMON_CTRL.CurrentState == StateCPU)
        if(sRMON_CTRL.StepCounter == 3)
          /*switch(sRMON_CTRL.CurrentState_reg) {
            case StateMAC0: sRMON_CTRL.NextState = StateMAC0;
            case StateMAC1: sRMON_CTRL.NextState = StateMAC1;
            default: sRMON_CTRL.NextState = StateMAC0;
          }*/
          if(sRMON_CTRL.CurrentState_reg == StateMAC0)
             sRMON_CTRL.NextState = StateMAC0;
          else if(sRMON_CTRL.CurrentState_reg == StateMAC1)
             sRMON_CTRL.NextState = StateMAC1;
          else sRMON_CTRL.NextState = StateMAC0;
         else
         sRMON_CTRL.NextState = sRMON_CTRL.CurrentState;

      else
        if(TRUE)
          sRMON_CTRL.NextState = StateMAC0;

  if(Reset)
    tmp4 = 0;

  else
    if(sRMON_CTRL.NextState != sRMON_CTRL.CurrentState)
      tmp5 = 0;

    else
      if(sRMON_CTRL.StepCounter != 15)
        tmp6 = (unsigned char)(unsigned int)sRMON_CTRL.StepCounter + 1;

  if((unsigned int)sRMON_CTRL.StepCounter == 1 || (unsigned int)sRMON_CTRL.StepCounter == 4 || (unsigned int)sRMON_CTRL.StepCounter == 7 || (unsigned int)sRMON_CTRL.StepCounter == 10)
    sRMON_CTRL.Read = TRUE;

  else
    sRMON_CTRL.Read = FALSE;
  if((unsigned int)sRMON_CTRL.StepCounter == 2 || (unsigned int)sRMON_CTRL.StepCounter == 5 || (unsigned int)sRMON_CTRL.StepCounter == 8 || (unsigned int)sRMON_CTRL.StepCounter == 11)
    sRMON_CTRL.Pipeline = TRUE;

  else
    sRMON_CTRL.Pipeline = FALSE;
  if((unsigned int)sRMON_CTRL.StepCounter == 3 || (unsigned int)sRMON_CTRL.StepCounter == 6 || (unsigned int)sRMON_CTRL.StepCounter == 9 || (unsigned int)sRMON_CTRL.StepCounter == 12)
    sRMON_CTRL.Write = TRUE;

  else
    sRMON_CTRL.Write = FALSE;
  if(Reset)
    tmp7 = 0;

  else
    if(sRMON_CTRL.Read)
      tmp8 = Douta;

  /*switch(sRMON_CTRL.CurrentState) {
    case StateMAC0: *Addra = 0x0 << 5 | Reg_addr_0 & 0x1F;
    case StateMAC1: *Addra = 0x1 << 5 | Reg_addr_1 & 0x1F;
    case StateCPU:  *Addra = CPU_rd_addr;
    default:   *Addra = 0;
  }*/
  
  if(sRMON_CTRL.CurrentState == StateMAC0)
   {*Addra = 0x0 << 5 | Reg_addr_0 & 0x1F;
    sRMON_CTRL.Addra = 0x0 << 5 | Reg_addr_0 & 0x1F; }
  if(sRMON_CTRL.CurrentState == StateMAC1)
    {*Addra = 0x1 << 5 | Reg_addr_1 & 0x1F;
    sRMON_CTRL.Addra = 0x1 << 5 | Reg_addr_1 & 0x1F;
    }
  if(sRMON_CTRL.CurrentState == StateCPU)
    {*Addra = CPU_rd_addr;
     sRMON_CTRL.Addra = CPU_rd_addr; 
     }
  else { *Addra = 0;
         sRMON_CTRL.Addra = 0; 
       }
  

  if(Reset)
    tmp20 = 0;
  else
    /*switch(sRMON_CTRL.CurrentState) {
      case StateMAC0: tmp21 = Douta+Reg_data_0;
      case StateMAC1: tmp22 = Douta+Reg_data_1;
      case StateCPU:  tmp23 = 0;
      default:   tmp24 = 0;
    }*/
    if (sRMON_CTRL.CurrentState == StateMAC0)
       tmp21 = Douta+Reg_data_0;
    if (sRMON_CTRL.CurrentState == StateMAC1)
       tmp22 = Douta+Reg_data_1;
    if (sRMON_CTRL.CurrentState == StateCPU)
       tmp23 = 0;
    else  tmp24 = 0;
   
  *Wea = sRMON_CTRL.Write;
  *Wea = sRMON_CTRL.Write;
  if(sRMON_CTRL.CurrentState == StateMAC0)
  {
    sRMON_CTRL.Reg_next_0 = sRMON_CTRL.Pipeline;
    *Reg_next_0 = sRMON_CTRL.Pipeline;
  }

  else
  {
    sRMON_CTRL.Reg_next_0 = FALSE;
    *Reg_next_0 = FALSE;
  }
  if(sRMON_CTRL.CurrentState == StateMAC1)
  {
    sRMON_CTRL.Reg_next_1 = sRMON_CTRL.Pipeline;
    *Reg_next_1 = sRMON_CTRL.Pipeline;
  }

  else
  {
    sRMON_CTRL.Reg_next_1 = FALSE;
    *Reg_next_1 = FALSE;
  }
  if(Reset)
  {
    tmp9 = FALSE;
    tmp10 = FALSE;
  }

  else
  {
    tmp11 = CPU_rd_apply;
    tmp12 = sRMON_CTRL.CPU_rd_apply_dl1;
  }
  if(Reset)
    tmp13 = FALSE;

  else
    if(sRMON_CTRL.CPU_rd_apply_dl1 && !sRMON_CTRL.CPU_rd_apply_dl2)
      tmp14 = TRUE;

    else
      if(sRMON_CTRL.CurrentState == StateCPU && sRMON_CTRL.Write)
        tmp15 = FALSE;

  *CPU_rd_grant = !sRMON_CTRL.CPU_rd_apply_reg;
  *CPU_rd_grant = !sRMON_CTRL.CPU_rd_apply_reg;
  if(Reset)
    tmp16 = 0;

  else
    if(sRMON_CTRL.Pipeline && sRMON_CTRL.CurrentState == StateCPU)
      tmp17 = Douta;

  if(Reset)
    sRMON_CTRL.CurrentState = tmp0;

  else
    sRMON_CTRL.CurrentState = tmp1;
  if(Reset)
    sRMON_CTRL.CurrentState_reg = tmp2;

  else
    if(sRMON_CTRL.CurrentState != StateCPU)
      sRMON_CTRL.CurrentState_reg = tmp3;

  if(Reset)
    sRMON_CTRL.StepCounter = tmp4;

  else
    if(sRMON_CTRL.NextState != sRMON_CTRL.CurrentState)
      sRMON_CTRL.StepCounter = tmp5;

    else
      if(sRMON_CTRL.StepCounter != 15)
        sRMON_CTRL.StepCounter = tmp6;

  if(Reset)
    sRMON_CTRL.DoutaReg = tmp7;

  else
    if(sRMON_CTRL.Read)
      sRMON_CTRL.DoutaReg = tmp8;


  if(Reset)
    tmp20 = 0;
  else
    /*switch(sRMON_CTRL.CurrentState) {
      case StateMAC0: *Dina = tmp21; sRMON_CTRL.Dina = tmp21;
      case StateMAC1: *Dina = tmp22; sRMON_CTRL.Dina = tmp22;
      case StateCPU:  *Dina = tmp23; sRMON_CTRL.Dina = tmp23;
      default:   *Dina = tmp24; sRMON_CTRL.Dina = tmp24;
    }*/

    if(sRMON_CTRL.CurrentState == StateMAC0)
     {*Dina = tmp21; sRMON_CTRL.Dina = tmp21;}
    if(sRMON_CTRL.CurrentState == StateMAC1)
     {*Dina = tmp22; sRMON_CTRL.Dina = tmp22;}
    if(sRMON_CTRL.CurrentState == StateCPU)
     { *Dina = tmp23; sRMON_CTRL.Dina = tmp23;}
    else { *Dina = tmp24; sRMON_CTRL.Dina = tmp24; }

  if(Reset)
  {
    sRMON_CTRL.CPU_rd_apply_dl1 = tmp9;
    sRMON_CTRL.CPU_rd_apply_dl2 = tmp10;
  }

  else
  {
    sRMON_CTRL.CPU_rd_apply_dl1 = tmp11;
    sRMON_CTRL.CPU_rd_apply_dl2 = tmp12;
  }
  if(Reset)
    sRMON_CTRL.CPU_rd_apply_reg = tmp13;

  else
    if(sRMON_CTRL.CPU_rd_apply_dl1 && !sRMON_CTRL.CPU_rd_apply_dl2)
      sRMON_CTRL.CPU_rd_apply_reg = tmp14;

    else
      if(sRMON_CTRL.CurrentState == StateCPU && sRMON_CTRL.Write)
        sRMON_CTRL.CPU_rd_apply_reg = tmp15;

  if(Reset)
  {
    sRMON_CTRL.CPU_rd_dout = tmp16;
    *CPU_rd_dout = tmp16;
  }

  else
    if(sRMON_CTRL.Pipeline && sRMON_CTRL.CurrentState == StateCPU)
    {
      sRMON_CTRL.CPU_rd_dout = tmp17;
      *CPU_rd_dout = tmp17;
    }

}

/*
void main() {
_Bool Clk;
_Bool Reset;
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
unsigned char CPU_rd_addr;
_Bool CPU_rd_apply;
_Bool CPU_rd_grant;
unsigned int CPU_rd_dout;
while(1) {
RMON_CTRL(Clk, Reset, Reg_apply_0, Reg_addr_0, Reg_data_0, &Reg_next_0, Reg_apply_1, Reg_addr_1, Reg_data_1, &Reg_next_1, &Addra, &Dina, Douta, &Wea, CPU_rd_addr, CPU_rd_apply, &CPU_rd_grant, &CPU_rd_dout);
}
}
*/
