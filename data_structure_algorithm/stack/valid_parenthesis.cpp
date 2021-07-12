// Question link: https://leetcode.com/problems/valid-parentheses/
#include <iostream>
#include <stack>
using namespace std;
bool isValidString(string str) {
    stack<char> myStack;
    for(int i=0; i<str.length(); i++) {
        if(str[i]=='{' || str[i]=='[' || str[i]=='(') {
            myStack.push(str[i]);
        }
        else {
            if(myStack.empty()) {
                return false;
            }
            switch(str[i]) {
                case '}':
                    if(myStack.top()=='{') {
                        myStack.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                case ']':
                    if(myStack.top()=='[') {
                        myStack.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                case ')':
                    if(myStack.top()=='(') {
                        myStack.pop();
                    }
                    else {
                        return false;
                    }
                    break;
            }
        }
    }
    return myStack.empty();
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 6.3 MB, less than 42.14% of C++ online submissions for Valid Parentheses.
int main() {
    string A = "([)]";
    cout << isValidString(A) << endl;
    string B = "{()}";
    cout << isValidString(B) << endl;
    return 0;
}