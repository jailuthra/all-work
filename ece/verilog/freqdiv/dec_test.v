module dec_test;
	reg clock;
	wire [3:0] q;

	decade_count uut(
		.clock(clock),
		.q(q)
	);

	initial begin
		$dumpfile("dec_test.lxt");
		$dumpvars(0, dec_test);
		clock = 1'b0;
		forever #5 clock = ~clock;
		$monitor("Time: %t, clk = %b, q = %b", $time, clock, q);
	end

	initial #200 $finish;

endmodule
