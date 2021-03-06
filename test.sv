reg   clk;
reg   rst_n;
reg   enable;
reg  [1:0] rounding;
reg  [2:0] operation;
reg  [63:0] operand_a;
reg  [63:0] operand_b;
wire  [63:0] out;
wire   ready;
wire   underflow;
wire   overflow;
wire   inexact;
wire   exception;
wire   invalid;
class packet0;
rand bit  clk;
rand bit  rst_n;
rand bit  enable;
rand bit [1:0] rounding;
rand bit [2:0] operation;
rand bit [63:0] operand_a;
rand bit [63:0] operand_b;
constraint   add_overflow{
rst_n = 1'b0;enable = 1'b1;operation==000;operation_a[62:52]==11'b11111111110;operation_b[62:52]==11'b11111111110;operation_a[51:0]+operation_b[51:0]>52'hfffffffffffff
}
endclass
class packet1;
rand bit  clk;
rand bit  rst_n;
rand bit  enable;
rand bit [1:0] rounding;
rand bit [2:0] operation;
rand bit [63:0] operand_a;
rand bit [63:0] operand_b;
constraint   add_underflow{
rst_n==0,enable==1,operation==000,operation_a[62:52]=11'b00000000000,operation_b[62:52]=11'b00000000000,operation_a[42:0]+operation_b[51:0]>52'hfffffffffffff
}
endclass
