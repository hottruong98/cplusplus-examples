#include <iostream>
using namespace std;
class Compare
{
public:
    int findSmaller(int a, int b);
    float findSmaller(float a, float b);
    char findSmaller(char a, char b);
};
int Compare::findSmaller(int a, int b)
{
    return a < b ? a : b;
}
float Compare::findSmaller(float a, float b)
{
    return a < b ? a : b;
}
char Compare::findSmaller(char a, char b)
{
    return a < b ? a : b;
}

int main()
{
    Compare obj;
    int i1 = 5;
    int i2 = 4;
    float f1 = 5.43;
    float f2 = 6.32;
    char c1 = 'c';
    char c2 = 'z';
    cout << obj.findSmaller(i1, i2) << " is the smaller of " << i1 << " and " << i2 << endl;
    cout << obj.findSmaller(f1, f2) << " is the smaller of " << f1 << " and " << f2 << endl;
    cout << obj.findSmaller(c1, c2) << " is the smaller of " << c1 << " and " << c2 << endl;
    return 0;
}