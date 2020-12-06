
#define MAXSIZE	10000//数组最大元素
#define maxsize 300//随机生成数据数


//一元多项式元素(链表)	
typedef struct node{
	float coef;
	int expn;
	struct node* next;
}Poly, *PolyPtr;

//一元多项式元素(数组)
typedef struct{
	float coefArray[MAXSIZE + 1];
	int Hightpower;//expn的最大值 
}ArrayPoly;


//定义一个函数指针
typedef PolyPtr(*Func)(PolyPtr, PolyPtr);//双目运算的函数指针

typedef PolyPtr(*Func_)(PolyPtr);//单目运算的函数指针

float GetValue(PolyPtr a);//求一元多项式的值
PolyPtr GetDerivation(PolyPtr a);//对一元多项式求导
PolyPtr Getlntegration(PolyPtr a);//对一元多项式求积分
PolyPtr AddPoly(PolyPtr a, PolyPtr b);//两个一元多项式的和
PolyPtr MinusPoly(PolyPtr a, PolyPtr b);//两个一元多项式的差
PolyPtr TimesPoly(PolyPtr a, PolyPtr b);//乘法第一种形式
PolyPtr TimesPoly2(PolyPtr a, PolyPtr b);//乘法第二种形式
ArrayPoly MultPoly(ArrayPoly a, ArrayPoly b);//数组乘法
void Time_Spend(PolyPtr a, PolyPtr b, Func func);//双目运算时间函数
void Time_Spend1(PolyPtr a, Func_ func);//单目运算时间测试函数
void Time_Spend3(PolyPtr a);//求值运算时间测试函数
void Time_Spend2(ArrayPoly a, ArrayPoly b);//数组乘法时间函数
void PutPoly(const char* filename);//随机生成数据写入文件
ArrayPoly Conversion(PolyPtr a);//将链表输入到数组里面
void PrintArray(ArrayPoly a);//数组的输出

void testTimes(PolyPtr a, PolyPtr b);//乘法测试函数
PolyPtr GetPoly(const char* filename);//从文件读入数据
void PutsPoly(const char* filename, PolyPtr c);//将结果读入文件
int NumPoly(PolyPtr a);//数一元多项式的项数
void SortPoly(PolyPtr a);//一元多项式升幂排列
void PrintPoly(PolyPtr a);//将一元多项式输出

void Destroy(PolyPtr a);//释放内存
int Menu();//菜单
void Enter();//入口函数
