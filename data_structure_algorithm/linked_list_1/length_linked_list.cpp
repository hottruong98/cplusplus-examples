#include <iostream>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            next = NULL;
        }
};
Node* takeInput() {
    int data;
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1) {
        Node* n = new Node(data);
        if(head == NULL) {
            head = n;
            tail = n;
        }
        else {
            tail->next = n; // The next property of old tail will point to the new node
            tail = n; // Assign the new node as the new tail
        }
        cin >> data;
    }
    return head;
}
void printLinkedList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next; // Move on to the next node
    }
    cout << "NULL" << endl;
}
int lengthLinkedList(Node* head) {
    int length = 0;
    Node* temp = head;
    while(temp) {
        length++;
        temp = temp->next;
    }
    return length;
}

int main() {
    Node* head = takeInput();
    printLinkedList(head);
    int length = lengthLinkedList(head);
    cout << "Length of the created Linked List is " << length << endl;
    return 0;
}