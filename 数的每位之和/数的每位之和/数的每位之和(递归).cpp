#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//�ݹ鷽ʽ
int DigitSum(unsigned int n){
	if (n < 10)
		return n;
	return n % 10 + DigitSum(n / 10);
}

//�ǵݹ鷽ʽ
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
	printf("������Ǹ�����:");
	scanf("%d", &num);
	printf("�ݹ鷽ʽ:%d\n", DigitSum(num));
	printf("�ǵݹ鷽ʽ:%d\n", digitSum(num));
	system("pause");
	return 0;
}