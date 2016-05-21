module freq_test;
	reg clk;
	wire c;

	freq_div uut (
		.clk(clk),
		.c(c)
	);

	initial begin
		$dumpfile("freq_test.lxt");
		$dumpvars(0, freq_test);
		clk = 1'b0;
		forever #5 clk = ~clk;
	end
	
	initial #200 $finish;

endmodule
