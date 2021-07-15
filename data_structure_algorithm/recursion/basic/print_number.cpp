#include <iostream>
using namespace std;

void printSequence(int n) {
    // Base case
    if(n == 0) {
        return;
    }
    // Recursive
    printSequence(n - 1);
    //
    cout << n << " ";
}
void printReverseSequence(int n) {
    if(n == 0) {
        return;
    }
    cout << n << " ";
    printReverseSequence(n - 1);
}
int main() {
    int n;
    cin >> n;
    if (n >= 0) {
        cout << "Print a sequence from 1 to " << n << endl;
        printSequence(n);
        cout << endl;
        cout << "Print a sequence from " << n << " to 1" << endl;
        printReverseSequence(n);
    }
    return 0;
}