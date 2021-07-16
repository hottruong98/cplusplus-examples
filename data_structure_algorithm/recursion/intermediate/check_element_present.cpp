#include <iostream>
using namespace std;
// Firstly, check the first index, if it returns false then check the small array
bool isPresent(const int *arr, int size, int element) {
    if(size == 0) {
        return false;
    }
    if(arr[0] == element) {
        return true;
    }
    return isPresent(arr + 1, size - 1, element);
}
// Firstly, check the small array, if it returns false then check the left index
bool isPresent2(const int *arr, int size, int element) {
    if(size == 0) {
        return false;
    }
    bool smallerAns = isPresent2(arr + 1, size - 1, element);
    return smallerAns? true : (arr[0] == element);
}
// Check from the last index
bool isPresent3(const int *arr, int size, int element) {
    if(size == 0) {
        return false;
    }
    if(arr[size - 1] == element) {
        return true;
    }
    return isPresent3(arr, size - 1, element);
}
// Check all the array but one by one index
bool isPresent4(const int *arr, int size, int element, int index) {
    if(index == size) {
        return false;
    }
    return arr[index] == element? true : isPresent4(arr, size, element, index + 1);
}
int main() {
    int A[5] = {3, 5, 1, 2, 7};
    int B[0] = {};
    int element;
    cout << "Enter the element you wanna check: ";
    cin >> element;
    cout << "\nIs the element present in array A? " << isPresent(A, 5, element);
    cout << "\nIs the element present in array A? " << isPresent2(A, 5, element);
    cout << "\nIs the element present in array A? " << isPresent3(A, 5, element);
    cout << "\nIs the element present in array A? " << isPresent4(A, 5, element, 0);
    cout << "\nIs the element present in array B? " << isPresent(B, 0, element);
    cout << "\nIs the element present in array B? " << isPresent2(B, 0, element);
    cout << "\nIs the element present in array A? " << isPresent3(B, 0, element);  
    cout << "\nIs the element present in array B? " << isPresent4(B, 0, element, 0) << endl;
    return 0;
}