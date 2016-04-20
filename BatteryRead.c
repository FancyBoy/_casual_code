/* 
   读取/sys/devices/platform/mt6320-battery/FG_Battery_CurrentConsumption中的电池流量然后在屏幕中输出并存到日志中。
   练习文件读写及延时处理。 
   2016.04.19 */
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#define loop_times=100
int main(int argc, char *argv[]) {
	//声明FILE类型指针及各种变量
  FILE *fp;
  FILE *fl;
  char buff[255];
  float buf;
  time_t sec;
  // 循环开始
  for (int i = 0; i < 100; i++) {
    // 获取时间秒数
    sec = time(NULL);           // 打开日志文件(追加模式)和系统电流文件(只读)
    fl = fopen("/sdcard/documents/logs/batterylog.csv", "a");
    fp = fopen("/sys/devices/platform/mt6320-battery/FG_Battery_CurrentConsumption", "r"); // 读取fp流的值并传输给buff
    fscanf(fp, "%s", buff);
    // 转换buff字符串为整形
    buf = atoi(buff);
    // 输出数据到屏幕
    printf("%d.  %g MA/H\n", i + 1, buf / 10);
    // 关闭系统驱动文件
    fclose(fp);
    // 写入数据到日志流中 
    // 格式为 数据[逗号分隔]时间
    fputs(buff, fl);
    fputs(",", fl);
    fputs(ctime(&sec), fl);
    /*
     使用ctime()将秒数转换为当地时间。
因为是以追加模式打开，故无需手动换行，自动在下一行写入。 
     */
    // fputs("\n",fl);
    // 关闭log文件
    fclose(fl);
    // 延时
    sleep(14);
    // go back
  }
  return 0;
}