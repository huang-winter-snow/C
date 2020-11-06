#include <stdio.h>

void dispaly(int* arr, int length)
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

void select(int* arr, int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < length; ++j)
		{
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		
		if (i == minIndex) {
			continue;
		}

		swap(&arr[i], &arr[minIndex]);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {3, 4, 2, 6, 7, 1, 7, 7, 21, 87, 22, 66, 11};

	int length = sizeof(arr) / sizeof(int);

	dispaly(arr, length);

	select(arr, length);

	dispaly(arr, length);

	return 0;
}