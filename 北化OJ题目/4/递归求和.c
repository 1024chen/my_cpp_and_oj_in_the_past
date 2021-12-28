#include<stdio.h>
#include<stdlib.h>

int f(int n){
    if (n == 0)
    {
        return 0;
    }
    return f(n-1)+n;
}

int main()
{
    int n;
    scanf("%d",&n);
    if (n<= 10000)
    printf("%d",f(n));
    return 0;
}