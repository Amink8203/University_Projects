`timescale 1ns/1ns
module gatelvl(input a,b,c, output[1:0] y);
    wire o1,o2,o3;
    nand #(10,8) NA1(o1,~b,~c),NA2(o2,o1,a),NA3(o3,b,c),NA4(y[1],o2,o3);
    wire m1,m2,m3,m4,m5,m6,m7,m8;
    nand #(10,8) an1(m1,~b,c),an2(m2,b,~c),an3(m3,m2,m1),an4(m4,~a,m3);
    nand #(10,8) an5(m5,b,c),an6(m6,~b,~c),an7(m7,m6,m5),an8(m8,a,m7);
    nand #(10,8) an9(y[0],m4,m8);
endmodule



