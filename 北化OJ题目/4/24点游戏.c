#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

int a[4];
bool calculate(int b)
{
    if (b == 1)
    {
        return a[0] == 24;
    }
    for (int m = 0; m < b; m++)
    {
        for (int n = 0; n < b; n++)
        {
            if (m == n)
            {
                continue;
            }
            int temp1 = a[m], temp2 = a[n];
            a[m] = temp1 + temp2;
            a[n] = a[b - 1];
            if (calculate(b - 1))
            {
                return true;
            }
            a[m] = temp1 - temp2;
            a[n] = a[b - 1];
            if (calculate(b - 1))
            {
                return true;
            }
            a[m] = temp1 * temp2;
            a[n] = a[b - 1];
            if (calculate(b - 1))
            {
                return true;
            }
            if (temp2 != 0 && (temp1 % temp2 == 0))
            {
                a[m] = temp1 / temp2;
                a[n] = a[b - 1];
                if (calculate(b - 1))
                    return true;
            }
            a[m] = temp1;
            a[n] = temp2;
        }
    }
    return false;
}

int main()
{
    
    while (scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]) != EOF)
    {
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0)
        {
            break;
        }
        if (calculate(4))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}