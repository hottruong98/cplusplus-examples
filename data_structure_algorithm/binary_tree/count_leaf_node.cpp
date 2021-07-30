#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class TreeNode {
    public:
        T data;
        TreeNode<T>* left;
        TreeNode<T>* right;
        TreeNode(T data) {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
        ~TreeNode() {
            delete left;
            delete right;
        }
};

template <typename T>
TreeNode<T>* takeInput() {
    cout << "Enter root data: ";
    T rootData;
    cin >> rootData;
    TreeNode<T>* root = new TreeNode<T>(rootData);
    queue<TreeNode<T>*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode<T>* f = q.front();
        q.pop();

        cout << "Enter the left child of " << f->data << ": ";
        T leftData;
        cin >> leftData;
        if(leftData != -1) {
            TreeNode<T>* leftChild = new TreeNode<T>(leftData);
            q.push(leftChild);
            f->left = leftChild;
        }

        cout << "Enter the right child of " << f->data << ": ";
        T rightData;
        cin >> rightData;
        if(rightData != -1) {
            TreeNode<T>* rightChild = new TreeNode<T>(rightData);
            q.push(rightChild);
            f->right = rightChild;
        }
    }
    return root;
}

template <typename T>
void printTree(TreeNode<T>* root) {
    if(root == nullptr) {
        return;
    }
    queue<TreeNode<T>*> q;
    q.push(root);

    while(!q.empty()) {
        int sizeOfLevel = q.size();
        for(int i = 0; i < sizeOfLevel; i++) {
            TreeNode<T>* f = q.front();
            cout << f->data << " ";
            q.pop();

            if(f->left) {
                q.push(f->left);
            }
            if(f->right) {
                q.push(f->right);
            }
        }
        cout << endl;
    }
}
template <typename T>
int countLeafNodes(TreeNode<T>* root) {
    if(!root) {
        return 0;
    }
    if(!root->left && !root->right) {
        cout << root->data << " ";
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int main() {
    // 1 2 3 4 5 7 -1 6 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // 1 2 2 3 4 4 3 5 6 7 8 8 7 6 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 2 -1 3 -1 3 -1 -1 -1 -1
    TreeNode<int>* root = takeInput<int>();
    cout << endl;
    printTree(root);
    cout << "Number of leaf nodes: " << countLeafNodes(root) << endl;
    return 0;
}
