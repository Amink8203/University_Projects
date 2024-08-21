module control(input clk,rst,w_detect,serOutValid,cout, output reg load_8bit,load_0,en,cnt_3_en,cnt_8_en);
    reg[2:0] ps,ns;
    parameter[2:0] Init = 0, detect = 1, cnt_3_bit = 2, cnt_load = 3, downcnt_8_bit = 4;
    always @(ps,w_detect,serOutValid,cout) begin
        ns = Init;
        {load_0,en,cnt_3_en,cnt_8_en} = 4'b0;
        case (ps)
            Init : begin ns = detect; en=1;load_0=1; end 
            detect : begin ns = w_detect ? cnt_3_bit : detect; en=w_detect?0:1; end 
            cnt_3_bit : begin ns = serOutValid ? cnt_load : cnt_3_bit; cnt_3_en = serOutValid?0:1; end 
            cnt_load : begin ns = downcnt_8_bit; load_8bit=1;cnt_8_en=1; end 
            downcnt_8_bit : begin ns = cout ? Init : downcnt_8_bit; load_8bit=0;cnt_8_en = cout ? 0:1; end 
            default: ns = Init;
        endcase 
    end
    always @(posedge clk,posedge rst) begin
        if(rst)
            ps <= Init;
        else
            ps <= ns;        
    end
endmodule







// module control(input clk,rst,start,w_detect,serOutValid,cout, output reg load_8bit,load_0,en,cnt_3_en,cnt_8_en,ready);
//     reg[2:0] ps,ns;
//     parameter[2:0] Idle = 0,Init = 1, detect = 2, cnt_3_bit = 3, cnt_load = 4, downcnt_8_bit = 5;

//     always @(ps,start,w_detect,serOutValid,cout) begin
//         ns = Idle;
//         {load_0,en,cnt_3_en,cnt_8_en,ready} = 5'b0;
//         case (ps)
//             Idle : begin ns = start ? Init : Idle; ready = 1'b1; end 
//             Init : begin ns = start ? Init : detect; en=1;load_0=1;cnt_3_en=0;cnt_8_en=0; end 
//             detect : begin ns = w_detect ? cnt_3_bit : detect; en=w_detect?0:1; end 
//             cnt_3_bit : begin ns = serOutValid ? cnt_load : cnt_3_bit; cnt_3_en = serOutValid?0:1; end 
//             cnt_load : begin ns = downcnt_8_bit; load_8bit=1;cnt_8_en=1; end 
//             downcnt_8_bit : begin ns = cout ? Idle : downcnt_8_bit; load_8bit=0;cnt_8_en = 1; end 
//             default: ns = Idle;
//         endcase 
//     end
//     always @(posedge clk,posedge rst) begin
//         if(rst)
//             ps <= Idle;
//         else
//             ps <= ns;        
//     end
// endmodule