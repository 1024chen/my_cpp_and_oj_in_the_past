//该谁发球了
#include <stdio.h>

int main()
{
    unsigned int a, b;
    while (scanf("%d%d", &a, &b) != EOF &&(a <= 100 && b<= 100))
    {
        unsigned int sum = a + b;
        if ((sum <= 20) && (a == 11 || b == 11))
        {
            printf("Game Over");
        }else if (sum <= 18)
        {
            switch (sum % 4)
            {
            case 0:
                printf("A\n");
                break;
            case 1:
                printf("A\n");
                break;
            case 2:
                printf("B\n");
                break;
            case 3:
                printf("B\n");
                break;
            default:
                break;
            }
        }
        else
        {
            sum % 2 == 0 ? printf("A") : printf("B");
        }
    }

    return 0;
}