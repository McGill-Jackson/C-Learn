#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//�ݹ鷽ʽ
int Fiponachi(int n){
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return Fiponachi(n - 1) + Fiponachi(n - 2);
}

//�ǵݹ鷽ʽ
int fiponachi(int n){
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	int sum = 1;
	int lp = 0, rp = 0;
	for (int i = 3; i <= n; i++){
		lp = rp;
		rp = sum;
		sum = lp + rp;
	}
	return sum;
}
int main(){

	printf("����Ҫ����ڼ���쳲�������?\n");
	int n = 0;
	scanf("%d", &n);
	printf("�ݹ鷽��:%d\n", Fiponachi(n));
	printf("�ǵݹ鷽��:%d\n", fiponachi(n));
	system("pause");
	return 0;
}