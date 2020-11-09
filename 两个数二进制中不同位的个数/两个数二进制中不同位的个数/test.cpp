#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int a, b;
	int c;
	printf("请输入两个整数:");
	scanf("%d %d", &a, &b);
	int count = 0;
	c = a^b;
	while (c){
		count++;
		c = c&(c - 1);
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}