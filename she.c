/* 
   千位以内加法计算训练程序
   专为我这种小学不过关的人设计！ code by CJR. 2016.04.04
   凌晨 
   UPDATE log 
   -- 2016.04.04 morning-- 
   
   改为了模块化
   支持自定次数以及命令行传入次数 ;---- ;
   --2016.04.04 night--
   增加了乘法模块 --2016.04.06 凌晨--
   用atoi()修复了传入参数是字符串无法直接用于判断的问题。
    突然发现一个问题，有些可以直接对比字符串。

   --2016.06.08凌晨-- 添加了颜色。
   添加了减法模块。

   ---- */
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
// 定义函数及变量
int prog(int times);
int result(int a, int b);
int t, select = 0;
char sign;
int marks;
int main(int argc, char *argv[]) {
  if (argc > 1) {
    t = atoi(argv[1]);          // 字符串转整形
  }
  // t=t*1; //printf("%d\n%s\n%s\n%d\n",argc,argv[0],argv[1],t);
  printf
    ("Which mode do you want?\n0 Plus Mode.\t1 Mulitply Mode.\nEnter the NUMBER above then press ENTER key.\n");
  scanf("%d", &select);
  if (select == 0) {
    sign = '+';
  } else if (select == 1) {
    sign = '-';
  } else {
    sign = 'x';
  }
  if (t > 1) {
    marks = prog(t);
  } else {
    // printf("%d",t);
    printf("How many times would you like?\n");
    scanf("%d", &t);
    marks = prog(t);
  }

  printf("The test is finished.Your marks is %d/%d.\n", marks, t);
  return 0;
}

int result(int a, int b) {
  int result;
  if (select == 0) {
    result = a + b;
  } else if (select == 1) {
    result = a - b;
  } else {
    result = a * b;
  }
  return result;
}

int prog(int ti) {
  float a[ti], b[ti];
  int d = 0;
  int answer;
  int right = 0, wrong = 0;
  srand((int)time(NULL));
  int c;
  for (d = 0; (d < ti); d++) {
    a[d] = rand() % 1000;
    b[d] = rand() % 1000;
    c = result(a[d], b[d]);
    printf("第%d次\n", d + 1);
    printf("%g%c%g=?\n", a[d], sign, b[d]);
    scanf("%d", &answer);
    if (answer == c) {
      printf("\x1b[40;33mBINGO!\x1b[m You are \x1b[40;32mRIGHT!\n");
      right++;
    } else {
      printf
        ("\x1b[40;31mYou are WRONG ,boy! \nHurry up!\nThe answer is %d.\x1b[m \n",
         c);
      wrong++;
    }
    printf("\x1b[40;36m----分割线----\n\x1b[m");
  }
  return right;
}