// 1. Print and reverse print with character array using recursion
// 2. Calculate length of a character array using recursion
#include <iostream>
using namespace std;

template <typename T>
void print(const T *arr, int size) {
    if(size == 0) {
        return;
    }
    cout << arr[0] << " ";
    print(arr + 1, size - 1);
}
// No need size input
void printChar(const char arr[]) { // const char arr[] <=> const char *arr != const char &arr
    if(arr[0] == '\0') {
        return;
    }
    cout << arr[0] << " ";
    printChar(arr + 1);
}

template <typename T>
void revPrint(const T *arr, int size) {
    if(size == 0) {
        return;
    }
    cout << arr[size - 1] << " ";
    revPrint(arr, size - 1);
}
// No need size input
void revPrintChar(const char arr[]) {
    if(arr[0] == '\0') {
        return;
    }
    revPrintChar(arr + 1);
    cout << arr[0] << " ";
}
int lengthOfChar(const char *arr) {
    if(arr[0] == '\0') {
        return 0;
    }
    return 1 + lengthOfChar(arr + 1);
}
int main() {
    char arr[] = "recursion with character array";
    print(arr, sizeof(arr)/sizeof(char) - 1);
    cout << endl;
    revPrint(arr, sizeof(arr)/sizeof(char) - 1);
    cout << endl;

    printChar(arr);
    cout << endl;
    revPrintChar(arr);
    cout << endl;

    int length = lengthOfChar(arr);
    cout << length << endl;
    return 0;
}