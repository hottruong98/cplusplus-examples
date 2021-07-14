/* Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
Input: s = "abbaca"
Output: "ca"
Input: s = "azxxzy"
Output: "ay" */
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
string removeDuplicates(string str) { // This code is good but the below ones are better
    stack<char> myStack;
    string result = "";
    for(const char& ch : str) {
        if(myStack.empty() || ch != myStack.top()) {
            myStack.push(ch);
        }
        else {
            myStack.pop();
        }
    }
    while(!myStack.empty()) {
        result.push_back(myStack.top());
        myStack.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
string removeDuplicatesWithoutStack(string str) {
    int size = 0;
    for(int i=0; i<str.length(); i++, size++) {
        str[size] = str[i];
        if(size>0 && str[size]==str[size-1]) {
            size -= 2;
        }
    }
    return str.substr(0,size);
}
string simulateStack(string str) { // Use this code for optimization instead of stack
    int ptrStack = -1; // Stack pointer
    string result = "";
    for(int i=0; i<str.size(); i++) {
        if(ptrStack == -1 || str[i] != str[ptrStack]) {
            ptrStack++;
            str[ptrStack] = str[i];
        }
        else {
            ptrStack--;
        }
    }
    for(int i=0; i<=ptrStack; i++) {
        result.push_back(str[i]);
    }
    return result;
}
int main() {
    string s = "azxxzy";
    cout << removeDuplicates(s) << endl;
    cout << removeDuplicatesWithoutStack(s) << endl;
    cout << simulateStack(s) << endl;
    return 0;
}