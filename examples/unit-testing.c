#include<assert.h>

// Computes the factorial of n
// Example: fact(4) == 24
int fact(int n)
{
    int result = 1; 
    int i = 1;
    while( i <=n )
    {
        result = result * i;
        i = i + 1;
    }
    return result;
}
void test_fact()
{
    assert(fact(1) == 1);
    assert(fact(4) == 24);
    assert(fact(0) == 1); // a tricky case
}


// Computes sum of factorials from 1 to m
// i.e. fact(1) + fact(2) + fact(3) + ... + fact(m)
int sumFact(int m)
{
    int result = 0;
    int i; 
    // Add up all the factorials from 1 to m
    for(i = 1; i <= m; i = i+1)
        result = result + fact(i);
    return result;
}
void test_sumFact()
{
    assert(sumFact(4) == 33); // we did this example by hand
}

void main()
{
    // Run tests if we want to
    // test_sumFact();
    // test_fact();


    // Look how small main is!
    printf("SumFact(4) == %d\n", sumFact(4));
}
