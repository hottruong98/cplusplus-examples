// Problem link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
#include <iostream>
#include <vector>
#include <stack>
#include <cctype>
using namespace std;

bool isNumber(const string& str) {
    int sign = 0;
    for(const char& ch : str) {
        if(str[0] == '-' && sign == 0 && str.size()>1) {
            sign = 1;
            continue;
        }
        if(!isdigit(ch)) {
            return false;
        }
    }
    return true;
}
int evalRPN(vector<string>& tokens) {
    stack<int> myStack;
    int operandA;
    int operandB;
    int result;
    for(int i=0; i<tokens.size(); i++) {
        if(isNumber(tokens[i])) {
            int num = stoi(tokens[i]);
            if(num) {
                myStack.push(num);
            }
            else {
                return -1;
            }    
        }
        else {
            if(myStack.size()<2) {
                return -1;
            }
            operandB = myStack.top();
            myStack.pop();
            operandA = myStack.top();
            myStack.pop();
            switch(tokens[i][0]) {
                case '+':
                    result = operandA + operandB;
                    break;
                case '-':
                    result = operandA - operandB;
                    break;
                case '*':
                    result = operandA * operandB;
                    break;
                case '/':
                    result = operandA / operandB;
                    break;                    
            }
            myStack.push(result);
        }
    }
    return myStack.size()==1?result:-1;
}

int evalRPN2(vector<string>& tokens) {
    stack<int> myStack;
    int operandA;
    int operandB;
    int result;
    for(int i=0; i<tokens.size(); i++) {
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            operandB = myStack.top();
            myStack.pop();
            operandA = myStack.top();
            myStack.pop();
            switch(tokens[i][0]) {
                case '+':
                    result = operandA + operandB;
                    break;
                case '-':
                    result = operandA - operandB;
                    break;
                case '*':
                    result = operandA * operandB;
                    break;
                case '/':
                    result = operandA / operandB;
                    break;                    
            }
            myStack.push(result);
        }
        else {
            myStack.push(stoi(tokens[i]));
        }
    }
    return myStack.top();
}
int main()
{
    vector<string> postfix {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalRPN(postfix) << endl;
    return 0;
}