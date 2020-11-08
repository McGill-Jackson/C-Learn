#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COLUMN 3

void Game(char board[ROW][COLUMN]);
void Establish(char board[ROW][COLUMN]);
void Human(char board[ROW][COLUMN]);
void Machine(char board[ROW][COLUMN]);
int Outcome(char board[ROW][COLUMN]);
void print(char board[ROW][COLUMN]);

//��Ϸ�˵�
void Game(char board[ROW][COLUMN]){
RETURN:
	int i = 0;
	printf("====================\n");
	printf("*   ��ʼ��Ϸ----1  *\n");
	printf("*   ������Ϸ----0  *\n");
	printf("====================\n");
	printf("���������ѡ��:");
	scanf("%d", &i);
	switch (i){
	case 1:
		Establish(board);
		print(board);
		while (1){
			Human(board);
			print(board);
			if (Outcome(board) == 0)
				goto RETURN;
			printf("��������.\n");
			Machine(board);
			print(board);
			if (Outcome(board) == 0)
				goto RETURN;
		}
		break;
	case 0:
		printf("��Ϸ����.\n");
		break;
	}
}
//���̳�ʼ��
void Establish(char board[ROW][COLUMN]){
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COLUMN; j++){
			board[i][j] = ' ';
		}
	}
}
//�������
void Human(char board[ROW][COLUMN]){
	printf("��������������Ҫ���ӵ�λ��(�ÿո����):");
	int i = 0;
	int j = 0;
	while (1){
		scanf("%d %d", &i, &j);
		if (board[i][j] == ' '){
			board[i][j] = 'X';
			break;
		}
		printf("�������λ����������,����������");
	}
	
}

//��������
void Machine(char board[ROW][COLUMN]){
	srand((unsigned)time(NULL));
	int i = 0;
	int j = 0;
	while (1){
		i = rand() % 3;
		j = rand() % 3;
		if (board[i][j] == ' '){
			board[i][j] = 'O';
			break;
		}
	}
	
}
//�ж�ʤ��
int Outcome(char board[ROW][COLUMN]){
	//��ʤ��
	for (int i = 0; i < ROW; i++){
		int count = 0;
		for (int j = 0; j < COLUMN; j++){
			if (board[i][j] == 'X')
				++count;
		}
		if (count == 3){
			printf("��ϲ��,Ӯ�����ⳡ����.\n");
			return 0;
		}
	}
	for (int j = 0; j < COLUMN; j++){
		int count = 0;
		for (int i = 0; i < ROW; i++){
			if (board[i][j] == 'X')
				++count;
		}
		if (count == 3){
			printf("��ϲ��,Ӯ�����ⳡ����.\n");
			return 0;
		}
	}
	if (board[0][0] == 'X'&&board[1][1] == 'X'&&board[2][2] == 'X'){
		printf("��ϲ��,Ӯ�����ⳡ����.\n");
		return 0;
	}
	else 	if (board[0][2] == 'X'&&board[1][1] == 'X'&&board[2][0] == 'X'){
		printf("��ϲ��,Ӯ�����ⳡ����.\n");
		return 0;
	}
	//��ʤ��
	for (int i = 0; i < ROW; i++){
		int count = 0;
		for (int j = 0; j < COLUMN; j++){
			if (board[i][j] == 'O')
				++count;
		}
		if (count == 3){
			printf("���ź�,������˵���.\n");
			return 0;
		}
	}
	for (int j = 0; j < COLUMN; j++){
		int count = 0;
		for (int i = 0; i < ROW; i++){
			if (board[i][j] == 'O')
				++count;
		}
		if (count == 3){
			printf("���ź�,������˵���.\n");
			return 0;
		}
	}
	if (board[0][0] == 'O'&&board[1][1] == 'O'&&board[2][2] == 'O'){
		printf("���ź�,������˵���.\n");
		return 0;
	}
	else 	if (board[0][2] == 'O'&&board[1][1] == 'O'&&board[2][0] == 'O'){
		printf("���ź�,������˵���.\n");
		return 0;
	}
	//ƽ��
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COLUMN; j++){
			if (board[i][j] == ' ')
				return 1;
		}
	}
	printf("�����������൱.\n");
	return 0;

}
//��ӡ����
void print(char board[ROW][COLUMN]){
	printf("+---+---+---+\n");
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COLUMN; j++){
			printf("| %c ", board[i][j]);
		}
		printf("|\n");
		printf("+---+---+---+\n");
	}
}

int main(){
	char board[ROW][COLUMN];
	Game(board);
	system("pause");
	return 0;
}