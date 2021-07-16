// Given A[] = {5,5,6,5,6} => countOccurrence(A, 5) = 3 and countOccurrence(A, 6) = 2;
#include <iostream>
using namespace std;
int countOccurrence(const int *arr, int size, int element) {
    if(size == 0) {
        return 0;
    }
    if(arr[0] == element) {
        return 1 + countOccurrence(arr + 1, size - 1, element);
    }
    else {
        return countOccurrence(arr + 1, size - 1, element);
    }
}
int countOccurrence2(const int *arr, int size, int element, int &count) {
    if(size == 0) {
        return 0;
    }
    if(arr[0] == element) {
        count++;
    }
    int smallAns = countOccurrence2(arr + 1, size - 1, element, count);
    return count;
}
int main() {
    int A[] = {1, 2, 4, 7, 3, 5, 6, 7, 0, 1};
    int B[] = {};
    int element;
    cout << "Enter the element you wanna check: ";
    cin >> element;
    cout << "\nOccurrence of the element in A: " << countOccurrence(A, 10, element);
    cout << "\nOccurrence of the element in B: " << countOccurrence(B, 0, element);
    cout << endl;
    int count = 0;
    cout << "Occurrence of the element in A: " << countOccurrence2(A, 10, element, count) << endl;
    return 0;  
}