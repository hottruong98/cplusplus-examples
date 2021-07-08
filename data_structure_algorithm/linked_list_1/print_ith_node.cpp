#include <iostream>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            next = nullptr;
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
            tail->next = n;
            tail = n;
        }
        cin >> data;
    }
    return head;
}
void printLinkedList(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << "->";
        temp = temp->next;
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
void printIthNode(Node* head, int pos) { // My solution (it seems not to be optimal)
    Node* temp = head;
    int count = 0;
    while(temp) {
        if(count == pos) {break;}
        temp = temp->next;
        count++;
    }
    if(count < pos) {
        cout << "You have entered a position larger than the linked list length!" << endl;
    }
    else {
        if(temp) {
            cout << temp->data << endl;
        }
        else {
            cout << "Empty" << endl;
        }
        
    }
}
void samplePrintIthNode(Node* head, int pos) {
    if(pos < 0) {
        cout << "-1" << endl;
        return;
    }
    int count = 1;
    while(count <= pos && head != NULL) {
        head = head->next;
        count++;
    }
    if(head) {
        cout << head->data << endl;
    }
    else {
        cout << "-1" << endl;
    }
}
int main() {
    Node* head = takeInput();
    printLinkedList(head);
    //printIthNode(head, -2);
    cout << "Choose the position of the node: ";
    int pos;
    cin >> pos;
    samplePrintIthNode(head, pos);
    return 0;
}

// Time complexity of samplePrintIthNode() function:
// Assuming that we have 10^5 nodes,
// If pos = 3 ==> T = O(i) (based mostly on the while loop)
// If pos = 10^5 ==> T = O(N) ==> The worst case is O(N) ==> fast