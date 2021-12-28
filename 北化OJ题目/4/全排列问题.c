#include <stdio.h>
#include <stdlib.h>

void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int a[], int b, int n)
{
    if (b == n)
        output(a, n);
    else
    {
        for (int i = b; i < n; i++)
        {
            swap(&a[b], &a[i]);
            permutation(a, b + 1,n);
            swap(&a[b], &a[i]);
        }
    }
}

int main()
{
    int N, a[10];
    while (scanf("%d", &N) && N > -1 && N < 8)
    {
        if (N == 0)
        {
            break;
        }

        for (int m = 0; m < N; m++)
        {
            a[m] = m + 1;
        }

        permutation(a, 0, N);
    }
    return 0;
}