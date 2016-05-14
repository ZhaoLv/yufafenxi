//LexAnalysis.h
#ifndef _LEXANALYSIS_H
#define _LEXANALYSIS_H
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iomanip>

#define COUNT 100//随机验证个数
#define RSTTIME 20000//重启保持时间
#define OPERTIME 800000//执行时间
#define CLKTIME 5000//时钟周期的一半
#define RSTSIGNAL "rst_n"//定义重启信号
#define TIMEUNIT "1ps"
#define TIMEPRECISION "1ps"
struct port
{
    char id[30];
	int direction;//方向 1:in 2:out 3:inout
    int width;//宽度
    port * next;//下一个节点
};

struct transaction
{
	char id[30];
	char t[300];
	transaction* next;
};

struct function
{
	char id[30];
	char condition[500];
	char action[500];
	char configuration[100];
	char boundry_condition[20][500];
	int i;//num of the boundry_condition
	function* next;
};
/*
struct boundry_condition
{
	function* f;
	char condition[10][500];
	int i;
	boundry_condition * next;
};
*/
struct constraint
{
	char time[15];
	char c[500];
	char port_name[100];
	constraint * next;
};

void close();
void initNode();
void printsv();
int mystrlen(char * word);
void print_boundrysv();
void printsv_with_if_class();
//void printsv_with_if();
void printsv_with_if_TB();
bool mystrstr(char * str1,char * str2);
//void scanner_boundry();
//char* instantiate(ofstream ofile);
//void printsv_timing();
//void test_ofile(ofstream ofile);
//port
void createport(char* id, int direct, int width);
void errorport(int line);
void scanner_port();
void printport();
//transaction
void createtransaction(char* id, char* t);
void errortransaction(int line);
void scanner_transaction();
void printtransaction();
char * findtransaction(char* word);
//function
void createfunction(char* id, char* condition, char* action, char* configuration);
void errorfunction(int line);
void scanner_function();
void printfunction();
function * fathersearch(char * id);
bool findconfiguration(function * f,port* p);
char * unfoldcondition(char* condition);
//boundry_condition
//void createboundry_condition(function * f);
//void print_boundry_condition();
//int replace_nearest(char* sSrc, char* sMatchStr, char* sReplaceStr, char* caNewString);
//void scanner_boundry_condition(function * f);


//constraint
void constraint_initial();
void constraint_close();
void create_constraint(char* condition);




#endif
