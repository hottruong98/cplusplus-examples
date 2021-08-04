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

class BST {
    TreeNode<int>* root;
    bool hasData(TreeNode<int>* root, int data) {
        if(root == NULL) {
            return false;
        }
        if(root->data == data) {
            return true;
        }
        if(root->data < data) {
            return hasData(root->right, data);
        } else {
            return hasData(root->left, data);
        }
    }
    TreeNode<int>* deleteData(TreeNode<int>* root, int data) {
        if(root == NULL) {
            return NULL;
        }
        if(data < root->data) {
            root->left = deleteData(root->left, data); // Update left node when deleted
        } 
        else if(data > root->data) {
            root->right = deleteData(root->right, data); // Update right node when deleted
        }
        else {
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            else if(root->left == NULL) {
                TreeNode<int>* temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if(root->right == NULL) {
                TreeNode<int>* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else {
                TreeNode<int>* tempLeft = root->left;
                TreeNode<int>* tempRight = root->right;
                root->left = NULL;
                root->right = NULL;
                delete root;

                // First choice: Replace deleted node with it's left node
                // Then insert the right subtree of deleted node to the right side of new node
                TreeNode<int>* temp = tempLeft;
                while(temp->right != NULL) {
                    temp = temp->right;
                }
                temp->right = tempRight;
                return tempLeft;

                // Second choice: Replace deleted node with it's right node
                // Then insert the left subtree of deleted node to the left side of new node
                /* TreeNode<int>* temp = tempRight;
                while(temp->left != NULL) {
                    temp = temp->left;
                }
                temp->left = tempLeft;
                return tempRight; */
            }
            /* else {
                TreeNode<int>* targetNode = root;

                if(root->left && root->right) {
                    root = root->left;
                    TreeNode<int>* temp = root;
                    while(temp->right) {
                        temp = temp->right;
                    }
                    temp->right = targetNode->right;
                }
                else {
                    if(!root->left) {
                        root = root->right;
                    }
                    else if(!root->right) {
                        root = root->left;
                    }
                }
                targetNode->left = NULL;
                targetNode->right = NULL;
                delete targetNode;
            } */
        }
        return root;
    }
    TreeNode<int>* insert(TreeNode<int>* root, int data) {
        if(root == NULL) {
            return new TreeNode<int>(data);
        }
        if(data < root->data) {
            root->left = insert(root->left, data);
        }
        else if(data > root->data) {
            root->right = insert(root->right, data);
        }
        return root;
    }
    public:
        BST() {
            root = NULL;
        }
        ~BST() {
            delete root;
        }
        void deleteData(int data) {
            root = deleteData(root, data);
        }
        void insert(int data) {
            root = insert(root, data);
        }
        bool hasData(int data) {
            return hasData(root, data);
        }
        void print() {
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
                        if(node->left) {
                            q.push(node->left);
                        } else {
                            q.push(NULL);
                            nullCount++;
                        }

                        if(node->right) {
                            q.push(node->right);
                        } else {
                            q.push(NULL);
                            nullCount++;
                        }
                    } else {
                        cout << "null ";
                        nullCount--;
                    }
                }
                cout << endl;
                level++;
            }
        }
};

int main() {
    BST myBST;
    vector<int> input {1, -1, 8, -3, 0, 6, 11, 4, 7, 10, 13, 2, 5, 12, 23};
    for(int i = 0; i < input.size(); i++) {
        myBST.insert(input[i]);
    }
    myBST.print();
    cout << "------- new BST -------\n";
    myBST.insert(9);
    myBST.insert(14);
    myBST.print();
    cout << "------- new BST -------\n";
    myBST.deleteData(11);
    myBST.print();
    return 0;
}