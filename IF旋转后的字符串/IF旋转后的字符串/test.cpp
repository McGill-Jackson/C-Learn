#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isRotary(char* str1,char* str2,int len){
	for (int i = 0; i < len; i++){
		if (!strcmp(str1, str2)){
			return 1;//³É¹¦
		}
		char* fp = str1;
		char fnum = *str1;
		while (*(str1 + 1) != '\0'){
			*str1 = *(str1 + 1);
			str1++;
		}
		*str1 = fnum;
		str1 = fp;
	}
	return 0;//Ê§°Ü
}

int main(){
	char str1[] = "AABCe";
	char str2[] = "BCDAA";
	
	printf("%d\n",isRotary(str1, str2, 5));
	system("pause");
	return 0;
}