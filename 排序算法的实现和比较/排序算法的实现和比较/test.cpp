#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>

#define MAXSIZE 1000//数据规模
typedef int KeyType;
typedef struct{
	int count[16];
	int size;
}Number,*Numstr;
Number n[9] = { 0 };
typedef struct{
	KeyType key;
	int flag;
}RedType,*Redstr;
typedef struct{
	RedType r[MAXSIZE + 1];
	int length;
}SqList,*Sqstr;
typedef void(*Func)(Sqstr);

//循环次数计算
void Count(Numstr n){
	n->count[1]++;
	int i = 0;
	for (i = 1; n->count[i] == 10; i++){
		n->count[i] = 0;
		n->count[i + 1]++;
	}
	if ((n->count[i] == 1)&&(n->size+1 == i)){
		n->size++;
	}
}
//循环次数打印
void Countprintf(Numstr n){
	for (int i = n->size; i > 0; i--){
		printf("%d", n->count[i]);
	}
}
//循环次数重置
void ReCount(Numstr n){
	for (int i = 1; i <= n->size; i++){
		n->count[i] = 0;
	}
	n->size = 0;
}
//直接插入排序
void InsertSort(Sqstr L){
	for (int i = 2; i <= L->length; ++i){
		if (L->r[i].key < L->r[i - 1].key){
			L->r[0] = L->r[i];
			L->r[i] = L->r[i - 1];
			int j;
			for (j = i - 2; L->r[0].key < L->r[j].key; --j){
				L->r[j + 1] = L->r[j];//基本语句
				Count(n + 1);
			}
			L->r[j + 1] = L->r[0];
		}
	}
	
}
//希尔插入
void ShellInsert(Sqstr L, int dk) {
	for (int i = dk + 1; i <= L->length; ++i){
		Count(n + 2);
		if (L->r[i].key < L->r[i - dk].key){
			L->r[0] = L->r[i];
			int j;
			for (j = i - dk; j>0 && L->r[0].key < L->r[j].key; j -= dk){
				L->r[j + dk] = L->r[j];//基本语句
				Count(n + 2);
			}
			L->r[j + dk] = L->r[0];
		}
	}
}
//希尔排序
void ShellSort(Sqstr L, int dt[], int t){
	for (int k = 0; k < t; ++k){
		ShellInsert(L, dt[k]);
	}
}
//希尔排序(all)
void ShellSortall(Sqstr L){
	int dt[5] = { 5, 4, 3, 2, 1 };
	ShellSort(L,dt,5);
}
//冒泡排序
void BubbleSort(Sqstr L){
	int m = L->length - 1;
	int flag = 1;
	while ((m>0) && (flag == 1)){
		flag = 0;
		for (int j = 1; j <= m; j++){
			Count(n + 3);
			if (L->r[j].key > L->r[j + 1].key){
				flag = 1;
				RedType t = L->r[j];
				L->r[j] = L->r[j + 1];
				L->r[j + 1] = t;
			}
		}
		m--;
	}
}
//快速交换
int Partition(Sqstr L, int low, int high){
	L->r[0] = L->r[low];
	int pivotkey = L->r[low].key;
	while (low < high){
		while (low < high&&L->r[high].key >= pivotkey){ --high; Count(n+4); }
		L->r[low] = L->r[high];
		while (low < high&&L->r[low].key <= pivotkey){ ++low; Count(n + 4); }
		L->r[high] = L->r[low];
	}
	L->r[low] = L->r[0];
	return low;
}
//快速排序*
void QSort(Sqstr L, int low, int high){
	if (low < high){
		int pivotloc = 0;
		pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}
//快速排序(all)
void Qsortall(Sqstr L){
	QSort(L, 1, L->length);
}
//简单选择排序
void SelectSort(Sqstr L){
	for (int i = 1; i < L->length; ++i){
		int k = i;
		for (int j = i + 1; j <= L->length; ++j){
			if (L->r[j].key < L->r[k].key)k = j;
			Count(n + 5);
		}
		if (k != i){
			RedType t = L->r[i];
			L->r[i] = L->r[k];
			L->r[k] = t;
		}
	}
}
//调整堆
void HeapAdjust(Sqstr L, int s, int m){
	RedType rc = L->r[s];
	for (int j = 2 * s; j <= m; j *= 2){
		Count(n + 6);
		if (j < m&&L->r[j].key < L->r[j + 1].key)++j;
		if (rc.key >= L->r[j].key)break;
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = rc;
}
//建初堆
void CreatHeap(Sqstr L){
	int n = L->length;
	for (int i = n / 2; i>0; --i){
		HeapAdjust(L, i, n);
	}
}
//堆排序*
void HeapSort(Sqstr L){
	CreatHeap(L);
	for (int i = L->length; i > 1; --i){
		RedType x = L->r[1];
		L->r[1] = L->r[i];
		L->r[i] = x;
		HeapAdjust(L, 1, i - 1);
	}
}
//归并(两有序)
void Merge(RedType R[], RedType T[], int low, int mid, int high){
	int i = low; int j = mid + 1; int k = low;
	while (i <= mid&&j <= high){
		Count(n + 7);
		if (R[i].key <= R[j].key)T[k++] = R[i++];
		else T[k++] = R[j++];
	}
	while (i <= mid){ T[k++] = R[i++]; }
		
	while (j <= high){ T[k++] = R[j++]; }
}
//归并转移
void MSort(RedType R[], RedType T[], int low, int high){
	Redstr S = (Redstr)malloc(sizeof(RedType)*(MAXSIZE + 1));
	//RedType S[MAXSIZE + 1];

	if (low == high)T[low] = R[low];
	else{
		int mid = (low + high) / 2;
		MSort(R, S, low, mid);
		MSort(R, S, mid + 1, high);
		Merge(S, T, low, mid, high);
	}
	free(S);
}
//归并排序
void MergeSort(Sqstr L){
	MSort(L->r, L->r, 1, L->length);
}
//基数排序
void RadixSort(Sqstr L){
	int max = L->r[1].key, i, j, k, tag, tag2, count = 0;
	RedType *temp[10];
	for (i = 2; i <= L->length; i++) {   //找最大数
		if (max < L->r[i].key) {
			max = L->r[i].key;
		}
	}
	while (max) {   //确定最大位数
		count++;
		max = max / 10;
	}
	for (i = 0; i < 10; i++) {
		temp[i] = (RedType *)malloc(sizeof(RedType)* (L->length + 1));
		temp[i][0].key = 0;
	}
	max = 1;
	while (count){
		for (i = 1; i <= L->length; i++) {   //分桶 
			Count(n + 8);
			tag = L->r[i].key / max % 10;
			temp[tag][0].key++;
			tag2 = temp[tag][0].key;
			temp[tag][tag2] = L->r[i];
		}
		k = 1;
		for (i = 0; i < 10; i++) {   //合并
			for (j = 1; j <= temp[i][0].key; j++){
				L->r[k] = temp[i][j];
				k++;
			}
			temp[i][0].key = 0;
		}

		max *= 10;
		count--;
	}
}
//顺序表初始化
Sqstr CreatSqList(){
	Sqstr L = (Sqstr)malloc(sizeof(SqList));
	memset(L->r, 0, sizeof(RedType)*(MAXSIZE + 1));
	L->length = 0;
	return L;
}
//随机生成数据读入文件
void PutData(const char* filename){
	FILE* fp = NULL;
	int a = 0;
	srand((unsigned)time(NULL));
	fp = fopen(filename, "w+");

	for (int i = 0; i < MAXSIZE; i++){
		a = rand() % MAXSIZE;
		fprintf(fp, " %d", a);
	}
	fclose(fp);
}
//从文件读入数据
void DataRead(Sqstr L,const char* filename){
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	if (!fp)return;

	while (!feof(fp)){
		L->length++;
		int c = 0;
		fscanf(fp, "%d", &c);
		L->r[L->length].key = c;
		L->r[L->length].flag++;
		for (int i = 1; i <= L->length-1; ++i){
			if (L->r[i].key == c){
				L->r[L->length].flag++;
			}
		}

	}
	fclose(fp);
}
//输出数据
void PrinttoU(Sqstr L){
	for (int i = 1; i <= L->length; ++i){
		printf("%3d", L->r[i].key);
	}
	printf("\n");
}
//稳定性判断
void Stability(Sqstr L){
	for (int i = 1; i < L->length; ++i){
		if (L->r[i].key==L->r[i+1].key&&L->r[i].flag>L->r[i + 1].flag){
			printf("不稳定.         ");
			return;
		}
	}
	printf("稳定.           ");
}
//结果正确性判断
void ifTure(Sqstr L){
	for (int i = 1; i < L->length; ++i){
		if (L->r[i].key > L->r[i + 1].key){
			printf("不正确.         ");
			return;
		}
	}
	printf("正确.           ");
}
//排序集
void test(Func func,int choice){
	Sqstr L1 = CreatSqList();
	DataRead(L1, ".\\Data.txt");
	clock_t begin, duration;
	begin = clock();
	func(L1);
	duration = clock() - begin;
	Stability(L1);
	ifTure(L1);
	printf("%5d毫秒           ", duration);
	Countprintf(n + choice);
	printf("\n");
	ReCount(n + choice);
	//PrinttoU(L1);
	free(L1);
}
void TEST(){
	printf("数据规模:%d    随机数范围:%d\n", MAXSIZE, MAXSIZE);
	printf("         是否稳定\t是否正确\t  所用时间\t   执行次数\t\n");
	for (int b = 1; b <= 10; b++){
		PutData(".\\Data.txt");
		printf("第%d组实验\n", b);
		
		printf("插入排序:"); test(InsertSort, 1);
		printf("希尔排序:"); test(ShellSortall, 2);
		printf("冒泡排序:"); test(BubbleSort, 3);
		printf("快速排序:"); test(Qsortall, 4);
		printf("选择排序:"); test(SelectSort, 5);
		printf("堆排序:  "); test(HeapSort, 6);
		printf("归并排序:"); test(MergeSort, 7);
		printf("基数排序:"); test(RadixSort, 8);
		Sleep(1000);
	}
}
int Menu(){
	printf("========================\n");
	printf("=1.    直接插入排序    =\n");
	printf("=2.      希尔排序      =\n");
	printf("=3.      冒泡排序      =\n");
	printf("=4.      快速排序      =\n");
	printf("=5.    简单选择排序    =\n");
	printf("=6.       堆排序       =\n");
	printf("=7.      归并排序      =\n");
	printf("=8.      基数排序      =\n");
	printf("=0.        退出        =\n");
	printf("========================\n");
	printf("请输入你的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//入口
void Enter(){
	PutData(".\\Data.txt");
	//转移表
	Func funcs[] = {
		NULL,
		InsertSort,
		ShellSortall,
		BubbleSort,
		Qsortall,
		SelectSort,
		HeapSort,
		MergeSort,
		RadixSort
	};
	while (1){
		int choice = Menu();
		if (choice < 0 || choice > 8) {
			printf("您的输入无效!\n");
			continue;
		}
		if (choice == 0){
			printf("程序结束.\n");
			break;
		}
		test(funcs[choice],choice);
	}
}
int main(){
	//TEST();

	Enter();
	system("pause");
	return 0;
}