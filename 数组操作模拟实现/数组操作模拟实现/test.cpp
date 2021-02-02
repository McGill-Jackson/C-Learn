#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.���ַ��� haystack �в��ҵ�һ�γ����ַ��� needle ��λ�ã���������ֹ�� '\0'��
char* E_strstr(char* text,const char* member){
	if (text == NULL || member == NULL)return NULL;
	int i = 0;//�ӵ�һ��λ�ÿ�ʼ����ƥ��
	for (i = 0; text[i] != '\0'; i++){
		if (text[i] == member[0]){
			int j = 0;//��Ҫ���ҵ��ַ����ĵ�һ��λ��ƥ��ɹ�
			for (j = 1; member[j] != '\0'; j++){//��ʼ�ж��ַ����Ƿ�ƥ��
				if (text[i + j] == member[j])continue;
				break;//�ַ�����ƥ��
			}
			if (member[j] == '\0'){//�ж��ַ����Ƿ�ƥ��ɹ�
				char* p = &text[i];
				return p;//����ƥ��ɹ���λ��
			}
		}
	}
	return NULL;//δƥ��ɹ�,����NULL
}
void test_strstr(){
	char haystack[20] = "RUNOOB";
	const char needle[10] = "NOOB";
	char *ret;

	ret = E_strstr(haystack, needle);
	printf("���ַ����ǣ� %s\n", ret);

	char str[] = "This is a simple string";
	char * pch;
	pch = E_strstr(str, "simple");
	if (pch != NULL)
		strncpy(pch, "sample", 6);
	printf("%s\n", str);
}
// 2.�� src ��ָ����ַ���׷�ӵ� dest ��ָ����ַ����Ľ�β��
char* E_strcat(char *dest, const char *src){
	if (dest == NULL)return NULL;
	if (src == NULL)return dest;
	int i = 0;
	for (i = 0; dest[i] != '\0'; i++){}//������dest�ַ����Ľ�β
	int j = 0;
	for (j = 0; src[j] != '\0'; j++){//��src������dest��β��
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';//���µ��ַ�����β����'\0'
	return dest;
}
void test_strcat(){
	char src[50], dest[50];
	strcpy(src, "This is source");
	strcpy(dest, "This is destination");
	E_strcat(dest, src);

	printf("���յ�Ŀ���ַ����� |%s|\n", dest);

	char str[80];
	strcpy(str, "these ");
	E_strcat(str, "strings ");
	E_strcat(str, "are ");
	E_strcat(str, "concatenated.");
	
	printf("%s\n", str);
}
// 3.�� str1 ��ָ����ַ����� str2 ��ָ����ַ������бȽϡ�
int E_strcmp(const char *str1, const char *str2){
	for (int i = 0; (str1[i] != '\0') || (str2[i] != '\0'); i++){//�����ַ������������,ѭ������
		int gap = str1[i] - str2[i];//ʹstr1��ASSIC��ֵ��str2�����
		if (gap < 0)return gap;//��str1<str2ʱ,����һ����ֵ
		if (gap > 0)return gap;//��str1>str2ʱ,����һ����ֵ
	}
	return 0;//��str1=str2ʱ,����һ��0
}
void test_strcmp(){
	char str1[15];
	char str2[15];
	int ret;
	strcpy(str1, "abcdef");
	strcpy(str2, "ABCDEF");
	ret = E_strcmp(str1, str2);
	if (ret < 0)
	{
		printf("str1 С�� str2\n");
	}
	else if (ret > 0)
	{
		printf("str1 ���� str2\n");
	}
	else
	{
		printf("str1 ���� str2\n");
	}

	char key[] = "apple";
	char buffer[80];
	do {
		printf("Guess my favorite fruit? ");
		fflush(stdout);
		scanf("%79s", buffer);
	} while (E_strcmp(key, buffer) != 0);
	printf("Correct answer!");
}
// 4.�� src ��ָ����ַ������Ƶ� dest��
char* E_strcpy(char *dest, const char *src) {
	if (dest == NULL || src == NULL)return NULL;
	int i = 0;
	for (i = 0; src[i] != '\0'; i++){
		dest[i] = src[i];//��λ�ø�ֵ
	}
	dest[i] = '\0';//���µ��ַ�����β����'\0'
	return dest;
}
void test_strcpy(){
	char src[40];
	char dest[100];
	memset(dest, '\0', sizeof(dest));
	E_strcpy(src, "This is runoob.com");
	E_strcpy(dest, src);
	printf("���յ�Ŀ���ַ����� %s\n", dest);

	char str1[] = "Sample string";
	char str2[40];
	char str3[40];
	strcpy(str2, str1);
	strcpy(str3, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
}
// 5.�����ַ��� str �ĳ��ȣ�ֱ���ս����ַ������������ս����ַ���
size_t E_strlen(const char *str){
	if (str == NULL)return NULL;
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++){
		++count;//�ڱ���������,ʹ�ü��������м���
	}
	return count;
}
void test_strlen(){
	char str[50];
	int len;
	strcpy(str, "This is runoob.com");
	len = E_strlen(str);
	printf("|%s| �ĳ����� |%d|\n", str, len);

	char szInput[256];
	printf("Enter a sentence: ");
	gets(szInput);
	printf("The sentence entered is %u characters long.\n", (unsigned)strlen(szInput));
}
// 6.�� str2 ���� n ���ַ��� str1���������ص��ڴ���ⷽ�棬memmove() �Ǳ� memcpy() ����ȫ�ķ�����
//���Ŀ�������Դ�������ص��Ļ���memmove() �ܹ���֤Դ���ڱ�����֮ǰ���ص�������ֽڿ�����Ŀ�������У�
//���ƺ�Դ��������ݻᱻ���ġ����Ŀ��������Դ����û���ص������ memcpy() ����������ͬ��
void* E_memmove(void *str1, const void *str2, size_t n){
	if (str1 == NULL || str2 == NULL)return NULL;
	char* dest;//ʹ����������ָ�����void*
	const char* src;
	dest = (char*)str1;
	src = (const char*)str2;
	if (str2 >= str1){//��str2��str1֮��,ֱ�������ֵ,�������δ�����ͱ����ǵ����
		for (size_t i = 0; i < n; i++){
			*(dest + i) = *(src + i);
		}
	}
	else{//��֮,��str2��str1֮ǰ,������һ��λ��������и�ֵ
		for (int i = n-1; i >= 0; i--){
			*(dest + i) = *(src + i);
		}
	}
	return str1;
}
void test_memmove(){
	char dest[] = "oldstring";
	char src[] = "newstring";

	printf("Before memmove dest = %s, src = %s\n", dest, src);
	E_memmove(dest, src, 9);
	printf("After memmove dest = %s, src = %s\n", dest, src);

	char str[] = "memmove can be very useful......";
	E_memmove(str + 20, str + 15, 11);
	puts(str);
}
// 7.�Ӵ洢�� str2 ���� n ���ֽڵ��洢�� str1��
void* E_memcpy(void *str1, const void *str2, size_t n){
	if (str1 == NULL || str2 == NULL)return NULL;
	char* dest;//ʹ����������ָ�����void*
	const char* src;
	dest = (char*)str1;
	src = (const char*)str2;
	for (size_t i = 0; i < n; i++){
		*(dest + i) = *(src + i);//�����ֵ
	}
	return str1;
}
void test_memcpy(){
	char dest[] = "oldstring";
	char src[] = "newstring";

	printf("Before memmove dest = %s, src = %s\n", dest, src);
	E_memcpy(dest, src, 9);
	printf("After memmove dest = %s, src = %s\n", dest, src);

	char str[] = "memmove can be very useful......";
	E_memcpy(str + 20, str + 15, 11);
	puts(str);
}
int main(){
	//test_strstr();
	//test_strcat();
	//test_strcmp();
	//test_strcpy();
	//test_strlen();
	//test_memmove();
	test_memcpy();
	system("pause");
	return 0;
}