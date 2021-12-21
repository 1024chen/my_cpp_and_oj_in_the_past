#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct Item
{
    int coeff;
    int index;
} Ite;

void change_serials(Ite *ite, int i)
{
    Ite temp;
    int locat = -1;
    for (int j = 0; j < i; j++)
    {
        for (int k = 0; k < i - 1 - j; k++)
        {
            if (ite[k].index < ite[k + 1].index)
            {
                temp = ite[k];
                ite[k] = ite[k + 1];
                ite[k + 1] = temp;
            }
        }
    }

    //标记
    int flag = 0;
    for (int j = 0; j < i; j++)
    {
        if (ite[j].index < 0)
        {
            locat = j;
            break;
        }
    }

    //验证系数和为 0
    int sum = 0, mark = 0;
    for (int j = 0; j < i; j++)
    {
        if (ite[j].index == ite[j + 1].index && mark == 0)
        {
            sum += (ite[j].coeff + ite[j + 1].coeff);
            mark = 1;
        }
        else if (ite[j].index == ite[j + 1].index && mark == 1)
        {
            sum += ite[j + 1].coeff;
        }
        else if (ite[j].index != ite[j + 1].index)
        {
            mark = 0;
        }
    }

    //结果多项式为0，直接输出0
    for (int j = 0; j < i; j++)
    {
        // || sum == 0
        if (ite[j].coeff == 0 || ite[j].index == -1)
        {
            flag = 1;
        }
        else
        {
            flag = -1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("0");
    }

    // if (locat == 0 ||(ite[0].coeff==0))
    // {
    //     printf("0");
    // }

    if (ite[0].index == 0 && i == 1)
    {
        printf("%d %d ", ite[0].coeff, ite[0].index);
    }
    else if (locat > 0)
    {
        i = locat;
        for (int j = 0; j < i; j++)
        {
            if (ite[j].coeff != 0)
            {
                printf("%d %d ", ite[j].coeff, ite[j].index);
            }
        }
    }
    else if (locat == -1)
    {
        for (int j = 0; j < i; j++)
        {
            if (ite[j].coeff != 0)
            {
                printf("%d %d ", ite[j].coeff, ite[j].index);
            }
        }
    }

    printf("\n");
}

int main()
{

    Ite term[MAX];
    int coeff, ind;
    int i = 0;
    while (scanf("%d %d", &coeff, &ind) == 2 && ind >= 0)
    {
        term[i].coeff = coeff * ind;
        term[i].index = ind - 1;
        i++;
    }
    if (i == 0)
    {
        printf("0\n");
    }
    else
    {
        change_serials(term, i);
    }

    return 0;
}