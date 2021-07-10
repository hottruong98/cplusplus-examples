// We can extend the capacity, 4 steps:
// 1. Create new array with double size
// 2. Copy data from old array to new one
// 3. Deallocate the old dynamic memory block
// 4. Point the old arr to the new arr
#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int nextIndex;
    int capacity;
    public:
        Stack() {
            capacity = 4;
            arr = new int[capacity];
            nextIndex = 0;
        }
        int size() {
            return nextIndex;
        }
        bool isEmpty() {
            return nextIndex==0;
        }
        void push(int element) {
            if(nextIndex == capacity) {
                int* newArr = new int[capacity*2];
                for(int i=0; i<capacity; i++) {
                    newArr[i] = arr[i];
                }
                delete[] arr;
                arr = newArr;
                capacity = capacity*2;
            }
            arr[nextIndex] = element;
            nextIndex++;
        }
        void pop() {
            if(isEmpty()) {
                cout << "Stack empty!" << endl;
                return;
            }
            nextIndex--;
        }
        int top() {
            if(isEmpty()) {
                cout << "Stack empty!" << endl;
                return -1;
            }
            return arr[nextIndex-1];
        }
};

int main() {
    Stack s;
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

    Stack s2;
    for(int i=0; i<10; i++) {
        s2.push(i);
    }
    while(!s2.isEmpty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    return 0;
}