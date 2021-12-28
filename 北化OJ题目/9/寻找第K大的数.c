#include <stdio.h>
#include <stdlib.h>
#define strLength 2000001
#define ElemType int

typedef struct numStr
{
    ElemType *str; //下标i从0开始，下标0位置表示-1000000，所以是一个数x表示在下标x+1000000处
    int int_num;
} NumStr;

void Create_numStr(NumStr *NS)
{
    NS->str = (ElemType *)malloc(strLength * sizeof(ElemType));
}

void Init_numStr(NumStr *NS, int N)
{
    NS->int_num = N;
    for (int i = 1; i < strLength; i++) //0号位置保留
    {
        NS->str[i] = 0;
    }
}

void InPut_numStr(NumStr *NS)
{
    int temp;
    //输入数需要存在+1000001处
    for (int i = 0; i < NS->int_num; i++)
    {
        scanf("%d", &temp);
        NS->str[temp + 1000000]++;
    }
}

void Find_numStr_KMax(NumStr *NS, int K)
{
    int J = 0;
    for (int i = strLength - 1; i >= 0; i--)
    {
        if (NS->str[i] > 0)
        {
            J++;
        }
        if (J == K)
        {
            printf("%d", i - 1000000);
        }
    }
}

void Free_numStr(NumStr *NS)
{
    free(NS->str);
    NS->int_num = 0;
}

int main(int argc, char const *argv[])
{
    NumStr NS;
    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);
    Create_numStr(&NS);
    Init_numStr(&NS, N);
    InPut_numStr(&NS);
    Find_numStr_KMax(&NS, K);
    Free_numStr(&NS);

    return 0;
}
