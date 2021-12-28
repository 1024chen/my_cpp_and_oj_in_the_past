#include <stdio.h>
#include <stdlib.h>

typedef struct age_array
{
    int arr[101]; //a[0]被闲置
} Age_array;

void init_age_array(Age_array *a)
{
    for (int i = 1; i < 101; i++)
    {
        a->arr[i] = 0;
    }
}

void out_put_age_arr(Age_array *a)
{
    for (int i = 1; i < 101; i++)
    {
        for (int j = a->arr[i]; j > 0; j--)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void in_put_sort_by_serial(Age_array *a, int n)
{
    int num;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        a->arr[num]++;
    }
}

int main()
{
    int n = 1;
    Age_array arr;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        init_age_array(&arr);
        in_put_sort_by_serial(&arr, n);
        out_put_age_arr(&arr);
    }

    return 0;
}
