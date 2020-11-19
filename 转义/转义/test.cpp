#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	double salary = 0;

	printf("\aEnter your desired monthly salary:");
	printf(" $_______\b\b\b\b\b\b\b");
	scanf("%lf", &salary);
	printf("\n\t$%.2lf a month is $%.2lf a year.", salary, salary*12.0);
	printf("\rGee!\n");

	system("pause");
	return 0;
}