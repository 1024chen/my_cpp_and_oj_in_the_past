//全排列算法-深搜字典序
#include <iostream>

using namespace std;

bool used[100];//标记某个数字是否被使用过
int a[100], Count, N;

void print() {
    for (int k = 1; k < N + 1; k++)
        cout << a[k];
    cout << "\n";
    Count++;
}

void dfs(int i) {
    if (i > N)//递归结束，打印结果
        print();
    else
        for (int k = 1; k <= N; k++)
            if (used[k] == 0) { //used[]是bool类型的数组，没有被使用时默认为0
                used[k] = 1;//做已使用过的标记
                a[i] = k;//赋值 a[1]=1,
                dfs(i + 1);
                // i的值在函数调用内会不断的增加直到超越N即最终终止此函数的条件是i=N+1
                used[k] = 0;//还原为未使用
            }
}

int main() {


    cin >> N; // N是指需要全排序使用的元素个数
    dfs(1);
    cout << Count << endl;
    // Count是一个全局变量，用于统计一共生成的序列数
    return 0;
}
