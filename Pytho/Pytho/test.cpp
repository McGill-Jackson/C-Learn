#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//
typedef struct {
	int money;
	int soda;
	int bouttle;
	int count;
}S_shop;

//二换一
void Two_forone(){
	S_shop s;
	printf("请输入你所给的钱.\n");
	s.money = 0;
	scanf("%d", &s.money);
	s.bouttle = 0;
	s.count = 0;
	for (s.soda=s.money; s.soda > 0; s.soda = s.bouttle/2,s.bouttle=s.bouttle%2){
		s.count = s.count + s.soda;
		s.bouttle = s.bouttle+s.soda;
	}
	printf("%d\n", s.count);
	return;
}

int main(){
	Two_forone();
	system("pause");
	return 0;

}