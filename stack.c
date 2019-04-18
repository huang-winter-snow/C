void init(int *top)
{
	*top = 0;
}

void push(int *s, int *top, int element)
{
	s[(*top)++] = element;
}

int pop(int *s, int *top) {
	return s[--(*top)];
}

int full(int *top, const int size)
{
	return *top == size ? 1 : 0;
}

int empty(int *top)
{
	return *top == 0 ? 1 : 0;
}

void display(int *s, int *top)
{
	printf("Stack: \n");
	int i;

	for (i = 0; i < *top; ++i)
	{
		printf("%d \n", s[i]);
	}

	printf("\n");
}