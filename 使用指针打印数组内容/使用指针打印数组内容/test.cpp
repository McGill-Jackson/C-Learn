#include<stdio.h>
#include<stdlib.h>

//ָ���ӡ����
void P_print(int str[],int len){
	int* p = str;
	for (int i = 0; i < len; i++){
		printf("%2d", *p);
		p = p + 1;
	}
	printf("\n");
}

int main(){
	int str[5] = { 1, 2, 3, 4, 5 };
	P_print(str, 5);
	system("pause");
	return 0;

}