#include <iostream>
using namespace std;

int countZero(int n) {
    // Base case
    if(n == 0) {
        return 0;
    }
    // Recursive
    int smallAns = countZero(n / 10);
    // Calculation
    if(n % 10 == 0) {
        return smallAns + 1;
    }
    else {
        return smallAns;
    }
    
}
int main() {
    int n;
    cin >> n;
    cout << countZero(n) << endl;
    return 0;
}