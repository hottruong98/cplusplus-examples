// Question link: https://leetcode.com/problems/valid-parentheses/
#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool isValidString(string str) {
    stack<char> myStack;
    map<char, char> myPair;
    myPair['{'] = '}';
    myPair['['] = ']';
    myPair['('] = ')';
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(') {
            myStack.push(str[i]);
        }
        else {
            if(myStack.empty()) {
                return false;
            }
            char closeBracket = str[i];
            if(closeBracket == myPair[myStack.top()]) {
                myStack.pop();
            }
            else {
                return false;
            }
        }
    }
    return myStack.empty();
}
// Runtime: 0 ms, faster than 100% of C++ online submissions for Valid Parentheses.
// Memory Usage: 6.4 MB, less than 42.14% of C++ online submissions for Valid Parentheses.
int main() {
    string A = "([)]";
    cout << isValidString(A) << endl;
    string B = "{()}";
    cout << isValidString(B) << endl;
    return 0;
}