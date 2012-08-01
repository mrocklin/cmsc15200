#include<stdbool.h>
#include<assert.h>

bool array_equal(int A[], int B[], int len)
{
    int i;
    for(i = 0; i < len; i++) // for all i from 0 to len-1
    {
        if (A[i] != B[i])
            return false;
    }
    return true;

}
bool array_equal_float(float A[], float B[], int len)
{
    int i;
    for(i = 0; i < len; i++) // for all i from 0 to len-1
    {
        if(abs(A[i] - B[i]) > .0001) // A[i] != B[i]
            return false;
    }
    return true;
}


void test_array_equal()
{
    int A[] = {1,2,3};
    int B[] = {1,2,3};
    int C[] = {4,5,6};
    assert(array_equal(A, B, 3));
    assert(array_equal(A, A, 3));
    assert(!array_equal(A, C, 3));
}

void main()
{
    test_array_equal();
}
