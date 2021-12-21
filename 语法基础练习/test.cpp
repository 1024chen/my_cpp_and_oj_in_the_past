#include <iostream>

using namespace std;

class test
{
private:
    int a;

public:
    test() { a = 10; };
    test(int a);
    ~test();
};

test::test(int a)
{
    this->a = a;
    cout << "this construct" << a << endl;
}

test::~test()
{
    cout << "destruct" << a << endl;
}

int main()
{
    test a1, a2(20);
    return 0;
}