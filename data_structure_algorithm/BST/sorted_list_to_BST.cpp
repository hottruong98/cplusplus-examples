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

void printList(ListNode<int>* head) {
    while(head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "null" << endl;
}

ListNode<int>* buildList() {
    ListNode<int>* head = NULL;
    cout << "Enter from head data: ";
    string headData;
    cin >> headData;
    if(headData != "null") {
        head = new ListNode<int>(stoi(headData));
    }
    ListNode<int>* temp = head;
    string data;
    cin >> data;
    while(data != "null") {
        temp->next = new ListNode<int>(stoi(data));
        temp = temp->next;
        cin >> data;
    }
    return head;
}

void deleteList(ListNode<int>* head) {
    if(head == NULL) {
        return;
    }
    while(head && head->next) {
        ListNode<int>* oldHead = head;
        head = head->next;
        oldHead->next = NULL;
        delete oldHead;
    }
    delete head;
}

TreeNode<int>* helper(ListNode<int>* &head, int left, int right) {
    if(left > right) {
        return NULL;
    }
    int rootIndex = (left + right) / 2;
    TreeNode<int>* leftTree = helper(head, left, rootIndex - 1);
    if(leftTree) {
        head = head->next;
    }
    TreeNode<int>* root = new TreeNode<int>(head->data);
    TreeNode<int>* rightTree = helper(head->next, rootIndex + 1, right);
    if(rightTree) {
        head = head->next;
    }
    root->left = leftTree;
    root->right = rightTree;
    return root;
}
TreeNode<int>* sortedListToBST(ListNode<int>* head) {
    int size = 0;
    ListNode<int>* temp = head;
    while(temp) {
        size++;
        temp = temp->next;
    }
    temp = head;
    return helper(temp, 0, size - 1);
}
int main() {
    // 0 1 2 3 4 5 6 null
    cout << "------- Create Linked List -------" << endl;
    ListNode<int>* head = buildList();
    printList(head);

    cout << "------- Create BST from sorted list -------" << endl;
    TreeNode<int>* root = sortedListToBST(head);
    cout << endl;
    printTree(root);

    cout << "------- Delete Linked List and BST -------" << endl;
    deleteList(head);
    delete root;
    return 0;
}