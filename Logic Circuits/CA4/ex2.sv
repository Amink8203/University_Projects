`timescale 1ns/1ns
module Edge_DFF (input D , clk, output Q, Qb);
    wire G1_o,G2_o,G3_o,G4_o;
    sr_latch_2inp G1_G2(G4_o,clk,G1_o,G2_o);
    sr_latch_3inp G3_G4(G2_o,D,clk,D,G3_o,G4_o);
    sr_latch_2inp G5_G6(G2_o,G3_o,Q,Qb);
endmodule