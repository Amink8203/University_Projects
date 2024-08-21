`timescale 1ns/1ns
module TB();
    wire signed [15:0] ex1,ex2,yosys1,yosys2;
    wire zer1, neg1, neg2,zer2, neg3,zer3, neg4,zer4;
    logic signed [15:0] inA, inB;
    logic inC;
    logic [2:0] opc;
    ALU_ex12 tb1(ex1,neg1,zer1,inA,inB,inC,opc);
    ALU_ex21 tb3(ex2,neg2,zer2,inA,inB,inC,opc);
    ALU_yosys12 tb2(yosys1,neg3,zer3,inA,inB,inC,opc);
    ALU_yosys21 tb4(yosys2,neg4,zer4,inA,inB,inC,opc);

    initial begin
        opc = 3'b000;
	    inC = 1'b1;
        inA = 16'd243;
        inB = 16'd3210;
        inC = 1'b0;
        
        #200 opc = 3'b000;
	    #200 opc = 3'b001;
        #200 opc = 3'b010;
        #200 opc = 3'b011;
        #200 opc = 3'b100;
        #200 opc = 3'b101;
        #200 opc = 3'b110;
        #200 opc = 3'b111;
	
        repeat(100) begin
          #200
	      inB = $random;
          opc = $random;
          inA = $random;
	      inC = $random;
        end
        #200 $stop;
    end

endmodule
