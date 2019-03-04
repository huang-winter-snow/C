#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node * next;
} node_t;

void print_list(node_t *head)
{
	node_t *current = head;

	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

void pushLast(node_t *head, int val)
{
	node_t *current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;
}

void pushFirst(node_t *head, int val)
{
	node_t *new_node;
	new_node = malloc(sizeof(node_t));

	new_node->val = val;
	new_node->next = head->next;

	head = new_node;
}

void pop(node_t *head)
{
	int retval = -1;
	node_t *next_node = NULL;

	if (head == NULL) 
		return -1;

	next_node = head->next;
	retval = head->val;

	head = next_node;

	return retval;
}

int remove_last(node_t *head)
{
	int retval = 0;

	if (head->next == NULL) {
		retval = head->val;
		free(head);
		return retval;
	}

	node_t *current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	retval = current->next->val;
	free(current->next);
	current->next = NULL;

	return retval;
}

int remove_by_index(node_t *head, int n)
{
	int i = 0;
	int retval = -1;

	node_t *current = head;
	node_t *temp_node = NULL;

	if (n == 0) {
		pop(head);
	}

	for (int i = 0; i < n -1; ++i)
	{
		if (current->next == NULL) {
			return -1;
		}

		current = current->next;
	}

	temp_node = current->next;
	retval = temp_node->val;
	current->next = temp_node->next;
	free(temp_node);

	return retval;
}


int main(int argc, char const *argv[])
{
	  node_t * test_list = malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    print_list(test_list);
}
