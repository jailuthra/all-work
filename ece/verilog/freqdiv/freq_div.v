module freq_div(
	input clk,
	output reg c
);
	initial c = 1'b0;
	wire [3:0] q;
	decade_count dc(clk, q);

	always @ (posedge clk)
	begin
		if (q == 4'b1001 | q == 4'b0100)
			c <= c ^ 1;
	end

endmodule
