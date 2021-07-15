// a geometric series is the sum of an infinite number of terms ...
// that have a constant ratio between successive terms.
// E.g. Sum(a * r^x)[x: 0->k] = 1 + 1/2 + 1/4 + 1/8 + 1/16 + .... + 1/2^k with a = 1 and r = 1/2
#include <iostream>
#include <cmath>
using namespace std;

double geometricSum(int a, double r, int k) {
    // Base case
    if(k == 0) {
        return 1;
    }
    // Recursive
    double smallAns = geometricSum(a, r, k - 1);
    // Calculation
    return a * pow(r, k) + smallAns;
}
int main() {
    int a, k;
    double r;
    cout << "Coefficient a = ";
    cin >> a;
    cout << "\nCommon ratio r = ";
    cin >> r;
    cout << "\nExponent k = ";
    cin >> k;
    if (a >= 0 && k >= 0) {
        cout << endl << "geometricSum = " << geometricSum(a, r, k) << endl;
    }
    return 0;
}
