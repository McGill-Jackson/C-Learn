#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 1024
#define Max 256
typedef  int Weight;
typedef  int TNode;

//�����������
typedef struct HTNode{
	char name;
	Weight weight;
	TNode parent, lchild, rchild;
}HTNode,*HTNodethr;

//��������
typedef struct HT{
	HTNode tree[MAXSIZE];
	int size;
}HT,*HTthr;

//������
typedef struct Ps{
	char code[MAXSIZE];
	int size;
}Ps,*Psthr;

//���뱾
typedef struct PsBook{
	Ps book[Max];
	int size;
}PsBook,*PsBookstr;

void Reverse(PsBookstr b);

//���ı�(��Ȩֵ)�ж�ȡ
void GetName(const char* filename, HTthr t){
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	if (!fp)return;
	
	while (!feof(fp)){
		char c = 0;
		fscanf(fp, "%c", &c);
		if (c == '\0')return;
		int i;
		for (i = 1; i < t->size; i++){
			if (t->tree[i].name == c){
				t->tree[i].weight++;
				break;
			}
		}
		if (i == t->size){
			t->tree[i].name = c;
			t->tree[i].weight++;
			t->size++;
		}
	}
	fclose(fp);
}
//���ı�(��Ȩֵ)�ж�ȡ
void GetWeight(const char* filenameN, const char* filenameW, HTthr t){
	FILE* fpn = NULL;
	fpn = fopen(filenameN, "r");
	if (!fpn)return;
	FILE* fpw = NULL;
	fpw = fopen(filenameW, "r");
	if (!fpw)return;

	int i = 1;
	while (!feof(fpw)){
		char c;
		Weight w;
		fscanf(fpn, "%c", &c);
		fscanf(fpw, "%d", &w);
		t->tree[i].name = c;
		t->tree[i].weight = w;
		i++;
		t->size++;
	}
	fclose(fpn);
	fclose(fpw);
}
//Weight and Name Writeing
void Write(HTthr t, const char* filename1, const char* filename2){
	FILE* fp1 = NULL;
	fp1 = fopen(filename1, "w+");
	if (!fp1)return;
	FILE* fp2 = NULL;
	fp2 = fopen(filename2, "w+");
	if (!fp2)return;

	for (int i = 1; i < t->size; i++){
		fprintf(fp1, "%c", t->tree[i].name);
		fprintf(fp2, "% d", t->tree[i].weight);
	}
	fclose(fp1);
	fclose(fp2);
}
//������������
void CreatTree(HTthr t){
	if (t == NULL || t->size == 1)return;
	int n = t->size-1;
	for (int i = 1; i < n; i++){
		int l = 0, r = 0;
		int lweight = 10000, rweight = 10000;
		for (int j = 1; j < t->size; j++){
			if (t->tree[j].parent != 0)continue;
			if (t->tree[j].weight <= lweight){
				rweight = lweight;
				r = l;
				lweight = t->tree[j].weight;
				l = j;
				continue;
			}
			else if(t->tree[j].weight <= rweight){
				rweight = t->tree[j].weight;
				r = j;
			}
		}
		t->tree[t->size].weight = lweight + rweight;
		t->tree[t->size].lchild = l;
		t->tree[t->size].rchild = r;
		t->tree[l].parent = t->tree[r].parent = t->size;
		t->size++;
	}
}
//�������뱾
void CreatBook(HTthr t,PsBookstr b){
	for (int i = 1; t->tree[i].name != '\0'; i++){
		b->book[i].code[b->book[i].size++] = t->tree[i].name;
		int j = i;
		while (t->tree[j].parent != 0){
			if (t->tree[t->tree[j].parent].lchild == j){
				b->book[i].code[b->book[i].size++] = '0';
			}
			else{
				b->book[i].code[b->book[i].size++] = '1';
			}
			j = t->tree[j].parent;
		}
		b->size++;
	}
	Reverse(b);
}
//��������
void Reverse(PsBookstr b){
	for (int i = 1; i < b->size; i++){
		for (int j = 1, k = b->book[i].size - 1; j < k; j++, k--){
			char c = b->book[i].code[j];
			b->book[i].code[j] = b->book[i].code[k];
			b->book[i].code[k] = c;
		}
	}
}
//������뱾
void PrintfBook(PsBookstr b){
	printf("���뱾����:\n");
	for (int i = 1; i < b->size; i++){
		printf("%c:", b->book[i].code[0]);
		for (int j = 1; j < b->book[i].size; j++){
			printf("%c", b->book[i].code[j]);
		}
		printf("\n");
	}
}

