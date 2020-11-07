#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//数组交换
void Array_exchangep(char str_a[], char str_b[],int len){
	char temporary = 0;
	for (int i = 0; i < len; i++){
		temporary = str_a[i];
		str_a[i] = str_b[i];
		str_b[i] = temporary;
	}

}

//打印数组
void print(char str[], char len){
	for (int i = 0; i < len; i++){
		printf("%2c", str[i]);
	}
	printf("\n");
}
int main(){
	char str_a[5] = { 'a', 'b', 'c', 'd', 'e' };
	char str_b[5] = { '1', '2', '3', '4', '5' };
	print(str_a, 5);
	print(str_b, 5);

	Array_exchangep(str_a, str_b, 5);
	print(str_a, 5);
	print(str_b, 5);

	system("pause");
	return 0;
}