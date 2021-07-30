#include <iostream>
using namespace std;

template <typename T>
class BTNode {
    public:
        T data;
        BTNode* left;
        BTNode* right;
        BTNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~ BTNode() {
            delete left;
            delete right;
        }
};

int main() {
    BTNode<int>* root = new BTNode<int>(10);
    BTNode<int>* n1 = new BTNode<int>(20);
    BTNode<int>* n2 = new BTNode<int>(30);
    BTNode<int>* n3 = new BTNode<int>(40);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    delete root;
    return 0;
}