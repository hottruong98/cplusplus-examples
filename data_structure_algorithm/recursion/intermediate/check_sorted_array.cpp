#include <iostream>
using namespace std;

bool isSorted(const int *arr, int size) {
    if(size == 0 || size == 1) {
        return true;
    }
    if(arr[0] <= arr[1]) {
        return isSorted(arr + 1, size - 1);
    }
    else {
        return false;
    }
}
bool isSorted2(const int arr[], int size) {
    if(size == 0 || size == 1) {
        return true;
    }
    bool isSmallerSorted = isSorted2(arr + 1, size - 1);
    if(!isSmallerSorted) {
        return false;
    }
    return arr[0] <= arr[1];
}
bool isSorted3(const int *arr, int size) {
    if(size == 0 || size == 1) {
        return true;
    }
    if(arr[size - 2] >= arr[size - 1]) {
        return false;
    }    
    return isSorted3(arr, size - 1);
}
int main() {
    int A[5] = {3, 5, 1, 2, 7};
    int B[7] = {5, 6, 7, 8, 9, 10, 11};
    cout << "Is A sorted? " << isSorted3(A, 5) << endl;
    cout << "Is B sorted? " << isSorted3(B, 7) << endl;
    return 0;
}