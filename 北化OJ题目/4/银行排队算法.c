#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int a[100];

void solve(int m,int total,int at,int st)
{
    int sum = 0;
        int serial = 0;
        int minum;
        for (int i = 0; i < 100; i++)
        {
            a[i] = 0;
        }
        for (int i = 0; i < total; i++)
        {
            scanf("%d%d", &at, &st);
            minum = INT_MAX;
            for (int j = 0; j < m; j++)
            {
                if (a[j] < a[serial])
                {
                    serial = j;
                    minum = a[j];
                }
            }
            if (at <= a[serial])
            {
                int temp = a[serial] -at;
                sum += temp;
                a[serial] += st;
            }
            else
            {
                a[serial] = at+st;
            }
        }
        printf("%.2lf\n",((double)sum)/(1.0*total));
}

int main()
{
    int m, total;
    int at, st; //到达时间与处理时间
    while (scanf("%d%d", &m, &total) != EOF)
    {
        solve(m,total,at,st);
    }

    return 0;
}