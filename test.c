#include <stdio.h>
#include <stdbool.h>

void add(int, char*);

int main(int argc, char const *argv[])
{
	int b = 2;
	int* p = &b;

	printf("%d", *p);
	
	return 0;
}