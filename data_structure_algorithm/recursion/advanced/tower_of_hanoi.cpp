// Given n disks, count the no. of steps to take n disks from A to C with helper B 
// Tower of hanoi law: only 1 disk/step & smaller disk must be on the bigger one
// Total (2^n - 1) steps in mathematics
// 1. move n-1 disks from A to helper B
// 2. move the largest disk from A to destination C
// 3. move n-1 disks from helper B to destination C
// Recursion: f(n) = f(n-1) + 1 + f(n-1) 
#include <iostream>
using namespace std;
int countSteps(int n) {
    if(n == 0) {
        return 0;
    }
    return countSteps(n - 1) + 1 + countSteps(n - 1);
}
void printSteps(int n, string source, string helper, string destination) {
    if(n == 0) {
        return;
    }
    printSteps(n - 1, source, destination, helper); // Move n-1 disks from source to helper
    // Move the largest disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl; 
    printSteps(n - 1, helper, source, destination); // Move n-1 disks from helper to destination
}
int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    cout << "Number of steps: " << countSteps(n) << endl;
    printSteps(n, "A", "B", "C");
    return 0;
}