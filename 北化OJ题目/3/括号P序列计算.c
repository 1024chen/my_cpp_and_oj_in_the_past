#include <stdio.h>
#include <stdlib.h>

#define MaxSize 1000

//返回左括号位置，从下标0开始
int leftBracketsMatch(char *str, int right)
{
    int left = right - 1;
    int rightNum = 1;
    int leftNum = 0;

    while (rightNum != leftNum && left >= 0)
    {
        if (str[left] == '(')
        {
            leftNum++;
        }
        else if (str[left] == ')')
        {
            rightNum++;
        }
        left--;
    }
    ++left;
    return left;
}

int main()
{
    char brackets[MaxSize];
    while (scanf("%s", &brackets) != EOF)
    {
        int iter = 0; //迭代器
        while (brackets[iter] != '\0')
        {
            if (brackets[iter] == ')')
            {
                int counter = 1;
                //这里实际上i是要从匹配的左括号位置开始
                for (int i = leftBracketsMatch(brackets, iter); i < iter; i++)
                {
                    if (brackets[i] == ')')
                    {
                        counter++;
                    }
                }
                printf("%d ",counter);
            }
            iter++;
        }
        printf("\n");
    }
    return 0;
}