#include <stdio.h>

union {
	char ch;
	int i;
} un;

int main(void)
{
	un.i = 0x12345678;

	if (un.ch == 0x12) {
		printf("big endian\n");
	} else {
		printf("small endian\n");
	}

	return 0;
}