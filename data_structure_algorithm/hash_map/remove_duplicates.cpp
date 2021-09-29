#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> removeDuplicates(int *arr, int size) {
    vector<int> output;
    unordered_map<int, bool> myMap;
    for(int i = 0; i < size; i++) {
        if(myMap.count(arr[i]) == 0) {
            myMap[arr[i]] = true;
            output.push_back(arr[i]);
        }
    }
    return output;
}
int main() {
    int arr[] = {2, 1, 3, 2, 1, 5, 4, 1, 3};
    vector<int> output = removeDuplicates(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << "|";
    }
    cout << endl;
    return 0;
}