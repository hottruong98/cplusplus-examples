#include <iostream>
using namespace std;

int lastIndex(const int *arr, int size, int element, int index) {
    if(index == size) {
        return -1;
    }
    return arr[index] == element? index : lastIndex(arr, size, element, index + 1);
}
int main() {
    int A[5] = {3, 5, 5, 2, 7};
    int B[0] = {};
    int element;
    cout << "Enter the element you wanna check: ";
    cin >> element;
    cout << "\nThe first index of that element in array A? " << lastIndex(A, 5, element, 0);
    cout << "\nThe first index of that element in array B? " << lastIndex(B, 0, element, 0);
    cout << endl;
    return 0;
}