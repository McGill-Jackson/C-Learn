#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//����ԭ��(��������)
void init(int str[], int len);//�����ʼ��
void print(int str[], int len);//��ӡ����
void reverse(int str[], int len);//����Ԫ������
void empty(int str[], int len);//��������Ԫ��

int main(){
	int str[10];

	//��������
	init(str, 10);
	print(str, 10);
	empty(str, 10);
	reverse(str, 10);
	print(str, 10);

	system("pause");
	return 0;
}

//��������
//�����ʼ��
void init(int str[], int len){
	for (int i = 0; i < len; i++){
		str[i] = 0;
	}
}

//��ӡ����
void print(int str[], int len){
	for (int i = 0; i < len; i++){
		printf("%2d", str[i]);
	}
	printf("\n");
}

//����Ԫ������
void reverse(int str[],int len){
	int a = 0;
	if (len  < 0)
		return;
	a = str[0];
	str[0] = str[len - 1];
	str[len - 1] = a;
	return reverse(str + 1, len - 2);
}

//��������Ԫ��
void empty(int str[], int len){
	printf("������10������.\n");
	for (int i = 0; i < len; i++){
		scanf("%d", &str[i]);
	}
}

