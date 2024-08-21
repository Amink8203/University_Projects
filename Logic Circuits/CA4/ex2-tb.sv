`timescale 1ns/1ns
module q2_tb();
    logic d = 1, clk = 0;
    wire Q, Qb;
    Edge_DFF DFF (d, clk, Q, Qb);    
    always #100 clk = ~clk;
    initial begin
        repeat (20) #150 d = $random;
        #200 $stop;
    end
endmodule
    
