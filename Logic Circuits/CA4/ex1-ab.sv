`timescale 1ns/1ns
module sr_latch_2inp (input S, R, output Q, Qb);
    nand #8 Snand (Q, Qb, S);
    nand #8 Rnand (Qb, Q, R);
endmodule

module sr_latch_3inp (input S1, R1, S2, R2, output Q, Qb);
    nand #12 Snand (Q, S1, S2, Qb);
    nand #12 Rnand (Qb, R1, R2, Q);
endmodule
