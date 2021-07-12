// Use template to create generic stack
#include <iostream>
using namespace std;

template <typename T>
class Stack {
    T* arr;
    int nextIndex;
    int capacity;
    public:
        Stack() {
            capacity = 4;
            arr = new T[capacity];
            nextIndex = 0;
        }
        int size() {
            return nextIndex;
        }
        bool isEmpty() {
            return nextIndex==0;
        }
        void push(T element) {
            if(nextIndex==capacity) {
                T* newArr = new T[capacity*2];
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
                cout << "Stack is empty" << endl;
                return;
            }
            nextIndex--;
        }
        T top() {
            if(isEmpty()) {
                cout << "Stack is empty" << endl;
                return 0; //return 0 instead of -1(int) b/c 0 can be int|double|char|bool|NULL(pointer)
            }
            return arr[nextIndex-1];
        }
};
int main() {
    Stack<double> s;
    s.push(3.14159); //pi
    s.push(2.71828); //e
    s.push(1.64872); //sqrt(e)
    s.push(1.41421); //sqrt(2)
    s.push(1.73205); //sqrt(3)

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}