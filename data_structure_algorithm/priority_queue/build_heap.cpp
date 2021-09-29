#include <iostream>
#include <queue>
using namespace std;

void toMaxHeap(int *arr, int size) {
    int start = size/2 - 1;
    for(int i = start; i >= 0; i--) {
        int parentIndex = i;
        while(true) {
            int leftChildIndex = 2*parentIndex + 1;
            int rightChildIndex = 2*parentIndex + 2;
            int maxIndex = parentIndex;
            if(leftChildIndex < size && arr[leftChildIndex] > arr[maxIndex]) {
                maxIndex = leftChildIndex;
            }
            if(rightChildIndex < size && arr[rightChildIndex] > arr[maxIndex]) {
                maxIndex = rightChildIndex;
            }
            if(maxIndex == parentIndex) {
                break;
            }
            swap(arr[parentIndex], arr[maxIndex]);
            parentIndex = maxIndex;
        }
    }
}

void toMinHeap(int *arr, int size) {
    int start = size/2 - 1;
    for(int i = start; i >= 0; i--) {
        int parentIndex = i;
        while(true) {
            int leftChildIndex = 2*parentIndex + 1;
            int rightChildIndex = 2*parentIndex + 2;
            int minIndex = parentIndex;
            if(leftChildIndex < size && arr[leftChildIndex] < arr[minIndex]) {
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < size && arr[rightChildIndex] < arr[minIndex]) {
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex) {
                break;
            }
            swap(arr[parentIndex], arr[minIndex]);
            parentIndex = minIndex;
        }
    }
}

int main() {
    int nums[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int size = sizeof(nums)/sizeof(int);

    priority_queue<int> maxHeap(nums, nums+size);
    cout << maxHeap.top() << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap(nums, nums+size);
    cout << minHeap.top() << endl;
    
    toMaxHeap(nums, size);
    for(int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
// T = O(n)
// S = O(1)