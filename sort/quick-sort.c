#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%-3d\n", arr[i]);
	}

	printf("\n");

	return;
}

void quickSort(int* arr, int low, int high)
{
	if (low < high) {
		int i = low;
		int j = high;
		int pivot = arr[low];

		while (i < j) {
			while(i < j && arr[j] >= pivot) {
				j--;
			}

			if (i < j) {
				arr[i++] = arr[j];
			}

			while(i < j && arr[i] < pivot) {
				i++;
			}

			if (i < j) {
				arr[j--] = arr[i];
			}
		}

		arr[i] = pivot;

		quickSort(arr, low, i - 1);
		quickSort(arr, i + 1, high);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {12, 85, 25, 16, 34, 23, 49, 95, 17, 61};
	int length = sizeof(arr) / sizeof(int);
	printf("%d\n", length);

	printf("排序前数组\n");
	display(arr, length);

	quickSort(arr, 0, length - 1);

	printf("排序后数组\n");
	display(arr, length);

	return 0;
}



