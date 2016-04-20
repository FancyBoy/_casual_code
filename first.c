#include <stdio.h>
int main(void)
{
	int num;
	char love[10];
	num = 100;
	printf("Hello world ! \n");
	printf("This is my first c program .\n");
	printf("请按回车键继续");
	getchar();
	printf("数字   =%d  \n", num);
	num = num + 1;
	printf("数字+1 =%d \n ", num);
	getchar();
	printf("。\n");
	scanf("%s", love);

	printf("%s。", love);
	getchar();
	return 0;

}