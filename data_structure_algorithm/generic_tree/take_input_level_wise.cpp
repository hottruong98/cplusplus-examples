#include <iostream>
#include <vector>
#include <queue>
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
    cout << "Enter root data: ";
    cin >> rootData;
    TreeNode<T>* root = new TreeNode<T>(rootData);
    queue<TreeNode<T>*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode<T>* f = q.front();
        q.pop();

        cout << "Enter the number of children of " << f->data << ": ";
        int numOfChildren;
        cin >> numOfChildren;
        for(int i = 0; i < numOfChildren; i++) {
            cout << "Enter data of child number " << i+1 << " of " << f->data << ": ";
            T childData;
            cin >> childData;
            TreeNode<T>* newChild = new TreeNode<T>(childData);
            f->children.push_back(newChild); 
            q.push(newChild);
        }
    }
    return root;
}

template <typename T>
void printTree(TreeNode<T>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << ": ";
    for(int i = 0; i < root->children.size(); i++) {
        cout << root->children.at(i)->data << " ";
    }
    cout << endl;
    for(int i = 0; i < root->children.size(); i++) {
        printTree(root->children.at(i));
    }
}

int main() {
    TreeNode<int>* root = takeInput<int>();
    printTree(root);
    return 0;
}