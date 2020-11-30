
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode          //���嵥����������
{
	ElemType data;
	struct LNode *next;        //ָ���̽��
} LinkList;

LinkList * CreateListF(LinkList *L, ElemType a[], int n);//ͷ�巨����������
LinkList * CreateListR(LinkList *L, ElemType a[], int n);//β�巨����������
void DispList(LinkList *L); //������������н��ֵ��ÿ�����֮���ÿո������������Ϊ�գ������NULL��ȫ������û��з������� 
void SetListNULL(LinkList *L);//ɾ�������������ݽ��,��������Ϊ�ձ� ���г���ʵ�֡�

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

void SetListNULL(LinkList *L)// ���г���ʵ�֣�ϸ�ڲ���ɾ�������������ݽ��,��������Ϊ�ձ�
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
//ͷ�巨����������
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
//β�巨����������
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