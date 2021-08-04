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

int rangeSumBST(TreeNode<int>* root, int low, int high) {
    if(root == NULL) {
        return 0;
    }
    int sum = 0;
    if(root->data >= low && root->data <= high) {
        sum = root->data + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
    if(root->data > high) {
        sum = rangeSumBST(root->left, low, high);
    }
    if(root->data < low) {
        sum = rangeSumBST(root->right, low, high);
    }
    return sum;
}

int rangeSumBST_2(TreeNode<int>* root, int low, int high) {
    if(root == NULL) {
        return 0;
    }
    int sum = 0;
    if(root->data >= low && root->data <= high) {
        sum += root->data;
    }
    sum += rangeSumBST_2(root->left, low, high);
    sum += rangeSumBST_2(root->right, low, high);
    return sum;
}
int main() {
    // 8 3 10 1 6 null 14 null null 4 7 13 null null null null null null null
    cout << "------- Create BST -------" << endl;
    TreeNode<int>* root = buildTree();
    cout << endl;
    printTree(root);
    cout << "------- Work with BST -------" << endl;
    cout << "Sum of nodes in range [2, 11]: " << rangeSumBST(root, 10, 11) << endl;
    delete root;
    return 0;
}