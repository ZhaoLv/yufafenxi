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
	printsv();
//	print_boundry_condition();
	print_boundrysv();
	close();

	
	return 0;
}