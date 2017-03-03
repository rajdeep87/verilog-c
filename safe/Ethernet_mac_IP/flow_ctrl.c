//#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct state_elements_flow_ctrl{
_Bool pause_apply;
_Bool xoff_gen;
_Bool xon_gen;
_Bool xoff_cpu_dl1;
_Bool xoff_cpu_dl2;
_Bool xon_cpu_dl1;
_Bool xon_cpu_dl2;
unsigned short int pause_quanta_dl1;
_Bool pause_quanta_val_dl1;
_Bool pause_quanta_val_dl2;
unsigned short int pause_quanta_counter;
_Bool tx_pause_en_dl1;
_Bool tx_pause_en_dl2;
};
void flow_ctrl(_Bool Reset, _Bool Clk, _Bool tx_pause_en, _Bool xoff_cpu, _Bool xon_cpu, unsigned short int pause_quanta, _Bool pause_quanta_val, _Bool *pause_apply, _Bool pause_quanta_sub, _Bool *xoff_gen, _Bool xoff_gen_complete, _Bool *xon_gen, _Bool xon_gen_complete)
{
  struct state_elements_flow_ctrl  sflow_ctrl;
  _Bool tmp29;
  _Bool tmp28;
  _Bool tmp27;
  unsigned short int tmp26;
  unsigned short int tmp25;
  unsigned short int tmp24;
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
  unsigned short int tmp9;
  unsigned short int tmp8;
  _Bool tmp7;
  _Bool tmp6;
  _Bool tmp5;
  _Bool tmp4;
  _Bool tmp3;
  _Bool tmp2;
  _Bool tmp1;
  _Bool tmp0;
  if(Reset)
  {
    tmp0 = FALSE;
    tmp1 = FALSE;
  }

  else
  {
    tmp2 = xoff_cpu;
    tmp3 = sflow_ctrl.xoff_cpu_dl1;
  }
  if(Reset)
  {
    tmp4 = FALSE;
    tmp5 = FALSE;
  }

  else
  {
    tmp6 = xon_cpu;
    tmp7 = sflow_ctrl.xon_cpu_dl1;
  }
  if(Reset)
  {
    tmp8 = 0;
  }

  else
  {
    tmp9 = pause_quanta;
  }
  if(Reset)
  {
    tmp10 = FALSE;
    tmp11 = FALSE;
  }

  else
  {
    tmp12 = pause_quanta_val;
    tmp13 = sflow_ctrl.pause_quanta_val_dl1;
  }
  if(Reset)
  {
    tmp14 = FALSE;
    tmp15 = FALSE;
  }

  else
  {
    tmp16 = tx_pause_en;
    tmp17 = sflow_ctrl.tx_pause_en_dl1;
  }
  if(Reset)
    tmp18 = FALSE;

  else
    if(xoff_gen_complete)
      tmp19 = FALSE;

    else
      if(sflow_ctrl.xoff_cpu_dl1 && !sflow_ctrl.xoff_cpu_dl2)
        tmp20 = TRUE;

  if(Reset)
    tmp21 = FALSE;

  else
    if(xon_gen_complete)
      tmp22 = FALSE;

    else
      if(sflow_ctrl.xon_cpu_dl1 && !sflow_ctrl.xon_cpu_dl2)
        tmp23 = TRUE;

  if(Reset)
    tmp24 = 0;

  else
    if(sflow_ctrl.pause_quanta_val_dl1 && !sflow_ctrl.pause_quanta_val_dl2)
      tmp25 = sflow_ctrl.pause_quanta_dl1;

    else
      if(pause_quanta_sub && (unsigned int)sflow_ctrl.pause_quanta_counter != 0)
        tmp26 = (unsigned short int)(unsigned int)sflow_ctrl.pause_quanta_counter - 1;

  if(Reset)
    tmp27 = FALSE;

  else
    if((unsigned int)sflow_ctrl.pause_quanta_counter == 0)
      tmp28 = FALSE;

    else
      if(sflow_ctrl.tx_pause_en_dl2)
        tmp29 = TRUE;

  if(Reset)
  {
    sflow_ctrl.xoff_cpu_dl1 = tmp0;
    sflow_ctrl.xoff_cpu_dl2 = tmp1;
  }

  else
  {
    sflow_ctrl.xoff_cpu_dl1 = tmp2;
    sflow_ctrl.xoff_cpu_dl2 = tmp3;
  }
  if(Reset)
  {
    sflow_ctrl.xon_cpu_dl1 = tmp4;
    sflow_ctrl.xon_cpu_dl2 = tmp5;
  }

  else
  {
    sflow_ctrl.xon_cpu_dl1 = tmp6;
    sflow_ctrl.xon_cpu_dl2 = tmp7;
  }
  if(Reset)
  {
    sflow_ctrl.pause_quanta_dl1 = tmp8;
  }

  else
  {
    sflow_ctrl.pause_quanta_dl1 = tmp9;
  }
  if(Reset)
  {
    sflow_ctrl.pause_quanta_val_dl1 = tmp10;
    sflow_ctrl.pause_quanta_val_dl2 = tmp11;
  }

  else
  {
    sflow_ctrl.pause_quanta_val_dl1 = tmp12;
    sflow_ctrl.pause_quanta_val_dl2 = tmp13;
  }
  if(Reset)
  {
    sflow_ctrl.tx_pause_en_dl1 = tmp14;
    sflow_ctrl.tx_pause_en_dl2 = tmp15;
  }

  else
  {
    sflow_ctrl.tx_pause_en_dl1 = tmp16;
    sflow_ctrl.tx_pause_en_dl2 = tmp17;
  }
  if(Reset)
  {
    sflow_ctrl.xoff_gen = tmp18;
    *xoff_gen = tmp18;
  }

  else
    if(xoff_gen_complete)
    {
      sflow_ctrl.xoff_gen = tmp19;
      *xoff_gen = tmp19;
    }

    else
      if(sflow_ctrl.xoff_cpu_dl1 && !sflow_ctrl.xoff_cpu_dl2)
      {
        sflow_ctrl.xoff_gen = tmp20;
        *xoff_gen = tmp20;
      }

  if(Reset)
  {
    sflow_ctrl.xon_gen = tmp21;
    *xon_gen = tmp21;
  }

  else
    if(xon_gen_complete)
    {
      sflow_ctrl.xon_gen = tmp22;
      *xon_gen = tmp22;
    }

    else
      if(sflow_ctrl.xon_cpu_dl1 && !sflow_ctrl.xon_cpu_dl2)
      {
        sflow_ctrl.xon_gen = tmp23;
        *xon_gen = tmp23;
      }

  if(Reset)
    sflow_ctrl.pause_quanta_counter = tmp24;

  else
    if(sflow_ctrl.pause_quanta_val_dl1 && !sflow_ctrl.pause_quanta_val_dl2)
      sflow_ctrl.pause_quanta_counter = tmp25;

    else
      if(pause_quanta_sub && (unsigned int)sflow_ctrl.pause_quanta_counter != 0)
        sflow_ctrl.pause_quanta_counter = tmp26;

  if(Reset)
  {
    sflow_ctrl.pause_apply = tmp27;
    *pause_apply = tmp27;
  }

  else
    if((unsigned int)sflow_ctrl.pause_quanta_counter == 0)
    {
      sflow_ctrl.pause_apply = tmp28;
      *pause_apply = tmp28;
    }

    else
      if(sflow_ctrl.tx_pause_en_dl2)
      {
        sflow_ctrl.pause_apply = tmp29;
        *pause_apply = tmp29;
      }

}
/*
void main() {
_Bool Reset;
_Bool Clk;
_Bool tx_pause_en;
_Bool xoff_cpu;
_Bool xon_cpu;
unsigned short int pause_quanta;
_Bool pause_quanta_val;
_Bool pause_apply;
_Bool pause_quanta_sub;
_Bool xoff_gen;
_Bool xoff_gen_complete;
_Bool xon_gen;
_Bool xon_gen_complete;
while(1) {
flow_ctrl(Reset, Clk, tx_pause_en, xoff_cpu, xon_cpu, pause_quanta, pause_quanta_val, &pause_apply, pause_quanta_sub, &xoff_gen, xoff_gen_complete, &xon_gen, xon_gen_complete);
}
}*/
