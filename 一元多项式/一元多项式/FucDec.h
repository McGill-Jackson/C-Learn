
#define MAXSIZE	10000//�������Ԫ��
#define maxsize 100//�������������


//һԪ����ʽԪ��(����)	
typedef struct node{
	float coef;
	int expn;
	struct node* next;
}Poly, *PolyPtr;

//һԪ����ʽԪ��(����)
typedef struct{
	float coefArray[MAXSIZE + 1];
	int Hightpower;//expn�����ֵ 
}ArrayPoly;


//����һ������ָ��
typedef PolyPtr(*Func)(PolyPtr, PolyPtr);



float GetValue(PolyPtr a);//��һԪ����ʽ��ֵ
PolyPtr GetDerivation(PolyPtr a);//��һԪ����ʽ��
PolyPtr Getlntegration(PolyPtr a);//��һԪ����ʽ�����
PolyPtr AddPoly(PolyPtr a, PolyPtr b);//����һԪ����ʽ�ĺ�
PolyPtr MinusPoly(PolyPtr a, PolyPtr b);//����һԪ����ʽ�Ĳ�
PolyPtr TimesPoly(PolyPtr a, PolyPtr b);//�˷���һ����ʽ
PolyPtr TimesPoly2(PolyPtr a, PolyPtr b);//�˷��ڶ�����ʽ
ArrayPoly MultPoly(ArrayPoly a, ArrayPoly b);//����˷�
void Time_Spend(PolyPtr a, PolyPtr b, Func func);
void Time_Spend2(ArrayPoly a, ArrayPoly b);//ʱ����Ժ���
void PutPoly(const char* filename);//�����������д���ļ�
ArrayPoly Conversion(PolyPtr a);//���������뵽��������
void PrintArray(ArrayPoly a);//��������
void testTimes(PolyPtr a, PolyPtr b);//�˷����Ժ���
PolyPtr GetPoly(const char* filename);//���ļ���������
void PutsPoly(const char* filename, PolyPtr c);//����������ļ�
int NumPoly(PolyPtr a);//��һԪ����ʽ������
void SortPoly(PolyPtr a);//һԪ����ʽ��������
void PrintPoly(PolyPtr a);//��һԪ����ʽ���

void Destroy(PolyPtr a);//�ͷ��ڴ�
int Menu();//�˵�
void Enter();//��ں���
