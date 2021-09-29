#include <iostream>
#include <queue>
using namespace std;
void kSorted(int *arr, int size, int k) {
    int start = 0;
    int end = 0;
    priority_queue<int> myQueue;
    for(int i = 0; i < size; i++, start++) {
        while(end < size && end - start < k) {
            myQueue.push(arr[end]);
            end++;
        }
        arr[i] = myQueue.top();
        myQueue.pop();
    }
}
void kSorted2(int *arr, int size, int k) {
    priority_queue<int> myQueue;
    // O(klogk)
    for(int i = 0; i < k; i++) {
        myQueue.push(arr[i]);
    }
    int start = 0;
    // O((N-k)logk)
    for(int i = k; i < size; i++) {
        arr[start++] = myQueue.top();
        myQueue.pop();   
        myQueue.push(arr[i]);
    }
    // O(klogk)
    while(!myQueue.empty()) {
        arr[start++] = myQueue.top();
        myQueue.pop();
    }
}
int main() {
    int nums[] = {12, 7, 5, 9, 4};
    int k = 3;
    int size = sizeof(nums)/sizeof(int);
    kSorted(nums, size, k);
    for(int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
// Given a valid k-sorted array -> we can use max heap to sort that array with:
// T = O((N+k)logk) = O(Nlogk) = O(N) (k<<N)
// S = O(k) = O(1) (k is very small) 