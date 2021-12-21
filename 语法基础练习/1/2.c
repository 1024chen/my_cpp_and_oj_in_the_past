//两整数除法
#include <stdio.h>

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        b == 0 ? printf("error\n")
               : printf("%d\n", (int)((float)a / (float)b + 0.5));//二次强转与偏差量0.5
    }

    return 0;
}