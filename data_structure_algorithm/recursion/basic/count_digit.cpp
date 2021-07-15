// Count digit of number 4732:
// Separate the last digit and solve the rest
// e.g. "473"|2 (3) <- "47"|3 (2) <- "4"|7 (1) <- ""|4 (0) => (3) + 1 = 4 digits
#include <iostream>
using namespace std;
int coutDigit(int n) {
    if(n == 0) {
        return 0;
    }
    int smallAns = coutDigit(n/10);
    return  smallAns + 1;
}
int main() {
    int n;
    cin >> n;
    if (n >= 0) {
        cout << coutDigit(n) << " digits" << endl;
    }
    return 0;
}