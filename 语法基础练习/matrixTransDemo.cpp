#include <iostream>
using namespace std;
 
void matrixTrans(int a[4][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			//交换两个数
			swap(a[i][j],a[j][i]);
		}
	}
}
 
int main()
{
	int test[4][4]={
		{1,2,3,4},
		{1,2,3,4},
		{5,6,7,8},
		{0,0,0,0}
	};
	matrixTrans(test);
 
	//输出转置后的数组
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<test[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
