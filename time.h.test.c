#include <stdio.h>
#include <time.h>
int main()
{
	time_t sec;
	sec=time(NULL);
	printf("%ld\n",sec);
	printf("%s",ctime(&sec));
	
	
	
	}