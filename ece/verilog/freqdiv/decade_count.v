module decade_count (
	input clock,
	output reg [3:0] q
);
	
	initial q = 4'b1001;

	always @ (posedge clock)
	begin
		if (q == 4'b1001)
			q <= 4'b0000;
		else
			q <= q + 4'b0001;
	end

endmodule
