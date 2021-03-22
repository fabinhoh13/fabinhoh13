module giroflex(L1, L2, L3, L4, L5, L6, L7, L8, CLK);
	input CLK;
	output reg L1, L2, L3, L4, L5, L6, L7, L8;

	initial begin
		L1 = 1'b1;
		L2 = 1'b0;
		L3 = 1'b0;
		L4 = 1'b0;
		L5 = 1'b0;
		L6 = 1'b0;
		L7 = 1'b0;
		L8 = 1'b1;
	end

	always @(posedge CLK) begin 
		if (L1 == 1'b1 && L2 == 1'b0 && L3 == 1'b0 && L4 == 1'b0 && L5 == 1'b0 && L6 == 1'b0 && L7 == 1'b0 && L8 == 1'b1) begin
			L1 = 1'b0;
			L3 = 1'b1;
			L6 = 1'b1;
			L8 = 1'b0;
		end
		else if (L1 == 1'b0 && L2 == 1'b0 && L3 == 1'b1 && L4 == 1'b0 && L5 == 1'b0 && L6 == 1'b1 && L7 == 1'b0 && L8 == 1'b0) begin
			L2 = 1'b1;
			L3 = 1'b0;
			L6 = 1'b0;
			L7 = 1'b1;
		end
		else if (L1 == 1'b0 && L2 == 1'b1 && L3 == 1'b0 && L4 == 1'b0 && L5 == 1'b0 && L6 == 1'b0 && L7 == 1'b1 && L8 == 1'b0) begin
			L2 = 1'b0;
			L7 = 1'b0;
			L4 = 1'b1;
			L5 = 1'b1;
		end
		else if (L1 == 1'b0 && L2 == 1'b0 && L3 == 1'b0 && L4 == 1'b1 && L5 == 1'b1 && L6 == 1'b0 && L7 == 1'b0 && L8 == 1'b0) begin
			L1 = 1'b1;
			L2 = 1'b1;
			L3 = 1'b1;
			L4 = 1'b1;
			L5 = 1'b1;
			L6 = 1'b1;
			L7 = 1'b1;
			L8 = 1'b1;
		end
	end

endmodule