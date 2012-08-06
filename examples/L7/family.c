// An example about recursion
typedef struct human *  Human;
struct human
{
    char * name;
    Human *children;
    int num_children;
}

int numDescendents(Human h)
{
    if (h->num_children == 0)
        return 0;

    int total = 0;
    int i;
    for(i = 0; i < h->num_children; i++)  // ask each child
        total = total + numDescendents(h->children[i]) + 1; // How many descendents do you have?

    return total;
}
