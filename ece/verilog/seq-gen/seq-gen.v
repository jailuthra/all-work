module sequence(
	input clk,
	output y
);

	reg [2:0] shift;

	initial shift = 3'b100;
	wire in;
	assign in = shift[2]&(~shift[0]) | (~shift[2])&(~shift[1]);
	assign y = shift[2];

	always @ (posedge clk)
	begin
		shift[0] <= in;
		shift[1] <= shift[0];
		shift[2] <= shift[1];
	end

endmodule
