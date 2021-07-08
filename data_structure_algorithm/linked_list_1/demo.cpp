#include <iostream>
using namespace std;
#define log(x) cout << x << endl
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
int main()
{
    //Create node statically
    Node n1(73); //HEAD NODE
    Node n2(266);
    Node n3(11); //TAIL NODE

    n1.next = &n2; //Create link/connection
    n2.next = &n3;
    log(n1.data);
    log(n2.data);
    log(n3.data);

    Node *head = &n1;
    log(head->data);

    //Create node dynamically
    Node *n4 = new Node(27); //In stack memory: n4; In heap memory: data and next
    Node *n5 = new Node(6);
    n4->next = n5; //Create the link
    return 0;
}