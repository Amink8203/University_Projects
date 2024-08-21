`timescale 1ns/1ns
module tb4();
    logic aa=0,bb=0,cc=0;
    wire[1:0] wswitch,wgate,wassign;
    switchlvl CUT1(aa,bb,cc,wswitch);
    gatelvl CUT2(aa,bb,cc,wgate);
    assignlvl CUT3(aa,bb,cc,wassign);
    initial begin
      #200 aa = 1;
      #200 bb = 1;
      #200 cc = 1;
      #200 aa = 0;
      #200 bb = 0;
      #200 cc = 0;
      #250 $stop;
    end
endmodule

