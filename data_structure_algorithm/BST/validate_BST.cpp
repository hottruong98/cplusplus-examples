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

// Idea: Check if inOrder traversal (L-root-R) of the binary tree is sorted => BST
// T = O(n) && S = O(1) 
bool isValidBSTHelper(TreeNode<int>* root, queue<int> &q) {
    if(root == NULL) {
        return true;
    }
    bool leftAns = isValidBSTHelper(root->left, q);
    if(q.size() > 0) {
        if(root->data <= q.front()) {
            return false;
        }
        q.pop();
    }
    q.push(root->data);
    bool rightAns = isValidBSTHelper(root->right, q);
    if((root->left && root->data <= root->left->data) || //
    (root->right && root->data >= root->right->data)) {
        return false;
    }
    return leftAns && rightAns;
}
bool isValidBST(TreeNode<int>* root) {
    queue<int> q;
    bool ans = isValidBSTHelper(root, q);
    // int size = q.size();
    // for(int i = 0; i < size; i++) {
    //     cout << q.front() << " ";
    //     q.pop();
    // }
    return ans;
}

// Each node has a constraint (min, max)
bool isValidBSTHelper_2(TreeNode<int>* root, TreeNode<int>* min, TreeNode<int>* max) {
    if(root == NULL) {
        return true;
    }
    if(max && root->data >= max->data || min && root->data <= min->data) {
        return false;
    }
    bool leftAns = isValidBSTHelper_2(root->left, min, root);
    bool rightAns = isValidBSTHelper_2(root->right, root, max);
    return leftAns && rightAns;
}
bool isValidBST_2(TreeNode<int>* root) {
    return isValidBSTHelper_2(root, NULL, NULL);
}

bool isValidBSTHelper_3(TreeNode<int>* root, long long min, long long max) {
    if(root == NULL) {
        return true;
    }
    if(root->data <= min || root->data >= max) {
        return false;
    }
    bool leftAns = isValidBSTHelper_3(root->left, min, root->data);
    bool rightAns = isValidBSTHelper_3(root->right, root->data, max);
    return leftAns && rightAns;
}
bool isValidBST_3(TreeNode<int>* root) {
    return isValidBSTHelper_3(root, -10000000000, 10000000000);
}
int main() {
    // not BST: 8 2 9 1 3 7 10 null null null null null null null null
    // BST: 8 3 10 1 6 null 14 null null 4 7 13 null null null null null null null
    cout << "------- Create BST -------" << endl;
    TreeNode<int>* root = buildTree();
    cout << endl;
    printTree(root);
    cout << "------- Work with BST -------" << endl;
    cout << "Is it a valid BST? ";
    if(isValidBST_3(root)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    delete root;
    return 0;
}