//����
void Coding(const char* filename1, PsBookstr b, const char* filename2){
	FILE* fp1 = NULL;
	fp1 = fopen(filename1, "r");
	if (!fp1)return;
	FILE* fp2 = NULL;
	fp2 = fopen(filename2, "w+");
	if (!fp2)return;

	printf("��������:");
	while (!feof(fp1)){
		char c = 0;
		fscanf(fp1, "%c", &c);
		for (int i = 1; i < b->size; i++){
			if (b->book[i].code[0] == c){
				for (int j = 1; j < b->book[i].size; j++){
					fprintf(fp2, "%c", b->book[i].code[j]);
					printf("%c", b->book[i].code[j]);
				}
			}
		}
	}
	printf("\n");
	fclose(fp1);
	fclose(fp2);
}

//����
void Decoding(const char* filename1, HTthr t, const char* filename2){
	if (t->size == 1)return;
	FILE* fp1 = NULL;
	fp1 = fopen(filename1, "r");
	if (!fp1)return;
	FILE* fp2 = NULL;
	fp2 = fopen(filename2, "w+");
	if (!fp2)return;
	int i = t->size - 1;
	while (!feof(fp1)){
		char c = 0;
		fscanf(fp1, "%c", &c);
		if (c == '0'){
			i = t->tree[i].lchild;
			if (t->tree[i].lchild == 0){
				printf("%c", t->tree[i].name);
				fprintf(fp2, "%c", t->tree[i].name);
				i = t->size - 1;
			}
		}
		else{
			i = t->tree[i].rchild;
			if (t->tree[i].lchild == 0){
				printf("%c", t->tree[i].name);
				fprintf(fp2, "%c", t->tree[i].name);
				i = t->size - 1;
			}
		}
	}
	printf("\n");
	fclose(fp1);
	fclose(fp2);
}

//��֤��������
void Verify(HTthr t){
	printf("��� �ַ� Ȩ�� ˫�� �� �Һ�\t\n");
	for (int i = 1; i < t->size; i++){
		printf("%3d %4c %4d %4d %4d %4d\t", i, t->tree[i].name, t->tree[i].weight, t->tree[i].parent, t->tree[i].lchild, t->tree[i].rchild);
		printf("\n");
	}
}

//��֤�����ȷ��
void Result(const char* filename1, const char* filename2){
	FILE* fp1 = NULL;
	fp1 = fopen(filename1, "r");
	if (!fp1)return;
	FILE* fp2 = NULL;
	fp2 = fopen(filename2, "r");
	if (!fp2)return;

	while ((!feof(fp1)) || (!feof(fp2))){
		char c1 = 0;
		char c2 = 0;
		fscanf(fp1, "%c", &c1);
		fscanf(fp2, "%c", &c2);
		if (c1 != c2){
			printf("���������.\n");
			break;
		}
	}
	fclose(fp1);
	fclose(fp2);
}

int Menu(){
	printf("========================\n");
	printf("=1.�������������(��Ȩ)=\n");
	printf("=2.        ����        =\n");
	printf("=3.�������������(��Ȩ)=\n");
	printf("=4.        ����        =\n");
	printf("=0.        �˳�        =\n");
	printf("========================\n");
	printf("���������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Enter(){

	HTthr pt = (HTthr)malloc(sizeof(HT));
	memset(pt->tree, 0, MAXSIZE*sizeof(HTNode));
	pt->size = 1;

	PsBookstr pb = (PsBookstr)malloc(sizeof(PsBook));
	for (int i = 0; i < Max; i++){
		memset(pb->book[i].code, 0, MAXSIZE*sizeof(char));
		pb->book[i].size = 0;
	}
	pb->size = 1;

	HTthr upt = (HTthr)malloc(sizeof(HT));
	memset(upt->tree, 0, MAXSIZE*sizeof(HTNode));
	upt->size = 1;

	PsBookstr upb = (PsBookstr)malloc(sizeof(PsBook));
	for (int i = 0; i < Max; i++){
		memset(upb->book[i].code, 0, MAXSIZE*sizeof(char));
		upb->book[i].size = 0;
	}
	upb->size = 1;

	while (1){
		int choice = Menu();
		if (choice < 0 || choice > 4) {
			printf("����������Ч!\n");
			continue;
		}
		if (choice == 0){
			break;
		}
		switch (choice){
		case 1:
			GetName(".\\Original.txt", pt);
			Verify(pt);
			Write(pt, ".\\Getname.txt", ".\\Weight.txt");
			CreatTree(pt);
			CreatBook(pt, pb);
			PrintfBook(pb);
			break;
		case 2:
			Coding(".\\Original.txt", pb, ".\\Decoding.txt");
			break;
		case 3:
			GetWeight(".\\Getname.txt",".\\Weight.txt", upt);
			CreatTree(upt);
			CreatBook(upt, upb);
			PrintfBook(upb);

			break;
		case 4:
			Decoding(".\\Decoding.txt", upt, ".\\ReOriginal.txt"); 
			Result(".\\ReOriginal.txt", ".\\Original.txt");
			break;
		}
	}
}

int main(){

	Enter();
	system("pause");
	return 0;
}