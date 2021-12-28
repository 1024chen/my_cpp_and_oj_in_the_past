#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int weight[1000];
int package(int n, int total)
{
    printf("n: %d total: %d\n", n, total);
    if (total == 0)
        return 1;
    if (total < 0 || (total > 0 && n < 1))
    {
        return 0;
    }
    if (1 == package(n - 1, total - weight[n - 1]))
    {
        return 1;
    }
    else
        return package(n - 1, total);
}

int main()
{
    int total, n, i;
    int weight[1000];
    while (scanf("%d%d", &total, &n) != EOF && (n > 0 && n < 1000))
    {
        //memset(weight, 0, sizeof(weight));
        for (i = 0; i < n; i++)
        {
            scanf("%d", &weight[i]);
        }
        if (1 == package(n, total))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
