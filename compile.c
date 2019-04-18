gcc -E -o example.i example.c //预处理

gcc -S -o example.s example.i //汇编

gcc -c -o example.o example.s //机器语言

gcc -o example example.o //

多模块编译

静态库创建

ar rcs lib库文件名.a 目标文件1 目标文件2 。。。 目标文件n

gcc -o 可执行文件 调用者的目标文件 -Ldir -l库文件名
gcc -o 可执行文件 -ldir 调用者的C源代码 -Ldir -l库文件名

共享库创建

gcc -shared -fPCI -o lib库文件名.so 目标文件1 目标文件2

gcc -o 可执行文件 -ldir 调用者的C源代码 -Ldir -l库文件名

export LD_LIBARARY_PATH=库文件的目录
