#include <stdio.h>
#include <stdlib.h>

void output(int n, int a[])
{
    for (int k = 1; k < n + 1; k++)
    {
        printf("%d ", a[k]);
    }
    printf("\n");
}

void permutation(int i, int n, int juedge[], int a[])
{
    if (i > n)
    {
        output(n, a);
    }
    else
    {
        for (int k = 1; k <= n; k++)
        {
            if (juedge[k] == 0)
            {
                a[i] = k;
                juedge[k] = 1;
                permutation(i + 1, n, juedge, a);
                juedge[k] = 0;
            }
        }
    }
}

int main()
{
    int juedge[100];
    int n;
    int a[100];
    int put[100];
    int ser = 0;
    while (scanf("%d", &put[ser]) != EOF && put[ser] > -1 && put[ser] < 8)
    {
        if (put[ser] == 0)
        {
            break;
        }
        ser++;
    }
    ser = 0;
    while (1)
    {
        n = put[ser];
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < 100; i++)
        {
            juedge[i] = 0;
        }
        permutation(1, n, juedge, a);
        ser++;
    }

    return 0;
}