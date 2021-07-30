#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class BTNode {
    public:
        T data;
        BTNode<T>* left;
        BTNode<T>* right;
        BTNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~BTNode() {
            delete left;
            delete right;
        }
};
template <typename T>
void printRecursive(BTNode<T>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << ": ";
    if(root->left != NULL) {
        cout << root->left->data << "L ";
    }
    if(root->right != NULL) {
        cout << " " << root->right->data << "R";
    }
    cout << endl;

    printRecursive(root->left);
    printRecursive(root->right);
}

template <typename T>
BTNode<T>* takeInputRecursive() {
    cout << "Enter data: ";
    T rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BTNode<T>* root = new BTNode<T>(rootData);
    BTNode<T>* leftChild = takeInputRecursive<T>();
    BTNode<T>* rightChild = takeInputRecursive<T>();
    root->left = leftChild;
    root->right = rightChild;
    return root;
} 

template <typename T>
BTNode<T>* takeInputLevelWise() {
    cout << "Enter root data: ";
    T rootData;
    cin >> rootData;
    BTNode<T>* root = new BTNode<T>(rootData);
    queue<BTNode<T>*> q;
    q.push(root);

    while(!q.empty()) {
        BTNode<T>* frontNode = q.front();
        q.pop();

        cout << "Enter data of the left child of " << frontNode->data << ": ";
        T leftData;
        cin >> leftData;
        if(leftData != -1) {
            BTNode<T>* leftChild = new BTNode<T>(leftData);
            q.push(leftChild);
            frontNode->left = leftChild;
        }
        cout << "Enter data of the right child of " << frontNode->data << ": ";
        T rightData;
        cin >> rightData;
        if(rightData != -1) {
            BTNode<T>* rightChild = new BTNode<T>(rightData);
            q.push(rightChild);
            frontNode->right = rightChild;
        }
    }
    return root;
} 

template <typename T>
void levelOrderTraversal(BTNode<T>* root) {
    queue<BTNode<T>*> q;
    if(root) {
        q.push(root);
        q.push(NULL);
    }
    while(!q.empty()) {
        BTNode<T>* frontNode = q.front();
        q.pop();
        if(frontNode == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL); // NULL differentiate between levels
            }
            continue;
        }
        cout << frontNode->data << " ";

        if(frontNode->left != NULL) {
            q.push(frontNode->left);
        }
        if(frontNode->right != NULL) {
            q.push(frontNode->right);
        }
    }
}
template <typename T>
void levelOrderTraversal_2(BTNode<T>* root) {
    queue<BTNode<T>*> q;
    if(root) {
        q.push(root);
    }
    while(!q.empty()) {
        int sizeOfEachLevel = q.size();
        for(int i = 0; i < sizeOfEachLevel; i++) {
            BTNode<T>* f = q.front();
            q.pop();
            cout << f->data << " ";

            if(f->left != nullptr) {
                q.push(f->left);
            }
            if(f->right != nullptr) {
                q.push(f->right);
            }
        }
        cout << endl;
    }
}

template <typename T>
int countNodes(BTNode<T>* root) {
    if(root == NULL) {
        return 0;
    }
    int leftNodes = 0;
    int rightNodes = 0;
    leftNodes += countNodes(root->left);
    rightNodes += countNodes(root->right);
    return 1 + leftNodes + rightNodes;
}
// L D R
template <typename T>
void inOrderTraversal(BTNode<T>* root) {
    if(root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
template <typename T>
void inOrderTraversal_2(BTNode<T>* root) {
    if(root == NULL) {
        return;
    }
    stack<BTNode<T>*> st;
    BTNode<T>* current = root;
    while(current || !st.empty()) {
        while(current) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        cout << current->data << " ";
        st.pop();
        current = current->right;
    }
}
// D L R
template <typename T>
void preOrderTraversal(BTNode<T>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

template <typename T>
void preOrderTraversal_2(BTNode<T>* root) {
    if(root == NULL) {
        return;
    }
    stack<BTNode<T>*> s;
    s.push(root);
    while(!s.empty()) {
        BTNode<T>* temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if(temp->right) {
            s.push(temp->right);
        }
        if(temp->left) {
            s.push(temp->left);
        }
    }
}
// L R D
template <typename T>
void postOrderTraversal(BTNode<T>* root) {
    if(root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
int main() {
    //BTNode<int>* root = takeInputRecursive<int>(); // 1 2 4 6 -1 -1 -1 5 -1 -1 3 7 8 -1 -1 9 -1 -1 -1
    BTNode<int>* root = takeInputLevelWise<int>(); // 1 2 3 4 5 7 -1 6 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    //printRecursive(root);
    levelOrderTraversal(root);
    levelOrderTraversal_2(root);
    inOrderTraversal(root);
    cout << endl;
    inOrderTraversal_2(root);
    cout << endl;
    preOrderTraversal(root);
    cout << endl;
    preOrderTraversal_2(root);
    cout << endl;
    postOrderTraversal(root);
    return 0;
}