
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define true 1
#define false 0

typedef struct Suspect{
	int words;
	int isCriminal;
}suspect;
//打印
void print(suspect meb[4], int len){
	printf("嫌疑人  话   罪犯\n");
	char s = 'A';
	for (int i = 0; i < len; i++){
		printf("%c       %d   %d\n", s, meb[i].words, meb[i].isCriminal);
		s++;
	}
}
//初始化
void Initialization(suspect meb[4],int len){
	for (int i = 0; i < len; i++){
		meb[i].words = true;
		meb[i].isCriminal = false;
	}
	
	
}
void is_Criminal(suspect meb[4], int len){
	for (int i = 0; i < len; i++){
		meb[i].words = false;
		if (meb[0].words == true)
			meb[0].isCriminal = false;
		else meb[0].isCriminal = true;
		if (meb[1].words == true)
			meb[2].isCriminal = true;
		else meb[2].isCriminal = false;
		if (meb[3].words == true)
			meb[2].words = false;
		else meb[2].words = true;
		if (meb[2].words == true)
			meb[3].isCriminal = true;
		else meb[3].isCriminal = false;
		if (meb[0].isCriminal == true && meb[1].isCriminal == false && meb[2].isCriminal == false && meb[3].isCriminal == false){
			printf("A是犯人.\n");
			return;
		}
		if (meb[0].isCriminal == false && meb[1].isCriminal == true && meb[2].isCriminal == false && meb[3].isCriminal == false){
			printf("B是犯人.\n");
			return;
		}
		if (meb[0].isCriminal == false && meb[1].isCriminal == false && meb[2].isCriminal == true && meb[3].isCriminal == false){
			printf("C是犯人.\n");
			return;
		}
		if (meb[0].isCriminal == false && meb[1].isCriminal == false && meb[2].isCriminal == false && meb[3].isCriminal == true){
			printf("D是犯人.\n");
			return;
		}
		meb[i].words = true;
	}

}
int main(){
	suspect meb[4];


	Initialization(meb,4);
	print(meb, 4);
	is_Criminal(meb, 4);

	system("pause");
	return 0;
}
