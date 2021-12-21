#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0,b=0,c=0,d=0;
    scanf("%d %d",&a,&b);
    scanf("%d %d",&c,&d);
    printf("%d %d",(a*c - b*d),(b*c + a*d));
    return 0;
}