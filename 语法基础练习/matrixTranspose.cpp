//matrix transpose
#include <iostream>

using namespace std;

int **matrixInput(int rows,int columns)
{
    int **a = (int **)malloc(rows * sizeof(int *)); //����rows��

    for (int i = 0; i < rows; i++)
        a[i] = (int *)malloc(columns * sizeof(int)); //��������

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
    cout<<"��������"<<endl;
    cin>>rows;
    cout<<"��������"<<endl;
    cin>>columns;
    cout << "��������Ԫ�أ������ȣ�(��������Ԫ�ز���ȱ©)" << endl;
    a = matrixInput(rows,columns);

    cout << "��ʼ����" << endl;
    matrixOutPut(a,rows,columns);
    matrixTrans(a,rows,columns);
    cout << "ת�ú�ľ���" << endl;
    matrixOutPut(a,rows,columns);

    //�ͷ�
    for (int i = 0; i < 3; i++)
        free(a[i]);
    free(a);
}