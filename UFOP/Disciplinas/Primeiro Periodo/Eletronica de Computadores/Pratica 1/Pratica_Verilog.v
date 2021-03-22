module cobrir(S, C, E, D, FECHAR, ABRIR);

	input S, C, E, D;
	output FECHAR, ABRIR;
	reg FECHAR, ABRIR;

	always@(*) begin 
		ABRIR = ~E&~S&~C;
		FECHAR = ~D&C | ~D&S;
	end
	
endmodule

module simulacao;
	reg T_S, T_C, T_E, T_D;
	wire T_FECHAR, T_ABRIR;

	initial begin
		T_S = 0;
		T_C = 0;
		T_E = 0;
		T_D = 0;
	end

	initial begin
		#16 $stop;
	end

	initial begin
		$display("\t \t TEMPO  D  E  S   C  FECHAR ABRIR");
		$monitor("%d   %b   %b   %b   %b   %b   %b", $time, T_D, T_E, T_S, T_C, T_FECHAR, T_ABRIR);
	end

	always begin
		#1 {T_D, T_E, T_S, T_C} = {T_D, T_E, T_S, T_C} + 1;
	end

	cobrir variaveis(.S(T_S), .C(T_C), .E(T_E), .D(T_D), .FECHAR(T_FECHAR), .ABRIR(T_ABRIR));

endmodule

