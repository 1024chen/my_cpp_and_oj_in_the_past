#include <stdio.h>
#include <stdlib.h>
int c = 0;

void move(char x, int n, char z)
{
    printf("%2d. Move disk %d from %c to %c\n", ++c, n, x, z);
}

void hanoi(int n, char x, char y, char z)
{
    if (n == 1)
    {
        move(x, 1, z);
    }
    else
    {
        hanoi(n - 1, x, z, y);
        move(x, n, z);
        hanoi(n - 1, y, x, z);
    }
}

int main()
{
    int a[100];
    int ser = 0;
    char x = 'X', y = 'Y', z = 'Z';
    while (scanf("%d", &a[ser]) != EOF)
    {
        if (a[ser] <= 0)
        {
            break;
        }
        ser++;
    }

    for (int i = 0; i < ser - 1; i++)
    {
        c = 0;
        hanoi(a[i], x, y, z);
        printf("\n");
    }
    c = 0;
    hanoi(a[ser - 1], x, y, z);
    // while (scanf("%d", &n) != EOF && n > 0)
    // {
    //     c = 0;
    //     hanoi(n, x, y, z);
    //     //printf("\n");
    // }

    return 0;
}