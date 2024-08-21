module Mealy (input clk,rst,serIn,en,output w_detect);
    reg[2:0] ns,ps;
    parameter [2:0] A=3'b000,B=3'b001,C=3'b010,D=3'b011,E=3'b100,F=3'b101,G=3'b110;

    always @(ps,serIn) begin
        ns = A;
        case (ps)
            A: ns= serIn ? A:B;
            B: ns= serIn ? C:B;
            C: ns= serIn ? D:B;
            D: ns= serIn ? E:B;
            E: ns= serIn ? F:B;
            F: ns= serIn ? G:B;
            G: ns= serIn ? A:B;
            default: ns=A; 
        endcase
    end
    assign w_detect = (ps == G)? ~serIn: 1'b0;
    always @(posedge clk,posedge rst) begin
        if(rst)
            ps<=A;
        else if(~en)
            ps <= A;
        else
            ps<=ns;
    end
endmodule