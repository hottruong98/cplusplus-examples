#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;
        TreeNode(T data) {
            this->data = data;
        } 
};
template <typename T>
TreeNode<T>* takeInput() {
    T rootData;
    cout << "Enter data: ";
    cin >> rootData;
    TreeNode<T>* root = new TreeNode<T>(rootData);

    int numOfChildren;
    cout << "Enter number of children of " << rootData << " : ";
    cin >> numOfChildren;
    for(int i = 0; i < numOfChildren; i++) {
        cout << "The child number " << i+1 << " of " << root->data << endl;
        TreeNode<T>* newChild = takeInput<T>();
        root->children.push_back(newChild);
    }
    return root;
}
template <typename T>
void printTree(TreeNode<T> *root) {
    if(root == NULL) {
        return; // Edge case
    }
    cout << root->data << ": ";
    for(int i = 0; i < root->children.size(); i++) {
        cout << root->children.at(i)->data << " ";
    }
    cout << endl;
    for(int i = 0; i < root->children.size(); i++) {
        printTree(root->children.at(i)); // Base case is leaf node
    }
}
int main() {
    TreeNode<int>* root = takeInput<int>();
    printTree(root);
    return 0;
}