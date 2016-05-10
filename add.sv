`timescale 1ps / 1ps
module test0;
reg  clk;
reg  rst_n;
reg  enable;
reg  [1:0]rounding;
reg  [2:0]operation;
reg  [63:0]operand_a;
reg  [63:0]operand_b;
wire  [63:0]out;
wire  ready;
wire  underflow;
wire  overflow;
wire  inexact;
wire  exception;
wire  invalid;
class packet;
rand bit rst_n;
rand bit enable;
randc bit [1:0]rounding;
rand bit [2:0]operation;
rand bit [63:0]operand_a;
rand bit [63:0]operand_b;
constraint  add{
rst_n == 1'b0;enable == 1'b1;operation==000;
}
endclass
fpu ins1 (
.clk(clk),
.rst_n(rst_n),
.enable(enable),
.rounding(rounding),
.operation(operation),
.operand_a(operand_a),
.operand_b(operand_b),
.out(out),
.ready(ready),
.underflow(underflow),
.overflow(overflow),
.inexact(inexact),
.exception(exception),
.invalid(invalid)
);
packet p;
initial
begin
p=new();
#0
rst_n = 1'b1;
# 20000;
repeat(100)
begin
assert(p.randomize());
rst_n=p.rst_n;
enable=p.enable;
rounding=p.rounding;
operation=p.operation;
operand_a=p.operand_a;
operand_b=p.operand_b;

# 800000;
$display("rst_n=%b",rst_n);
$display("enable=%b",enable);
$display("rounding=%b",rounding);
$display("operation=%b",operation);
$display("operand_a=%b",operand_a);
$display("operand_b=%b",operand_b);
$display("out=%b",out);
$display("ready=%b",ready);
$display("underflow=%b",underflow);
$display("overflow=%b",overflow);
$display("inexact=%b",inexact);
$display("exception=%b",exception);
$display("invalid=%b",invalid);
end
$finish;
end
always
begin : CLOCK_clk
clk = 1'b0;
#5000;
clk = 1'b1;
#5000;
end
endmodule
