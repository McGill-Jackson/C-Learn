#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//非递归方式
int Reverse_string(char * string){
	int lp, rp;
	int len = strlen(string);

	for (lp = 0, rp = len - 1; lp < rp; lp++, rp--){
		int tpr ;
		tpr = string[lp];
		string[lp] = string[rp];
		string[rp] = tpr;
	}
	return 0;
}

//递归方式
void reverse_string(char * string){
	int lp, rp;
	int tpr = 0;
	lp = 0;
	rp = strlen(string)-1;
	if (lp == rp)
		return;
	tpr = string[lp];
	string[lp] = string[rp];
	string[rp] = '\0';
	reverse_string(string + 1);
	string[rp] = tpr;
}

int main(){
	char string[] = "Hehe reverse!";
	Reverse_string(string);
	printf("非递归方式:%s\n",string);
	reverse_string(string);
	printf("递归方式:%s\n", string);
	system("pause");
	return 0;
}