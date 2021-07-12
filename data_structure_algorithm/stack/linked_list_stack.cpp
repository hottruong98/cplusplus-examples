// Creating stack using linked list instead of array
// Insert at HEAD instead of TAIL because we can't not pop() from TAIL
// HEAD->4->3->2->TAIL
// All the function in class Stack: T = O(1) (constant)
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
class Stack {
    Node<T>* head;
    int size;
    public:
        Stack() {
            head = NULL;
            size = 0;
        }
        int getSize() {
            return size;
        }
        bool isEmpty() {
            return size==0;
        }
        void push(T element) {
            Node<T>* newNode = new Node<T>(element);
            newNode->next = head;
            head = newNode;
            size++;
        }
        void pop() {
            if(isEmpty()) {
                cout << "Stack is empty!" << endl;
                return;
            }
            Node<T>* oldHead = head;
            head = head->next;
            oldHead->next = NULL; // First, isolate the old node
            delete oldHead; // Then, delete it's dynamic memory block
            size--;
        }
        T top() {
            if(isEmpty()) {
                cout << "Stack is empty!" << endl;
                return 0;
            }
            return head->data;
        }
};
int main() {
    Stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.getSize() << endl;
    cout << s.isEmpty() << endl;

    Stack<int> s2;
    for(int i=0; i<10; i++) {
        s2.push(i);
    }
    while(!s2.isEmpty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    return 0;
}
