// sumArray(arr) = arr[0]+a[1]+...+arr[size-1] = arr[0]+sumArray(smaller arr)
#include <iostream>
using namespace std;

int sumArray(const int *arr, int size) {
    if(size == 0) {
        return 0;
    }
    return arr[0] + sumArray(arr + 1, size - 1);
}
int sumArray2(const int *arr, int size) {
    if(size == 0) {
        return 0;
    }
    return arr[size - 1] + sumArray2(arr, size - 1);
}
// Calculate sum of array from the index
int sumArray3(const int *arr, int size, int index) {
    if(index == size) {
        return 0;
    }
    return arr[index] + sumArray3(arr, size, index + 1);
}
int main() {
    int A[5] = {3, 5, 1, 2, 7};
    int B[0] = {};
    cout << "sum of A = " << sumArray(A, 5) << endl;
    cout << "sum of A = " << sumArray2(A, 5) << endl;
    cout << "sum of A = " << sumArray3(A, 5, 0) << endl;
    cout << "sum of B = " << sumArray(B, 0) << endl;
    cout << "sum of B = " << sumArray2(B, 0) << endl;
    cout << "sum of B = " << sumArray3(B, 0, 0) << endl;    
    return 0;
}