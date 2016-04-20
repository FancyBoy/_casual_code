#include<stdio.h>
float cube(float in);
int main()
{
	float a, b;
	int i;
	printf("请输入一个数:\n");
	scanf("%f", &a);
	for (i = 0; i < 3; i++)
	{
		// b=a*a;
		b = cube(a);
	}
	printf("\n%g³=%g", a, b);
	return 0;
}

float cube(float in)
{
	static float result = 1;
	result = result * in;
	return result;
}