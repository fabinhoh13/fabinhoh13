module mux1(f1, f3, f5, f7, fx, gl0, gl1);
  input f1, f3, f5, f7, gl0, gl1;
  output fx;
  reg fx;


  always @(*) begin
    case({gl0, gl1})
      'b00: fx = f1;
      'b01: fx = f3;
      'b10: fx = f5;
      'b11: fx = f7;
    endcase
  end
endmodule

module mux2(f2, f4, f6, f8, fy, gl0, gl1);
  input f2, f4, f6, f8, gl0, gl1;
  output fy;
  reg fy;


  always @(*) begin
    case({gl0, gl1})
      'b00: fy = f2;
      'b01: fy = f4;
      'b10: fy = f6;
      'b11: fy = f8;
    endcase
  end
endmodule

module and1(fx, fy, comando, enable, result0);
  input fx, fy, comando, enable;
  output result0;
  reg result0;

  always @(enable) begin 
      result0 = (~fx) & (~fy) & (~comando) & enable;
  end
endmodule

module and2(fx, fy, comando, enable, result1);
  input fx, fy, comando, enable;
  output result1;
  reg result1;

  always @(enable) begin
      result1 = (~fx) & (~fy) & (comando) & enable;
  end 
endmodule

module DEMUX1(gl0, gl1, result0, s0, s1, s2, s3);
  input gl0, gl1, result0;
  output s0, s1, s2, s3;
  reg s0, s1, s2, s3;

  always @(*) begin
    case({gl0, gl1})
      'b00: s0 = result0;
      'b01: s1 = result0;
      'b10: s2 = result0;
      'b11: s3 = result0;
    endcase
  end
endmodule

module DEMUX2(gl0, gl1, result1, s0, s1, s2, s3);
  input gl0, gl1, result1;
  output s0, s1, s2, s3;
  reg s0, s1, s2, s3;

  always @(*) begin
    case({gl0, gl1})
      'b00: s0 = result1;
      'b01: s1 = result1;
      'b10: s2 = result1;
      'b11: s3 = result1;
    endcase
  end
endmodule

module busy(enable, b);
	input enable;
	output b;
	reg b;

	always @(*)
    	begin
        	b = enable;
    	end
    	
endmodule

module topMUX1;
	reg tf1, tf3, tf5, tf7, tgl0, tgl1;
	wire tfx;

	initial
		begin
			tf1 = 0;
			tf3 = 0;
			tf5 = 0;
			tf7 = 0;
			tgl0 = 0;
			tgl1 = 0;
		end
	
	initial
		begin
			#64 $stop;
		end

	always 
		begin
			#1 {tf1, tf3, tf5, tf7, tgl0, tgl1} = {tf1, tf3, tf5, tf7, tgl0, tgl1} + 1;
		end

	initial
		begin
			$display("f1 f3 f5 f7 gl0 gl1 fx");
			$monitor("%b %b %b %b  %b  %b %b",tf1, tf3, tf5, tf7, tgl0, tgl1, tfx);
		end

	topMUX1 m(.f1(tf1), .f3(tf3), .f5(tf5), .f7(tf7), .gl0(tgl0), .gl1(tgl1), .fx(tfx));

endmodule

module topMUX2;	
	reg tf2, tf4, tf6, tf8, tgl0, tgl1;
	wire tfy;

	initial
		begin
			tf1 = 0;
			tf3 = 0;
			tf5 = 0;
			tf7 = 0;
			tgl0 = 0;
			tgl1 = 0;
		end
	
	initial
		begin
			#64 $stop;
		end

	always 
		begin
			#1 {tf2, tf4, tf6, tf8, tgl0, tgl1} = {tf2, tf4, tf6, tf8, tgl0, tgl1} + 1;
		end

	initial
		begin
			$display("f2 f4 f6 f8 gl0 gl1 fy");
			$monitor("%b %b %b %b  %b  %b %b",tf2, tf4, tf6, tf8, tgl0, tgl1, tfy);
		end

	topMUX2 m2(.f2(tf2), .f4(tf4), .f6(tf6), .f8(tf8), .gl0(tgl0), .gl1(tgl1), .fy(tfy));

