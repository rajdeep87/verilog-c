//#include <stdio.h>
#define TRUE 1
#define FALSE 0
struct state_elements_Random_gen{
unsigned short int Ramdom;
unsigned short int Ramdom_counter;
unsigned char Slot_time_counter;
_Bool Random_time_meet;
unsigned short int Random_sequence;
};
void Random_gen(_Bool Reset, _Bool Clk, _Bool Init, unsigned char RetryCnt, _Bool *Random_time_meet)
{
  struct state_elements_Random_gen  sRandom_gen;
  _Bool tmp10;
  _Bool tmp9;
  _Bool tmp8;
  unsigned short int tmp7;
  unsigned short int tmp6;
  unsigned short int tmp5;
  unsigned char tmp4;
  unsigned char tmp3;
  unsigned char tmp2;
  unsigned short int tmp1;
  unsigned short int tmp0;
  if(Reset)
    tmp0 = 0;

  else
    tmp1 = (sRandom_gen.Random_sequence & 511) << 1 | (!(sRandom_gen.Random_sequence >> 2 & 1) ^ (sRandom_gen.Random_sequence >> 9 & 1));

  if(RetryCnt == 0)
    sRandom_gen.Ramdom = 0x000 << 1 | sRandom_gen.Random_sequence;

  else
    if(RetryCnt == 1)
      sRandom_gen.Ramdom = 0x00 << 2 | sRandom_gen.Random_sequence >> 0 & 3;

    else
      if(RetryCnt == 2)
        sRandom_gen.Ramdom = 0x00 << 3 | sRandom_gen.Random_sequence >> 0 & 7;

      else
        if(RetryCnt == 3)
          sRandom_gen.Ramdom = 0x00 | sRandom_gen.Random_sequence >> 0 & 15;

        else
          if(RetryCnt == 4)
            sRandom_gen.Ramdom = 0x00 | sRandom_gen.Random_sequence >> 0 & 31;

          else
            if(RetryCnt == 5)
              sRandom_gen.Ramdom = 0x00 | sRandom_gen.Random_sequence >> 0 & 63;

            else
              if(RetryCnt == 6)
                sRandom_gen.Ramdom = 0x00 | sRandom_gen.Random_sequence >> 0 & 127;

              else
                if(RetryCnt == 7)
                  sRandom_gen.Ramdom = 0x00 | sRandom_gen.Random_sequence >> 0 & 255;

                else
                  if(RetryCnt == 8)
                    sRandom_gen.Ramdom = 0x00 | sRandom_gen.Random_sequence >> 0 & 511;

                  else
                    if(RetryCnt == 9)
                      sRandom_gen.Ramdom = sRandom_gen.Random_sequence >> 0 & 1023;

                    else
                      if(TRUE)
                        sRandom_gen.Ramdom = sRandom_gen.Random_sequence >> 0 & 1023;

  if(Reset)
    tmp2 = 0;

  else
    if(Init)
      tmp3 = 0;

    else
      if(!sRandom_gen.Random_time_meet)
        tmp4 = (unsigned char)(unsigned int)sRandom_gen.Slot_time_counter + 1;

  if(Reset)
    tmp5 = 0;

  else
    if(Init)
      tmp6 = sRandom_gen.Ramdom;

    else
      if((unsigned int)sRandom_gen.Ramdom_counter != 0 && (unsigned int)sRandom_gen.Slot_time_counter == 255)
        tmp7 = (unsigned short int)(unsigned int)sRandom_gen.Ramdom_counter - 1;

  if(Reset)
    tmp8 = TRUE;

  else
    if(Init)
      tmp9 = FALSE;

    else
      if((unsigned int)sRandom_gen.Ramdom_counter == 0)
        tmp10 = TRUE;

  if(Reset)
    sRandom_gen.Random_sequence = tmp0;

  else
    sRandom_gen.Random_sequence = tmp1;
  if(Reset)
    sRandom_gen.Slot_time_counter = tmp2;

  else
    if(Init)
      sRandom_gen.Slot_time_counter = tmp3;

    else
      if(!sRandom_gen.Random_time_meet)
        sRandom_gen.Slot_time_counter = tmp4;

  if(Reset)
    sRandom_gen.Ramdom_counter = tmp5;

  else
    if(Init)
      sRandom_gen.Ramdom_counter = tmp6;

    else
      if((unsigned int)sRandom_gen.Ramdom_counter != 0 && (unsigned int)sRandom_gen.Slot_time_counter == 255)
        sRandom_gen.Ramdom_counter = tmp7;

  if(Reset)
  {
    sRandom_gen.Random_time_meet = tmp8;
    *Random_time_meet = tmp8;
  }

  else
    if(Init)
    {
      sRandom_gen.Random_time_meet = tmp9;
      *Random_time_meet = tmp9;
    }

    else
      if((unsigned int)sRandom_gen.Ramdom_counter == 0)
      {
        sRandom_gen.Random_time_meet = tmp10;
        *Random_time_meet = tmp10;
      }

}
/*
void main() {
_Bool Reset;
_Bool Clk;
_Bool Init;
unsigned char RetryCnt;
_Bool Random_time_meet;
while(1) {
Random_gen(Reset, Clk, Init, RetryCnt, &Random_time_meet);
}
}*/
