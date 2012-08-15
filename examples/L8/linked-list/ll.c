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
    int count = 0;
    while(n != NULL)
    {
        count++;
        n = n->next;
    }
    return count;
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
    Node newNode = mkNode(item);
    newNode->next = NULL;

    if (n==NULL)
        return newNode;
    else
    {
        Node temp = n;
        while(temp->next != NULL)
            temp = temp->next;
        // At this point temp->next == NULL 
        // I.e. we are at the end of the list
        temp->next = newNode;
    }

    return n;
}
int get(Node n, int index)
{
    int count = 0;
    Node temp = n;
    while(count != index)
    {
        count++;
        temp = temp->next;
    }
    return temp->data;
}
void set(Node n, int index, int value)
{
    int count = 0;
    Node temp = n;
    while(count != index)
    {
        count++;
        temp = temp->next;
    }
    temp->data = value;
}
bool contains(Node n, int value)
{
    Node temp = n;
    while(temp != NULL)
    {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}
