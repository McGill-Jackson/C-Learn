#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//ABD##FE###CG#H##I##

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree CreatBinTree(); //���򴴽�
int GetHeight(BinTree BT);//���ĸ߶�

void InorderTraversal(BinTree BT);//�������
void PreorderTraversal(BinTree BT);//�������
void PostorderTraversal(BinTree BT);//�������
void Inorder_Traversal(BinTree BT);//�������(�ǵݹ�)
void Preorder_Traversal(BinTree BT);//�������(�ǵݹ�)
void Postorder_Traversal(BinTree BT);//�������(�ǵݹ�)
void LevelorderTraversal(BinTree BT);//˳�����
void PreorderPrintLeaves(BinTree BT);//�������Ҷ���

int main()
{
	BinTree BT = CreatBinTree();
	printf("%d\n", GetHeight(BT));
	printf("Inorder:");    InorderTraversal(BT);    printf("\n");
	printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
	printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
	printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
	printf("Leaf nodes are:");PreorderPrintLeaves(BT);printf("\n");
	system("pause");
	return 0;
}

//���򴴽�
BinTree CreatBinTree(){
	char ch;
	scanf("%c", &ch);
	if (ch == '#')return NULL;
	else{
		BinTree BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = ch;
		BT->Left = CreatBinTree();
		BT->Right = CreatBinTree();
		return BT;
	}
}
//���ĸ߶�
int GetHeight(BinTree BT){
	if (BT == NULL)
		return 0;
	else{
		int l = GetHeight(BT->Left);
		int r = GetHeight(BT->Right);
		if (l > r)return(l + 1);
		else return(r + 1);
	}
}
//�������
void InorderTraversal(BinTree BT){
	if (BT){
		InorderTraversal(BT->Left);
		printf("%2c", BT->Data);
		InorderTraversal(BT->Right);
	}
}
//�������
void PreorderTraversal(BinTree BT){
	if (BT){
		printf("%2c", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}
//�������
void PostorderTraversal(BinTree BT){
	if (BT){
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf("%2c", BT->Data);
	}
}
//�������
void LevelorderTraversal(BinTree BT){
	BinTree temp[100];
	int in = 0;
	int out = 0;
	
	temp[in++] = BT;

	while (in > out){
		if (temp[out]){
			printf("%2c", temp[out]->Data);
			temp[in++] = temp[out]->Left;
			temp[in++] = temp[out]->Right;
		}
		out++;
	}
}
//�������Ҷ���
void PreorderPrintLeaves(BinTree BT){
	if (BT){
		if ((BT->Left==NULL)&&(BT->Right==NULL))
			printf("%2c", BT->Data);
		PreorderPrintLeaves(BT->Left);
		PreorderPrintLeaves(BT->Right);
	}
}
//�������(�ǵݹ�)
void Inorder_Traversal(BinTree BT){

}
