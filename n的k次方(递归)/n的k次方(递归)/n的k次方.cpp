#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//�ݹ鷽ʽ
int K_side(int n, int k){
	if (k == 0)
		return 1;
	return n*K_side(n, k - 1);
}

//�ǵݹ鷽ʽ
int k_side(int n, int k){
	int sub = 1;
	for (; k > 0; k--){
		sub = sub*n;
	}
	return sub;
}
int main(){
	int n, k;
	printf("������n��k�η�(�ÿո���):");
	scanf("%d %d", &n, &k);
	printf("�ݹ鷽ʽ:%d\n", K_side(n, k));
	printf("�ǵݹ鷽ʽ:%d\n", k_side(n, k));
	system("pause");
	return 0;
}