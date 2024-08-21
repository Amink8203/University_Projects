`timescale 1ns/1ns
module q3_tb();
    logic d = 0, clk = 0, pre = 1, clr = 1;
    wire Q, Qb;
    PC_DFF pcdff (d, clk, pre , clr, Q, Qb);
    always #100 clk = ~clk;
    initial begin
        repeat (20) #150 {d,pre,clr} = $random;
        #200 $stop;
    end
endmodule