module exor(
    input a,
    input b,
    output y
    );
	 
	 wire n_a, n_b;
	 wire o, p;
	 
	 not N1(n_a, a);
	 not N2(n_b, b);
	 and A1(o, n_a, b);
	 and A2(p, n_b, a);
	 or O1(y, o, p);
	 

endmodule
