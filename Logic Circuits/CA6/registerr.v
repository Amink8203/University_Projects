module register(input clk,rst,ld,init,input[15:0] PIn, output reg [15:0] PO);
	always @(posedge clk,posedge rst) begin
        if(rst)
            PO <= 16'b0;
        else if(init)
            PO <= 16'b0000000011111111;
        else
            PO <= (ld) ? PIn : PO;
    end
endmodule