// m * n = m + (m + m + ... + m) n-1 times
#include <iostream>
using namespace std;

int multiply(int m, int n) {
    // Base case
    if(n == 0 || m == 0) {
        return 0;
    }
    // Recursive and calculation
    if(m > 0 && n > 0) {
        int smallAns = multiply(m, n - 1);
        return m + smallAns;
    }
    // Convert other cases to the problem with 2 positive inputs
    if(m < 0 && n < 0) {
        return multiply(-m, -n);
    }
    if(m < 0 && n > 0) {
        return -multiply(-m, n);
    }
    if(m > 0 && n < 0) {
        return -multiply(m, -n);
    }
}
int main() {
    int m, n;
    cin >> m >> n;
    cout << m << " * " << n << " = " << multiply(m, n) << endl;
    return 0;
}