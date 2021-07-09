#include <iostream>
#include <string>
using namespace std;

int solution(int a, int b)
{
    if ((a < 0 || a > 100000000) || ((b < 0 || b > 100000000)))
    {
        return -1;
    }
    string strA = to_string(a);
    string strB = to_string(b);
    string strC = "";

    for (int i = 0; i < strA.length() || i < strB.length(); i++)
    {
        if (i < strA.length())
        {
            strC += strA[i];
        }
        if (i < strB.length())
        {
            strC += strB[i];
        }
    }
    if (strC.length() <= 9) // Solve out of range error of stoi() in case A and B < 100000000 but the result > INT_MAX
    {
        int decimalZip = stoi(strC);
        if (decimalZip > 100000000)
        {
            return -1;
        }
        return decimalZip;
    }
    return -1; 
}
int main()
{
    cout << "Type in A: ";
    int a;
    cin >> a;
    cout << "\nType in B: ";
    int b;
    cin >> b;
    int c = solution(a, b);
    cout << "\nDecimal zip of A and B is " << c << endl;
    return 0;
}