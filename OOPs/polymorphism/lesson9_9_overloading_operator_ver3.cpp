/*
*In the program below, overload the '+' operator to perform the following function:
*Add the lengths of the two shapes together
*Add the widths of the two shapes together
*Calculate and return the area of the new shape
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
    //Declare the operator function as a global operator function that is made friend of the class
    //(friend function can access private member data of the class)
    //In this case, we have to pass both 2 arguments into the function because it's not a member function
    friend Shape operator+(Shape &, Shape &);
    int getLength()
    {
        return length;
    }
    int getWidth()
    {
        return width;
    }
};
Shape operator+(Shape &obj1, Shape &obj2)
{
    return Shape(obj1.length + obj2.length, obj1.width + obj2.width);
}
int main()
{
    Shape sh1(4, 4);
    Shape sh2(2, 6);
    Shape sh3;

    sh3 = sh1 + sh2;
    cout << "\nsh1.length + sh2.length = " << sh3.getLength();
    cout << "\nsh1.width + sh2.width = " << sh3.getWidth();
    cout << "\nsh3.area() = " << sh3.area();
    return 0;
}