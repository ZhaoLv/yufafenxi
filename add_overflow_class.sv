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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]<11'b11111111110;operand_b[62:52]>11'b11111111110;operand_a[51]&&operand_b[51]<=1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]>11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]>11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet1;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]==11'b11111111110;operand_b[62:52]>11'b11111111110;operand_a[51]&&operand_b[51]<=1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]>11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]>11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet2;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]==11'b11111111110;operand_b[62:52]==11'b11111111110;operand_a[51]&&operand_b[51]<=1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]>11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]>11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet3;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]==11'b11111111110;operand_b[62:52]==11'b11111111110;operand_a[51]&&operand_b[51]==1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]>11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]>11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet4;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]==11'b11111111110;operand_b[62:52]==11'b11111111110;operand_a[51]&&operand_b[51]==1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]==11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]>11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet5;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]==11'b11111111110;operand_b[62:52]==11'b11111111110;operand_a[51]&&operand_b[51]==1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]==11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]==11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet6;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]<11'b11111111110;operand_b[62:52]==11'b11111111110;operand_a[51]&&operand_b[51]<=1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]>11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]>11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet7;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]<11'b11111111110;operand_b[62:52]==11'b11111111110;operand_a[51]&&operand_b[51]==1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]>11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]>11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet8;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]<11'b11111111110;operand_b[62:52]==11'b11111111110;operand_a[51]&&operand_b[51]==1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]==11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]>11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet9;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]<11'b11111111110;operand_b[62:52]==11'b11111111110;operand_a[51]&&operand_b[51]==1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]==11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]==11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet10;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]<11'b11111111110;operand_b[62:52]>11'b11111111110;operand_a[51]&&operand_b[51]==1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]>11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]>11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet11;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]<11'b11111111110;operand_b[62:52]>11'b11111111110;operand_a[51]&&operand_b[51]==1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]==11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]>11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet12;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]<11'b11111111110;operand_b[62:52]>11'b11111111110;operand_a[51]&&operand_b[51]==1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]==11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]==11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet13;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]<11'b11111111110;operand_b[62:52]>11'b11111111110;operand_a[51]&&operand_b[51]<=1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]==11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]>11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet14;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]<11'b11111111110;operand_b[62:52]>11'b11111111110;operand_a[51]&&operand_b[51]<=1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]==11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]==11'b11111111110;}}
constraint c3{enable==0;}
endclass
class packet15;
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
constraint c0{rst_n == 1'b0;enable == 1'b1;operation==000;operand_a[62:52]<11'b11111111110;operand_b[62:52]>11'b11111111110;operand_a[51]&&operand_b[51]<=1;operand_a[63]^operand_b[63]==0;}
constraint c1{enable==0;}
constraint c2{if(overflow==1) {enable==1;operand_a[62:52]==11'b00000000000;operand_b[62:52]>11'b11111111110;}else {enable==1;operand_b[62:52]==11'b00000000000;operand_a[62:52]==11'b11111111110;}}
constraint c3{enable==0;}
endclass
