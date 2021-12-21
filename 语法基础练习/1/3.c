//字符串反转
#include <stdio.h>
#include <string.h>

int main()
{
    char a[100], temp;
    scanf("%s", &a);
    int len = strlen(a);
    printf("%d\n", len);
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", a[i]);
    }
    printf("\n");

    return 0;
}