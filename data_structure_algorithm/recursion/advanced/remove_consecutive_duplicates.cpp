// Input: aabbbcdda -> abcda
// Input: abcbd -> abcbd
#include <iostream>
using namespace std;

void removeDuplicates(char *arr) {
    if(arr[0] == '\0') {
        return;
    }
    if(arr[0] == arr[1]) {
        for(int i = 1; arr[i] != '\0'; i++) {
            arr[i] = arr[i + 1];
        }
        removeDuplicates(arr);
    }
    else {
        removeDuplicates(arr + 1);
    }
}
int main() {
    char arr[100];
    cout << "Enter character array: ";
    cin >> arr;
    removeDuplicates(arr);
    cout << "\nAfter removing consecutive duplicates: " << arr << endl;
    return 0;
}
