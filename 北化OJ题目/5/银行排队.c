#include<stdio.h>
#include<string.h>
 
int main()
{
	int a[100]; 
	int n,m,j,k,i,T,x,y,total,current;
	double sum;
	while (scanf("%d%d",&m,&total)!=EOF)
	{
		sum=0;
		current=0;
		memset(a,0,sizeof(a));//元素全初始化为0
		for (i=0;i<total;i++)
		{
			scanf("%d%d",&x,&y);
			int min = 1000000;
			for (j=0;j<m;j++)
			{
				if (a[j]<a[current])
				{
					min = a[j];
					current = j;
				}
			}
			if (x<=a[current])//Dèòa???ó 
			{
				sum += (a[current] - x) ;
				a[current] += y;
			}
			else//2?Dèòa???ó 
			{
				a[current] = x+y;
			}
			
		}
		
		printf("%.2lf\n",sum/(1.0*total) );
	}
	
		
	return 0;
 } 
