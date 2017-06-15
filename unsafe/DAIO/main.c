#include <assert.h>

struct state_elements_main{
  _Bool rx_status_3;
  _Bool rx_status_2;
  _Bool rx_status_1;
  _Bool rx_status_0;
  unsigned char pc;
  _Bool clock_out;
  _Bool parity;
  _Bool load_A;
  _Bool load_B;
  _Bool load_buff;
  unsigned int shift_reg;
  unsigned char bit_count_A;
  unsigned char bit_count_B;
  unsigned short int frame_counter;
};
struct state_elements_main  smain;

//parameters

  int L0 = 0;
  int L1 = 1;
  int L2 = 2;
  int L3 = 3;
  int L4 = 4;
  int L5 = 5;
  int L6 = 6;
  int L7 = 7;
  int L8 = 8;
  int L9 = 9;
  int L10 = 10;


void initial(_Bool *clock_out, unsigned char *rx_status, _Bool *parity, _Bool *load_A, _Bool *load_B, _Bool *load_buff, unsigned int *shift_reg, unsigned char *frame_ofs)
{
  
  smain.bit_count_A = 0;
  smain.bit_count_B = 0;
  smain.frame_counter = 0;
  smain.clock_out = 0;
  *clock_out = 0;
  smain.rx_status_3 = 0;
  smain.rx_status_2 = 0;
  smain.rx_status_1 = 0;
  smain.rx_status_0 = 0;
  smain.parity = 0;
  *parity = 0;
  smain.load_A = 0;
  *load_A = 0;
  smain.load_B = 0;
  *load_B = 0;
  smain.load_buff = 0;
  *load_buff = 0;
  smain.shift_reg = 0;
  *shift_reg = 0;
  smain.pc = L0;
}

void daio(unsigned char xtal, unsigned char rx_control, _Bool reset, _Bool bit_in, _Bool preamble_1, _Bool preamble_2, _Bool preamble_3, _Bool carrier_loss, _Bool biphase_violation, _Bool *clock_out, unsigned char *rx_status, _Bool *parity, _Bool *load_A, _Bool *load_B, _Bool *load_buff, unsigned int *shift_reg, unsigned char *frame_ofs)
{
  
  // clocked block 
  if(reset)
  {
    smain.rx_status_3 = 0;
    smain.rx_status_2 = 0;
    smain.load_A = 0;
    *load_A = 0;
    smain.load_B = 0;
    *load_B = 0;
    smain.load_buff = 0;
    *load_buff = 0;
    smain.bit_count_A = 0;
    smain.bit_count_B = 0;
    smain.frame_counter = 0;
    smain.pc = L0;
  }
  else
  {
    if(smain.pc == L0) {
      if(((rx_control >> 2) & 1))
        smain.pc = L1;
    }
    else if(smain.pc == L1)
    {
      if((rx_control&3) == 0)
      {
        smain.clock_out = ((xtal >> 0) & 1);
        *clock_out = ((xtal >> 0) & 1);
      }
      else if((rx_control&3) == 1)
      {
        smain.clock_out = ((xtal >> 1) & 1);
        *clock_out = ((xtal >> 1) & 1);
      }
      else if((rx_control&3) == 2)
      {
        smain.clock_out = ((xtal >> 2) & 1);
        *clock_out = ((xtal >> 2) & 1);
      }
      else if((rx_control&3) == 3)
      {
        smain.clock_out = ((xtal >> 3) & 1);
        *clock_out = ((xtal >> 3) & 1);
      }
     smain.pc = L2;
   }
   else if(smain.pc == L2) {
     if(preamble_1)
     {
        smain.bit_count_A = 4;
        smain.pc = L3;
     }
   }
   else if(smain.pc == L3) {
      if((smain.bit_count_A & 0x7f) < 32)
      {
        if((smain.bit_count_A & 0x7f) == 31)
        {
          smain.load_A = 1;
          *load_A = 1;
        }
        if((smain.bit_count_A & 0x7f) == 2)
        {
           smain.load_B = 0;
           *load_B = 0;
        }
        if((smain.bit_count_A & 0x7f) == 3)
        {
           smain.load_buff = 1;
           *load_buff = 1;
        }
        if((smain.bit_count_A & 0x7f) == 5)
        {
           smain.load_buff = 0;
           *load_buff = 0;
        }
        smain.bit_count_A = ((smain.bit_count_A & 0x7F) + 1)&0x7F;
      }
      else
       smain.pc = L4;
   }
   else if(smain.pc == L4)
   {
       smain.bit_count_B = 1;
       smain.frame_counter = 1;
       smain.pc = L5;
   }
   else if(smain.pc == L5) {
     if((smain.bit_count_B & 0x7f) < 32)
     {
       if(((smain.bit_count_B & 0x7f) == 4) && preamble_3 == 0)
          smain.rx_status_2 = 1;
       if((smain.bit_count_B & 0x7f) == 31)
       {
          smain.load_B = 1;
          *load_B = 1;
       }
       if((smain.bit_count_B & 0x7f) == 2)
       {
          smain.load_A = 0;
          *load_A = 0;
       }
       smain.bit_count_B = ((smain.bit_count_B & 0x7f) + 1) & 0x7f;
     }
     else
       smain.pc = L6;
  }
  else if(smain.pc == L6) {
    if((smain.frame_counter  & 0x1FF) < 191)
    {
       smain.bit_count_A = 1;
       smain.pc = L7;
    }
    else
       smain.pc = L0;
  }
  else if(smain.pc == L7) {
   if(smain.bit_count_A < 32) 
   {
     if(((smain.bit_count_A & 0x7f) == 4) && preamble_2 == 0)
       smain.rx_status_2 = 1;
     if((smain.bit_count_A & 0x7f) == 31)
     {
       smain.load_A = 1;
       *load_A = 1;
     }
     if((smain.bit_count_A & 0x7f) == 2)
     {
       smain.load_B = 0;
       *load_B = 0;
     }
     if((smain.bit_count_A & 0x7f) == 3)
     {
      if((smain.frame_counter & 3) == 0)
      {
        smain.load_buff = 1;
        *load_buff = 1;
      }
     }
     if((smain.bit_count_A & 0x7f) == 5)
     {
       smain.load_buff = 0;
       *load_buff = 0;
     }
     smain.bit_count_A = ((smain.bit_count_A & 0x7F) + 1)&0x7F;
   }
   else
     smain.pc = L8;
 }
 else if(smain.pc == L8)
 {
    smain.bit_count_B = 1;
    smain.pc = L9;
 }
 else if(smain.pc == L9) {
   if((smain.bit_count_B & 0x7f) < 32)
   {
     if(((smain.bit_count_B & 0x7f) == 4) && preamble_3 == 0)
       smain.rx_status_2 = 1;
     if((smain.bit_count_B & 0x7f) == 31)
     {
       smain.load_B = 1;
       *load_B = 1;
     }
     if((smain.bit_count_B & 0x7f) == 2)
     {
       smain.load_A = 0;
       *load_A = 0;
     }
     smain.bit_count_B = ((smain.bit_count_B & 0x7F) + 1)&0x7F;
   }
   else
    smain.pc = L10;
 }
 else if(smain.pc == L10)
 {
   smain.frame_counter = ((smain.frame_counter & 0x1FF) + 1)&0x1FF;
   smain.pc = L6;
 }
}
  
// clocked block 
if(reset)
{
  smain.shift_reg = 0;
  *shift_reg = 0;
  smain.rx_status_1 = 0;
  smain.rx_status_0 = 0;
}
else if(smain.pc != L0 && smain.pc != L1)
{
  smain.shift_reg = (((smain.shift_reg & 524287) << 1) | bit_in) & 0xFFFFF;
  *shift_reg = (((smain.shift_reg >> 0 & 524287) << 1) | bit_in) & 0xFFFFF;
  if(carrier_loss)
    smain.rx_status_0 = 1;
  if(biphase_violation)
    smain.rx_status_1 = 1;
}

// clocked block 
if(reset || smain.pc == L2 || smain.pc == L4 || smain.pc == L6 || smain.pc == L8)
{
   smain.parity = 0;
   *parity = 0;
}
else if(smain.pc != L0 && smain.pc != L1)
{
   smain.parity = smain.parity ^ bit_in;
   *parity = smain.parity ^ bit_in;
}

   // continuous assignments
   *rx_status = (smain.rx_status_3 << 3 | smain.rx_status_2 << 2 | smain.rx_status_1 << 1 | smain.rx_status_0);
  
  *frame_ofs = (*frame_ofs & 0xC) | (smain.frame_counter & 3) ;
  
}

