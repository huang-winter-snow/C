#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

#ifndef _BinHeap_H
#define _BinHeap_H


struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif


#define MinPQSize (10)
#define MinData (-32767)

struct HeapStruct {
	int Capacity;
	int Size;
	ElementType *Elements;
}

PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;

    if (MaxElements < MinPQSize) {
    	Error("Priority queue size is too small");     
    }      

    H = malloc(sizeof ( struct HeapStruct));  

    if (H == NULL) {
    	FatalError("Out of space!!!");    
    }  

    H->Elements = malloc(MaxElements + 1);
	if (H->Elements == NULL) {
		FatalError("Out of space!!!");
	}

	H->Capacity = MaxElements;
	H->size = 0;
	H->Elements[0] = MinData;

	return H;
}

void MakeEmpty(PriorityQueue H)
{
	H->Size = 0;
}

void Insert(ElementType X, PriorityQueue H)
{
	int i;

	if (IsFull(H)) {
		Error("Priority queue is full");
		return;
	}

	for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
	{
		H->Elements[i] = H->Elements[i / 2];
	}

	H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H)
{
	int i, child;
	ElementType MinElement, LastElement;

	if (IsEmpty(H)) {
		Error("Priority queue is empty");
		return H->Elements[0];
	}

	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];

	for (i = 0; i * 2 < H->size; i = child)
	{
		child = i * 2;
		if (child != H->Size && H->Elements[child + 1] < H->Elements[child]) {
			child++;
		}

		if (LastElement > H->Elements[child]) {
			H->Elements[i] = H->Elements[child];
		} else {
			break;
		}
	}

	H->Elements[i] = LastElement;

	return MinElement;
}

ElementType FindMin(PriorityQueue H) 
{
	if (!IsEmpty(H)) {
		return H->Elements[1];
	}

	Error("Priority Queue is Empty");

	return H->Elements[0];
}

int IsEmpty(PriorityQueue H) 
{
	return H->Size == 0;
}

int IsFull(PriorityQueue H) 
{
	return H->Size == H->Capacity;
}

void Destroy(PriorityQueue H)
{
	free(H->Elements);
	free(H);
}

#define MaxSize 1000;

int main(int argc, char const *argv[])
{
	PriorityQueue H;
	int i, j;

	H = Initialize(MaxSize);

	for (i = 0, j = MaxSize / 2; i < MaxSize; i++, j = (j + 71) % MaxSize)
	{
		Insert(j, H);
	}

	j = 0;

	while (!IsEmpty(H)) {
		if (DeleteMin(H) != j++) {
			printf("Error in DeleteMin, %d\n", j);
		}
	}

	printf("Done...\n");

	return 0;
}


































