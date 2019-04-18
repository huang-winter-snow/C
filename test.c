#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a = 10;

	while (a != 0) {
		printf("%d\n", --a);
	}

	return 0;
}