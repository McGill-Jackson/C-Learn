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

//游戏菜单
void Game(char board[ROW][COLUMN]){
RETURN:
	int i = 0;
	printf("====================\n");
	printf("*   开始游戏----1  *\n");
	printf("*   结束游戏----0  *\n");
	printf("====================\n");
	printf("请输入你的选择:");
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
			printf("电脑落子.\n");
			Machine(board);
			print(board);
			if (Outcome(board) == 0)
				goto RETURN;
		}
		break;
	case 0:
		printf("游戏结束.\n");
		break;
	}
}
//棋盘初始化
void Establish(char board[ROW][COLUMN]){
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COLUMN; j++){
			board[i][j] = ' ';
		}
	}
}
//玩家下棋
void Human(char board[ROW][COLUMN]){
	printf("请用输入你所想要落子的位置(用空格隔开):");
	int i = 0;
	int j = 0;
	while (1){
		scanf("%d %d", &i, &j);
		if (board[i][j] == ' '){
			board[i][j] = 'X';
			break;
		}
		printf("你输入的位置已有棋子,请重新输入");
	}
	
}

//电脑下棋
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
//判断胜负
int Outcome(char board[ROW][COLUMN]){
	//人胜利
	for (int i = 0; i < ROW; i++){
		int count = 0;
		for (int j = 0; j < COLUMN; j++){
			if (board[i][j] == 'X')
				++count;
		}
		if (count == 3){
			printf("恭喜你,赢得了这场比赛.\n");
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
			printf("恭喜你,赢得了这场比赛.\n");
			return 0;
		}
	}
	if (board[0][0] == 'X'&&board[1][1] == 'X'&&board[2][2] == 'X'){
		printf("恭喜你,赢得了这场比赛.\n");
		return 0;
	}
	else 	if (board[0][2] == 'X'&&board[1][1] == 'X'&&board[2][0] == 'X'){
		printf("恭喜你,赢得了这场比赛.\n");
		return 0;
	}
	//机胜利
	for (int i = 0; i < ROW; i++){
		int count = 0;
		for (int j = 0; j < COLUMN; j++){
			if (board[i][j] == 'O')
				++count;
		}
		if (count == 3){
			printf("很遗憾,你输给了电脑.\n");
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
			printf("很遗憾,你输给了电脑.\n");
			return 0;
		}
	}
	if (board[0][0] == 'O'&&board[1][1] == 'O'&&board[2][2] == 'O'){
		printf("很遗憾,你输给了电脑.\n");
		return 0;
	}
	else 	if (board[0][2] == 'O'&&board[1][1] == 'O'&&board[2][0] == 'O'){
		printf("很遗憾,你输给了电脑.\n");
		return 0;
	}
	//平局
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COLUMN; j++){
			if (board[i][j] == ' ')
				return 1;
		}
	}
	printf("你与电脑旗鼓相当.\n");
	return 0;

}
//打印棋盘
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