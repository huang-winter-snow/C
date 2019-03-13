#include <stdio.h>
#include <stdlib.h>

void init(int *head, int *tail)
{
	*head = *tail = 0;
}

void enqueue(int *q, int *tail, int element)
{
	q[(*tail)++] = element;
}

int dequeue(int *q, int *head)
{
	return q[(*head)++];
}

int full(int tail, const int size)
{
	return tail == size;
}

int empty(int head, int tail)
{
	return tail == head;
}

void display(int *q, int head, int tail)
{
	int i = tail - 1;

	while (i >= head) {
		printf("%d \n", q[i--]);
	}

	printf("\n");
}


int main(int argc, char const *argv[])
{
	const int SIZE = 5;

	int head, tail, element;
	int queue[SIZE];

	init(&head, &tail);

	printf("--Enqueue elements--\n");

	while(!full(tail, SIZE)) {
		printf("Enter a number to enqueue:\n");

		scanf("%d", &element);

		enqueue(queue, &tail, element);

		display(queue, head, tail);
	}

	printf("Queue is full\n");

	printf("--Dequeue elements --\n");

	while (!empty(head, tail)) {
		element = dequeue(queue， &head);

		printf("dequeue element %d\n", element);

		display(queue, head, tail);
	}

	printf("Queue is empty\n");

	return 0;
}
