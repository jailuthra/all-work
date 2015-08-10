module test;

    reg a = 0;
    reg b = 0;
    wire y;

    initial begin
        a = 0;
        b = 0;

        # 100;
        a = 0;
        b = 1;

        # 100;
        a = 1;
        b = 0;

        # 100;
        a = 1;
        b = 1;

    end

    exor e1 (a, b, y);

    initial
        $monitor("At time %t, a = %d, b = %d, y = %d", $time, a, b, y);
endmodule
