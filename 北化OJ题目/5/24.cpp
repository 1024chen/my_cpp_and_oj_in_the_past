//ȫ�����㷨-�����ֵ���
#include <iostream>

using namespace std;

bool used[100];//���ĳ�������Ƿ�ʹ�ù�
int a[100], Count, N;

void print() {
    for (int k = 1; k < N + 1; k++)
        cout << a[k];
    cout << "\n";
    Count++;
}

void dfs(int i) {
    if (i > N)//�ݹ��������ӡ���
        print();
    else
        for (int k = 1; k <= N; k++)
            if (used[k] == 0) { //used[]��bool���͵����飬û�б�ʹ��ʱĬ��Ϊ0
                used[k] = 1;//����ʹ�ù��ı��
                a[i] = k;//��ֵ a[1]=1,
                dfs(i + 1);
                // i��ֵ�ں��������ڻ᲻�ϵ�����ֱ����ԽN��������ֹ�˺�����������i=N+1
                used[k] = 0;//��ԭΪδʹ��
            }
}

int main() {


    cin >> N; // N��ָ��Ҫȫ����ʹ�õ�Ԫ�ظ���
    dfs(1);
    cout << Count << endl;
    // Count��һ��ȫ�ֱ���������ͳ��һ�����ɵ�������
    return 0;
}
