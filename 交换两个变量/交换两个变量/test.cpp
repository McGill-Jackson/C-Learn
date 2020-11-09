#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int a = 0;
	int b = 0;

	printf("请输入两个数字(用空格隔开):");
	scanf("%d %d", &a, &b);
	//交换算法核心
	a = a^b;
	b = a^b;
	a = a^b;
	printf("交换后为: %d %d\n", a, b);

	system("pause");
	return 0;
}