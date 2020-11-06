#include <stdio.h>
#include <stdlib.h>

void display(int* arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d%s", arr[i], i == length - 1 ? " " : ", ");
	}

	printf("\n");
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp; 
}

void bubble(int* arr, int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {2, 3, 5, 21, 2, 3, 999, 2, 34, 87};

	int length = sizeof(arr) / sizeof(int);

	display(arr, length);

	bubble(arr, length);

	display(arr, length);

	return 0;
}