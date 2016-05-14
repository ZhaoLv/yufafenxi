`include  "add_class.sv"
`timescale 1ps / 1ps
module test;
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
packet0  p0;
initial
begin
p0=new();
#0
rst_n = 1'b1;
# 20000;
repeat(100)
begin

p0.constraint_mode(0);
p0.c0.constraint_mode(1);
assert(p0.randomize());
rst_n=p0.rst_n;
enable=p0.enable;
rounding=p0.rounding;
operation=p0.operation;
operand_a=p0.operand_a;
operand_b=p0.operand_b;
p0.out=out;
p0.ready=ready;
p0.underflow=underflow;
p0.overflow=overflow;
p0.inexact=inexact;
p0.exception=exception;
p0.invalid=invalid;
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
