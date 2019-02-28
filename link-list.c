#include <stdio.h>
#include <stdlib.h>


typedef struct node 
{
    int data;
    struct node *next;
} node;

typedef void (*callback)(node *)

node *create(int data, node *next)
{
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error cerating a new node.\n");
        exit(0);
    }

    new_node->data = data;
    new_node->next = next;

    return new_node;
}

node *prepend(node *head, int data)
{
    node *new_node = create(data, head);
    head = new_node;

    return head;
}

node *append(node *head, int data)
{
    if (head == NULL) {
        return NULL;
    }

    node *cursor = head;
    while(cursor->next != NULL) {
        cursor = cursor->next;
    }

    node *new_node = create(data, NULL);
    cursor->next = new_node;

    return head;
}

node *insert_after(node *head, int data, node *prev)
{
    if (head == NULL || prev == NULL) {
        return NULL;
    }

    node *cursor = head;
    while (cursor != prev) {
        cursor = cursor->next;
    }

    if (cursor != NULL) {
        node *new_node = create(data, cursor->next);
        cursor->next = new_node;
        return head;
    } else {
        return NULL;
    }
}

node *insert_before(node *head, int data, node *next)
{
    if (next == NULL || head == NULL) {
        return NULL;
    }

    if (head == next) {
        head = prepend(head, data);
        return head;
    }

    node *cursor = head;
    while (cursor != NULL) {
        if (cursor->next == next) {
            break;
        }

        cursor = cursor->next;
    }

    if (cursor != NULL) {
        node *new_node = create(data, cursor->next);
        cursor->next = new_node;
        return head;
    } else {
        return NULL;
    }
}

void traverse(node *head, callback f)
{
    node *cursor = head;
    while (cursor != NULL) {
        f(cursor);
        cursor = cursor->next;
    }
}

node *remove_front(node *head)
{
    if (head == NULL)
        return NULL;
    node *front = head;
    head = head->next;
    front->next = NULL;

    if (front == head)
        head = NULL;

    free(front);

    return head;
}

node *remove_back(node *head)
{
    if (head == NULL)
        return NULL;

    node *cursor = head;
    node *back = NULL;
    while (cursor->next != NULL) {
        back = cursor;
        cursor = cursor->next;
    }

    if (back != NULL) {
        back->next = NULL;
    }

    if (cursor == head) {
        head = NULL;
    }

    free(cursor);

    return head;
}

node *remove_any(node *head, node *nd)
{
    if (nd == NULL)
        return NULL;

    if (nd == head) {
        return remove_front(head);
    }

    if (nd->next == NULL)
        return remove_back(head);

    node *cursor = head;

    while (cursor != NULL) {
        if (cursor->next == nd)
            break;
        cursor = cursor->next;
    }

    if (cursor != NULL) {
        node *tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }  

    return head;
}

void display(node *n) 
{
    if (n != NULL)
        printf("%d\n", n->data);
}

node *search(node *head, int data)
{
    node *cursor = head;
    while (cursor != NULL) {
        if (cursor->data == data)
            return cursor;
        cursor = cursor->next;
    }

    return NULL;
}

void dispose(node *head)
{
    node *cursor, *tmp;

    if (head != NULL) {
        cursor = head->next;
        head->next = NULL;
        while (cursor != NULL) {
            tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
    }
}

int count(node *head)
{
    node *cursor = head;
    int c = 0;
    while (cursor != NULL) {
        c++;
        cursor = cursor->next;
    }

    return c;
}

node *insertion_sort(node *head)
{
    node *x, *y, *e;

    x = head;
    head = NULL;

    while (x != NULL) {
        e = x;
        x = x->next;
        if (head != NULL) {
            if (e->data > head->data) {
                y = head;
                while ((y->next != NULL) && (e->data > y->next->data)) {
                    y = y->next;
                }

                e->next = y->next;
                y->next = e;
            } else {
                e->next = head;
                head = e;
            }
        } else {
            e->next = NULL;
            head = e;
        }
    }

    return head;
}

node *reverse(node *head)
{
    node *prev = NULL;
    node *current = head;
    node *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    return head;
}

void menu()
{
    printf("---C  Link List Demonstration ---\n");
    printf("0.menu\n");
    printf("1.prepend an element\n");
    printf("2.append an element\n");
    printf("3.search for an element\n");
    printf("4.insert after an element\n");
    printf("5.insert before an element\n");
    printf("6.remove front node\n");
    printf("7.remove back node\n");
    printf("8.remove any node\n");
    printf("9.sort the  list\n");
    printf("10.Reverse the linked list\n");
    printf("-1.quit\n");
}

int main(int argc, char const *argv[])
{
    int command = 0;
    int data;

    node *head = NULL;
    node *tmp = NULL;
    callback disp = display;

    menu();
    while(1) {
        printf("\nEnter a command(0-10, -1 to quit)");
        scanf("%d", &command);

        if (command == -1) {
            break;
        }

        switch(command) {
            case 0:
                menu();
                break;
            case 1:
                printf("Please enter a number to prepend:\n");
                scanf("%d", &data);
                head = prepend(head, data);
                traverse(head, disp);
                break;
            case 2:
                printf("Please enter a number to append:\n");
                scanf("%d", &data);
                head = append(head, data);
                traverse(head, disp);
                break;
            case 3:
                printf("Please enter a number to search:\n");
                scanf("%d", &data);
                if (tmp != NULL) {
                    printf("Element with value %d found.\n", data);
                } else {
                    printf("Element with value %d not found\n", data);
                } 
                break;
            case 4:
                printf("Enter the element value where you want to insert after\n");
                scanf("%d", &data);
                tmp = search(head, data);
                if (tmp != NULL) {
                    printf("Enter the element value to insert after:\n");
                    scanf("%d", &data);
                    head = insert_after(head, data, tmp);
                    if (head != NULL)
                        traverse(head, disp);
                } else {
                    printf("Element with value %d not found\n", data);
                } 
                break;
            case 5:  
                printf("Enter the element value where you want to insert before\n");
                scanf("%d", &data);
                tmp = search(head, data);
                if (tmp != NULL) {
                    printf("Enter the element value to insert before:\n");
                    scanf("%d", &data);
                    head = insert_before(head, data, tmp);

                    if (head != NULL)
                        traverse(head, disp);
                } else {
                    printf("Element with value %d not found\n", data);
                } 
                break;
            case 6:
                head = remove_front(head);
                if (head != NULL)
                    traverse(head, disp);
                break;
            case 7:
                head = remove_back(head);
                if (head != NULL)
                    traverse(head, disp);
                break;
            case 8:
                printf("Enter the element value to remove:\n");
                scanf("%d", &data);
                tmp = search(head, data);
                if (tmp != NULL) {
                    remove_any(head, tmp);
                    if (head != NULL) 
                        traverse(head, disp);
                } else {
                    printf("Element with value %d not found\n", data);
                }
                break;
            case 9:
                head = insertion_sort(head);
                if (head != NULL)
                    traverse(head, disp);
                break;
            case 10:
                head = reverse(head);
                if (head != NULL)
                    traverse(head, disp);
                break;                                           
        }
    }
    dispose(head);
    return 0;
}










