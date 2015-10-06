module decoder(
    input [3:0] C,
    output [3:0] y
    );
	
	mux41 M0({1'b1,1'b0,1'b1,1'b0}, C[1:0], y[0]);
	mux41 M1({~C[3], 1'b0, C[3]&~C[2], 1'b1}, C[1:0], y[1]);
	mux41 M2({~C[3], C[3]&~C[2], ~C[3]&~C[2], ~C[3]}, C[1:0], y[2]);
	mux41 M3({1'b0, ~C[3]&C[2], ~C[3]&C[2], 1'b0}, C[1:0], y[3]);

endmodule
