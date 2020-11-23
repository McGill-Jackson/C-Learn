//һԪ����ʽ�Ļ�������
//��ֵ
//��
//�����
//��
//��
//��
//����
//���

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

//һԪ����ʽԪ��	
typedef struct node{
	float coef;
	int expn;
	struct node* next;
}Poly,*PolyPtr;

void Destroy(PolyPtr a);

//��ֵ
float GetValue(PolyPtr a){
	float x, sum = 0;
	printf("������X��ֵ��");
	scanf("%f", &x);
	PolyPtr pa = a->next;
	while (pa != NULL){
		if (pa->expn == 0){
			sum = sum + pa->coef;
			pa = pa->next;
		}
		else{
			float m=1.0;
			for (int i = 0; i < pa->expn; i++){
				m = m*x;
			}
			sum = sum + pa->coef*m;
			pa = pa->next;
		}
	}
	return sum;
}

//��
PolyPtr GetDerivation(PolyPtr a){
	PolyPtr c = (PolyPtr)malloc(sizeof(Poly));
	PolyPtr pa, r, pc = c;
	if (a == NULL || c == NULL)
		return NULL;
	pa = a->next;
	pc->next = NULL;
	pc->coef = 0;
	pc->expn = 0;

	while (pa != NULL){
		r = (PolyPtr)malloc(sizeof(Poly));
		r->next = NULL;
		r->coef = pa->coef*pa->expn;
		r->expn = pa->expn - 1;
		pa = pa->next;
		if (r->coef == 0){
			free(r);
			r = NULL;
		}
		if (r){
			pc->next = r;
			pc = r;
			c->expn = r->expn;
		}
	}
	return c;
}

//�����
PolyPtr Getlntegration(PolyPtr a){
	PolyPtr c = (PolyPtr)malloc(sizeof(Poly));
	PolyPtr pa, r, pc = c;
	if (a == NULL || c == NULL)
		return NULL;
	pa = a->next;
	pc->next = NULL;
	pc->coef = 0;
	pc->expn = 0;

	while (pa != NULL){
		r = (PolyPtr)malloc(sizeof(Poly));
		r->next = NULL;
		r->coef = pa->coef / (pa->expn + 1);
		r->expn = pa->expn + 1;
		pa = pa->next;
		if (r->coef == 0){
			free(r);
			r = NULL;
		}
		if (r){
			pc->next = r;
			pc = r;
			c->expn = r->expn;
		}
	}
	return c;
}

//�ӷ�
PolyPtr AddPoly(PolyPtr a, PolyPtr b){
	PolyPtr c = (PolyPtr)malloc(sizeof(Poly));
	PolyPtr pa, pb, r, pc = c;
	if (a == NULL || b == NULL || c == NULL)
		return NULL;
	pa = a->next;
	pb = b->next;
	pc->next = NULL;
	pc->coef = 0;
	pc->expn = 0;

	while (pa != NULL&&pb != NULL){
		r = (PolyPtr)malloc(sizeof(Poly));
		r->next = NULL;
		if (pa->expn < pb->expn){
			r->coef = pa->coef;
			r->expn = pa->expn;
			pa = pa->next;
		}
		else if (pa->expn > pb->expn){
			r->coef = pb->coef;
			r->expn = pb->expn;
			pb = pb->next;
		}
		else{
			r->coef = pa->coef + pb->coef;
			r->expn = pa->expn;
			pa = pa->next;
			pb = pb->next;
			if (r->coef == 0){
				free(r);
				r = NULL;
			}
		}
		if (r){
			pc->next = r;
			pc = r;
			c->expn = r->expn;
		}
	}
	r = (pa == NULL ? pb : pa);
	//lΪ�ϳ���һ��һԪ����ʽ������Ĳ���
	PolyPtr l;
	while (r != NULL){
		l = (PolyPtr)malloc(sizeof(Poly));
		l->coef = r->coef;
		l->expn = r->expn;
		l->next = NULL;
		pc->next = l;
		c->expn = r->expn;
		pc = l;
		r = r->next;
	}
	return c;
}

