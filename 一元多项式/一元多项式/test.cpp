#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#define MAXSIZE	10000//数组最大元素
#define maxsize 1000//随机生成数据数
//一元多项式元素(链表)	
typedef struct node{
	float coef;
	int expn;
	struct node* next;
}Poly,*PolyPtr;

//一元多项式元素(数组)
typedef struct{
	float coefArray[MAXSIZE + 1];
	int Hightpower;//expn的最大值 
}ArrayPoly;

float GetValue(PolyPtr a);//求一元多项式的值
PolyPtr GetDerivation(PolyPtr a);//对一元多项式求导
PolyPtr Getlntegration(PolyPtr a);//对一元多项式求积分
PolyPtr AddPoly(PolyPtr a, PolyPtr b);//两个一元多项式的和
PolyPtr MinusPoly(PolyPtr a, PolyPtr b);//两个一元多项式的差
PolyPtr TimesPoly(PolyPtr a, PolyPtr b);//乘法第一种形式
PolyPtr TimesPoly2(PolyPtr a, PolyPtr b);//乘法第二种形式
PolyPtr GetPoly(char* filename);//从文件读入数据
void Time_Spend(PolyPtr a, PolyPtr b);
void Time_Spend2(PolyPtr a, PolyPtr b);//时间测试函数
void PutPoly(char* filename);//随机生成数据写入文件
void testTimes(PolyPtr a, PolyPtr b);//乘法测试函数
int NumPoly(PolyPtr a);//数一元多项式的项数
void SortPoly(PolyPtr a);//一元多项式升幂排列
void Destroy(PolyPtr a);//释放内存
void PrintPoly(PolyPtr a);//将一元多项式输出

//求值
float GetValue(PolyPtr a){
	float x, sum = 0;
	printf("请输入X的值：");
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

//求导
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

//求积分
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

//加法
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
	//l为较长的一个一元多项式多出来的部分
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

//减法
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

//乘法
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
			PolyPtr d = (PolyPtr)malloc(sizeof(Poly));
			d->next = NULL;
			d->coef = 0;
			d->expn = 0;
			PolyPtr r = (PolyPtr)malloc(sizeof(Poly));
			r->next = NULL;
			r->coef = pa->coef*pb->coef;
			r->expn = pa->expn+pb->expn;
			d->next = r;
			pc = c;
			c = AddPoly(c, d);
			Destroy(pc);
			free(d);
			free(r);
			pb = pb->next;
		}
		pa = pa->next;
	}
	return c;
}
//乘法第二种方式
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

/*数组乘法*/
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

//定义一个函数指针
typedef PolyPtr(*Func)(PolyPtr, PolyPtr);

//时间测试函数
void Time_Spend(PolyPtr a, PolyPtr b, Func func){
	clock_t begin, duration;
	begin = clock();
	//TimesPoly(a, b);//带测函数
	func(a, b);
	duration = clock() - begin;
	printf("用时约%d毫秒\n", duration );
}

void Time_Spend2(ArrayPoly a, ArrayPoly b){
	clock_t begin, duration;
	begin = clock();
	MultPoly(a, b);
	duration = clock() - begin;
	printf("用时约%d毫秒\n", duration);
}
//随机生成数据写入文件
void PutPoly(char* filename){
	FILE* fp = NULL;
	float a = 0;
	int b = 0;
	srand((unsigned)time(NULL));
	fp = fopen(filename, "w+");
	for (int i = 0; i < maxsize; i++){
		a = (float)(rand() % 10);
		b = rand() % 1000;
		fprintf(fp, "%.1f %d ", a, b);
	}
	fclose(fp);
}

/*将链表元素输入到数组里面*/
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

/*数组的输出*/
void PrintArray(ArrayPoly a){
	for (int i = 0; i <= a.Hightpower; i++){
		printf("%6.1f", a.coefArray[i]);
	}
	printf("\n");
	return;
}

