// Create a generic function that accepts 2 inputs and returns their sum
// Put the function declaration and definition in the head file.
#include <iostream>
using namespace std;

template <typename T> //tell the compiler we're using a template
T sumTwo(T a, T b)    //T represents the variable type
{
    return a + b;
}

template <typename T, typename U> //different data types are allowed
T getBigger(T a, U b)
{
    return a > b ? a : b;
}

int main()
{
    int i1 = 4;
    int i2 = 5;
    float f1 = 12.43;
    float f2 = 6.11;
    cout << i1 << " + " << i2 << " = " << sumTwo(i1, i2) << endl;
    cout << f1 << " + " << f2 << " = " << sumTwo(f1, f2) << endl;
    cout << "Between " << i1 << " and " << f1 << " " << getBigger(i1, f1) << " is bigger.\n";
    return 0;
}
