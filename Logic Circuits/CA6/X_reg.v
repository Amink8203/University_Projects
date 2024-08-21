module X_reg(input clk,rst,ld,input[15:0] PIn, output reg [15:0] PO);
	always @(posedge clk,posedge rst) begin
        if(rst)
            PO <= 16'b0;
        else
            PO <= (ld) ? PIn : PO;
    end
endmodule