//乘法测试函数
void testTimes(PolyPtr a, PolyPtr b){
	ArrayPoly e = Conversion(a);
	ArrayPoly f = Conversion(b);
	Time_Spend2(e, f);
	ArrayPoly g = MultPoly(e, f);
	PrintArray(g);
	
	Time_Spend(a, b,TimesPoly2);
	PolyPtr d = TimesPoly2(a, b);
	PrintPoly(d);

	Time_Spend(a, b, TimesPoly);
	PolyPtr c = TimesPoly(a, b);
	PrintPoly(c);
	
	return;
}
//从文件读入数据
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

//将结果数据写入文件
void PutsPoly(char* filename,PolyPtr c){
	FILE* fp = NULL;
	
	PolyPtr pc = c->next;
	fp = fopen(filename, "w+");
	while (pc != NULL){
		
		fprintf(fp, "%.1f %d ", pc->coef, pc->expn);
		pc = pc->next;
	}
	fclose(fp);
}

//数一元多项式的项数
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

//一元多项式升幂排列
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
				linshi--;//当释放掉一个结点,内部循环次数会变少,将linshi减一可以让比较次数正常
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

//输出
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

//释放内存
void Destroy(PolyPtr a){
	PolyPtr p = NULL;
	while (a){
		p = a->next;
		free(a);
		a = NULL;
		a = p;
	}
}

//菜单
int Menu() {
	printf("=====================\n");
	printf(" 1. 对一元多项式求值\n");
	printf(" 2. 对一元多项式求导\n");
	printf(" 3. 对一元多项式求积分\n");
	printf(" 4. 对一元多项式求和\n");
	printf(" 5. 对一元多项式求差\n");
	printf(" 6. 对一元多项式求积\n");
	printf(" 7. 从文件中读入一元多项式\n");
	printf(" 8. 将一元多项式输出\n");
	printf(" 0. 退出\n");
	printf(" 注(单目运算只作用于多项式1)\n");
	printf("=====================\n");
	printf(" 请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//入口函数
void Enter(){
	PolyPtr a = NULL;
	PolyPtr b = NULL;
	PolyPtr c = NULL;
	PutPoly(".\\Polyone.txt");
	Sleep(1000);
	PutPoly(".\\Polytwo.txt");
	while (1){
		
		int choice = Menu();
		if (choice < 0 || choice > 9) {
			printf("您的输入无效!\n");
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
			PutsPoly(".\\Polythree.txt", c);//将结果写入3号文本(下同)
			printf("运算成功!\n");
			break;
		case 3:
			Destroy(c);
			c = Getlntegration(a);
			PutsPoly(".\\Polythree.txt", c);
			printf("运算成功!\n");
			break;
		case 4:
			Destroy(c);
			c = AddPoly(a, b);
			PutsPoly(".\\Polythree.txt", c);
			printf("运算成功!\n");
			break;
		case 5:
			Destroy(c);
			c = MinusPoly(a, b);
			PutsPoly(".\\Polythree.txt", c);
			printf("运算成功!\n");
			break;
		case 6:
			Destroy(c);
			c = TimesPoly(a, b);
			PutsPoly(".\\Polythree.txt", c);
			printf("运算成功!\n");
			break;
		case 7:
			a=GetPoly(".\\Polyone.txt");
			SortPoly(a);
			b=GetPoly(".\\Polytwo.txt");
			SortPoly(b);
			//Time_Spend(a, b);
			//Time_Spend2(a, b);
			break;
		case 8:
			printf("\n这是用户的第一个一元多项式:");
			PrintPoly(a);
			printf("\n这是用户的第二个一元多项式:");
			PrintPoly(b);
			printf("\n这是用户最近进行的计算的结果:\n");
			PrintPoly(c);
			break;
		case 9:
			testTimes(a, b);
			break;
		}
	}

}

int main(){
	Enter();
	system("pause");
	return 0;
}