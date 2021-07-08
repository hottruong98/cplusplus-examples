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
// Special cases:
// 1. pos<0: XXXXX
// 2. pos=0: head
// 3. pos>length: XXXXX (the allowed maximum pos = length of Linked List --> after tail)
Node* insertNode(Node* head, int pos, int data) {
    if(pos < 0) {
        return head;
    }
    
    if(pos == 0) {
        Node* n = new Node(data);
        n->next = head;
        head = n;
        return head;
    }

    // if(pos > lengthLinkedList(head)) { //Redundance
    //     return head;
    // }

    Node* temp = head;
    int count = 1;
    while(count <= pos-1 && temp != NULL) {
        
        temp = temp->next; //temp is currently the position [count]th
        count++;
    }
    //temp is now the node at [pos-1]
    if(temp) {
        Node* newNode = new Node(data);
        Node* oldNode = temp->next; //Save address of the old node into oldNode
        temp->next = newNode; //Temp is the node at [pos-1], with "next" will now point to our new node
        newNode->next = oldNode; //The new node now at [pos] will point to the old one now at [pos+1]
    }
    return head;
}
Node* change(Node* head) { //Test function
    Node* temp = head;
    temp = temp->next;
    return temp;
}
int main() {
    Node* head = takeInput();
    printLinkedList(head);
    cout << "Insert a new node at position: ";
    int pos;
    cin >> pos;
    cout << "\nData of the new node: ";
    int data;
    cin >> data;
    head = insertNode(head, pos, data);
    printLinkedList(head);
    // head = change(head);
    // printLinkedList(head);
    return 0;
}
