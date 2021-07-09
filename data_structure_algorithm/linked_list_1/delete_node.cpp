// Because we create nodes dynamically ==> delete it = deallocate it's dynamic memory block ==> avoid memory leak problem
// Before deleting a node, assign NULL value to the "next" attribute
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
    Node* head = nullptr;
    Node* tail = nullptr;
    while(data != -1) {
        Node* newNode = new Node(data); //Must be dynamic node so that it wont be deallocated after out of {}
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode; //The old tail/node
            tail = newNode; //the new tail = new node
        }
        cin >> data;
    }
    return head;
}
void printLinkedList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
Node* deleteNode(Node* head, int pos) {
    if(pos < 0) {
        return head;
    }
    if(pos == 0) {
        Node* newHead = head->next;
        head->next = nullptr;
        delete head; // head was created dynamically 
                     // ==> we need to deallocate dynamic memory block that it's pointing to
        return newHead;
    }
    Node* temp = head;
    int count = 1;
    while(temp != nullptr && count <= pos-1) {
        temp = temp->next; // from node[1] to node[pos-1] if temp != null
        count++;
    }
    if(temp != nullptr && temp->next != nullptr) { // temp->next != nullptr to prevent the case pos = length
        Node* oldNode = temp->next; // this node[pos] need to be deleted
        temp->next = oldNode->next; // node[pos-1] points to node[pos+1] 
                                    // or the link between node[pos-1] and node[pos] has been destroyed
        oldNode->next = nullptr;
        delete oldNode; // deallocating dynamic memory block that oldNode's pointing to
        return head;
    }
    return head;
}
int main() {
    cout << "Type in node data: ";
    Node* head = takeInput();
    cout << "\n";
    printLinkedList(head);
    cout << "\nYou want to delete node at position: ";
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    printLinkedList(head);
    return 0;
}