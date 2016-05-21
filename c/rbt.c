#include <stdio.h>
#include <stdlib.h>

/* RED-BLACK TREE */
#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"

enum color {
    BLACK,
    RED
};

struct node {
    long val;
    enum color col;
    struct node *p;
    struct node *l;
    struct node *r;
};

struct Tree {
    struct node *root;
    struct node *nil;
};

void rbPrint(struct Tree *T, struct node *ptr);
void leftRotate(struct Tree *T, struct node *x);
void rightRotate(struct Tree *T, struct node *x);
void rbInsert(struct Tree *T, long val);
void rbInsertFixup(struct Tree *T, struct node *z);

int main()
{
    struct Tree *T = malloc(sizeof(struct Tree));
    T->nil = malloc(sizeof(struct node));
    T->nil->col = BLACK;
    T->nil->p = NULL;
    T->root = T->nil;
    int n = 1;
    while (n != 0) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        } else {
            rbInsert(T, n);
        }
    }
    rbPrint(T, T->root);
    printf("\n");
    return 0;
}

void rbPrint(struct Tree *T, struct node *ptr)
{
    if (ptr != T->nil) {
        if (ptr->col == BLACK) {
            printf(KNRM "%d ", ptr->val);
        } else {
            printf(KRED "%d ", ptr->val);
        }
        rbPrint(T, ptr->l);
        rbPrint(T, ptr->r);
    }
}

void leftRotate(struct Tree *T, struct node *x)
{
    struct node *y = x->r;
    // turn y's left subtree to x's right
    x->r = y->l;
    if (y->l != T->nil) {
        y->l->p = x;
    }
    // Set y's new parent as x's current parent
    y->p = x->p;
    // Edge case, x was root
    if (x->p == T->nil) {
        T->root = y;
    } else if (x == x->p->l) {
        x->p->l = y;
    } else if (x == x->p->r) {
        x->p->r = y;
    }
    // Put x on y's left
    y->l = x;
    x->p = y;
}

void rightRotate(struct Tree *T, struct node *x)
{
    struct node *y = x->l;
    // turn y's right subtree to x's left 
    x->l = y->r;
    if (y->r != T->nil) {
        y->r->p = x;
    }
    // Set y's new parent as x's current parent
    y->p = x->p;
    // Edge case, x was root
    if (x->p == T->nil) {
        T->root = y;
    } else if (x == x->p->l) {
        x->p->l = y;
    } else if (x == x->p->r) {
        x->p->r = y;
    }
    // Put x on y's right
    y->r = x;
    x->p = y;
}

void rbInsert(struct Tree *T, long val)
{
    struct node *z = malloc(sizeof(struct node));
    z->val = val;
    struct node *y, *x;
    y = T->nil;
    x = T->root;
    while (x != T->nil) {
        y = x;
        if (z->val < x->val) {
            x = x->l;
        } else {
            x = x->r;
        }
    }
    z->p = y;
    if (y == T->nil) {
        T->root = z;
    } else if (z->val < y->val) {
        y->l = z;
    } else {
        y->r = z;
    }
    z->l = T->nil;
    z->r = T->nil;
    z->col = RED;
    rbInsertFixup(T, z);
}

void rbInsertFixup(struct Tree *T, struct node *z)
{
    struct node *y;
    while (z->p->col == RED) {
        if (z->p == z->p->p->l) {
            y = z->p->p->r;
            if (y->col == RED) {
                z->p->col = BLACK;
                y->col = BLACK;
                z->p->p->col = RED;
                z = z->p->p;
            } else {
                if (z == z->p->r) {
                    z = z->p;
                    leftRotate(T, z);
                }
                z->p->col = BLACK;
                z->p->p->col = RED;
                rightRotate(T, z->p->p);
            }
        } else {
            y = z->p->p->l;
            if (y->col == RED) {
                z->p->col = BLACK;
                y->col = BLACK;
                z->p->p->col = RED;
                z = z->p->p;
            } else {
                if (z == z->p->l) {
                    z = z->p;
                    rightRotate(T, z);
                }
                z->p->col = BLACK;
                z->p->p->col = RED;
                leftRotate(T, z->p->p);
            }
        }
    }
    T->root->col = BLACK;
}
