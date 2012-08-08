#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"array.h"

// This test should be larger and more well separated. I.e. there should be
// separate tests for each function. 

// It is short in the interests of class time

void test_everything()
{
    Collection C = mkEmptyCollection();
    append(C, 3);
    assert(get(C, 0) == 3);

    append(C, 2);
    assert(length(C) == 2);

    assert(contains(C, 3));
    assert(!contains(C, 5));
}

void main()
{
    test_everything();
    printf("Tests pass!\n");
}
