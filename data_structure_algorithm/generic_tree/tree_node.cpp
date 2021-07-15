#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
    public:
        T data;
        vector<TreeNode<T> *> children; // Children là vector store address các TreeNode != hay [các con trỏ trỏ đến các node !=]
        TreeNode(T data) {
            this->data = data;
        }
};
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
    TreeNode<int> *root = new TreeNode<int>(10);
    TreeNode<int> *n1 = new TreeNode<int>(20);
    TreeNode<int> *n2 = new TreeNode<int>(30);
    root->children.push_back(n1);
    root->children.push_back(n2);
    printTree(root);
    return 0;
}