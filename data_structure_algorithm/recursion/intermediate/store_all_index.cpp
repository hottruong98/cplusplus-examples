// Store all the position of the element to an array or vector
#include <iostream>
#include <vector>
using namespace std;
// Pass by reference
void saveAllIndex(const int *arr, int size, int element, vector<int> &position) {
    if(size == 0) {
        return;
    }
    saveAllIndex(arr, size - 1, element, position);
    if(arr[size - 1] == element) {
        position.push_back(size - 1);
    }
}
// Pass by pointer
void saveAllIndex2(const int *arr, int size, int element, vector<int> *ptrPosition) {
    if(size == 0) {
        return;
    }
    saveAllIndex2(arr, size - 1, element, ptrPosition);
    if(arr[size - 1] == element) {
        ptrPosition->push_back(size - 1);
    }
}
// Using array
int getAllIndexUsingArray(const int *arr, int size, int element, int *ptrIndexArray) {
    if(size == 0) {
        return 0;
    }
    if(arr[size - 1] == element) {
        *ptrIndexArray = size - 1;
        return 1 + getAllIndexUsingArray(arr, size - 1, element, ptrIndexArray + 1);
    }
    else {
        return getAllIndexUsingArray(arr, size - 1, element, ptrIndexArray);
    }
}
int main() {
    int A[] = {1, 2, 4, 7, 3, 5, 6, 7, 0, 1};
    int B[] = {};
    int element;
    cout << "Enter the element value: ";
    cin >> element;
    vector<int> position;

    // Pass by reference
    saveAllIndex(A, 10, element, position);
    cout << "\nAll the position of the element in A: ";
    for(int i=0; i<position.size(); i++) {
        cout << position.at(i) << " ";
    }

    position.clear();
    // Pass by pointer
    saveAllIndex2(A, 10, element, &position);
    cout << "\nAll the position of the element in A: ";
    for(int i=0; i<position.size(); i++) {
        cout << position.at(i) << " ";
    }

    // Using array
    int indexArray[10];
    int sizeOfArray = getAllIndexUsingArray(A, 10, element, indexArray);
    cout << "\nAll the position of the element in A: ";
    for(int i=0; i<sizeOfArray; i++) {
        cout << indexArray[i] << " ";
    }
    cout << endl;

    return 0;
}