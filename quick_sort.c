#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int length)
{
	for (int i = 0; i < length; i++) {
		printf("%d%s", arr[i], i == length - 1 ? " " : ", ");
	}

	printf("\n");
}

void quick_sort(int* arr, int low, int high)
{
	if (low >= high) {
		return;
	}

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

	quick_sort(arr, low, i-1);
	quick_sort(arr, i + 1, high);
}

int main(int argc, char const *argv[])
{
	int arr[] = {23, 322, 1, 54, 86, 2, 90, 102, 66, 233, 6, 98};

	int length = sizeof(arr) / sizeof(int);

	display(arr, length);

	quick_sort(arr, 0, length - 1);

	display(arr, length);

	return 0;
}

/*
int partition(int* arr, int low, int high) 
{
	if (low >= high) {
		return -1;
	}

	int i = low;
	int j = high;
	int pivot = arr[low];

	while(i < j) {
		while(i < j && arr[j] >= pivot) {
			j--;
		}

		if (i < j) {
			arr[i++] = arr[j];
		}

		while (i < j && arr[i] < pivot) {
			i++;
		}

		if (i < j)
		{
			arr[j--] = arr[i];
		}
	}

	arr[i] = pivot;

	return i;
}

void quick_sort(int* arr, int low, int high)
{
	if (low >= high) {
		return;
	}

	int index = partition(arr, low, high);

	quick_sort(arr, low, index - 1);
	quick_sort(arr, index + 1, high);
}*/