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
    int nullCount = 0;
    while(!q.empty()) {
        int sizeOfEachLevel = q.size();
        if(sizeOfEachLevel == nullCount) {
            break;
        }
        cout << "Level " << level << ": ";
        for(int i = 0; i < sizeOfEachLevel; i++) {
            TreeNode<int>* node = q.front();
            q.pop();
            if(node) {
                cout << node->data << " ";
            } else {
                nullCount--;
                cout << "null ";
                continue;
            }
            if(node && node->left) {
                q.push(node->left);
            } else {
                q.push(NULL);
                nullCount++;
            }
            if(node && node->right) {
                q.push(node->right);
            } else {
                q.push(NULL);
                nullCount++;
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

TreeNode<int>* helper(vector<int> &nums, int left, int right) {
    if(left > right) {
        return NULL;
    }
    int rootIndex = (left + right) / 2; // Height-balanced binary tree
    TreeNode<int>* root = new TreeNode<int>(nums.at(rootIndex));
    root->left = helper(nums, left, rootIndex - 1);
    root->right = helper(nums, rootIndex + 1, right);
    return root;
}
TreeNode<int>* sortedArrayToBST(vector<int> &nums) {
    return helper(nums, 0, nums.size() - 1);
}
int main() {
    // not BST: 8 2 9 1 3 7 10 null null null null null null null null
    // BST: 8 3 10 1 6 null 14 null null 4 7 13 null null null null null null null
    cout << "------- Create BST -------" << endl;
    TreeNode<int>* root = buildTree();
    cout << endl;
    printTree(root);
    cout << "------- Work with BST -------" << endl;
    vector<int> sortedArray {-3, -1, 0, 1, 4, 6, 7, 8, 10, 11, 12, 13, 23};
    printTree(sortedArrayToBST(sortedArray));
    delete root;
    return 0;
}