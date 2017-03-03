// Swap model from "Applying SAT Methods in Unbounded Symbolic Model
// Checking," by Ken McMillan.
// Initially, x[j]=j.  At each clock cycle, two adjacent numbers are
// swapped.
//
// Author: Fabio Somenzi <Fabio@Colorado.EDU>

module swap(clock,i);
    parameter K = 3;		// bits in each number
    parameter Nm1 = 7;		// highest index (must be less than 1<<K)
    input         clock;
    input [K-1:0] i;

    reg [K-1:0]   x [0:Nm1];
    reg [K-1:0]   tmp;
    wire [K-1:0]  m, p;
    integer 	  j;

    initial begin
	for (j=0; j<=Nm1; j=j+1)
	  x[j] = j;
	tmp = 0;
    end

    assign p = (i >= Nm1) ? (Nm1): i;
    assign m = (p == 0) ? Nm1 : (p-1);

    always @ (posedge clock) begin
	tmp = x[p];
	x[p] = x[m];
	x[m] = tmp;
    end

endmodule // swap

