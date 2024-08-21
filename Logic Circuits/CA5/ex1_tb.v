`timescale 1ns/1ns
module testb ();
    reg serIn=0,clk=0,rst=0,en=0;
    wire w_detect_moore;
    Mealy UUT(clk,rst,serIn,en,w_detect_moore);
    always #100 clk = ~clk;
    initial begin
            #50
            #200 serIn = 0; 
            #200 serIn = 1; 
            #200 serIn = 1; 
            #200 serIn = 1; 
            #200 serIn = 1; 
            #200 serIn = 1; 
            #200 serIn = 0;
            #200 $stop;
    end
endmodule