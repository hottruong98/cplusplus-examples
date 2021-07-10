#include <iostream>
using namespace std;

class Stack {
    int* arr; // We gonna create a dynamic array cuz we don't know the size of stack
    int nextIndex;
    int capacity;
    public: 
        Stack() {
            capacity = 4;
            arr = new int[capacity];
            nextIndex = 0;
        }
        Stack(int capacity) { 
            this->capacity = capacity;
            arr = new int[this->capacity]; 
            nextIndex = 0;
        }
        // Return the number of elements present in stack
        int size() {
            return nextIndex;
        }
        bool isEmpty() {
            return nextIndex==0;
        }
        void push(int element) {
            if(nextIndex == capacity) {
                cout << "Full stack" << endl;
                return;
            }
            arr[nextIndex] = element;
            nextIndex++;
        }
        void pop() {
            if(isEmpty()) {
                cout << "Stack empty" << endl;
                return;
            }
            nextIndex--;
        }
        int top() {
            if(isEmpty()) {
                cout << "Stack empty" << endl;
                return -1;
            }
            return arr[nextIndex-1];
        }
};
int main() {
    Stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.size() << endl;
    cout << s.isEmpty() << endl;

    Stack s2(10);
    for(int i=0; i<10; i++) {
        s2.push(i);
    }
    while(!s2.isEmpty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    return 0;
}