endmodule

module topAND1;
	reg tfx, tfy, tcomando, tenable;
    wire tresult0;

    initial
        begin
            tfx = 0;
            tfy = 0;
            tcomando = 0;
            tenable = 0;
       	end

    initial
    	begin
    		#16 $stop;
     	end

    always
    	begin
        	#1 {tfx,tfy,tcomando,tenable} = {tfx,tfy,tcomando,tenable} + 1;
     	end

    initial
    	begin
    		$display("Fx Fy Comando Enable Result0");
    		$monitor("%b %b   %b      %b     %b",tfx,tfy,tcomando,tenable,tesult0);
  		end

  topAND1 a(.fx(tfx),.fy(tfy),.comando(tcomando),.enable(tenable),.result0(tresult0));
	
endmodule

module topAND2;
	reg tfx, tfy, tcomando, tenable;
    wire tresult1;

    initial
        begin
            tfx = 0;
            tfy = 0;
            tcomando = 0;
            tenable = 0;
       	end

    initial
    	begin
    		#16 $stop;
     	end

    always
    	begin
        	#1 {tfx,tfy,tcomando,tenable} = {tfx,tfy,tcomando,tenable} + 1;
     	end

    initial
    	begin
    		$display("Fx Fy Comando Enable Result1");
    		$monitor("%b %b   %b      %b     %b",tfx,tfy,tcomando,tenable,tesult1);
  		end

  topAND2 a2(.fx(tfx),.fy(tfy),.comando(tcomando),.enable(tenable),.result1(tresult1));
	
endmodule

module topDEMUX1;
	reg tgl0, tgl1, tresult0;
	wire ts0, ts1, ts2, ts3;

	initial
		begin
			tresult0 = 0;
			tgl0 = 0;
			tgl1 = 0;
		end
	
	initial
		begin
			#8 $stop;
		end

	always 
		begin
			#1 {tgl0, tgl1, tresult0} = {tgl0, tgl1, tresult0} + 1;
		end

	initial
		begin
			$display("gl0 gl1 result0 s0 s1 s2 s3");
			$monitor(" %b  %b    %b   %b %b %b %b",tgl0, tgl1, tresult0, ts0, ts1, ts2, ts3);
		end

	topDEMUX1 dm1(.gl0(tgl0), .gl1(tgl1), .result0(tresult0), .s0(ts0), .s1(ts1), .s2(ts2), .s3(ts3));
	
endmodule

module topDEMUX2;
	reg tgl0, tgl1, tresult1;
	wire ts0, ts1, ts2, ts3;

	initial
		begin
			tresult1 = 0;
			tgl0 = 0;
			tgl1 = 0;
		end
	
	initial
		begin
			#8 $stop;
		end

	always 
		begin
			#1 {tgl0, tgl1, tresult1} = {tgl0, tgl1, tresult1} + 1;
		end

	initial
		begin
			$display("gl0 gl1 result1 s0 s1 s2 s3");
			$monitor(" %b  %b    %b   %b %b %b %b",tgl0, tgl1, tresult1, ts0, ts1, ts2, ts3);
		end

	topDEMUX2 dm2(.gl0(tgl0), .gl1(tgl1), .result1(tresult1), .s0(ts0), .s1(ts1), .s2(ts2), .s3(ts3));
	
endmodule

module topBUSY;
	reg tenable;
	wire tb;

	initial
		begin
			tenable = 0;
		end
	
	initial
		begin
			#1 $stop;
		end

	always 
		begin
			#1 {tenable} = {tenable} + 1;
		end

	initial
		begin
			$display("enable b");
			$monitor(" %b    %b", tenable, tb);
		end

	topBUSY busy(.enable(tenable), .b(tb));

endmodule