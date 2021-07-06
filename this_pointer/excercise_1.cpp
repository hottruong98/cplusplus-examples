#include <iostream>
using namespace std;
class Test
{
    int x;

public:
    Test(int x);
    void change(Test *t);
    void print();
};
Test::Test(int x = 0)
{
    this->x = x;
}
void Test::change(Test *t)
{
    this->x = t->x;
}
void Test::print()
{
    cout << "x = " << x << endl;
}

int main()
{
    Test obj(5);
    obj.print();
    Test *ptr = new Test(10);
    obj.print();
    obj.change(ptr);
    obj.print();
    return 0;
}