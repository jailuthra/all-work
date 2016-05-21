#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node *left;
	struct Node *right;
};

typedef struct Node Node;

void insert(Node **nodeptr, int key);
void printInOrder(Node *node);
Node * search(Node *node, int key);
void printLevelOrder(Node *node);

int main()
{
	int size;
	scanf("%d", &size);
	int i, key;
	Node *node = NULL;
	for (i=0; i<size; i++) {
		scanf("%d", &key);
		insert(&node, key);
	}
    printf("\nLevel order\n");
    printLevelOrder(node);
    printf("\nIn order\n");
	printInOrder(node);
	return 0;
}

Node * search(Node *node, int key)
{
	if (node->key == key || !node) {
		return node;
	} else if (key < node->key) {
		return search(node->left, key);
	} else {
		return search(node->right, key);
	}
}

void printInOrder(Node *node)
{
	if (node->left) {
		printInOrder(node->left);
	}
	printf("%c\n", node->key);
	if (node->right) {
		printInOrder(node->right);
	}
}

struct node_lev {
    Node *node;
    int lev;
};

void printLevelOrder(Node *node)
{
    /*Node *temp_node = node;*/
    struct node_lev *temp_node = malloc(sizeof(struct node_lev));
    temp_node->node = node;
    temp_node->lev = 0;

    struct node_lev *nv;

    int lev = 0;
    while (temp_node)
    {
        
        if (temp_node->lev > lev) {
            lev = temp_node->lev;
            printf("\n");
        }

        printf("%c ", temp_node->node->key);

        /*if (temp_node->node->left && temp_node->node->right) {
            printf("Node %c has left %c, right %c\n", temp_node->node->key,
                   temp_node->node->left->key, temp_node->node->right->key);
        } else if (temp_node->node->left) {
            printf("Node %c has left %c, right NULL\n", temp_node->node->key,
                   temp_node->node->left->key);
        } else if (temp_node->node->right) {
            printf("Node %c has left NULL, right %c\n", temp_node->node->key,
                   temp_node->node->right->key);
        }*/

        nv = malloc(sizeof(struct node_lev));
        /*Enqueue left child */
        if (temp_node->node->left)
        {
            nv->node = temp_node->node->left;
            nv->lev = temp_node->lev + 1;    
            Enqueue(nv);
        }
 
        nv = malloc(sizeof(struct node_lev));
        /*Enqueue right child */
        if (temp_node->node->right)
        {
            nv->node = temp_node->node->right;
            nv->lev = temp_node->lev + 1;    
            Enqueue(nv);
        }

        free(temp_node);

        /*Dequeue node and make it temp_node*/
        temp_node = Front();
        Dequeue();
    }

    free(temp_node);
}

void insert(Node **nodeptr, int key)
{
	Node * node = *nodeptr;
	if (!node) {
		node = malloc(sizeof(Node));
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		*nodeptr = node;
	} else if (key < node->key) {
		insert(&node->left, key);
	} else {
		insert(&node->right, key);
	}
}

