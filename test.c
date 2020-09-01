#include <stdio.h>
#include <stdlib.h>

void quickSort(int* arr, int low, int high);
void display(int arr[], int length);

int main(int argc, char const *argv[])
{
	int arr[] = {12, 32, 4, 5, 2, 8, 10, 21, 98, 52, 6};

	int length = sizeof(arr) / sizeof(int);

	printf("排序前数组\n");
	display(arr, length);

	quickSort(arr, 0, length - 1);

	printf("排序后数组\n");
	display(arr, length);

	return 0;
}

void quickSort(int* arr, int low, int high)
{
	if (low < high) {
		int pivot = arr[low];
		int i = low;
		int j = high;

		while (i < j) {
			while(i < j && arr[j] >= pivot) {
				j--;
			}

			if (i < j) {
				arr[i++] = arr[j];
			}

			while (i < j && arr[i] < pivot) {
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

void display(int arr[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%-3d", arr[i]);
	}

	printf("\n");
}