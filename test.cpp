#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iomanip>
#include "LexAnalysis.h"

using namespace std;

int main()
{
	
	
	initNode();
	scanner_port();
//	printport();
	scanner_transaction();
//	printtransaction();
	scanner_function();
//	printfunction();
//	printsv();
//	print_boundry_condition();
//	print_boundrysv();
	printsv_with_if_class();
	printsv_with_if_TB();
	close();
	
	
	
	
	/*
	char str1[]="#10;a>10;#20;b<10";
	//char* str2="abcdeee";
	char* token=strtok(str1,"#");
	while(token!=NULL)
	{
	cout<<token<<endl;
	token=strtok(NULL,"#");
	}
	int i;
	cin>>i;
	*/
	

	
	
}