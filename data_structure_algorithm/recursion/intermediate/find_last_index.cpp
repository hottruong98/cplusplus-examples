#include <iostream>
using namespace std;
// Simply, just check one by one index from right to left
int lastIndex(const int *arr, int size, int element, int index) {
    if(index == -1) {
        return -1;
    }
    return arr[index] == element? index : lastIndex(arr, size, element, index - 1);
}
// No need to use the index variable
int lastIndex2(const int *arr, int size, int element) {
    if(size == 0) {
        return -1;
    }
    return arr[size - 1] == element? (size - 1) : lastIndex2(arr, size - 1, element); 
}
// We can check from left to right, compare the valid index in the right array with the left valid index
int lastIndex3(const int *arr, int size, int element, int index) {
    if(index == size) {
        return -1;
    }
    int smallAns = lastIndex3(arr, size, element, index + 1);
    if(smallAns != -1) {
        return smallAns;
    }
    else {
        return arr[index] == element? index : -1;
    }
}
int main() {
    int A[5] = {3, 5, 5, 2, 7};
    int B[0] = {};
    int element;
    cout << "Enter the element you wanna check: ";
    cin >> element;
    cout << "\nThe last index of that element in array A? " << lastIndex(A, 5, element, 4);
    cout << "\nThe last index of that element in array A? " << lastIndex2(A, 5, element);
    cout << "\nThe last index of that element in array A? " << lastIndex3(A, 5, element, 0);
    cout << "\nThe last index of that element in array B? " << lastIndex(B, 0, element, 0);
    cout << "\nThe last index of that element in array B? " << lastIndex2(B, 0, element);
    cout << endl;
    return 0;
}