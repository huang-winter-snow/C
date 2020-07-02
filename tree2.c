#include <stdio.h>
#include <stdlib.h>

struct node {
	int item;
	struct node* left;
	struct node* right;
};

struct node* newNode(int item)
{
	struct node* leaf = (struct node*)malloc(sizeof(struct node));
	leaf->item = item;
	leaf->left = NULL;
	leaf->right = NULL;

	return leaf;
}

int checkHeightBalance(struct node* root, int *height) 
{
	int leftHeight = 0, rightHeight = 0;
	int l = 0, r = 0;

	if (root == NULL) {
		*height = 0;

		return 1;
	}

	l = checkHeightBalance(root->left, &leftHeight);
	r = checkHeightBalance(root->right, &rightHeight);

	printf("%d\n", root->item);

	*height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

	if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2)) {
		return 0;
	} else {
		return 1 && r;
	}
}

int main(void)
{
	int height = 0;

	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);

	root->left->left = newNode(4);
	root->right->right = newNode(5);

	if (checkHeightBalance(root, &height)) {
		printf("The tree is balanced\n");
	} else {
		printf("The tree is not balanced\n");
	}
}









