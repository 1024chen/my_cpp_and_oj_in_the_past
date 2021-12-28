#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double F(int x, int n)
{
    if (x == 0)
    {
        return sin((double)n);
    }
    return sin(F(x - 1, n));
}

int main()
{
    int n, m;
    int i = 0;
    while (scanf("%d", &n) != EOF && (n >= 0 && n <= 100))
    {
        if (i > 20)
        {
            break;
        }

        m = n;
        printf("%.6f\n", F(n, m));
        i++;
    }

    return 0;
}