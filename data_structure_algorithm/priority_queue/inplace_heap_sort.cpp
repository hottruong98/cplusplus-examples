#include <iostream>
#include <vector>
using namespace std;


void heapSort(vector<int> &nums) {
    int size = nums.size();
    int parentIndex = 0;
    for(int i = 1; i < size; i++) {
        int childIndex = i;
        while(childIndex > 0) {
            parentIndex = (childIndex-1)/2;
            if(nums[childIndex] < nums[parentIndex]) {
                swap(nums[parentIndex], nums[childIndex]);
                childIndex = parentIndex;
            }
            else {
                break;
            }
        }
    }
    while(size >= 1) {
        swap(nums[0], nums[size - 1]);
        size--;
        parentIndex = 0;
        int minIndex = parentIndex;
        while(true) {
            int leftChildIndex = 2*parentIndex + 1;
            int rightChildIndex = 2*parentIndex + 2;
            if(leftChildIndex < size && nums[leftChildIndex] < nums[minIndex]) {
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < size && nums[rightChildIndex] < nums[minIndex]) {
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex) {
                break;
            }
            swap(nums[parentIndex], nums[minIndex]);
            parentIndex = minIndex;
        }
    }
}

int main() {
    vector<int> nums = {10, 5, 8, 1, 4};
    nums = {100, 10, 15, 4, 17, 21, 67};
    heapSort(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

// T = O(NlogN)
// S = O(1) -> instead of building a separate data structure, ...
// we could use the same array