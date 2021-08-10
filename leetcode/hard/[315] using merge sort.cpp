#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void mergeSort(vector<pair<int, int>> &input, vector<int> &counter, int left, int right);
    void merge(vector<pair<int, int>> &input, vector<int> &counter, int left, int right);
    public:
        vector<int> countSmaller(vector<int>& nums) {
            int size = nums.size();
            vector<int> counter(size, 0);
            vector<pair<int, int>> valueAndIndex;
            for(int i = 0; i < size; i++) {
                valueAndIndex.push_back(pair<int, int>(nums[i], i));
            }
            mergeSort(valueAndIndex, counter, 0, size - 1);
            return counter;
        }
};
void Solution::mergeSort(vector<pair<int, int>> &input, vector<int> &counter, int left, int right) {
    if(left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(input, counter, left, mid);
    mergeSort(input, counter, mid + 1, right);
    merge(input, counter, left, right);
}
void Solution::merge(vector<pair<int, int>> &input, vector<int> &counter, int left, int right) {
    vector<pair<int,int>> temp(right - left + 1, pair<int, int>(0, 0));
    int mid = (left + right) / 2;
    int tempIndex = 0;
    int leftIndex = left;
    int rightIndex = mid + 1;
    // Descending sort
    while(leftIndex <= mid && rightIndex <= right) {
        if(input[leftIndex].first > input[rightIndex].first) {
            // If an element[i] in the left array is greater than an element[j] in the right array,
            // it is also greater than all elements[>j] in the right array because we are sorting
            // in DESCENDING order.
            // Why not ascending sort? Because we're counting smaller elements on the right side,
            // and we did call recursion on the left part of the array first. Then if we implement
            // ascending sort, we have to use a loop instead of a command, it will cost much time.
            counter[input[leftIndex].second] += right - rightIndex + 1;
            temp[tempIndex++] = input[leftIndex++];
        }
        else {
            temp[tempIndex++] = input[rightIndex++];
        }
    }
    while(leftIndex <= mid) {
        temp[tempIndex++] = input[leftIndex++];
    }
    while(rightIndex <= right) {
        temp[tempIndex++] = input[rightIndex++];
    }
    for(int i = left; i <= right; i++) {
        input[i] = temp[i - left];
    }
}

int main() {
    vector<int> nums = {1, -1, 8, -3, 0, 6, 11, 4, 7, 10, 13, 2, 5, 12, 23};
    nums = {-1, 5, 2, 1, 0, 2, -3, -1};
    nums = {1, 3, 1, 1, 0, 2, 9, 7, 3, 5, -1, 8, 11, 3, 2, 1, 4, 1, 3, 5, 17, 10, 12, 24, 0, 23, 15, -8, 0};
    vector<int> output;
    Solution mySolution;
    output = mySolution.countSmaller(nums);
    int size = output.size();
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}
// Average runtime on Leetcode: 500 ms
// Average memory on Leetcode: 216 MB
// Time complexity: T(n) = n.log(n)