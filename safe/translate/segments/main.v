// Simple FSM illustrating that convergence of the dijunction of the partial
// iterates may occur when the fixpoint has not been reached yet in the
// segmented approach to EG computation.
//
// Author: Fabio Somenzi <Fabio@Colorado.EDU>
// Modified By: Rajdeep Mukherjee <rajdeep.mukherjee@cs.ox.ac.uk>

module main(clock,i, o, state);
    input clock,i;
    output o;
    output state;
    reg state;

    parameter A = 0;
    parameter B = 1;
    parameter C = 2;
    parameter D = 3;
    parameter E = 4;
    
    initial state = A;

  always @ (posedge clock) begin
	 case (state)
	  0: state = i ? B : A;
	  1: state = i ? C : D;
	  2: state = B;
	  3: state = E;
	  4: state = E;
	 endcase // case(state)
  end
  assign o = state == A;
  assert property3: (state == A || state == B || state == C || state == D || state == E);
endmodule // sg1

module test();
 wire clock, i, o, state;
  
 parameter A = 0;
 parameter B = 1;
 parameter C = 2;
 parameter D = 3;
 parameter E = 4;
 main m1(clock,1'b0, o, state);
 assert property1: !(i==0) || (state == A); 
 main m2(clock,1'b1, o, state);
 assert property2: !(i==1) || (state == B); 
endmodule 
