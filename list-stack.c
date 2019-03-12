#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
}

void init(struct node *head)
{
	head = NULL;
}

struct node *push(struct node *head, int data)
{
	struct node *tmp = (struct node*)malloc(sizeof(struct node));

	if (tmp == NULL)
		exit(0);

	tmp->data = data;
	tmp->next = head;

	head = tmp;

	return head;
}

struct node *pop(struct node *head, int *element)
{
	struct node *tmp = head;

	*element = head->data;
	head = head->next;
	free(tmp);
}

int empty(struct node *head)
{
	return head == NULL ? 1 : 0;
}

void display(struct node *head)
{
	struct node *current;
	current = head;

	if (current != NULL) {
		printf("Stack:\n");

		do
		{
			printf("%d\n", current->data);
		} while (current != NULL);
	} else {
		printf("The Stack is empty\n");
	}
}

int main(int argc, char const *argv[])
{
	struct node *head = NULL;

	int size, element;
	int counter = 0;

	printf("Enter the number of stack elements\n");
	scanf("%d", &size);

	printf("--- Push element into the linked stack ---\n");

	init(head);

	while (counter < size) {
		printf("Enter a number to push into the stack:\n");
		scanf("%d", &element);
		head = push(head, element);
		display(head);
		counter++;
	}

	printf("--- Pop elements from the linked stack --- \n");

	while (empty(head) == 0) {
		head = pop(head, &element);
		printf("Pop %d from stack\n", element);
		display(head);
	}
	return 0;
}
