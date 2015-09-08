module decoder_t;

	// Inputs
	reg [3:0] C;

	// Outputs
	wire [3:0] y;

	// Instantiate the Unit Under Test (UUT)
	decoder uut (
		.C(C), 
		.y(y)
	);

	initial begin

		C = 4'b1101;
		#100;

		C = 4'b1100;
		#100;

		C = 4'b1011;
		#100;

		C = 4'b1010;
		#100;
		
		C = 4'b1001;
		#100;

		C = 4'b0010;
		#100;
		
		C = 4'b0011;
		#100;
		
		C = 4'b0100;
		#100;
		
		C = 4'b0101;
		#100;
		
		C = 4'b0110;
		#100;


	   

	end

    initial
       $monitor("At time %t, C = %b,  y = %b", $time, C , y); 
      
endmodule

