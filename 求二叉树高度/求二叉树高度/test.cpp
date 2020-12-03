#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//ABD##FE###CG#H##I##
//����������

/*------�������Ķ���-------*/
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int flag;
};

/*------��ջ�Ķ���-------*/
typedef Position SElementType;
typedef struct SNode *PtrToSNode;
typedef PtrToSNode Stack;
struct SNode {
	SElementType Data;
	PtrToSNode Next;
};

Stack CreateStack();//��ջ�Ĺ���
bool IsEmpty(Stack S);//��ջ�п�
bool Push(Stack S, SElementType X);//��ջ��ջ
SElementType Pop(Stack S); // ɾ����������S��ջ��Ԫ�� 
SElementType Peek(Stack S);// ������S��ջ��Ԫ�� 

BinTree CreatBinTree(); //���򴴽���
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
	printf("Inorder_:");  Inorder_Traversal(BT);  printf("\n");
	printf("Preorder_:");   Preorder_Traversal(BT);   printf("\n");
	printf("Postorder_:");  Postorder_Traversal(BT);  printf("\n");
	printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
	printf("Leaf nodes are:");PreorderPrintLeaves(BT);printf("\n");
	system("pause");
	return 0;
}
//��ջ�Ĺ���
Stack CreateStack(){
	//����һ����ջ,ջ��ָ����Ϊ��(��ջ��ͷ�ڵ�)
	Stack a = (Stack)malloc(sizeof(struct SNode));
	a->Data = NULL;
	a->Next = NULL;
	return a;
}
//��ջ�п�
bool IsEmpty(Stack S){
	if (S->Next == NULL)
		return true;
	return false;
}
//��ջ��ջ
bool Push(Stack S, SElementType X){
	Stack p = (Stack)malloc(sizeof(struct SNode));
	p->Data = X;
	p->Next = S->Next;
	S->Next = p;
	return true;
}
// ɾ����������S��ջ��Ԫ�� 
SElementType Pop(Stack S){
	if (IsEmpty(S) == true){
		printf("ջ���ÿ�.\n");
		return NULL;
	}
	SElementType e = S->Next->Data;
	Stack p = S->Next;
	S->Next = S->Next->Next;
	free(p);
	return e;
}
// ������S��ջ��Ԫ�� 
SElementType Peek(Stack S){
	return S->Next->Data;
}

//���򴴽�
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
//�������(�ǵݹ�)
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
//�������(�ǵݹ�)
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
