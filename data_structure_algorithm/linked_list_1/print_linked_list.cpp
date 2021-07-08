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
void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    //Statically
    Node n1(27);
    Node *head = &n1;
    Node n2(6);
    Node n3(19);
    Node n4(98);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    printLinkedList(head); //Because we pass by value (not reference) ...
                           //...==> after exiting the function, "head" will return to the original value
    printLinkedList(head); //If We pass by reference: void printLinkedList(Node *&head) = reference to pointer "head", ...
                           //...this will only return NULL

    //Dynamically
    Node *n5 = new Node(5);
    Node *head_dynamic = n5;
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);

    n5->next = n6;
    n6->next = n7;

    printLinkedList(head_dynamic);
    printLinkedList(head_dynamic);
    return 0;
}