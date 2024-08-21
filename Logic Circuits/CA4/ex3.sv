`timescale 1ns/1ns
module PC_DFF (input D , clk, PRE, CLR, output Q, Qb);
    wire G1_o,G2_o,G3_o,G4_o;
    sr_latch_3inp G1_G2(PRE,CLR,G4_o,clk,G1_o,G2_o);
    sr_latch_3inp G3_G4(G2_o,CLR,clk,D,G3_o,G4_o);
    sr_latch_3inp G5_G6(PRE,CLR,G2_o,G3_o,Q,Qb);
endmodule