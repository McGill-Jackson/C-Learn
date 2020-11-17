#include<stdio.h>
#include<stdlib.h>

//×Ö·û´®×óÐý
void Rotary_L(char* p, int n){
	for (int i = 0; i < n; i++){
		char* fp = p;
		char fnum = *p;
		while (*(p+1) != '\0'){
			*p = *(p + 1);
			p++;
		}
		*p  = fnum;
		p = fp;
	}

}
int main(){
	char str[] = "hello bit.";
	char* p = str;
	//char* p = "hello bit.";
	Rotary_L(p, 3);
	while (*p != '\0'){
		printf("%c", *p);
		p++;
	}
	system("pause");
	return 0;
}