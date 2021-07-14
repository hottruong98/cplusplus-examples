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
        int size() {
            return sizeOfQueue;
        }
        bool empty() {
            return sizeOfQueue==0;
        }
        void push(T element) {
            if(sizeOfQueue==capacity) {
                T* newArr = new T[capacity*2];
                for(int i=0; i<capacity; i++) {
                    newArr[i] = arr[(firstIndex + i) % capacity]; // Ex: cap=5, fI=3, nI=3 => 3-4-0-1-2
                }
                nextIndex = capacity;
                firstIndex = 0;
                delete[] arr;
                arr = newArr;
                capacity *= 2;
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
                nextIndex = 0;
                firstIndex = -1;
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
   Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << "size: " << q.size() << endl;
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
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
    cout << q.front() << endl; 
    q.pop(); 
    cout << q.front() << endl; 
    q.pop(); 
    cout << "size: " << q.size() << endl;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60); 
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << "size: " << q.size() << endl;
    return 0;
}