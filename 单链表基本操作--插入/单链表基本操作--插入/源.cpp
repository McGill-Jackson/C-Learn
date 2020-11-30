#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct LNode    //定义单链表结点类型
{
	ElemType data;
	struct LNode *next;
} LinkList;

void InitList(LinkList *&L);  //链表初始化，创建头结点。裁判程序实现，细节不表。
void DestroyList(LinkList *&L);  //销毁单链表，释放单链表所有结点空间。裁判程序实现，细节不表。
void DispListN(LinkList *L, int n); //输出第n个结点值。 n为结点的逻辑序号。如果n不在链表长度范围，则输出结点值用NULL表示。
bool ListInsert(LinkList *&L, int i, ElemType e); //将元素e插入在L的第i个结点处，i为结点的逻辑序号，i的取值在【1，L->Length+1】范围内时，可成功插入，返回true, 否则插入失败，返回false。 


int main()
{
	LinkList *h;
	ElemType  ch;
	InitList(h);  //裁判程序实现
	int i = 1, n;
	while ((ch = getchar()) != '\n')
	{
		if (ListInsert(h, i, ch))
			i++;
	}
	scanf("%d", &n);
	DispListN(h, n);
	DestroyList(h);  //裁判程序实现
	system("pause");
	return 0;
}

void InitList(LinkList *&L){
	L = (LinkList*)malloc(sizeof(LinkList));
	L->data = 0;
	L->next = NULL;
	return;
}

void DestroyList(LinkList *&L){
	LinkList *p;
	while (L){
		p = L->next;
		free(L);
		L = p;
	}
	return;
}

void DispListN(LinkList *L, int n){
	if (n == 0){
		printf("The %dth is NULL\n", n);
		return;
	}
	LinkList *p = L->next;
	for (int i = 1; i <= n-1; i++){
		if (p == NULL){
			printf("The %dth is NULL\n",n);
			return;
		}
		p = p->next;
	}
	printf("The %dth is %c\n", n, p->data);
	return;
}

bool ListInsert(LinkList *&L, int i, ElemType e){
	LinkList *p = L;
	LinkList *lp = NULL;
	for (int j = 0; j < i; j++){
		if (p == NULL)return false;
		lp = p;
		p = p->next;
	}
	LinkList *r = (LinkList*)malloc(sizeof(LinkList));
	lp->next = r;
	r->data = e;
	r->next = p;
	return true;
}