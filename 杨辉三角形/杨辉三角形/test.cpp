#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//�����
int C_number(int n, int i){
	if (i == 0 || i > n){
		return 0;
	}
	if (n == 1)
		return 1;
	return C_number(n - 1, i) + C_number(n - 1, i - 1);
}

int main(){
	int row,n, i;
	printf("��������Ҫ�������������ε�����:");
	scanf("%d",&row);
	for ( n = 1; n <= row; n++){
		for (i = 1; i <= n; i++){
			printf("%4d", C_number(n, i));
		}
		printf("\n");
	}
	system("pause");
	return 0;
}