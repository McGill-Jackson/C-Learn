
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define true 1
#define false 0

typedef struct Suspect{
	int words;
	int isCriminal;
}suspect;
//��ӡ
void print(suspect a, suspect b, suspect c, suspect d){
	printf("������  ��   �ﷸ\n");
	printf("A       %d   %d\n", a.words, a.isCriminal);
	printf("B       %d   %d\n", b.words, b.isCriminal);
	printf("C       %d   %d\n", c.words, c.isCriminal);
	printf("D       %d   %d\n", d.words, d.isCriminal);
}
//��ʼ��
void Initialization(suspect* a, suspect* b, suspect* c, suspect* d){
	a->words = true;
	a->isCriminal = false;
	b->words = true;
	b->isCriminal = false;
	c->words = true;
	c->isCriminal = false;
	d->words = true;
	d->isCriminal = false;
}
void is_Criminal(suspect a, suspect b, suspect c, suspect d){

	if (a.words == true)
		a.isCriminal = false;
	else a.isCriminal = true;
	if (b.words == true)
		c.isCriminal = true;
	else c.isCriminal = false;
	if (d.words == true)
		c.words = false;
	else c.words = true;
	if (c.words == true)
		d.isCriminal = true;
	else d.isCriminal = false;
	if (a.isCriminal == true && b.isCriminal == false && c.isCriminal == false && d.isCriminal == false){
		printf("A�Ƿ���.\n");
		return;
	}


	if (a.isCriminal == false && b.isCriminal == true && c.isCriminal == false && d.isCriminal == false){
		printf("B�Ƿ���.\n");
		return;
	}

	if (a.isCriminal == false && b.isCriminal == false && c.isCriminal == true && d.isCriminal == false){
		printf("C�Ƿ���.\n");
		return;
	}

	if (a.isCriminal == false && b.isCriminal == false && c.isCriminal == false && d.isCriminal == true){
		printf("D�Ƿ���.\n");
		return;
	}

	else{
		return;
	} 
	print(a, b, c, d);
	
}
int main(){
	suspect a, b, c, d;
	suspect* pa=&a;
	suspect* pb=&b;
	suspect* pc=&c;
	suspect* pd=&d;
	

	Initialization(pa, pb, pc, pd);

	a.words = false;
	is_Criminal(a, b, c, d);
	Initialization(pa, pb, pc, pd);
	b.words = false;
	is_Criminal(a, b, c, d);
	Initialization(pa, pb, pc, pd);
	c.words = false;
	is_Criminal(a, b, c, d);
	Initialization(pa, pb, pc, pd);
	d.words = false;
	is_Criminal(a, b, c, d);
	Initialization(pa, pb, pc, pd);
	system("pause");
	return 0;
}