int main() {
  unsigned char xtal;
  unsigned char rx_control;
  _Bool reset;
  _Bool bit_in;
  _Bool preamble_1;
  _Bool preamble_2;
  _Bool preamble_3;
  _Bool carrier_loss;
  _Bool biphase_violation;
  _Bool clock_out;
  unsigned char rx_status;
  _Bool parity;
  _Bool load_A;
  _Bool load_B;
  _Bool load_buff;
  unsigned int shift_reg;
  unsigned char frame_ofs;
  _Bool   nondet_bool;
  unsigned char nondet_uchar;
  __ASTREE_volatile_input((nondet_bool));
  __ASTREE_volatile_input((nondet_uchar));
  
  initial(&clock_out, &rx_status, &parity, &load_A, &load_B, &load_buff, &shift_reg, &frame_ofs);

  reset = 1;
   xtal = nondet_uchar;
   rx_control = nondet_uchar;
   bit_in = nondet_bool;
   preamble_1 = nondet_bool;
   preamble_2 = nondet_bool; 
   preamble_3 = nondet_bool;
   carrier_loss = nondet_bool;
   biphase_violation = nondet_bool;
  daio(xtal, rx_control, reset, bit_in, preamble_1, preamble_2, preamble_3, carrier_loss, biphase_violation, &clock_out, &rx_status, &parity, &load_A, &load_B, &load_buff, &shift_reg, &frame_ofs);

  reset = 0;
  while(1) {
   xtal = nondet_uchar;
   rx_control = nondet_uchar;
   bit_in = nondet_bool;
   preamble_1 = nondet_bool;
   preamble_2 = nondet_bool; 
   preamble_3 = nondet_bool;
   carrier_loss = nondet_bool;
   biphase_violation = nondet_bool;
   
   daio(xtal, rx_control, reset, bit_in, preamble_1, preamble_2, preamble_3, carrier_loss, biphase_violation, &clock_out, &rx_status, &parity, &load_A, &load_B, &load_buff, &shift_reg, &frame_ofs);

   assert(((rx_status >> 3) & 1) != 0);
   //assert((load_A==1 || load_B==0));
  }
  return 1;
}
