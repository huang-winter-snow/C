#include <stdio.h>
#include <stdlib.h>

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

int kthSmallest(int* arr, int low, int high, int k) 
{	
	while(1) {
		int position = partition(arr, low, high);

		int index = k - 1;

		if (position == index) {
			return arr[position];
		} else if (position > k) {
			high = position - 1;
		} else {
			low = position + 1;
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {23, 322, 1, 54, 86, 2, 90, 102, 66, 233, 6, 98};

	int length = sizeof(arr) / sizeof(int);

	int k = 3;

	printf("K-th smallest element is %d\n", kthSmallest(arr, 0, length - 1, k));

	return 0;
}

