/*
*In the program below, overload the '+' operator to perform the following function:
*Add the areas of the two shapes together
*/
#include <iostream>
using namespace std;
class Shape
{
    int length;
    int width;

public:
    Shape(int length = 2, int width = 2)
    {
        this->length = length;
        this->width = width;
    }
    int area()
    {
        return length * width;
    }
    //Declare and define the operator function as a member function.
    //Use "&" to make our code efficient by referencing the second object (2nd operand)
    //instead of making a duplicate object inside the operator function.
    int operator+(Shape &obj)
    {
        return area() + obj.area();
    }
};
int main()
{
    Shape sh1(4, 4);
    Shape sh2(2, 6);
    Shape sh3;

    int total = sh1 + sh2;
    cout << "\nSh1.area() = " << sh1.area();
    cout << "\nSh2.area() = " << sh2.area();
    cout << "\nTotal = " << total;
    return 0;
}