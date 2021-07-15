#include <iostream>
using namespace std;
int fact(int n) {
    cout << "n = " << n << endl;
    if(n < 0) {
        return -1;
    }
    // 1. Base case
    if(n == 0) {
        return 1;
    }
    // 2. Assume it will work for smaller problems
    int smallerAns = fact(n-1);
    // 3. The bigger problem
    int ans = n * smallerAns;
    return ans;
}
int main() {
    int n;
    cin >> n;
    int ans = fact(n);
    cout << "ans = " << ans << endl;
    return 0;
}