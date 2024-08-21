`timescale 1ns/1ns
module q1_tb ();
    logic S,R;
    wire Q1, QB1;
    wire Q2, QB2;
    sr_latch_2inp _2inp(S, R, Q1, QB1);
    sr_latch_3inp _3inp(S, R, S, R, Q2, QB2);

    initial begin
            S = 0; R = 1;
            #200 S = 0; R = 1;
            #200 S = 1; R = 1;
            #200 S = 1; R = 0;
            #200 S = 0; R = 0;
            #200 S = 1; R = 0;
            #200 S = 0; R = 0;
            #200 S = 1; R = 1;
            #200 S = 1; R = 0;
            #100 $stop;
    end

endmodule