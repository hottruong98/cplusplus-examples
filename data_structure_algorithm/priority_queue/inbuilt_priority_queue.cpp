#include <iostream>
#include <queue>
using namespace std;

int main() {
    vector<int> nums = {100, 10, 15, 4, 17, 21, 67};

    priority_queue<int> maxHeap; // Max heap
    for(int i = 0; i < nums.size(); i++) {
        maxHeap.push(nums[i]);
    }
    cout << "size: " << maxHeap.size() << endl;
    cout << "Max: " << maxHeap.top() << endl;
    cout << "Descending order: ";
    while(!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << "\n--------------\n";

    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap
    for(int i = 0; i < nums.size(); i++) {
        minHeap.push(nums[i]);
    }
    cout << "size: " << minHeap.size() << endl;
    cout << "Min: " << minHeap.top() << endl;
    cout << "Ascending order: ";
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << "\n--------------\n";

    priority_queue<int> minHeap2; // Min heap based on max heap
    for(int i = 0; i < nums.size(); i++) {
        minHeap2.push(-1*nums[i]);
    }
    cout << "size: " << minHeap2.size() << endl;
    cout << "Min: " << -1*minHeap2.top() << endl;
    cout << "Ascending order: ";
    while(!minHeap2.empty()) {
        cout << -1*minHeap2.top() << " ";
        minHeap2.pop();
    }
    cout << "\n--------------\n";
    return 0;
}
