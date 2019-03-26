#include <stdio.h>

#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	int height;
} node;

void dispose(node *t);
node *find(int e, node *t);
node *find_min(node *t);
node *find_max(node *t);
node *insert(int data, node *t);
node *delete(int data, node *t);
void display_avl(node *t);
int get(node *n);

void dispose(node *t)
{
	if (t != NULL) {
		dispose(t->left);
		dispose(t->right);
		free(t);
	}
}

node *find(int e, node *t)
{
	if (t == NULL) {
		return NULL;
	}

	if (e < t->data) {
		return find(e, t->left);
	} else if (e > t->data) {
		return find(e, t->right);
	} else {
		return t;
	}
}

node *find_min(node *t)
{
	if (t == NULL) {
		return NULL;
	} else if (t->left == NULL) {
		return t;
	} else {
		return find_min(t->left);
	}
}

node *find_max(node *t)
{
	if (t != NULL) {
		while (t->right != NULL) {
			t = t->right;
		}
	}

	return t;
}

static int height(node *n)
{
	if (n == NULL) {
		return -1;
	} else {
		return n->height;
	}
}

static int max(int l, int r)
{
	return l > r ? l : r;
}

static node *single_rotate_with_left(node *k2)
{
	node *k1 = NULL;

	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;

	return k1;
}

static node* single_rotate_with_right(node *k1)
{
	node * k2;

	k2 = k1->right;
	k1->right = k2->right;
	k2->left = k1;

	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->right), k1->right) + 1;

	return k2;
}

static node* double_rotate_with_left(node *k3)
{
	k3->left = single_rotate_with_left(k3->left);

	return single_rotate_with_left(k3);
}

static node* double_rotate_with_right(node *k1)
{
	k1->right = single_rotate_with_left(k1->right);

	return single_rotate_with_right(k1);
}

node* insert(int e, node *t)
{
	if (t == NULL) {
		t = (node *)malloc(sizeof(node));
		if (t == NULL) {
			fprintf(stderr, "Out of memory!!!\n");
			exit(1);
		} else {
			t->data = e;
			t->height = 0;
			t->left = t->right = NULL;
		}
	} else if (e < t->data) {
		t->left = insert(e, t->left);
		if (height(t->left) - height(t->right) == 2) {
			if (e < t->left->data) {
				t = single_rotate_with_left(t);
			} else {
				t = double_rotate_with_left(t);
			}
		}
	} else if (e > t->data) {
		t->right = insert(e, t->right);
		if (height(t->right) - height(t->left) == 2) {
			if (e > t->right->data) {
				t = single_rotate_with_right(t);
			} else {
				t = double_rotate_with_right(t);
			}
		}
	}

	t->height = max(height(t->left), height(t->right)) + 1;

	return t;
}

node *delete(int e, node *t)
{
	printf("Sorry; Delete is inimplement; %d remains\n", e);
	return t;
}

int get(node *n)
{
	return n->data;
}

void display_avl(noede *t)
{
	if (t == NULL)
	{
		return;
	}

	printf("%d\n", t->data);

	if (t->left != NULL)
	{
		printf("(L:%d)\n", t->left->data);
	}

	if (t->right != NULL) {
		printf("(R: %d)\n", t->right->data);
	}

	printf("\n");

	display_avl(t->left);
	display_avl(t->right);
}


int main(int argc, char const *argv[])
{
	node *t, *p;

	int i;
	int j = 0;
	const int max = 10;

	printf("---C AVL Tree Demo --- \n");

	t = NULL;

	printf("Insert:\n");

	for (i = 0; i < max; i++, j = (j + 7) % max)
	{
		/* code */
		t = insert(j , t);
		printf("%d\n", j);
	}

	printf(" into the tree\n");

	display_avl(t);

	dispose(t);
	
	return 0;
}