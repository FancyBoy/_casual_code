#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Author:CJR\n");
	printf("Start Android's own Settings APP\n");
	system("am start --user 0 -n com.android.settings/com.android.settings.Settings");
	return 0;
	}