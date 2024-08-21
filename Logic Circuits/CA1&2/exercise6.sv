module ex6(input[6:0] i, output[2:0] w);
    wire[1:0] m,n,p,q;
    assignlvl O1(i[0],i[1],i[2],m);
    assignlvl O2(i[3],i[4],i[5],n);
    assignlvl O3(i[6],m[0],n[0],p);
    assignlvl O4(p[1],m[1],n[1],q);
    assign w[0] = p[0];
    assign w[1] = q[0];
    assign w[2] = q[1];
endmodule

