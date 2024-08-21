`timescale 1ns/1ns
module tb12();
    logic aa=0,bb=0,cc=0;
    wire[1:0] y;
    switchlvl CUT1(aa,bb,cc,y);
    initial begin
      #150 aa = 1;
      #150 bb = 1;
      #150 cc = 1;
      #150 aa = 0;
      #150 bb = 0;
      #150 cc = 0;
      #200 $stop;
    end
endmodule
