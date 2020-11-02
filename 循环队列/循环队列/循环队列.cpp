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

//���г�ʼ��
void initQueue(LoopQueue &queue){
	queue.front = 0;
	queue.rear = 0;
	queue.tag = 0;
	for (int i = 0; i < MAXSIZE; i++){
		queue.squ[i] = 0;
	}
	printf("��ʼ���ɹ�!\n");
}
//��Ӳ���
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
//���Ӳ���
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
//��ӡ����
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
		printf("�˳�----------0\n");
		printf("���----------1\n");
		printf("����----------2\n");
		printf("��ӡ----------3\n");
	Re_enter:
		printf("������ѡ��:");
		scanf("%d", &choose);
		if (choose != 0 && choose != 1 && choose != 2 && choose != 3)
		{
			printf("����ȷ����ѡ���е�����!\n");
			goto Re_enter;
		}
		switch (choose)
		{
		case 0:
			printf("�������!\n");
			goto End;
			break;
			
		case 1:
			printf("��������Ҫ��ӵ�����:");
			scanf("%d", &num);
			if (enQueue(q, num)){
				printf("��ӳɹ�!\n");
			}
			else{
				printf("���ʧ��!\n");
			}
			break;
		case 2:
			deQueue(q, num);
			printf("���ӵ�Ԫ��Ϊ:%d\n", num);
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