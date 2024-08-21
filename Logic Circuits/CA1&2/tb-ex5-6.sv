`timescale 1ns/1ns
module tb56();
    logic[6:0] t = 0;
    wire[2:0] outswitch,outassign;
    ex5 CUT1(t,outswitch);
    ex6 CUT2(t,outassign);
    initial begin
      #200 t[0] = 1;
      #200 t[5] = 1;
      #200 t[1] = 1;
      #200 t[3] = 1;
      #200 t[2] = 1;
      #200 t[6] = 1;
      #200 t[4] = 1;

      #200 t[0] = 0;
      #200 t[5] = 0;
      #200 t[1] = 0;
      #200 t[3] = 0;
      #200 t[2] = 0;
      #200 t[6] = 0;
      #200 t[4] = 0;
      #250 $stop;
    end
endmodule


