module main(clock);
    input clock;
    reg	  req;
    wire  ack;
    wire  nd;

    initial begin
	req = 0;
    end

    assign nd = $ND(0,1);

    always @ (posedge clock)
	req = nd;
    
    reqAck ra(clock,req,ack);

endmodule // main

module reqAck(clock,req,ack);
    input	    clock;
    input	    req;
    output	    ack;

    parameter 
	idle = 2'd0,
	starting = 2'd1,
	working = 2'd2,
	done = 2'd3;
    
    reg [1:0]	    state;
    wire	    start;
    wire	    ready;

    initial begin
	state = 0;
    end

    always @ (posedge clock) begin
	case (state)
	  idle:
	      begin
		  if (req)
		      state = starting;
		  else
		      state = idle;
	      end // case: idle
	  starting:
	      begin
		  state = working;
	      end // case: starting
	  working:
	      begin
		  if (ready)
		      state = done;
		  else
		      state = working;
	      end // case: working
	  done:
	      begin
		  state = idle;
	      end // case: done
	endcase // case (state)
    end // always @ (req or ready)

    assign ack = state == done;
    assign start = state == starting;


    slaveND slv(clock,start,ready);

endmodule // reqAck


module slaveND(clock,start,ready);
    input     clock;
    input     start;
    output    ready;

    reg [1:0] count;
    wire      nd;

    initial begin
	count = 0;
    end

    assign nd = $ND(0,1);

    always @ (posedge clock) begin
	if (start)
	    count = 0;
	else if (count == 0)
	    count = count + nd;
	else
	    count = count + 1;
    end // always @ (posedge clock)

    assign ready = count == 2'b11;

endmodule // slaveND
