#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int a = 0;
	int b = 0;

	printf("��������������(�ÿո����):");
	scanf("%d %d", &a, &b);
	//�����㷨����
	a = a^b;
	b = a^b;
	a = a^b;
	printf("������Ϊ: %d %d\n", a, b);

	system("pause");
	return 0;
}