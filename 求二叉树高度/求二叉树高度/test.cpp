#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef char ElementTyoe;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
	ElementTyoe Date;
	BinTree Left;
	BinTree right;
};
BinTree CreatBinTree(BinTree &BT){
	char x;
	scanf("%c", &x);
	if (x = '0'){
		BT = NULL;
		return 0;
	}

	BT = (BinTree)malloc(sizeof(struct TNode));
	if (&BT == NULL)
		return 0;
	BT->Date = x;
	CreatBinTree((BT->Left));
	CreatBinTree((BT->right));
	return BT;
}
void FreeBinTree(BinTree BT){
	if (BT != NULL){
		if (BT->Left){
			FreeBinTree(BT->Left);
			BT->Left = NULL;
		}
		if (BT->right){
			FreeBinTree(BT->right);
			BT->right = NULL;

		}
	}
}

int main(){
	BinTree BT;
	CreatBinTree(BT);

	system("pause");
	return 0;

}