// Right rotator.
//
// Author: Fabio Somenzi <Fabio@Colorado.EDU>


module rotate(clock,amount,din,dout);
    input	      clock;
    input [1:0] amount;
    input [3:0]    din;
    output [3:0]   dout;

    reg [3:0]      dout;
    reg [3:0]      inr;

    wire [3:0] tmp0;
    wire [3:0] tmp1;
    wire [3:0] tmp2;

    initial begin
	dout = 0;
	inr = 0;
    end

    assign tmp0 = inr;
    assign tmp1 = amount[0] ?
	{tmp0[0:0], tmp0[3:1]} : tmp0;
    assign tmp2 = amount[1] ?
	{tmp1[1:0], tmp1[3:2]} : tmp1;

    always @ (posedge clock) begin
	dout = tmp2;
	inr = din;
    end // always @ (posedge clock)

endmodule // rotate
