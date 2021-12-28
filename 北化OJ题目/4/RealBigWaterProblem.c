#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double F(int x, int n)
{
    if (x == 0)
    {
        return cos((double)n);
    }
    return cos(F(x - 1, n));
}

int main()
{
    char str[31];
    int n, m;
    int i = 0;
    while (scanf("%s", str) != EOF)
    {
        if (i > 20)
            break;
        if (strlen(str) <= 3)
        {
            n = atoi(str);
            m = n;
            printf("%.6lf\n",F(n,m));
        }else
        {
            printf("0.739085\n");
        }
        
        i++;
    }

    return 0;
}