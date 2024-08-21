`timescale 1ns/1ns
module switchlvl(input a,b,c, output[1:0] y);
    supply1 vdd;
    supply0 gnd;
    wire wp0,wp1,wp2,wp3,wp4,wp5;
    wire wn0,wn1,wn2;
    pmos #(5,6,7) P0(wp0,vdd,a),P1(wp1,wp0,b),P2(y[0],wp1,~c),P3(wp2,wp0,~b),P4(y[0],wp2,c);
    pmos #(5,6,7) P5(wp3,vdd,~a),P6(wp4,wp3,b),P7(y[0],wp4,c),P8(wp5,wp3,~b),P9(y[0],wp5,~c);
    nmos #(3,4,5) N0(wn0,gnd,b),N1(wn0,gnd,c),N2(wn1,wn0,~b),N3(wn1,wn0,~c),N4(wn1,gnd,~a);
    nmos #(3,4,5) N5(wn2,wn1,b),N6(wn2,wn1,~c),N7(y[0],wn2,~b),N8(y[0],wn2,c),N9(y[0],wn1,a);
    wire w0,w1;
    wire n0,n1;
    pmos #(5,6,7) P10(w0,vdd,~a), P11(y[1],w0,~b),P12(y[1],w0,~c),P13(w1,vdd,~b),P14(y[1],w1,~c);
    nmos #(3,4,5) N10(n0,gnd,~c),N11(n1,n0,~b),N12(n1,gnd,~a),N13(y[1],n1,~b),N14(y[1],n1,~c);
endmodule
