#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//递归方式
int K_side(int n, int k){
	if (k == 0)
		return 1;
	return n*K_side(n, k - 1);
}

//非递归方式
int k_side(int n, int k){
	int sub = 1;
	for (; k > 0; k--){
		sub = sub*n;
	}
	return sub;
}
int main(){
	int n, k;
	printf("请输入n的k次方(用空格间隔):");
	scanf("%d %d", &n, &k);
	printf("递归方式:%d\n", K_side(n, k));
	printf("非递归方式:%d\n", k_side(n, k));
	system("pause");
	return 0;
}