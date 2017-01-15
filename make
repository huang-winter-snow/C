#include<stdio.h>

make Makefile

make 

-d 显示调试信息

-f 默认读取makefile文件

Makefile编写规则：
	目标列表：关联列表
	<tab>命令列表 


	目标列表：用一个或多个空格分开的目标文件的清单
	关联性列表：用一个或多个空格分隔开的目标文件，是目标列表依赖的目标文件的清单
	命令列表：用于创建目标文件将要执行的命令清单，这些命令被换行符分开。命令列表的每个命令以《tab》开始

power:power.c
	gcc -o power power.c


power:power.o computer.o
	gcc -o power.o computer.o
power.o:power.c
	gcc -o power.o -c power.c
computer.o computer.c
	gcc -o computer.o computer.c

======================================================================

bin/mymath_test:obj/mymath.o obj/mymath_test.o
	gcc -o bin/mymath_test obj/mymath.o obj/mymath_test.o
obj/mymath.o:src/mymath.c
	gcc -o obj/mymath.o -Iinclude -c src/mymath.c
obj/mymath_test.o:src/mymath_test.c
	gcc -o obj/mymath_test.o -Iinclude -c src/mymath_test.c


