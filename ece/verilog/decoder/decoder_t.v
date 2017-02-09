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

       $dumpfile("test.vcd");
       $dumpvars(0,decoder_t);
		C = 4'b1101;
		#1;

		C = 4'b1100;
		#1;

		C = 4'b1011;
		#1;

		C = 4'b1010;
		#1;
		
		C = 4'b1001;
		#1;

		C = 4'b0010;
		#1;
		
		C = 4'b0011;
		#1;
		
		C = 4'b0100;
		#1;
		
		C = 4'b0101;
		#1;
		
		C = 4'b0110;
		#1;


	   

	end

    initial
    begin
       $monitor("At time %t, C = %b,  y = %b", $time, C , y); 
    end     
endmodule

