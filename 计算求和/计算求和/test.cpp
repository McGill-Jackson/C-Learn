#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//计算求和
int Stack_sum(int a, int n){
	int sum = 0;
	int s = 1;
	for (; n > 0; n--){
		sum = sum + a*n*s;
		s *= 10;
	}
	return sum;
}

int main(){
	int a;
	int n;

	printf("请输入数字a,以及前n项.");
	scanf("%d %d", &a, &n);
	printf("所求结果为%d\n", Stack_sum(a, n));
	system("pause");
	return 0;
}