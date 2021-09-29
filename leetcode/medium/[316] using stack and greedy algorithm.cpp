#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string removeDuplicateLetters(string str) {
    string ans;
    unordered_map<char, int> remainingFreq;
    unordered_map<char, bool> isInStack;
    stack<char> myStack;

    int size = str.size();

    // Initialization
    for(int i = 0; i < size; i++) {
        remainingFreq[str[i]]++;
        isInStack[str[i]] = false;
    }

    // Lexicographical order: keep the smallest at bottom of stack
    if(size > 0) {
        myStack.push(str[0]);
        remainingFreq[str[0]]--;
        isInStack[str[0]] = true;
    }
    for(int i = 1; i < size; i++) {
        remainingFreq[str[i]]--;
        if(isInStack[str[i]]) {
            // Because in each step, we found an optimal piece of answer, ...
            // ... no need to consider a duplicate letter which is definitely ...
            // ... smaller or equal the top element in stack.
            continue;
        }
        // In stack, always keep the smaller letter beneath the bigger one, but if ...
        // ... the frequency of the letter is only 1, we must keep it.
        while(!myStack.empty() && str[i] < myStack.top() && remainingFreq[myStack.top()] > 0) {
            isInStack[myStack.top()] = false;
            myStack.pop();
        }
        myStack.push(str[i]);
        isInStack[str[i]] = true;
    }

    // Copy from stack to output
    while(!myStack.empty()) {
        ans += myStack.top();
        myStack.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    string input = "cbacdcbc";
    input = "bcabc";
    string output = removeDuplicateLetters(input);
    cout << output << endl;
    return 0;
}