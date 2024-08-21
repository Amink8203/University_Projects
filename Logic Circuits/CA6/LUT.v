module LUT(input [2:0] address, output [15:0] data);
    reg [15:0] temp;
    always @(address) begin
        case(address)
            0: temp = 16'h0080;
            1: temp = 16'h0015; 
            2: temp = 16'h0008;
            3: temp = 16'h0004;
            4: temp = 16'h0002;
            5: temp = 16'h0001;
            6: temp = 16'h0001;
            7: temp = 16'h0001;
        endcase
    end
    assign data = temp;
endmodule