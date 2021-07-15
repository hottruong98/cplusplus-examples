#include <iostream>
using namespace std;

double pow(int base, int exponent) {
    // Base case
    if(exponent == 0) {
        return 1;
    }
    // Deal with negative exponent
    if(exponent < 0) {
        return 1/pow(base, - exponent); // x^(-n) = 1/x^n
    }
    // Recursive + calculation
    if(exponent > 0) {
        return base * pow(base, exponent - 1); // x^n = x*x^(n-1)
    }
}
int main() {
    int base;
    cin >> base;
    int exponent;
    cin >> exponent;
    double ans = pow(base, exponent);
    cout << base << "^" << exponent << " = " << ans << endl;
    return 0;
}