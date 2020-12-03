#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//ABD##FE###CG#H##I##
//测试树序列

/*------二叉树的定义-------*/
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int flag;
};

/*------堆栈的定义-------*/
typedef Position SElementType;
typedef struct SNode *PtrToSNode;
typedef PtrToSNode Stack;
struct SNode {
	SElementType Data;
	PtrToSNode Next;
};

Stack CreateStack();//链栈的构造
bool IsEmpty(Stack S);//链栈判空
bool Push(Stack S, SElementType X);//链栈入栈
SElementType Pop(Stack S); // 删除并仅返回S的栈顶元素 
SElementType Peek(Stack S);// 仅返回S的栈顶元素 

BinTree CreatBinTree(); //先序创建树
int GetHeight(BinTree BT);//树的高度

void InorderTraversal(BinTree BT);//中序遍历
void PreorderTraversal(BinTree BT);//先序遍历
void PostorderTraversal(BinTree BT);//后序遍历
void Inorder_Traversal(BinTree BT);//中序遍历(非递归)
void Preorder_Traversal(BinTree BT);//先序遍历(非递归)
void Postorder_Traversal(BinTree BT);//后序遍历(非递归)
void LevelorderTraversal(BinTree BT);//顺序遍历
void PreorderPrintLeaves(BinTree BT);//先序输出叶结点

int main()
{
	BinTree BT = CreatBinTree();
	printf("%d\n", GetHeight(BT));
	printf("Inorder:");    InorderTraversal(BT);    printf("\n");
	printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
	printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
	printf("Inorder_:");  Inorder_Traversal(BT);  printf("\n");
	printf("Preorder_:");   Preorder_Traversal(BT);   printf("\n");
	printf("Postorder_:");  Postorder_Traversal(BT);  printf("\n");
	printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
	printf("Leaf nodes are:");PreorderPrintLeaves(BT);printf("\n");
	system("pause");
	return 0;
}
//链栈的构造
Stack CreateStack(){
	//构造一个空栈,栈顶指针置为空(链栈有头节点)
	Stack a = (Stack)malloc(sizeof(struct SNode));
	a->Data = NULL;
	a->Next = NULL;
	return a;
}
//链栈判空
bool IsEmpty(Stack S){
	if (S->Next == NULL)
		return true;
	return false;
}
//链栈入栈
bool Push(Stack S, SElementType X){
	Stack p = (Stack)malloc(sizeof(struct SNode));
	p->Data = X;
	p->Next = S->Next;
	S->Next = p;
	return true;
}
// 删除并仅返回S的栈顶元素 
SElementType Pop(Stack S){
	if (IsEmpty(S) == true){
		printf("栈以置空.\n");
		return NULL;
	}
	SElementType e = S->Next->Data;
	Stack p = S->Next;
	S->Next = S->Next->Next;
	free(p);
	return e;
}
// 仅返回S的栈顶元素 
SElementType Peek(Stack S){
	return S->Next->Data;
}

//先序创建
BinTree CreatBinTree(){
	char ch;
	scanf("%c", &ch);
	if (ch == '#')return NULL;
	else{
		BinTree BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = ch;
		BT->flag = 0;
		BT->Left = CreatBinTree();
		BT->Right = CreatBinTree();
		return BT;
	}
}
//树的高度
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
//中序遍历
void InorderTraversal(BinTree BT){
	if (BT){
		InorderTraversal(BT->Left);
		printf("%2c", BT->Data);
		InorderTraversal(BT->Right);
	}
}
//先序遍历
void PreorderTraversal(BinTree BT){
	if (BT){
		printf("%2c", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}
//后序遍历
void PostorderTraversal(BinTree BT){
	if (BT){
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf("%2c", BT->Data);
	}
}
//层序遍历
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
//先序输出叶结点
void PreorderPrintLeaves(BinTree BT){
	if (BT){
		if ((BT->Left==NULL)&&(BT->Right==NULL))
			printf("%2c", BT->Data);
		PreorderPrintLeaves(BT->Left);
		PreorderPrintLeaves(BT->Right);
	}
}
//中序遍历(非递归)
void Inorder_Traversal(BinTree BT){
	Stack S = CreateStack();
	BinTree p = BT;
	BinTree q ;
	while (p || !IsEmpty(S)){
		if (p){
			Push(S, p);
			p = p->Left;
		}
		else{
			q = Pop(S);
			printf("%2c", q->Data);
			p = q->Right;
		}
	}
}
//先序遍历(非递归)
void Preorder_Traversal(BinTree BT){
	Stack S = CreateStack();
	BinTree p = BT;
	BinTree q ;
	while (p || !IsEmpty(S)){
		if (p){
			printf("%2c", p->Data);
			Push(S, p);
			p = p->Left;
		}
		else{
			q = Pop(S);
			p = q->Right;
		}
	}
}
//后序遍历(非递归)
void Postorder_Traversal(BinTree BT){
	Stack S = CreateStack();
	BinTree p = BT;
	BinTree q ;
	while (p || !IsEmpty(S)){
		if (p){
			p->flag = 0;
			Push(S, p);
			p = p->Left;
		}
		else{
			q = Peek(S);
			if (q->flag == 0){
				p = q->Right;
				q->flag = 1;
			}
			else{
				q = Pop(S);
				printf("%2c", q->Data);
				p = NULL;
			}
		}
	}

}
