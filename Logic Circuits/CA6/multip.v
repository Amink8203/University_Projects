module multip(input [15:0] data,X_pow,input sel,output [15:0] mux_out);
	assign mux_out = sel ? X_pow : data;
endmodule