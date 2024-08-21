`timescale 1ns/1ns
module assignlvl(input a,b,c, output[1:0] y);
    assign #(30,24) y[1] = (a&b) | (b&c) | (a&c);
    assign #(40,32) y[0] = ((~a)&(~b)&c) | ((~a)&b&(~c)) | (a&b&c) | (a&(~b)&(~c));
endmodule










