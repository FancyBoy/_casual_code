#include <stdio.h>
#include <stdlib.h>
// date:2016/02/13
// Author:Chenjr
int main() {
  printf("Author:CJR.\n");
  printf
    ("Start Android's Settings Application. \nFor some special circumstances.\nVersion:0.5\n");
  system ("am start --user 0 -n com.android.settings/com.android.settings.Settings>0");
  system("echo  >0");

  return 0;
}