#include <iostream>
using namespace std;
void printAllIndex(const int *arr, int size, int element) {
    if(size == 0) {
        return;
    }
    printAllIndex(arr, size - 1, element);
    if(arr[size - 1] == element) {
        cout << size - 1 << " ";
    }
}
int main() {
    int A[] = {1, 2, 4, 7, 3, 5, 6, 7, 0, 1};
    int B[] = {};
    int element;
    cout << "Enter the element you wanna check: ";
    cin >> element;
    cout << "\nAll index of the element in A: ";
    printAllIndex(A, 10, element);
    cout << "\nAll index of the element in B: ";
    printAllIndex(B, 0, element);
    cout << endl;
    return 0;
}