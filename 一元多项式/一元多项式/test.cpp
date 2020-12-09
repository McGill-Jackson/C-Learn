#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include"FucDec.h"


//��ֵ
float GetValue(PolyPtr a,float x){
	float sum = 0;
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

	while ((pa != NULL)&&(pb != NULL)){
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

//�˷�(���ú���)
PolyPtr TimesPoly(PolyPtr a, PolyPtr b){
	
	
	PolyPtr c = (PolyPtr)malloc(sizeof(Poly));
	PolyPtr pa, pb, pc = NULL;
	if (a == NULL || b == NULL || c == NULL)
		return NULL;
	pa = a->next;
	pb = b->next;
	c->next = NULL;
	c->coef = 0;
	c->expn = 0;

	while (pa != NULL){
		pb = b->next;
		while (pb != NULL){
			
			PolyPtr r = (PolyPtr)malloc(sizeof(Poly));
			r->next = NULL;
			r->coef = pa->coef*pb->coef;
			r->expn = pa->expn+pb->expn;
			c = Add_Poly(c, r);
			pb = pb->next;
		}
		pa = pa->next;
	}
	return c;
}
//�˷�(�����ú���)
PolyPtr Times_Poly(PolyPtr a, PolyPtr b){


	PolyPtr c = (PolyPtr)malloc(sizeof(Poly));
	PolyPtr pa, pb, pc = NULL;
	if (a == NULL || b == NULL || c == NULL)
		return NULL;
	pa = a->next;
	pb = b->next;
	c->next = NULL;
	c->coef = 0;
	c->expn = 0;

	while (pa != NULL){
		pb = b->next;
		while (pb != NULL){
			
			PolyPtr r = (PolyPtr)malloc(sizeof(Poly));
			r->next = NULL;
			r->coef = pa->coef*pb->coef;
			r->expn = pa->expn + pb->expn;
			//c = Add_Poly(c, r);
			pc = c;
			int flot = 0;
			if (pc->next == NULL){
				pc->next = r;
			}
			else while (pc->next != NULL){
				if (pc->next->expn < r->expn){
					pc = pc->next;
					continue;
				}
				else if (pc->next->expn == r->expn){
					pc->next->coef += r->coef;
					free(r);
					flot++;
					break;
				}
				else{
					PolyPtr p = pc->next;
					pc->next = r;
					r->next = p;
					flot++;
					break;
				}
				pc = pc->next;
			}
			if (flot == 0){
				pc->next = r;
			}
			pb = pb->next;
		}
		pa = pa->next;
	}
	return c;
}

//�˷���������
PolyPtr Add_Poly(PolyPtr a, PolyPtr b){
	if (a == NULL || b == NULL)
		return NULL;
	PolyPtr pa = a;
	if (pa->next == NULL){
		pa->next = b;
		return a;
	}
	while (pa->next != NULL){
		if (pa->next->expn < b->expn){
			pa = pa->next;
			continue;
		}
		else if (pa->next->expn == b->expn){
			pa->next->coef += b->coef;
			free(b);
			return a;
		}
		else{
			PolyPtr p = pa->next;
			pa->next = b;
			b->next = p;
			return a;
		}
		pa = pa->next;
	}
	pa->next = b;
	return a;
}
//�˷��ڶ��ַ�ʽ
PolyPtr TimesPoly2(PolyPtr a, PolyPtr b){


	PolyPtr c = (PolyPtr)malloc(sizeof(Poly));
	PolyPtr pa, pb, pc = NULL;
	if (a == NULL || b == NULL || c == NULL)
		return NULL;
	pa = a->next;
	pb = b->next;
	c->next = NULL;
	c->coef = 0;
	c->expn = 0;

	while (pa != NULL){
		pb = b->next;
		PolyPtr d = (PolyPtr)malloc(sizeof(Poly));
		PolyPtr pd = d;
		d->next = NULL;
		d->coef = 0;
		d->expn = 0;

		while (pb != NULL){
			
			PolyPtr r = (PolyPtr)malloc(sizeof(Poly));
			r->next = NULL;
			r->coef = pa->coef*pb->coef;
			r->expn = pa->expn + pb->expn;
			pd->next = r;
			pd = r;
			pb = pb->next;
		}
		pc = c;
		c = AddPoly(c, d);
		Destroy(pc);
		Destroy(d);
		pa = pa->next;
	}
	return c;
}

//����˷�
ArrayPoly MultPoly(ArrayPoly a, ArrayPoly b){
	int i, j;
	ArrayPoly poly;
	memset(poly.coefArray, 0, sizeof(poly.coefArray));
	poly.Hightpower = a.Hightpower + b.Hightpower;
	for (i = 0; i <= a.Hightpower; i++){
		for (j = 0; j <= b.Hightpower; j++){
			poly.coefArray[i + j] += a.coefArray[i] * b.coefArray[j];
		}
	}
	return poly;
}

//˫Ŀ����ʱ����Ժ���
void Time_Spend(PolyPtr a, PolyPtr b, Func func){
	clock_t begin, duration;
	begin = clock();
	PolyPtr p = func(a, b);
	duration = clock() - begin;
	printf("��ʱԼ%d����\n", duration );
	Destroy(p);
}
//��Ŀ����ʱ����Ժ���
void Time_Spend1(PolyPtr a, Func_ func){
	clock_t begin, duration;
	begin = clock();
	PolyPtr p = func(a);
	duration = clock() - begin;
	printf("��ʱԼ%d����\n", duration);
	Destroy(p);
}
//��ֵ����ʱ����Ժ���
void Time_Spend3(PolyPtr a,float x){
	clock_t begin, duration;
	begin = clock();
	GetValue(a,x);
	duration = clock() - begin;
	printf("��ʱԼ%d����\n", duration);
}
//����˷�ʱ����Ժ���
void Time_Spend2(ArrayPoly a, ArrayPoly b){
	clock_t begin, duration;
	begin = clock();
	MultPoly(a, b);
	duration = clock() - begin;
	printf("��ʱԼ%d����\n", duration);
}


//�����������д���ļ�
void PutPoly(const char* filename){
	FILE* fp = NULL;
	float a = 0;
	int b = 0;
	srand((unsigned)time(NULL));
	fp = fopen(filename, "w+");
	for (int i = 0; i < maxsize; i++){
		a = (float)(rand() % 10);
		b = rand() % 5000;
		fprintf(fp, "%.1f %d ", a, b);
	}
	fclose(fp);
}

//������Ԫ�����뵽��������
ArrayPoly Conversion(PolyPtr a){
	PolyPtr pa;
	ArrayPoly array;
	
	pa = a->next;
	memset(array.coefArray, 0, sizeof(array.coefArray));
	array.Hightpower = 0;
	while (pa != NULL){
		if (pa->expn == array.Hightpower){
			array.coefArray[array.Hightpower] = pa->coef;
			pa = pa->next;
		}
		array.Hightpower++;
	}
	array.Hightpower--;
	return array;
}

//��������
void PrintArray(ArrayPoly a){
	for (int i = 0; i <= a.Hightpower; i++){
		printf("%6.1f", a.coefArray[i]);
	}
	printf("\n");
	return;
}

//�˷����Ժ���
void testTimes(PolyPtr a, PolyPtr b){
	ArrayPoly e = Conversion(a);
	ArrayPoly f = Conversion(b);
	printf("����:");
	Time_Spend2(e, f);//����
	//ArrayPoly g = MultPoly(e, f);
	//PrintArray(g);
	
	//Time_Spend(a, b,TimesPoly2);//�ڶ���
	//PolyPtr d = TimesPoly2(a, b);
	//PrintPoly(d);
	//Destroy(d);
	printf("�޺���:");

	Time_Spend(a, b, Times_Poly);//�к���
	//PolyPtr h = Times_Poly(a, b);
	//PrintPoly(h);
	//Destroy(h);
	printf("�к���:");

	Time_Spend(a, b, TimesPoly);//�к���
	//PolyPtr c = TimesPoly(a, b);
	//PrintPoly(c);
	//Destroy(c);

	return;
}

//ÿ�������ʱ��
void testTimes1(PolyPtr a, PolyPtr b){
	float x;
	printf("������X��ֵ:");
	scanf("%f", &x);
	printf("��ֵ����:"); Time_Spend3(a,x);
	printf("������:"); Time_Spend1(a, GetDerivation);
	printf("���������:"); Time_Spend1(a, Getlntegration);
	printf("�������:"); Time_Spend(a, b, AddPoly);
	printf("�������:"); Time_Spend(a, b, MinusPoly);
	printf("�������:"); Time_Spend(a, b, TimesPoly2);
}

//���ļ���������
PolyPtr GetPoly(const char* filename){
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

//���������д���ļ�
void PutsPoly(const char* filename, PolyPtr c){
	FILE* fp = NULL;
	
	PolyPtr pc = c->next;
	fp = fopen(filename, "w+");
	while (pc != NULL){
		
		fprintf(fp, "%.1f %d ", pc->coef, pc->expn);
		pc = pc->next;
	}
	fclose(fp);
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
		int linshi = i;
		for (int j = 0; j < NumPoly(a) - 1-linshi; j++){
			pa = c;
			pb = c->next;

			if (pa->expn == pb->expn){
				pa->coef = pa->coef + pb->coef;
				pa->next = pb->next;
				free(pb);
				linshi--;//���ͷŵ�һ�����,�ڲ�ѭ�����������,��linshi��һ�����ñȽϴ�������
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
			printf("%3.1f*x^%d", p->coef, p->expn);
		else
			printf("%3.1f", p->coef);
	}

	p = p->next;
	while (p){
		if (p->expn != 0)
			printf("%+3.1f*x^%d", p->coef, p->expn);
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
		if (choice < 0 || choice > 10) {
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
			float x;
			printf("������X��ֵ:");
			scanf("%f", &x);
			printf("����õ�ֵΪ:");
			printf("%3.1f\n",GetValue(a,x));
			break;
		case 2:
			c = GetDerivation(a);
			PutsPoly(".\\Polythree.txt", c);//�����д��3���ı�(��ͬ)
			printf("������:");
			PrintPoly(c);
			Destroy(c);
			break;
		case 3:
			c = Getlntegration(a);
			PutsPoly(".\\Polythree.txt", c);
			printf("���������:");
			PrintPoly(c);
			Destroy(c);
			break;
		case 4:
			c = AddPoly(a, b);
			PutsPoly(".\\Polythree.txt", c);
			printf("�������:");
			PrintPoly(c);
			Destroy(c);
			break;
		case 5:
			c = MinusPoly(a, b);
			PutsPoly(".\\Polythree.txt", c);
			printf("�������:");
			PrintPoly(c);
			Destroy(c);
			break;
		case 6:
			c = TimesPoly(a, b);
			PutsPoly(".\\Polythree.txt", c);
			printf("�������:");
			PrintPoly(c);
			Destroy(c);
			break;
		case 7:
			a=GetPoly(".\\Polyone.txt");
			SortPoly(a);
			b=GetPoly(".\\Polytwo.txt");
			SortPoly(b);
			break;
		case 8:
			printf("\n�����û��ĵ�һ��һԪ����ʽ:");
			PrintPoly(a);
			printf("\n�����û��ĵڶ���һԪ����ʽ:");
			PrintPoly(b);
			//printf("\n�����û�������еļ���Ľ��:\n");
			//PrintPoly(c);
			break;
		case 9:
			testTimes(a, b);
			break;
		case 10:
			testTimes1(a, b);
			break;
		}
	}

}

int main(){
	Enter();
	system("pause");
	return 0;
}