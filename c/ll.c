#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
    int data;
    struct Node * next;
} * start = NULL;

void insert_beg(int data)
{
    struct Node * n = malloc(sizeof(struct Node));
    assert(n);
    n->data = data;
    n->next = start;
    start = n;
}

void insert_end(int data)
{
    if (start == NULL) {
        insert_beg(data);
        return;
    }
    struct Node * n = malloc(sizeof(struct Node));
    assert(n);
    n->data = data;
    n->next = NULL;
    struct Node * end = start;
    while (end->next != NULL) {
        end = end->next;
    }
    end->next = n;
}

void delete_beg()
{
    assert(start);
    struct Node * temp = start;
    start = start->next;
    free(temp);
}

void delete_end()
{
    assert(start);
    if (start->next == NULL) {
        /* One element case */
        delete_beg();
        return;
    }
    struct Node * temp = start;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void traverse()
{
    struct Node * ptr = start;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int opt, e;
    do {
        printf("1. Print List\n2. Insert at beginning\n");
        printf("3. Insert at end\n4. Delete from beginning\n");
        printf("5. Delete from end\n6. Exit\n\n");
        printf("Option: ");
        scanf("%d", &opt);
        printf("\n");
        switch (opt) {
            case 1:
                if (start == NULL) {
                    printf("List is empty\n");
                } else {
                    traverse();
                }
                break;
            case 2:
                printf("Element: ");
                scanf("%d", &e);
                insert_beg(e);
                break;
            case 3:
                printf("Element: ");
                scanf("%d", &e);
                insert_end(e);
                break;
            case 4:
                if (start == NULL) {
                    printf("List is empty\n");
                } else {
                    delete_beg();
                }
                break;
            case 5:
                if (start == NULL) {
                    printf("List is empty\n");
                } else {
                    delete_end();
                }
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Whatchya saying?\n");
        }
        printf("\n");
    } while (opt != 6);
    return 0;
}
