#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//递归方式
int DigitSum(unsigned int n){
	if (n < 10)
		return n;
	return n % 10 + DigitSum(n / 10);
}

//非递归方式
int digitSum(unsigned int n){
	int sum = 0;
	do{
		int num;
		num = n % 10;
		sum = sum + num;
		n = n / 10;
	} while (n>0);
	return sum;
}
int main(){
	int num = 0;
	printf("请输入非负整数:");
	scanf("%d", &num);
	printf("递归方式:%d\n", DigitSum(num));
	printf("非递归方式:%d\n", digitSum(num));
	system("pause");
	return 0;
}