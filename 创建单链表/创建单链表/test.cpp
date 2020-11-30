
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode          //定义单链表结点类型
{
	ElemType data;
	struct LNode *next;        //指向后继结点
} LinkList;

LinkList * CreateListF(LinkList *L, ElemType a[], int n);//头插法建立单链表。
LinkList * CreateListR(LinkList *L, ElemType a[], int n);//尾插法建立单链表。
void DispList(LinkList *L); //输出单链表所有结点值，每个结点之间用空格间隔，如果链表为空，则输出NULL。全部输出用换行符结束。 
void SetListNULL(LinkList *L);//删除链表所有数据结点,将链表置为空表。 裁判程序实现。

int main()
{
	LinkList *L, *ha, *hb;
	L = NULL;
	ElemType a[100] = { 0 };
	int i = 0;
	char ch;
	while ((ch = getchar()) != '\n')
	{
		a[i++] = ch;
	}
	ha = CreateListR(L, a, i);
	hb = CreateListF(L, a, i);
	printf("A: "); DispList(ha);
	printf("B: "); DispList(hb);
	SetListNULL(ha);
	SetListNULL(hb);
	printf("A: "); DispList(ha);
	printf("B: "); DispList(hb);
	free(ha);
	free(hb);
	system("pause");
	return 0;
}

void SetListNULL(LinkList *L)// 裁判程序实现，细节不表。删除链表所有数据结点,将链表置为空表。
{
	if (L == NULL)
		return;
	LinkList *p;
	LinkList *a = L->next;
	while (a){
		p = a->next;
		free(a);
		a = p;
	}
	L->next = NULL;
	return;
}
//头插法建立单链表。
LinkList * CreateListF(LinkList *L, ElemType a[], int n){
	L = (LinkList*)malloc(sizeof(LinkList));
	if (L == NULL)
		return NULL;
	L->data = 0;
	L->next = NULL;
	LinkList *lp, *rp;
	lp = L;
	for (int i = 0; i < n; i++){
		rp = (LinkList*)malloc(sizeof(LinkList));
		if (L == NULL)
			return NULL;
		rp->data = a[i];
		rp->next = lp->next;
		lp->next = rp;
	}
	return L;
}
//尾插法建立单链表
LinkList * CreateListR(LinkList *L, ElemType a[], int n){
	L = (LinkList*)malloc(sizeof(LinkList));
	if (L == NULL)
		return NULL;
	L->data = 0;
	L->next = NULL;
	LinkList *lp, *rp;
	lp = L;
	for (int i = 0; i < n; i++){
		rp = (LinkList*)malloc(sizeof(LinkList));
		if (rp == NULL)
			return NULL;
		rp->data = a[i];
		lp->next = rp;
		rp->next = NULL;
		lp = rp;
	}
	return L;
}

void DispList(LinkList *L){
	if (L->next == NULL){
		printf("NULL\n");
		return;
	}
	LinkList *p = L->next;
	while (p != NULL){
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
	return;
}