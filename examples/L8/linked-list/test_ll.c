#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include"ll.h"

void test_everything()
{
    Node head = NULL;
    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);

    assert(length(head) == 3);
    assert(contains(head, 2));
    assert(!contains(head, 5));
    assert(get(head, 2) == 3);
    set(head, 1, 5);
    assert(contains(head, 5));

}
void main()
{
    test_everything();
    printf("Tests pass!\n");
}

