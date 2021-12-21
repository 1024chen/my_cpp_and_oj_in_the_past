//matrix transpose
#include <iostream>

using namespace std;

int **matrixInput(int rows,int columns)
{
    int **a = (int **)malloc(rows * sizeof(int *)); //申请rows行

    for (int i = 0; i < rows; i++)
        a[i] = (int *)malloc(columns * sizeof(int)); //申请三列

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> a[i][j];
        }
    }
    return a;
}

void matrixOutPut(int **a,int rows,int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void matrixTrans(int **a,int rows,int columns)
{
    int temp;
    for (int i = 0; i < rows; i++)
    {
        for (int j = i+1; j < columns; j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}

int main()
{
    int **a;
    int rows,columns;
    cout<<"输入行数"<<endl;
    cin>>rows;
    cout<<"输入列数"<<endl;
    cin>>columns;
    cout << "依次输入元素，行优先：(整行输入元素不可缺漏)" << endl;
    a = matrixInput(rows,columns);

    cout << "初始矩阵" << endl;
    matrixOutPut(a,rows,columns);
    matrixTrans(a,rows,columns);
    cout << "转置后的矩阵" << endl;
    matrixOutPut(a,rows,columns);

    //释放
    for (int i = 0; i < 3; i++)
        free(a[i]);
    free(a);
}