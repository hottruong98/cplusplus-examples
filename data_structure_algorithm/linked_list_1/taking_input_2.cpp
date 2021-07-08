// Inserting at HEAD (reversing a linked list: fixing the tail and moving the head node)
// Input: 1 2 3 4 ==> Output: 4->3->->2->1->NULL
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
void printLinkedList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data <<"->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
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
        } else {
            n->next = head;
            head = n;
        }
        cin >> data;
    }
    return head;
}
int main() {
    Node* head = takeInput(); // T = O(N)
    printLinkedList(head);
    return 0;
}