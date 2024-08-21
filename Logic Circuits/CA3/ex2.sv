`timescale 1ns/1ns
module AB_AND1(output signed [15:0]out,input signed [15:0] inA,input signed [15:0] inB);
    assign out = inA & inB;
endmodule

module AB_OR1(output signed [15:0]out,input signed [15:0] inA,input signed [15:0] inB);
    assign out = inA | inB;
endmodule

module AB_CONCAT1(output signed [15:0]out,input signed [15:0] inA,input signed [15:0] inB);
    assign out = {inA[7:0], inB[7:0]};
endmodule

module COMPLEMENT1(output signed [15:0]out,input signed [15:0] inA);
    assign out = ~inA;
endmodule

module SHIFT1(output signed [15:0]out,input signed [15:0] inB);
    assign out = inB >>> 1;
endmodule


module MUX4TO1A1(output signed [15:0]out,input [2:0] opc,input signed [15:0] inA,input signed [15:0] inA_comp);
    assign out = 
        (opc[1:0] == 2'b00) ? inA_comp:
        ((opc[1:0] == 2'b01) || (opc[1:0] == 2'b10) || (opc[1:0] == 2'b11)) ? inA:
        16'b0;
endmodule

module MUX4TO1B1(output signed [15:0]out,input [2:0] opc,input signed [15:0] inB,input signed [15:0] inB_shifted);
    assign out = 
        ((opc[1:0] == 2'b00) || (opc[1:0] == 2'b01)) ? 16'b0:
        (opc[1:0] == 2'b10) ? inB:
        (opc[1:0] == 2'b11) ? inB_shifted:
        16'b0;
endmodule

module MUX4TO1CONTROL1(output out,input [2:0] opc,input inC);
    assign out = 
        ((opc[1:0] == 2'b00) || (opc[1:0] == 2'b01)) ? 1'b1:
        (opc[1:0] == 2'b10) ? inC:
        (opc[1:0] == 2'b11) ? 1'b0:
        1'b0;
endmodule

module FIRST4OPS1(output signed [15:0]out,input signed [15:0] inA_new,input signed [15:0] inB_new,input inC_new);
    assign out = inA_new + inB_new + inC_new;
endmodule

module LAST3OPS1(output signed [15:0]out,input [2:0] opc,input signed [15:0] A_B_anded,input signed [15:0] A_B_concat,input signed [15:0] A_B_ored);
    assign out = 
        (opc[1:0] == 2'b00) ? A_B_anded:
        (opc[1:0] == 2'b01) ? A_B_ored:
        (opc[1:0] == 2'b10) ? A_B_concat:
        16'b0;   
endmodule


module ALU_ex21(
    output logic signed [15:0] outW,
    output neg, zer,
    input signed [15:0] inA, inB,
    input inC,
    input [2:0] opc
);
    wire control_mux;
    wire[15:0] a_mux, b_mux, a_comp, b_shift, a_b_ored, a_b_anded, a_b_concat, first4ops, last3ops;
    AB_AND1 anding(a_b_anded,inA,inB);
    AB_OR1 oring(a_b_ored,inA,inB);
    AB_CONCAT1 concating(a_b_concat,inA,inB);
    COMPLEMENT1 complementing(a_comp,inA);
    SHIFT1 shifting(b_shift,inB);
    MUX4TO1A1 A_mux(a_mux,opc,inA,a_comp);    
    MUX4TO1B1 B_mux(b_mux,opc,inB,b_shift);    
    MUX4TO1CONTROL1 Control_mux(control_mux,opc,inC);
    FIRST4OPS1 F_OPS(first4ops,a_mux,b_mux,control_mux);
    LAST3OPS1 L_OPS(last3ops,opc,a_b_anded,a_b_concat,a_b_ored);
    assign outW = 
        (opc[2:0] == 3'b111) ? 16'b0:
        (opc[2] == 1'b0) ? first4ops:
        (opc[2] == 1'b1) ? last3ops:
        16'b0; 
    assign neg = outW[15];
    assign zer = ~|outW;
endmodule