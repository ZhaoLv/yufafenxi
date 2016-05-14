class packet0;
rand bit rst_n;
rand bit enable;
randc bit [1:0]rounding;
rand bit [2:0]operation;
rand bit [63:0]operand_a;
rand bit [63:0]operand_b;
bit [63:0]out;
bit ready;
bit underflow;
bit overflow;
bit inexact;
bit exception;
bit invalid;
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;}
endclass
