#include <stdio.h>

int pow(int a, int x)
{	
	int i;
	int p=1;
	
	for(i=0; i<x; i++)
		p = p * a;
	
	return p;
}

int main()
{
	int a, x, p;
	printf("I will compute a^x for you.\n");
	
	printf("Please enter a value for a: ");
	scanf("%d", &a);
	printf("Please enter a value for x: ");
	scanf("%d", &x);
		
	p = pow(a,x);
	
	printf("%d^%d = %d", a, x, p);
	
	return(0);
}
