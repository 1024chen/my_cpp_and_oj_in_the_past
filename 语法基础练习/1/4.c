//1到1000遍历条件输出
#include <stdio.h>
#include <string.h>

int main()
{
    for (int i = 1; i <= 1000; i++)
    {
        if (i % 3 == 0)
        {
            if (i % 5 == 0)
            {
                printf("great\n");
            }
            else
            {
                printf("tri\n");
            }
        }
        else if (i % 5 == 0)
        {
            printf("fri\n");
        }
        else
        {
            printf("%d\n", i);
        }
    }

    return 0;
}