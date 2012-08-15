#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>
#include "ll.h"

typedef struct node *   Node;
struct node
{
    int data;
    struct node * next;
};

int length(Node n)
{
    if (n==NULL)
        return 0;
    return 1 + length(n->next);
}

Node mkEmptyList()
{
    return NULL;
}

Node mkNode(int item)
{
    Node n = malloc(sizeof(struct node));
    n->data = item;
    n->next = NULL;
    return n;
}

Node prepend(Node n, int item)
{
    Node head = mkNode(item);
    head->next = n;
    return head;
}
Node append(Node n, int item)
{
    if (n == NULL)
    {
        n = mkNode(item); 
        n->next = NULL;
    }
    else
    {
        n->next = append(n->next, item);
    }
    return n;
}
int get(Node n, int index)
{
    if (index == 0)
        return n->data;
    else
        return get(n->next, index-1);
}

void set(Node n, int index, int value)
{
    if (index == 0)
        n->data = value;
    else
        set(n->next, index-1, value);
}
bool contains(Node n, int value)
{
    if (n == NULL)
        return false;
    else if (n->data == value)
        return true;
    else 
        return contains(n->next, value);
}
