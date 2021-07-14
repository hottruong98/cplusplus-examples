#include <iostream>
using namespace std;

template <typename T>
class Queue {
    T* arr;
    int capacity;
    int nextIndex;
    int firstIndex;
    int sizeOfQueue;
    public:
        Queue() {
            capacity = 4;
            arr = new T[capacity];
            nextIndex = 0;
            firstIndex = -1;
            sizeOfQueue = 0;
        }
        Queue(int capacity) {
            this->capacity = capacity;
            arr = new T[this->capacity];
            nextIndex = 0;
            firstIndex = -1;
            sizeOfQueue = 0;
        }
        int size() {
            return sizeOfQueue;
        }
        bool empty() {
            return sizeOfQueue==0;
        }
        void push(T element) {
            if(sizeOfQueue==capacity) {
                cout << "Queue is full" << endl;
                return;
            }
            arr[nextIndex] = element;
            nextIndex = (nextIndex + 1) % capacity;
            if(firstIndex==-1) {
                firstIndex = 0;
            }
            sizeOfQueue++;
        }
        void pop() {
            if(empty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            firstIndex = (firstIndex + 1) % capacity;
            sizeOfQueue--;
            if(sizeOfQueue==0) {
                // Reset (optional)
                firstIndex = -1;
                nextIndex = 0;
            }
        }
        T front() {
            if(empty()) {
                cout << "Queue is empty" << endl;
                return 0;
            }
            return arr[firstIndex];
        }
};
int main() {
/*     Queue<int> q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60); // Full
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100); // Full
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl; // empty, 0
    q.pop(); // Empty
    cout << q.front() << endl; // empty, 0
    q.pop(); // empty

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60); // Full
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop(); */

    Queue<int> q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    cout<<q.front()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    q.push(60);
    q.push(70);

    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;

    return 0;
}