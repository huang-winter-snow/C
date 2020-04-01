#include <stdio.h>
#include <stdlib.h>

struct data 
{
    int key;
    int value;
};

struct data *array;
int capacity = 10;
int size = 0;

int hashcode(int key)
{
    return (key % capacity);
}

int get_prime(int n)
{
    if (n % 2 == 0) {
        n++;
    }

    for (; !if_prime(n); n += 2);

    return n;
}

int if_prime(int n)
{
    int i;
    if (n == 1 || n == 0) {
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        if (n % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

void init_array()
{
    int i;
    capacity = get_prime(capacity);
    array = (struct data*) malloc(capacity *sizeof(struct data));

    for (i = 0; i < capacity; i++)
    {
        array[i].key = 0;
        array[i].value = 0;
    }
}

void insert(int key)
{
    int index = hashcode(key);

    if (array[index].value == 0) {
        array[index].key = key;
        array[index].value = 1;
        size++;

        printf("\n Key (%d) has been inserted \n", key);
    } else if (array[index].key == key) {
        printf("\n Key (%d) already present, hence updating its value \n");
        array[index].value += 1;
    } else {
        printf("\n element cannot be inserted");
    }
}

void remove_element(int key)
{
    int index = hashcode(key);

    if (array[index].value == 0) {
        printf("\n this key does not exists");
    } else {
        array[index].key = 0;
        array[index].value = 0;
        size--;

        printf("\n Key (%d) has been removed\n")
    }
}

void display()
{
    int i;
    for (i = 0; i < capacity; i++)
    {
        if (array[i].value == 0) {
            printf("\n Array[%d] has no elements \n");
        } else {
            printf("\n array[%d] has elements -: \n key(%d) and value(%d) \t", i, array[i].key, array[i].value);
        }
    }
}

int size_of_hashtable()
{
    return size;
}

void main(void)
{
    int choice, key, value, n, c;

    init_array();

    do {
        printf("\n implementation of hash table in C \n\n");
        printf("menu-: \n1.Inserting item in the hash table"
                        "\n2.Removing item form the hash table"
                        "\n3.Check the size if hash table"
                        "\n4.Display a hash table"
                        "\n\n please enter your choice -:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Inserting element in hash table\n");
            printf("Enter key -:\t");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            printf("Deleting in hash table\n enter the key to delete-:");
            scanf("%d", &key);
            remove_element(key);
            break;
        case 3:
            n = size_of_hashtable();
            printf("size of hash table is-: %d", n);
            break;   
        case 4:
            display();

            break;     
        default:
            break;
        }  

        printf("\n do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);              
    } while(c == 1);

    getch();
}