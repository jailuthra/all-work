module seq_t;
	// Inputs
	reg clk;

	// Outputs
	wire y;

	sequence uut (
		.clk(clk),
		.y(y)
	);

	initial begin
		$dumpfile("seq_t.lxt");
		$dumpvars(0,seq_t);
		clk = 1'b0;
		forever #5 clk = ~clk;
	end

	initial #200 $finish;

	initial
		$monitor("Time: %t, clk = %b, y = %b", $time, clk, y);

endmodule
