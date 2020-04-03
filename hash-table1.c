#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

typedef struct node {
    char name[10];
    struct node* next;
} node;


node* first[26] = {NULL};

int hash(const char* buffer)
{
    return tolower(buffer[0]) - 'a';
}

void insert(int key, const char* buffer)
{
    node* newptr = (node *) malloc(sizeof(node));
    if (newptr == NULL) {
        return;
    }

    strcpy(newptr->name, buffer);
    newptr->next = NULL;

    if (first[key] == NULL) {
        first[key] = newptr;
    } else {
        node* preptr = first[key];
        while (1)
        {
            if (preptr->next == NULL) {
                preptr->next = newptr;
                break;
            }

            preptr = preptr->next;
        }        
    }
}

int main(void)
{
    char *name;

    printf("please enter name:\n");

    scanf("%s", name);

    int hashValue = hash(name);

    insert(hashValue, name);

    return 0;
}