//����
PolyPtr MinusPoly(PolyPtr a, PolyPtr b){
	PolyPtr c = (PolyPtr)malloc(sizeof(Poly));
	PolyPtr pb, r, pc = c;
	if (a == NULL || b == NULL || c == NULL)
		return NULL;
	pb = b->next;
	pc->next = NULL;
	pc->coef = 0;
	pc->expn = 0;

	while (pb != NULL){
		r = (PolyPtr)malloc(sizeof(Poly));
		r->next = NULL;
		r->coef = -(pb->coef) ;
		r->expn = pb->expn;
		pb = pb->next;
		if (r->coef == 0){
			free(r);
			r = NULL;
		}
		if (r){
			pc->next = r;
			pc = r;
			c->expn = r->expn;
		}
	}
	PolyPtr d = AddPoly(a,c);
	Destroy(c);
	return d;
}

//�˷�
PolyPtr TimesPoly(PolyPtr a, PolyPtr b){
	
	
	PolyPtr c = (PolyPtr)malloc(sizeof(Poly));
	PolyPtr pa, pb, pc = c;
	if (a == NULL || b == NULL || c == NULL)
		return NULL;
	pa = a->next;
	pb = b->next;
	pc->next = NULL;
	pc->coef = 0;
	pc->expn = 0;

	while (pa != NULL){
		pb = b->next;
		while (pb != NULL){
			PolyPtr d = (PolyPtr)malloc(sizeof(Poly));
			d->next = NULL;
			d->coef = 0;
			d->expn = 0;
			PolyPtr r = (PolyPtr)malloc(sizeof(Poly));
			r->next = NULL;
			r->coef = pa->coef*pb->coef;
			r->expn = pa->expn+pb->expn;
			d->next = r;
			c = AddPoly(c, d);
			free(d);
			free(r);
			pb = pb->next;
		}
		pa = pa->next;
	}
	return c;
}

//ʱ����Ժ���
void Time_Spend(PolyPtr a, PolyPtr b){
	clock_t begin, duration;
	begin = clock();
	TimesPoly(a, b);
	duration = clock() - begin;
	printf("��ʱԼ%d����\n", duration );
}

//�����������д���ļ�
void PutPoly(char* filename){
	FILE* fp = NULL;
	float a = 0;
	int b = 0;
	srand((unsigned)time(NULL));
	fp = fopen(filename, "w+");
	for (int i = 0; i < 300; i++){
		a = (float)(rand() % 100);
		b = rand() % 100;
		fprintf(fp, "%f %d ", a, b);
	}
	fclose(fp);
}

//����
PolyPtr GetPoly(char* filename){
	PolyPtr poly = NULL, p, pTail;
	FILE* fp = NULL;
	fp = fopen(filename, "r");

	if (!fp)
		return poly;
	poly = (PolyPtr)malloc(sizeof(Poly));
	poly->coef = 0;
	poly->expn = 0;
	poly->next = NULL;
	pTail = poly;

	while (!feof(fp)){
		p = (PolyPtr)malloc(sizeof(Poly));
		p->coef = 0;
		p->expn = 0;
		fscanf(fp, "%f%d", &(p->coef), &(p->expn));
		if (p->coef == 0){
			free(p);
			continue;
		}
		p->next = pTail->next;
		pTail->next = p;
		pTail = p;
	}
	return poly;
}

//��һԪ����ʽ������
int NumPoly(PolyPtr a){
	PolyPtr pa;
	int count = 0;
	pa = a->next;
	while (pa != NULL){
		count++;
		pa = pa->next;
	}
	return count;
}

