#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct state_elements_edge_det{
  _Bool ed;
};
struct state_elements_edge_det  sedge_det;

void edge_det(_Bool rst, _Bool clk, _Bool ce, _Bool i, _Bool *pe, _Bool *ne, _Bool *ee)
{
  _Bool tmp1;
  _Bool tmp0;
  
  *pe = !sedge_det.ed && i;
  *ne = sedge_det.ed && !i;
  *ee = sedge_det.ed ^ i;
  
  if(rst)
    tmp0 = FALSE;
  else if(ce)
      tmp1 = i;

  if(rst)
    sedge_det.ed = tmp0;

  else
    if(ce)
      sedge_det.ed = tmp1;
}

