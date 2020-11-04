#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//冒泡排序
void Bubble_sort(int str[],int len){

	for (; len > 1; len--){
		for (int i = 0, j = 1; j < len; i++, j++){
			int temporary = 0;
			if (str[i]>str[j]){
				temporary = str[j];
				str[j] = str[i];
				str[i] = temporary;
			}
		}
	}
}

int main(){
	int n=0;
	int str[100];	
	printf("你要输入几个数字?");
	scanf("%d", &n);

	printf("请一一输入你想要输入的整数.");
	for (int i = 0; i < n; i++)
		scanf("%d", &str[i]);
	int len = n;
	//int len = sizeof(str) / sizeof(str[0]);
	Bubble_sort(str, len);
	for (int i = 0; i < len; i++){
		printf("%d ", str[i]);
	}
	printf("\n");
	

	system("pause");
	return 0;
}