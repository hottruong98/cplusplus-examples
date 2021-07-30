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
int getHeight(TreeNode<T>* root) {
    if(root == nullptr) {
        return 0;
    }
    int maxHeight = 0;
    int leftHeight = 0;
    int rightHeight = 0;
    leftHeight = getHeight(root->left);
    rightHeight = getHeight(root->right);
    maxHeight = max(leftHeight, rightHeight);
    return maxHeight + 1; 
}

template <typename T>
bool isSymmetric(TreeNode<T>* root) {
    queue<TreeNode<T>*> leftQueue;
    queue<TreeNode<T>*> rightQueue;
    if(root->left) {
        leftQueue.push(root->left);
    }
    else {
        leftQueue.push(NULL);
    }
    if(root->right) {
        rightQueue.push(root->right);
    }
    else {
        rightQueue.push(NULL);
    }
    while(!leftQueue.empty() && !rightQueue.empty()) {
        TreeNode<T>* leftTreeNode = leftQueue.front();
        TreeNode<T>* rightTreeNode = rightQueue.front();
        leftQueue.pop();
        rightQueue.pop();
        if(leftTreeNode == NULL && rightTreeNode == NULL) {
            continue;
        }
        else if (leftTreeNode == NULL || rightTreeNode == NULL) {
            return false;
        }
        if(leftTreeNode->data != rightTreeNode->data) {
            return false;
        }
        if(leftTreeNode->left) {
            leftQueue.push(leftTreeNode->left);
        }
        else {
            leftQueue.push(NULL);
        }
        if(leftTreeNode->right) {
            leftQueue.push(leftTreeNode->right);
        }
        else {
            leftQueue.push(NULL);
        }
        if(rightTreeNode->right) {
            rightQueue.push(rightTreeNode->right);
        }
        else {
            rightQueue.push(NULL);
        }
        if(rightTreeNode->left) {
            rightQueue.push(rightTreeNode->left);
        }
        else {
            rightQueue.push(NULL);
        }
    }
    return true;
}
template <typename T>
bool helper(TreeNode<T>* leftTree, TreeNode<T>* rightTree) {
    if(!leftTree && !rightTree) {
        return true;
    }
    if(!leftTree || !rightTree) {
        return false;
    }
    return leftTree->data == rightTree->data && helper(leftTree->left, rightTree->right) && helper(leftTree->right, rightTree->left);
}
template <typename T>
bool isSymmetric_2(TreeNode<T>* root) {
    if(root == NULL) {
        return true;
    }
    return helper(root->left, root->right);
}
int main() {
    // 1 2 3 4 5 7 -1 6 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // 1 2 2 3 4 4 3 5 6 7 8 8 7 6 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 2 -1 3 -1 3 -1 -1 -1 -1
    TreeNode<int>* root = takeInput<int>();
    cout << endl;
    printTree(root);
    cout << "Height of tree is " << getHeight(root) << endl;
    cout << "Is symmetric? " << isSymmetric(root) << endl;
    cout << "Is symmetric? " << isSymmetric_2(root) << endl;
    return 0;
}
