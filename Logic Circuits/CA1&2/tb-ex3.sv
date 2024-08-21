`timescale 1ns/1ns
module tb3();
    logic aa=0,bb=0,cc=0;
    wire[1:0] wswitch,wgate;
    switchlvl CUT1(aa,bb,cc,wswitch);
    gatelvl CUT(aa,bb,cc,wgate);
    initial begin
      #200 aa = 1;
      #200 bb = 1;
      #200 cc = 1;
      #200 aa = 0;
      #200 bb = 0;
      #200 cc = 0;
      #150 $stop;
    end
endmodule

