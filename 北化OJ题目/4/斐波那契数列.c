#include <stdio.h>
#include <stdlib.h>

int fabonaci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fabonaci(n - 1) + fabonaci(n - 2);
}

int main()
{
    int num;
    scanf("%d", &num);
    if (num > 0 && num <= 35)
        printf("%d", fabonaci(num - 1));
}