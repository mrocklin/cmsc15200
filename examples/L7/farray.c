struct farray // array of floats
{
    float *data;
    int len;
};

float sum(struct farray A)
{
    int i;
    float total = 0;
    for(i = 0; i < A.len; i++)
        total += A.data[i];
    return total;
}

