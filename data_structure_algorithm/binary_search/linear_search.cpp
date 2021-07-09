#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for(int i=0; i<size; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}
int main() {
    cout << "Enter size of array: ";
    int size;
    cin >> size;
    int arr[size];
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }
    cout << "\nEnter the key: ";
    int key;
    cin >> key;
    int pos = linearSearch(arr, size, key);
    if(pos == -1) {
        cout << "\nKey not found" << endl;
    }
    else {
        cout << "\nKey found at index " << pos << endl;
    }
    return 0;
}