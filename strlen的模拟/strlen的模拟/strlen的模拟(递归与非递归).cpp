#include<stdio.h>
#include<stdlib.h>

//非递归方式
int Strlen(char str[]){
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++){
		count++;
	}
	return count;
}

//递归方式
int strLen(char str[]){
	if (str[0] == '\0')
		return 0;
	return 1 + strLen(str + 1);
}

int main(){
	char str[] = "Hehe strlen!";
	printf("非递归方式:%d\n", Strlen(str));
	printf("递归方式:%d\n", strLen(str));
	system("pause");
	return 0;
}