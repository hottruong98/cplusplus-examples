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
    //Declare the operator function as a global operator function that is made friend of the class
    //(friend function can access private member data of the class)
    //In this case, we have to pass both 2 arguments into the function because it's not a member function
    friend int operator+(Shape &, Shape &);
};
int operator+(Shape &obj1, Shape &obj2)
{
    return obj1.area() + obj2.area();
}
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