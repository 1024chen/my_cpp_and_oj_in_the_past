#include<stdio.h>
#include<stdlib.h>

int juedge(int lena,int lenb,char a[],char b[]){
    int counter = 0;
    int min = lena > lenb ? lenb : lena;
    int max = lena > lenb ? lena : lenb;
    for (int i = 0; i < min; i++)
    {
        if (a[i] != b[i])
        {
            counter++;
        }
    }
     counter += max - min;
     return counter;
}

int main()
{
    int lena,lenb;
    char a[1000],b[1000];
    scanf("%d",&lena);
    scanf("%d",&lenb);
    scanf("%s",a);
    scanf("%s",b);
    printf("%d",juedge(lena,lenb,a,b));
    return 0;
}