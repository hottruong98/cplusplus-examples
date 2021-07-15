// n = 12345 => sumOfDigit(n) = sumOfDigit(1234) + 5
#include <iostream>
using namespace std;
int sumOfDigit(int n) {
    // Base case
    if(n == 0) {
        return 0;
    }
    // Recursive
    int smallAns = sumOfDigit((n / 10));
    // Calculation
    int lastDigit = n % 10;
    return smallAns + lastDigit;
}
int main() {
    int n;
    cin >> n;
    if(n >= 0) {
        cout << sumOfDigit(n) << endl;
    }
    return 0;
}