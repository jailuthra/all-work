#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

/* STACK OPS */
struct stack
{
    struct node **arr;
    int n;
    int top;
};

#define SUCCESS 0
#define OVERFLOW -1
#define NA -2
#define UNDERFLOW -1

int push(struct stack *s, struct node *val)
{
    if (s->top == s->n - 1) {
        return OVERFLOW;
    } else {
        s->top += 1;
        s->arr[s->top] = val;
        return SUCCESS;
    }
}

struct node * pop(struct stack *s)
{
    if (s->top < 0) {
        return NULL;
    } else {
        s->top -= 1;
        return s->arr[s->top + 1];
    }
}

struct node * top(struct stack *s)
{
    if (s->top < 0) {
        return NULL;
    } else {
        return s->arr[s->top];
    }
}

/* TREE OPS */
struct node {
    char val;
    struct node *l;
    struct node *r;
    struct node *p;
};

void postorder(struct node *n)
{
    if (n) {
        postorder(n->l);
        postorder(n->r);
        printf("%c", n->val);
    }
}

struct node * make_node(char c)
{
    struct node *n = malloc(sizeof(struct node));
    n->l = n->r = n->p = NULL;
    n->val = c;
    return n;
}

/* PARSING */
int precedence[128]; //> ^ / * - +

void update_precedence()
{
    int i, j;
    for (j=0; j<127; j++) {
        precedence[j] = 0;
    }
    i = 1;
    char * prec = "+-*/^";
    for (j=0; prec[j]; j++) {
        precedence[prec[j]] = i++;
    }
}

struct node * join_trees(struct node *op, struct node *a, struct node *b)
{
    op->l = a;
    a->p = op;
    op->r = b;
    b->p = op;
    return op;
}

struct node * parse_tree(char *str, int *i)
{
    int j = *i;

    struct stack *trees;
    trees = malloc(sizeof(struct stack));
    trees->top = -1;
    trees->n = 100;
    trees->arr = malloc(sizeof(struct node *) * trees->n);
    struct stack *ops;
    ops = malloc(sizeof(struct stack));
    ops->top = -1;
    ops->n = 100;
    ops->arr = malloc(sizeof(struct node *) * ops->n);

    struct node *n, *o, *a, *b;
    while (str[j] != '\0' && str[j] != ')') {
        if (str[j] == '(') {
            j++;
            n = parse_tree(str, &j);
            push(trees, n);
            continue;
        } else if (str[j] <= 'z' && str[j] >= 'a') {
            n = make_node(str[j]);
            push(trees, n);
        } else { // operator
            n = make_node(str[j]);
            while (ops->top >= 0 && precedence[top(ops)->val] >= precedence[n->val]) {
                o = pop(ops);
                b = pop(trees);
                a = pop(trees);
                push(trees, join_trees(o, a, b));
            }
            push(ops, n);
        }
        j++;
    }
    j++;
    while (ops->top >= 0) {
        o = pop(ops);
        b = pop(trees);
        a = pop(trees);
        push(trees, join_trees(o, a, b));
    }

    *i = j;
    assert(trees->top == 0 && ops->top == -1);

    return pop(trees);
}

int main()
{
    int t, i;
    update_precedence();
    scanf("%d", &t);
    char str[101];
    struct node *expr;
    while (t--) {
        scanf("%s", str);
        i = 0;
        expr = parse_tree(str, &i);
        postorder(expr);
        printf("\n");
    }
    return 0;
}