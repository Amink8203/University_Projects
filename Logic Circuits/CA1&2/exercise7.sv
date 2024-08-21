module ex7(input[14:0] i, output[3:0] w);
    wire[2:0] m,n;
    wire[1:0] p,q,r;
    ex5 O1(i[6:0],m);
    ex5 O2(i[13:7],n);
    assignlvl O3(i[14],m[0],n[0],p);
    assignlvl O4(p[1],m[1],n[1],q);
    assignlvl O5(q[1],m[2],n[2],r);
    assign w[0] = p[0];
    assign w[1] = q[0];
    assign w[2] = r[0];
    assign w[3] = r[1];
endmodule


