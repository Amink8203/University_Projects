module  romm_file(
addr,
q     
);
//-----------Input Ports---------------
input [2:0] addr ;
output reg [15:0] q ;

(* romstyle = "M9K" *)(* ram_init_file = "romm_file.mif" *)  reg  [15:0] rom [2:0];

	always @ (addr)
	begin
		q <= rom[addr];
	end 

endmodule 