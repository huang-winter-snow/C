gcc
预处理—preprocessing
编译—compilation
汇编—assembly
链接—linking

include <stdio.h>

int main(void)
{
	printf(“this is test”);
	return 0;
 }

gcc -c main.c ==== 编译不链接，生成.o目标文件
gcc -E main.c ==== 预处理 
gcc -S main.c ==== 只编译不汇编
gcc -g main.c -o main_d ==== 可进行gdb调试


gcc main.c -o main -I../path === 指定头文件目录
gcc main.c -fpic -shared -o libmain.so === 动态库
gcc main.c -o main -I../path -L../path -I../main.so

gcc -I 【大写字母i】=== 寻找头文件目录 /usr/local/include 
gcc -L 【大写字母l】=== 寻找库文件 /usr/local/lib
gcc -i 【小写字母l】=== -l word , 表示**寻找动态链接库文件**libword.so
