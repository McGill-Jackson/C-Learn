#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(){
	int a = 0;
	int tmp = 0;
	printf("������һ��������");
	scanf("%d", &a);
	printf("����λΪ:");
	for (int i = 30; i >= 0; i = i - 2){
		tmp = (a >> i) & 1;
		printf("%2d", tmp);
	}
	printf("\nż��λΪ:");
	for (int i = 31; i >= 0; i = i - 2){
		tmp = (a >> i) & 1;
		printf("%2d", tmp);

	}
	printf("\n");
	system("pause");
	return 0;
}
