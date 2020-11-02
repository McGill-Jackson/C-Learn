#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 10

typedef int Elementype;
typedef int Position;
int count = 0;

typedef struct{

	Elementype squ[MAXSIZE];
	Position front;
	Position rear;
	int tag;
}LoopQueue;

//队列初始化
void initQueue(LoopQueue &queue){
	queue.front = 0;
	queue.rear = 0;
	queue.tag = 0;
	for (int i = 0; i < MAXSIZE; i++){
		queue.squ[i] = 0;
	}
	printf("初始化成功!\n");
}
//入队操作
int enQueue(LoopQueue &queue, Elementype a){
	if (count == MAXSIZE)
		queue.tag = 1;
	if (queue.front == queue.rear&&queue.tag == 1)
		return ERROR;
	else{
		queue.squ[queue.rear] = a;
		queue.rear = (queue.rear + 1) % MAXSIZE;
		count++;
	}
	return OK;
}
//出队操作
int deQueue(LoopQueue &queue, Elementype &a){
	if (count == 0)
		queue.tag = 0;
	if (queue.front == queue.rear&&queue.tag == 0)
		return ERROR;
	else{
		a = queue.squ[queue.rear];
		queue.squ[queue.rear] = 0;
		queue.front = (queue.front + 1) % MAXSIZE;
		count--;
	}
	return OK;
}
//打印队列
void printfQueue(LoopQueue &queue){

	for (int i = 0; i < MAXSIZE; i++){
		printf("|%d", queue.squ[i]);
	}
	printf("|\n");
}
void Menu(){
	LoopQueue q;
	initQueue(q);
	int num = 0;
	int choose = 0;
	while (1){
		printf("退出----------0\n");
		printf("入队----------1\n");
		printf("出队----------2\n");
		printf("打印----------3\n");
	Re_enter:
		printf("请输入选项:");
		scanf("%d", &choose);
		if (choose != 0 && choose != 1 && choose != 2 && choose != 3)
		{
			printf("请正确输入选项中的数字!\n");
			goto Re_enter;
		}
		switch (choose)
		{
		case 0:
			printf("程序结束!\n");
			goto End;
			break;
			
		case 1:
			printf("请输入需要入队的数字:");
			scanf("%d", &num);
			if (enQueue(q, num)){
				printf("入队成功!\n");
			}
			else{
				printf("入队失败!\n");
			}
			break;
		case 2:
			deQueue(q, num);
			printf("出队的元素为:%d\n", num);
			break;
		case 3:
			printfQueue(q);
			break;
		}
	}
End:
	return;
}
int main(){

	Menu();
	system("pause");
	return 0;
}