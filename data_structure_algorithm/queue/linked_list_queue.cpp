#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node* next;
        Node(T data) {
            this->data = data;
            next = NULL;
        }
};
template <typename T>
class Queue {
    Node<T>* head;
    Node<T>* tail;
    int sizeOfQueue;
    public:
        Queue() {
            head = NULL;
            tail = NULL;
            sizeOfQueue = 0;
        }
        int size() {
            return sizeOfQueue;
        }
        bool empty() {
            return sizeOfQueue==0;
        }
        void push(T element) {
            Node<T>* newNode = new Node<T>(element);
            if(head==NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
            sizeOfQueue++;
        }
        void pop() {
            if(empty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            Node<T>* oldHead = head;
            head = head->next;
            oldHead->next = NULL;
            delete oldHead;
            sizeOfQueue--;
        }
        T front() {
            if(empty()) {
                cout << "Queue is empty" << endl;
                return 0;
            }
            return head->data;
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