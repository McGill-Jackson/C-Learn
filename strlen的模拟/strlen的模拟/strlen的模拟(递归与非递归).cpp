#include<stdio.h>
#include<stdlib.h>

//�ǵݹ鷽ʽ
int Strlen(char str[]){
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++){
		count++;
	}
	return count;
}

//�ݹ鷽ʽ
int strLen(char str[]){
	if (str[0] == '\0')
		return 0;
	return 1 + strLen(str + 1);
}

int main(){
	char str[] = "Hehe strlen!";
	printf("�ǵݹ鷽ʽ:%d\n", Strlen(str));
	printf("�ݹ鷽ʽ:%d\n", strLen(str));
	system("pause");
	return 0;
}