//һԪ����ʽ��������
void SortPoly(PolyPtr a){
	PolyPtr pa, pb, c ;
	if (a == NULL)return ;

	
	for (int i = 0; i < NumPoly(a) - 1; i++){
		c = a->next;
		for (int j = 0; j < NumPoly(a) - 1 - i; j++){
			pa = c;
			pb = c->next;

			if (pa->expn == pb->expn){
				pa->coef = pa->coef + pb->coef;
				pa->next = pb->next;
				free(pb);
				continue;
			}
			if (pa->expn > pb->expn){
				int m = pa->expn;
				float s = pa->coef;
				pa->expn = pb->expn;
				pa->coef = pb->coef;
				pb->expn = m;
				pb->coef = s;
			}
			c = c->next;
		}
	}
}

//���
void PrintPoly(PolyPtr a){
	PolyPtr p = NULL;
	if (!a)
		return;
	p = a->next;
	if (p->coef != 0){
		if (p->expn != 0)
			printf("%3.1f x^%d", p->coef, p->expn);
		else
			printf("%3.1f", p->coef);
	}

	p = p->next;
	while (p){
		if (p->expn != 0)
			printf("%+3.1f x^%d", p->coef, p->expn);
		else
			printf("%+3.1f", p->coef);
		p = p->next;
	}
	printf("\n");
}

//�ͷ��ڴ�
void Destroy(PolyPtr a){
	PolyPtr p = NULL;
	while (a){
		p = a->next;
		free(a);
		a = NULL;
		a = p;
	}
}

//�˵�
int Menu() {
	printf("=====================\n");
	printf(" 1. ��һԪ����ʽ��ֵ\n");
	printf(" 2. ��һԪ����ʽ��\n");
	printf(" 3. ��һԪ����ʽ�����\n");
	printf(" 4. ��һԪ����ʽ���\n");
	printf(" 5. ��һԪ����ʽ���\n");
	printf(" 6. ��һԪ����ʽ���\n");
	printf(" 7. ���ļ��ж���һԪ����ʽ\n");
	printf(" 8. ��һԪ����ʽ���\n");
	printf(" 0. �˳�\n");
	printf(" ע(��Ŀ����ֻ�����ڶ���ʽ1)\n");
	printf("=====================\n");
	printf(" ����������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//��ں���
void Enter(){
	PolyPtr a = NULL;
	PolyPtr b = NULL;
	PolyPtr c = NULL;
	PutPoly(".\\Polyone.txt");
	Sleep(1000);
	PutPoly(".\\Polytwo.txt");
	while (1){
		
		int choice = Menu();
		if (choice < 0 || choice > 8) {
			printf("����������Ч!\n");
			continue;
		}
		if (choice == 0) {
			Destroy(a);
			Destroy(b);
			Destroy(c);
			printf("goodbye!\n");
			break;
		}
		switch (choice){
		case 1:
			printf("%3.1f\n",GetValue(a));
			break;
		case 2:
			Destroy(c);
			c = GetDerivation(a);
			printf("����ɹ�!\n");
			break;
		case 3:
			Destroy(c);
			c = Getlntegration(a);
			printf("����ɹ�!\n");
			break;
		case 4:
			Destroy(c);
			c = AddPoly(a, b);
			printf("����ɹ�!\n");
			break;
		case 5:
			Destroy(c);
			c = MinusPoly(a, b);
			printf("����ɹ�!\n");
			break;
		case 6:
			Destroy(c);
			c = TimesPoly(a, b);
			printf("����ɹ�!\n");
			break;
		case 7:
			a=GetPoly(".\\Polyone.txt");
			SortPoly(a);
			b=GetPoly(".\\Polytwo.txt");
			SortPoly(b);
			Time_Spend(a, b);
			break;
		case 8:
			printf("\n�����û��ĵ�һ��һԪ����ʽ:");
			PrintPoly(a);
			printf("\n�����û��ĵڶ���һԪ����ʽ:");
			PrintPoly(b);
			printf("\n�����û�������еļ���Ľ��:\n");
			PrintPoly(c);
			break;
		}
	}

}

int main(){
	Enter();
	system("pause");
	return 0;
}