module transmittor(input [7:0] parin_8_cnt, input clk,rst,load,cnt_8_en, output reg[7:0] parout_8_cnt,output cout);

    always @(posedge clk , posedge rst) begin
        if(rst)
            parout_8_cnt <= 8'd0;
        else begin
            if(load)
                parout_8_cnt <= parin_8_cnt;
            else if(cnt_8_en)
                parout_8_cnt <= parout_8_cnt - 1;
        end                    
    end
    assign cout = ~|{cnt_8_en,parout_8_cnt};
endmodule