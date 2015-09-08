module mux41(
    input [0:3] I,
    input [1:0] S,
    output y
    );

	assign y = ~S[1]&~S[0]&I[0] | ~S[1]&S[0]&I[1] | S[1]&~S[0]&I[2] | S[1]&S[0]&I[3];

endmodule
