#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	int height;
	struct node* left;
	struct node* right;
};

int max(int a, int b);

int height(struct node* n)
{
	if (n == NULL) {
		return 0;
	}

	return n->height;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

struct node* newNode(int key)
{
	struct node* root = (struct node*)malloc(sizeof(struct node));

	root->key = key;
	root->left = NULL;
	root->right = NULL;
	root->height = 1;

	return root;
}

struct node* rightRotate(struct node* y)
{
	struct node* x = y->left;
	struct node* t2 = x->right;

	x->right = y;
	x->left = t2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

struct node* leftRotate(struct node* x)
{
	struct node* y = x->right;
	struct node* t2 = y->left;

	y->left = x;
	y->right = t2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

int getBalance(struct node* n)
{
	if (n == NULL) {
		return 0;
	}

	return height(n->left) - height(n->right);
}

struct node* insertNode(struct node* node, int key)
{
	if (node == NULL) {
		return newNode(key);
	}

	if (key < node->key) {
		node->left = insertNode(node->left, key);
	} else if (key > node->key) {
		node->right = insertNode(node->right, key);
	} else {
		return node;
	}

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);
	if (balance > 1 && key < node->left->key) {
		return rightRotate(node);
	}

	if (balance < -1 && key > node->right->key) {
		return leftRotate(node);
	}

	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);

		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);

		return leftRotate(node);
	}

	return node;
}

struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	while(current->left != NULL) {
		current = current->left;
	}

	return current;
}

struct node* deleteNode(struct node* root, int key) 
{
	if (root == NULL) {
		return root;
	}

	if (key < root->key) {
		root->left = deleteNode(root->left, key);
	} else if (key > root->key) {
		root->right = deleteNode(root->right, key);
	} else {
		if ((root->left == NULL) || (root->right == NULL)) {
			struct node* temp = root->left ? root->left : root->right;

			if (temp == NULL) {
				temp = root;
				root = NULL;
			} else {
				*root = *temp;
				free(temp);
			}
		} else {
			struct node* temp = minValueNode(root->right);

			root->key = temp->key;

			root->right = deleteNode(root->right, temp->key);			
		}
	}

	if (root == NULL) {
		return root;
	}

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0) {
		return rightRotate(root);
	}

	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);

		return rightRotate(root);
	}

	if (balance < -1 && getBalance(root->right) <= 0) {
		return leftRotate(root);
	}

	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);

		return leftRotate(root);
	}

	return root;
}

void printPreOrder(struct node* root)
{
	if (root != NULL) {
		printf("%d \n", root->key);

		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

int main(void) 
{
	struct node* root = NULL;

	root = insertNode(root, 2);
	root = insertNode(root, 1);

	root = insertNode(root, 7);
	root = insertNode(root, 4);

	root = insertNode(root, 5);
	root = insertNode(root, 3);
	root = insertNode(root, 8);

	printPreOrder(root);

	root = deleteNode(root, 3);

	printf("\nAfter deletion: ");
	printPreOrder(root);

	return 0;
}


























