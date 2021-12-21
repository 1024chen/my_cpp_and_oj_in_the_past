#include <stdio.h>

int main()
{
    int a;
    while (scanf("%d", &a) != EOF && a != 0)
    {
        for (int i = 1; i <= a; i++)
        {
            printf(" %d ", i);
        }
        printf("\n");
        for (int i = 2; i <= a - 1; i++)
        {
            for (int k = 1; k <= a; k++)
            {
                if (k == 1)
                {
                    printf("%d  ", (4 * a - 2) - i);
                }
                else if (k == a)
                {
                    printf("%d  ", (a - 1) + i);
                }
                else
                {
                    printf("   ");
                }
            }
            printf("\n");
        }

        for (int i = (3 * a - 2); i >= (2 * a - 1); i--)
        {
            printf("%d  ", i);
        }
    }

    return 0;
}