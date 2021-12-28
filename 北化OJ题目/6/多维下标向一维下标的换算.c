#include <stdio.h>
#include <stdlib.h>
#define MAX_DATA_LEN 100
#define MAX_DIM_LEN 20

typedef struct Array
{
    int *data;
    int dims;
    int *L;
} Array;

void Init(Array *array, int n)
{
    array->L = (int *)malloc(n * sizeof(int));
    array->dims = n;
}

int GetIndex(Array *array, int *I)
{
    int len = array->dims;
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        int iter = I[i];
        for (int j = i + 1; j < len; j++)
        {
            iter *= array->L[j];
        }
        index += iter;
    }
    return index;
}

void Destory(Array *array)
{
    array->dims = 0;
    free(array->L);
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        Array array;
        Init(&array, n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &array.L[i]);
        }
        int I[MAX_DIM_LEN];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &I[i]);
        }
        int index = GetIndex(&array, I);
        printf("%d\n", index);
        Destory(&array);
    }
    return 0;
}