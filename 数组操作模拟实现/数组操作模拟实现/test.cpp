#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.在字符串 haystack 中查找第一次出现字符串 needle 的位置，不包含终止符 '\0'。
char* E_strstr(char* text,const char* member){
	if (text == NULL || member == NULL)return NULL;
	int i = 0;//从第一个位置开始进行匹配
	for (i = 0; text[i] != '\0'; i++){
		if (text[i] == member[0]){
			int j = 0;//需要查找的字符串的第一个位置匹配成功
			for (j = 1; member[j] != '\0'; j++){//开始判断字符串是否匹配
				if (text[i + j] == member[j])continue;
				break;//字符串不匹配
			}
			if (member[j] == '\0'){//判断字符串是否匹配成功
				char* p = &text[i];
				return p;//返回匹配成功的位置
			}
		}
	}
	return NULL;//未匹配成功,返回NULL
}
void test_strstr(){
	char haystack[20] = "RUNOOB";
	const char needle[10] = "NOOB";
	char *ret;

	ret = E_strstr(haystack, needle);
	printf("子字符串是： %s\n", ret);

	char str[] = "This is a simple string";
	char * pch;
	pch = E_strstr(str, "simple");
	if (pch != NULL)
		strncpy(pch, "sample", 6);
	printf("%s\n", str);
}
// 2.把 src 所指向的字符串追加到 dest 所指向的字符串的结尾。
char* E_strcat(char *dest, const char *src){
	if (dest == NULL)return NULL;
	if (src == NULL)return dest;
	int i = 0;
	for (i = 0; dest[i] != '\0'; i++){}//遍历至dest字符串的结尾
	int j = 0;
	for (j = 0; src[j] != '\0'; j++){//将src复制至dest的尾部
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';//在新的字符串结尾加上'\0'
	return dest;
}
void test_strcat(){
	char src[50], dest[50];
	strcpy(src, "This is source");
	strcpy(dest, "This is destination");
	E_strcat(dest, src);

	printf("最终的目标字符串： |%s|\n", dest);

	char str[80];
	strcpy(str, "these ");
	E_strcat(str, "strings ");
	E_strcat(str, "are ");
	E_strcat(str, "concatenated.");
	
	printf("%s\n", str);
}
// 3.把 str1 所指向的字符串和 str2 所指向的字符串进行比较。
int E_strcmp(const char *str1, const char *str2){
	for (int i = 0; (str1[i] != '\0') || (str2[i] != '\0'); i++){//当两字符串均遍历完成,循环结束
		int gap = str1[i] - str2[i];//使str1的ASSIC码值与str2的相减
		if (gap < 0)return gap;//当str1<str2时,返回一个负值
		if (gap > 0)return gap;//当str1>str2时,返回一个正值
	}
	return 0;//当str1=str2时,返回一个0
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
		printf("str1 小于 str2\n");
	}
	else if (ret > 0)
	{
		printf("str1 大于 str2\n");
	}
	else
	{
		printf("str1 等于 str2\n");
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
// 4.把 src 所指向的字符串复制到 dest。
char* E_strcpy(char *dest, const char *src) {
	if (dest == NULL || src == NULL)return NULL;
	int i = 0;
	for (i = 0; src[i] != '\0'; i++){
		dest[i] = src[i];//逐位置赋值
	}
	dest[i] = '\0';//在新的字符串结尾加上'\0'
	return dest;
}
void test_strcpy(){
	char src[40];
	char dest[100];
	memset(dest, '\0', sizeof(dest));
	E_strcpy(src, "This is runoob.com");
	E_strcpy(dest, src);
	printf("最终的目标字符串： %s\n", dest);

	char str1[] = "Sample string";
	char str2[40];
	char str3[40];
	strcpy(str2, str1);
	strcpy(str3, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
}
// 5.计算字符串 str 的长度，直到空结束字符，但不包括空结束字符。
size_t E_strlen(const char *str){
	if (str == NULL)return NULL;
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++){
		++count;//在遍历过程中,使用计数器进行计数
	}
	return count;
}
void test_strlen(){
	char str[50];
	int len;
	strcpy(str, "This is runoob.com");
	len = E_strlen(str);
	printf("|%s| 的长度是 |%d|\n", str, len);

	char szInput[256];
	printf("Enter a sentence: ");
	gets(szInput);
	printf("The sentence entered is %u characters long.\n", (unsigned)strlen(szInput));
}
// 6.从 str2 复制 n 个字符到 str1，但是在重叠内存块这方面，memmove() 是比 memcpy() 更安全的方法。
//如果目标区域和源区域有重叠的话，memmove() 能够保证源串在被覆盖之前将重叠区域的字节拷贝到目标区域中，
//复制后源区域的内容会被更改。如果目标区域与源区域没有重叠，则和 memcpy() 函数功能相同。
void* E_memmove(void *str1, const void *str2, size_t n){
	if (str1 == NULL || str2 == NULL)return NULL;
	char* dest;//使用完整类型指针代替void*
	const char* src;
	dest = (char*)str1;
	src = (const char*)str2;
	if (str2 >= str1){//当str2在str1之后,直接逐个赋值,不会出现未拷贝就被覆盖的情况
		for (size_t i = 0; i < n; i++){
			*(dest + i) = *(src + i);
		}
	}
	else{//反之,当str2在str1之前,则从最后一个位置逐个进行赋值
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
// 7.从存储区 str2 复制 n 个字节到存储区 str1。
void* E_memcpy(void *str1, const void *str2, size_t n){
	if (str1 == NULL || str2 == NULL)return NULL;
	char* dest;//使用完整类型指针代替void*
	const char* src;
	dest = (char*)str1;
	src = (const char*)str2;
	for (size_t i = 0; i < n; i++){
		*(dest + i) = *(src + i);//逐个赋值
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