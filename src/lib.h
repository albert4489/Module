/**
	@file lib.h
	Калькулятор
	@author Bohuslavskiy A. КН-922B
*/

#ifndef HEADER_FILE
#define HEADER_FILE
/** 
 Підключення бібліотек 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
/** 
 Константа зі значенням 100 
*/ 
#define MAX 100
/** 
 Прототипи функцій 
*/ 
int isOperator(char ch);
int getPriority(char operator);
int primeoperation(int num1, int num2, char operator);
int calculator(char* formula);
int main();

#endif
