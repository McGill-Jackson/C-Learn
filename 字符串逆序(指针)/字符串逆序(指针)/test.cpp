#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ÄæĞò
void ReverseStr(char* str){
	char a;
	int len = strlen(str);
	int j = len;
	for (int i = 0; i < j / 2; i++){
		a = *str;
		*str = *(str + len - 1);
		*(str + len - 1) = a;
		str++;
		len-=2;
	}
}

int main(){
	char str[] = "hello bit!";
	ReverseStr(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}