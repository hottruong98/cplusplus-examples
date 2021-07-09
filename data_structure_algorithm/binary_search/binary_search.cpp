#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0, end = size - 1;
    while(start <= end) {
        int mid = (start + end)/2;

        if(arr[mid] == key) {
            return mid;
        }
        else {
            if(arr[mid] > key) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
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
    int pos = binarySearch(arr, size, key);
    if(pos == -1) {
        cout << "\nKey not found" << endl;
    }
    else {
        cout << "\nKey found at index " << pos << endl;
    }
    return 0;
}