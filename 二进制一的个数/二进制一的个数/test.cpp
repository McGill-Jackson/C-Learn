#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//1�ĸ���
int Number_if_one(int a){
	int count = 0;
	while (a){
		count++;
		a = a&(a - 1);
	}
	return count;
}

int main(){
	int a = 0;
	printf("������һ������:");
	scanf("%d", &a);
	Number_if_one(a);
	printf("������1�ĸ���Ϊ:%d\n",Number_if_one(a));
	system("pause");
	return 0;
}