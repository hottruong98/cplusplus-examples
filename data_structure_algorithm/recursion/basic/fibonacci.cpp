// Find the fibonacci number given its order in the Fibonacci sequence
#include <iostream>
using namespace std;

int fibonacci(int n) {
    // 1. Base case
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    // 2. Recursive case
    int smallerOutput1 = fibonacci(n - 1);
    int smallerOutput2 = fibonacci(n - 2);
    // 3. Calculation
    return smallerOutput1 + smallerOutput2;
}
int main() {
    int n; // n is the order of the number in the Fibonacci sequence starting from 0
    cin >> n;
    int ans;
    if (n >= 0) {
        ans = fibonacci(n);
        cout << "Fibonacci number at " << n << "th is " << ans << endl;
    }
    else {
        cout << "n should be >= 0" << endl;
    }
    return 0;
}