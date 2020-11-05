#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//函数原型(函数声明)
void init(int str[], int len);//数组初始化
void print(int str[], int len);//打印数组
void reverse(int str[], int len);//数组元素逆置
void empty(int str[], int len);//输入数组元素

int main(){
	int str[10];

	//函数调用
	init(str, 10);
	print(str, 10);
	empty(str, 10);
	reverse(str, 10);
	print(str, 10);

	system("pause");
	return 0;
}

//函数定义
//数组初始化
void init(int str[], int len){
	for (int i = 0; i < len; i++){
		str[i] = 0;
	}
}

//打印数组
void print(int str[], int len){
	for (int i = 0; i < len; i++){
		printf("%2d", str[i]);
	}
	printf("\n");
}

//数组元素逆置
void reverse(int str[],int len){
	int a = 0;
	if (len  < 0)
		return;
	a = str[0];
	str[0] = str[len - 1];
	str[len - 1] = a;
	return reverse(str + 1, len - 2);
}

//输入数组元素
void empty(int str[], int len){
	printf("请输入10个数字.\n");
	for (int i = 0; i < len; i++){
		scanf("%d", &str[i]);
	}
}

