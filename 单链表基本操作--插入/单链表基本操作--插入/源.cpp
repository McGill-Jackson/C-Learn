#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct LNode    //���嵥����������
{
	ElemType data;
	struct LNode *next;
} LinkList;

void InitList(LinkList *&L);  //�����ʼ��������ͷ��㡣���г���ʵ�֣�ϸ�ڲ���
void DestroyList(LinkList *&L);  //���ٵ������ͷŵ��������н��ռ䡣���г���ʵ�֣�ϸ�ڲ���
void DispListN(LinkList *L, int n); //�����n�����ֵ�� nΪ�����߼���š����n���������ȷ�Χ����������ֵ��NULL��ʾ��
bool ListInsert(LinkList *&L, int i, ElemType e); //��Ԫ��e������L�ĵ�i����㴦��iΪ�����߼���ţ�i��ȡֵ�ڡ�1��L->Length+1����Χ��ʱ���ɳɹ����룬����true, �������ʧ�ܣ�����false�� 


int main()
{
	LinkList *h;
	ElemType  ch;
	InitList(h);  //���г���ʵ��
	int i = 1, n;
	while ((ch = getchar()) != '\n')
	{
		if (ListInsert(h, i, ch))
			i++;
	}
	scanf("%d", &n);
	DispListN(h, n);
	DestroyList(h);  //���г���ʵ��
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