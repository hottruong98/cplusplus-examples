/* When we want to create many nodes (e.g. 100 nodes) ==> it's a waste of time manually create one by one like demo example.
 * So, We gonna create a function to take input from users and return the "head" of the linked list
 * In array, we use "loop for" to save input into the array, but we cant do it with Linked List ...
 * ... because we dont know the size of it from the start. 
 */
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void printLinkedList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next; // Change the pointer value or the object that the pointer point to
    }
    cout << "NULL" << endl;
}
Node* takeInput() {
    int data;
    cin>>data;
    Node *head = NULL; //Initially, Linked List is empty
    Node *tail = NULL;
    while(data != -1) { // When you create something statically in the {}, they will be deleted once they go out of the scope {}
        // Creating Linked List
        // We must create the node dynamically so that it won't be deleted each loop {}
        Node *n = new Node(data);
        // 1st node
        if(head == NULL) {
            head = n;
            tail = n;
        }
        else {
            tail->next = n; // Insert a tail
            tail = n; // Set current node as the tail
        }
        cin>>data;
    }
    return head;
}
int main()
{
    Node* head = takeInput();
    printLinkedList(head);

    return 0;
}

// Calculate the time complexity of takeInput() function:
// Create 1 node --> k steps
// Create N nodes --> N.k steps
// So, T = O(N)

// The next code will be about inserting a head --> the same as inserting a tail in this example