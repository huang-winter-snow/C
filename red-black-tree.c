#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

#define NeInfinity (-10000)

#ifndef _RedBlack_H
#define _RedBlack_H

struct RedBlackNode;

typedef struct RedBlackNode *Position;
typedef struct RedBlackNode *RedBlackTree;

RedBlackTree MakeEmpty(RedBlackTree T);
Position Find(ElementType X, RedBlackTree T);
Position FindMin(RedBlackTree T);
Position FindMax(RedBlackTree T);
RedBlackTree Initialize(void);
RedBlackTree Insert(ElementType X, RedBlackTree T);
RedBlackTree Remove(ElementType X, RedBlackTree T);
ElementType Retrieve(Position P);
void PrintTree(RedBlackTree T);

#endif

typedef enum ColorType {
	Red, Black
} ColorType;

struct RedBlackNode {
	ElementType Element;
	RedBlackTree Left;
	RedBlackTree Right;
	ColorType Color;
};

static Position NullNode = NULL;

RedBlackTree Initialize(void)
{
	RedBlackTree T;

	if (NullNode == NULL) {
		NullNode = malloc(sizeof(struct RedBlackNode));
		if (NullNode == NULL) {
			FatalError("Out of space!!!");
		}

		NullNode->Left = NullNode->Right = NullNode;
		NullNode->Color = Black;
		NullNode->Element = 12345;
	}

	T = malloc(sizeof(struct RedBlackNode));

	if (T == NULL) {
		FatalError("Out of space!!!");
	}

	T->Element = NegInfinity;
	T->Left = T->Right = NullNode;
	T->Color = Black;

	return T;
}

void Output(ElementType Element)
{
	printf("%d\n", Element);
}

static void DoPrint(RedBlackTree T)
{
	if (T != NullNode) {
		DoPrint(T->Left);
		Output(T->Element);
		DoPrint(T->Right);
	}
}































