#include <iostream>
#include <queue>
using namespace std;

int* kSmallest(int *input, int size, int k) {
    int *arr = new int[k]; // static int arr[constant]
    int index = 0;
    priority_queue<int> maxHeap;

    // O(logK)
    for(int i = 0; i < k; i++) {
        maxHeap.push(input[i]);
    }
    // O((N-K)logK)
    for(int i = k; i < size; i++) {
        if(maxHeap.top() > input[i]) {
            maxHeap.pop();
            maxHeap.push(input[i]);
        }
    }
    // O(KlogK)
    while(!maxHeap.empty()) {
        arr[index++] = maxHeap.top();
        maxHeap.pop();
    }
    return arr;
}
int* kSmallest2(int *input, int size, int k) {
    priority_queue<int> maxHeap;
    int *arr = new int[k];
    int index = 0;

    for(int i = 0; i < size; i++) {
        maxHeap.push(input[i]);
        if(maxHeap.size() > k) { // maintain the size of maximum priority queue
            maxHeap.pop();
        }
    }
    while(!maxHeap.empty()) {
        arr[index++] = maxHeap.top();
        maxHeap.pop();
    }
    return arr;
}
int main() {
    int nums[] = {8, 5, 12, 10, 0, 1, 6, 9};
    int size = sizeof(nums)/sizeof(int);
    int k = 4;
    int *smallest = kSmallest2(nums, size, k);
    for(int i = 0; i < k; i++) {
        cout << smallest[i] << " ";
    }
    cout << endl;
    return 0;
}
// Instead of sorting the array first with O(NlogN), we use max heap to solve the problem:
// T = O(NlogK) = O(N) (k << N)
// S = O(k) = O(1)
// But if we use minimum priority queue, T = O(NlogN) and S = O(N)