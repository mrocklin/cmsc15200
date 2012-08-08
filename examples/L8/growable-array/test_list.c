#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"list.h"

// This test should be larger and more well separated. I.e. there should be
// separate tests for each function. 

// It is short in the interests of class time

void test_everything()
{
    List L = mkEmptyList();
    append(L, 3);
    assert(get(L, 0) == 3);

    append(L, 2);
    assert(length(L) == 2);

    assert(contains(L, 3));
    assert(!contains(L, 5));
}

void main()
{
    test_everything();
    printf("Tests pass!\n");
}
