#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
    public:
        T data;
        TreeNode<T>* left;
        TreeNode<T>* right;
        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            delete left;
            delete right;
        }
};

void printTree(TreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()) {
        cout << "Level " << level << ": ";
        int sizeOfEachLevel = q.size();
        for(int i = 0; i < sizeOfEachLevel; i++) {
            TreeNode<int>* node = q.front();
            q.pop();
            cout << node->data << " ";
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
        level++;
        cout << endl;
    }
}

TreeNode<int>* buildTree() {
    queue<TreeNode<int>*> q;
    TreeNode<int>* root = NULL; 
    cout << "Enter root data: ";
    string rootData;
    cin >> rootData;
    if(rootData != "null") {
        root = new TreeNode<int>(stoi(rootData));
        q.push(root);
    }
    while(!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();

        cout << "Enter left child of node " << node->data << ": ";
        string leftData;
        cin >> leftData;
        if(leftData != "null") {
            TreeNode<int>* leftChild = new TreeNode<int>(stoi(leftData));
            q.push(leftChild);
            node->left = leftChild;
        }

        cout << "Enter right child of node " << node->data << ": ";
        string rightData;
        cin >> rightData;
        if(rightData != "null") {
            TreeNode<int>* rightChild = new TreeNode<int>(stoi(rightData));
            q.push(rightChild);
            node->right = rightChild;
        }
    }
    return root;
}

// Recursion
TreeNode<int>* searchBST(TreeNode<int>* root, int value) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data > value) {
        return searchBST(root->left, value);
    }
    if(root->data < value) {
        return searchBST(root->right, value);
    }
    return root;
}

// Iteration
TreeNode<int>* searchBST_2(TreeNode<int>* root, int value) {
    while(root != NULL) {
        if(root->data > value) {
            root = root->left;
            continue;
        }
        if(root->data < value) {
            root = root->right;
            continue;
        }
        return root;
    }
}
int main() {
    // 8 3 10 1 6 null 14 null null 4 7 13 null null null null null null null
    cout << "------- Create BST -------" << endl;
    TreeNode<int>* root = buildTree();
    cout << endl;
    printTree(root);
    cout << "------- Search in  BST -------" << endl;
    cout << "Enter the value: ";
    int value;
    cin >> value;
    printTree(searchBST(root, value));
    delete root;
    return 0;
}