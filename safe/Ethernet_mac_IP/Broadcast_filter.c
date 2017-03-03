//#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_Broadcast_filter{
 unsigned short int time_counter;
 unsigned short int broadcast_counter;
 _Bool broadcast_drop;
};

void Broadcast_filter(_Bool Reset, _Bool Clk, _Bool broadcast_ptr, _Bool *broadcast_drop, _Bool broadcast_filter_en, unsigned short int broadcast_bucket_depth, unsigned short int broadcast_bucket_interval)
{
  struct state_elements_Broadcast_filter  sBroadcast_filter;
  _Bool tmp8;
  _Bool tmp7;
  _Bool tmp6;
  unsigned short int tmp5;
  unsigned short int tmp4;
  unsigned short int tmp3;
  unsigned short int tmp2;
  unsigned short int tmp1;
  unsigned short int tmp0;
  if(Reset)
    tmp0 = 0;

  else
    if(sBroadcast_filter.time_counter == broadcast_bucket_interval)
      tmp1 = 0;

    else
      tmp2 = (unsigned short int)(unsigned int)sBroadcast_filter.time_counter + 1;
  if(Reset)
    tmp3 = 0;

  else
    if(sBroadcast_filter.time_counter == broadcast_bucket_interval)
      tmp4 = 0;

    else
      if(broadcast_ptr && sBroadcast_filter.broadcast_counter != broadcast_bucket_depth)
        tmp5 = (unsigned short int)(unsigned int)sBroadcast_filter.broadcast_counter + 1;

  if(Reset)
    tmp6 = FALSE;

  else
    if(broadcast_filter_en && sBroadcast_filter.broadcast_counter == broadcast_bucket_depth)
      tmp7 = TRUE;

    else
      tmp8 = FALSE;
  if(Reset)
    sBroadcast_filter.time_counter = tmp0;

  else
    if(sBroadcast_filter.time_counter == broadcast_bucket_interval)
      sBroadcast_filter.time_counter = tmp1;

    else
      sBroadcast_filter.time_counter = tmp2;
  if(Reset)
    sBroadcast_filter.broadcast_counter = tmp3;

  else
    if(sBroadcast_filter.time_counter == broadcast_bucket_interval)
      sBroadcast_filter.broadcast_counter = tmp4;

    else
      if(broadcast_ptr && sBroadcast_filter.broadcast_counter != broadcast_bucket_depth)
        sBroadcast_filter.broadcast_counter = tmp5;

  if(Reset)
  {
    sBroadcast_filter.broadcast_drop = tmp6;
    *broadcast_drop = tmp6;
  }

  else
    if(broadcast_filter_en && sBroadcast_filter.broadcast_counter == broadcast_bucket_depth)
    {
      sBroadcast_filter.broadcast_drop = tmp7;
      *broadcast_drop = tmp7;
    }

    else
    {
      sBroadcast_filter.broadcast_drop = tmp8;
      *broadcast_drop = tmp8;
    }
}

/*
void main() {
_Bool Reset;
_Bool Clk;
_Bool broadcast_ptr;
_Bool broadcast_drop;
_Bool broadcast_filter_en;
unsigned short int broadcast_bucket_depth;
unsigned short int broadcast_bucket_interval;

 while(1) {
  Broadcast_filter(Reset, Clk, broadcast_ptr, &broadcast_drop, broadcast_filter_en, broadcast_bucket_depth, broadcast_bucket_interval);
 }
} */
