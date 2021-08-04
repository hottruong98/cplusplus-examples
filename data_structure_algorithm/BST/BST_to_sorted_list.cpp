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
template <typename T>
class ListNode {
    public:
        T data;
        ListNode<T>* next;
        ListNode(T data) {
            this->data = data;
            next = NULL;
        }
        ~ListNode() {
            delete next;
        }
};
class BST {
    TreeNode<int>* root;
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
    TreeNode<int>* deleteData(TreeNode<int>* root, int data) {
        if(root == NULL) {
            return NULL;
        }
        if(data < root->data) {
            root->left = deleteData(root->left, data);
        }
        else if(data > root->data) {
            root->right = deleteData(root->right, data);
        }
        else {
            if(root->left == NULL && root->right) {
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

                TreeNode<int>* temp = tempLeft;
                while(temp->right != NULL) {
                    temp = temp->right;
                }
                temp->right = tempRight;
                return tempLeft;
            }
        }
        return root;
    }
    // InOrder traversal: return both head and tail
    pair<TreeNode<int>*, TreeNode<int>*> toSortedList(TreeNode<int>* root) {
        pair<TreeNode<int>*, TreeNode<int>*> listHeadTail {NULL, NULL};
        if(root == NULL) {
            return listHeadTail;
        }
        if(root->left == NULL && root->right == NULL) {
            listHeadTail.first = root;
            listHeadTail.second = listHeadTail.first;
            return listHeadTail;
        }
        pair<TreeNode<int>*, TreeNode<int>*> leftHeadTail = toSortedList(root->left);
        pair<TreeNode<int>*, TreeNode<int>*> rightHeadTail = toSortedList(root->right);  
        TreeNode<int>* temp = root;
        if(leftHeadTail.first != NULL && leftHeadTail.second != NULL) {
            leftHeadTail.second->right = root;
            root->left = NULL;
            root->right = rightHeadTail.first ? rightHeadTail.first : root->right;
        }
        listHeadTail.first = leftHeadTail.first ? leftHeadTail.first : temp;
        listHeadTail.second = rightHeadTail.second ? rightHeadTail.second : temp;
        return listHeadTail;
    }
    // InOrder traversal: return tail and save head (update head from right to left -> final head = root of tree)
    TreeNode<int>* toSortedList_2(TreeNode<int>* root, TreeNode<int>* &head) {
        if(root == NULL) {
            return NULL;
        }
        if(root->left == NULL && root->right == NULL) {
            return root;
        }
        TreeNode<int>* rightTail = toSortedList_2(root->right, head);
        if(head) {
            root->right = head; // Update right subtree with new right sorted list
            head = NULL; // Reset head
        }
        TreeNode<int>* leftTail = toSortedList_2(root->left, head);
        if(head) {
            root->left = head; // Update left subtree with new left sorted list
            head = NULL; // Reset head
        }
        // Sort and save new head of sorted list
        if(leftTail != NULL) {
            TreeNode<int>* temp = root->left;
            root->left = NULL;
            leftTail->right = root;
            head = temp;
        } 
        else {
            head = root;
        }
        return rightTail == NULL? root : rightTail;
    }
    // PreOrder traversal: return both head and tail
    pair<TreeNode<int>*, TreeNode<int>*> flatten(TreeNode<int>* root) {
        pair<TreeNode<int>*, TreeNode<int>*> listHeadTail;
        listHeadTail.first = NULL;
        listHeadTail.second = NULL;
        if(root == NULL) {
            return listHeadTail;
        }
        if(root->left == NULL && root->right == NULL) {
            listHeadTail.first = root;
            listHeadTail.second = listHeadTail.first;
            return listHeadTail;
        }
        pair<TreeNode<int>*, TreeNode<int>*> leftHeadTail;
        pair<TreeNode<int>*, TreeNode<int>*> rightHeadTail;
        leftHeadTail = flatten(root->left);
        rightHeadTail = flatten(root->right);
        root->left = NULL;
        if(leftHeadTail != listHeadTail && rightHeadTail != listHeadTail) {
            root->right = leftHeadTail.first;
            leftHeadTail.second->right = rightHeadTail.first;
        }
        else if(leftHeadTail == listHeadTail && rightHeadTail != listHeadTail) {
            root->right = rightHeadTail.first;
        }
        else if(leftHeadTail != listHeadTail && rightHeadTail == listHeadTail) {
            root->right = leftHeadTail.first;
            rightHeadTail.second = leftHeadTail.second;
        }
        listHeadTail.first = root;
        listHeadTail.second = rightHeadTail.second;
        return listHeadTail;
    }
    // PreOrder traversal: return only tail
    TreeNode<int>* flatten_2(TreeNode<int>* root) {
        if(root == NULL) {
            return root;
        }
        if(root->left == NULL && root->right == NULL) {
            return root;
        }
        TreeNode<int>* leftTail = flatten_2(root->left);
        TreeNode<int>* rightTail = flatten_2(root->right);
        if(leftTail != NULL) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        return rightTail == NULL? leftTail : rightTail;
    }
    public:
        BST() {
            root = NULL;
        }
        ~BST() {
            delete root;
        }
        void insert(int data) {
            root = insert(root, data);
        }
        void deleteData(int data) {
            root = deleteData(root, data);
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
        void toSortedList() {
            pair<TreeNode<int>*, TreeNode<int>*> listHeadTail;
            listHeadTail = toSortedList(root);
            root = listHeadTail.first;
        }
        void toSortedList_2() {
            TreeNode<int>* head = NULL;
            toSortedList_2(root, head);
            root = head;
        }
        void flatten() {
            pair<TreeNode<int>*, TreeNode<int>*> myHeadTail;
            myHeadTail = flatten(root);
            root = myHeadTail.first;
        }
        void flatten_2() {
            flatten_2(root);
        }
};

int main() {
    cout << "------- new BST -------\n";
    BST myBST;
    vector<int> input;
    input = {1, -1, 8, -3, 0, 6, 11, 4, 7, 10, 13, 2, 5, 12, 23};
    // input = {1, -2, -3};
    // input = {4, 2, 5, 1, 3, 6};
    // input = {};
    for(int i = 0; i < input.size(); i++) {
        myBST.insert(input[i]);
    }
    myBST.print();
    cout << "------- new BST -------\n";
    myBST.toSortedList(); // Convert BST to list not create new one
    myBST.print();
    cout << "------- new BST -------\n";
    // myBST.flatten_2();
    // myBST.print();
    return 0;
}