#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
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

// Construct tree from preOrder and inOrder traversal
template <typename T>
TreeNode<T>* buildTree(vector<T> &preOrder, vector<T> &inOrder) {
    T rootData = preOrder.at(0);
    TreeNode<T>* root = new TreeNode<T>(rootData);
    if(preOrder.size() == 1) {
        return root;
    }
    int k = 0;
    for(int i = 0; i < inOrder.size(); i++) {
        if(rootData == inOrder.at(i)) {
            k = i;
            break;
        }
    }  
    if(k != 0) {
        vector<T> leftPreOrder(preOrder.begin() + 1, preOrder.end() - (preOrder.size() - k - 1));
        vector<T> leftInOrder(inOrder.begin(), inOrder.end() - (inOrder.size() - k));
        root->left = buildTree(leftPreOrder, leftInOrder);
    }
    if(k != inOrder.size() - 1) {
        vector<T> rightPreOrder(preOrder.begin() + k + 1, preOrder.end());
        vector<T> rightInOrder(inOrder.begin() + k + 1, inOrder.end());
        root->right = buildTree(rightPreOrder, rightInOrder);
    }
    return root;
}

// Construct tree from preOrder and inOrder traversal
// inOrder: (inStart)->|left|(root)|right|<-(inEnd)
// preOrder: (preStart)->|(root)|left|right|<-(preEnd)
template <typename T>
TreeNode<T>* helper(vector<T> &preOrder, vector<T> &inOrder, int preStart, int inStart, int inEnd, unordered_map<T, int> &rootIndex) {
    if(inStart > inEnd) {
        return NULL;
    }
    TreeNode<T>* node = new TreeNode<T>(preOrder.at(preStart));

    int leftPreStart = preStart + 1;
    int leftInStart = inStart;
    int leftInEnd = rootIndex[node->data] - 1;

    int rightPreStart = leftPreStart + (leftInEnd - leftInStart) + 1;
    int rightInStart = rootIndex[node->data] + 1;
    int rightInEnd = inEnd;

    node->left = helper(preOrder, inOrder, leftPreStart, leftInStart, leftInEnd, rootIndex);
    node->right = helper(preOrder, inOrder, rightPreStart, rightInStart, rightInEnd, rootIndex);
    return node;
}
template <typename T>
TreeNode<T>* buildTree_2(vector<T> &preOrder, vector<T> &inOrder) {
    unordered_map<T, int> index;
    int size = inOrder.size();
    for(int i = 0; i < size; i++) {
        index[inOrder.at(i)] = i;
    }
    TreeNode<T>* root = helper(preOrder, inOrder, 0, 0, size - 1, index);
    return root;
}

// Construct tree from inOrder and postOrder traversal
// inOrder: (inStart)->|left|(root)|right|<-(inEnd)
// postOrder: (postStart)->|left|right|(root)|<-(postEnd)
template <typename T>
TreeNode<T>* helper_3(vector<T> &inOrder, vector<T> &postOrder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<T, int> &rootIndex) {
    if(inStart > inEnd) {
        return NULL;
    }
    TreeNode<T>* node = new TreeNode<T>(postOrder.at(postEnd));
    int leftInStart = inStart;
    int leftInEnd = rootIndex[node->data] - 1;
    int leftPostStart = postStart;
    int leftPostEnd = leftPostStart + leftInEnd - leftInStart;
    
    int rightInStart = rootIndex[node->data] + 1;
    int rightInEnd = inEnd;
    int rightPostStart = leftPostEnd + 1;
    int rightPostEnd = postEnd - 1;
    node->left = helper_3(inOrder, postOrder, leftInStart, leftInEnd, leftPostStart, leftPostEnd, rootIndex);
    node->right = helper_3(inOrder, postOrder, rightInStart, rightInEnd, rightPostStart, rightPostEnd, rootIndex);
    return node;
}
template <typename T>
TreeNode<T>* buildTree_3(vector<T> &inOrder, vector<T> &postOrder) {
    unordered_map<T, int> index;
    int size = inOrder.size();
    for(int i = 0; i < size; i++) {
        index[inOrder.at(i)] = i;
    }
    TreeNode<T>* root = helper_3(inOrder, postOrder, 0, size - 1, 0, size - 1, index);
    return root;
}

int main() {
    // 1 2 3 4 5 7 -1 6 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // 1 2 2 3 4 4 3 5 6 7 8 8 7 6 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 2 -1 3 -1 3 -1 -1 -1 -1
    // vector<int> preOrder {3, 9, 20, 15, 7};
    // vector<int> inOrder {9, 3, 15, 20, 7};
    // vector<int> preOrder {1, 2};
    // vector<int> inOrder {2, 1};
    vector<int> preOrder {1, 2, 3};
    vector<int> inOrder {2, 3, 1};
    TreeNode<int>* root = buildTree_2(preOrder, inOrder);
    cout << endl;
    printTree(root);

    vector<int> inOrder_3 {9, 3, 15, 20, 7};
    vector<int> postOrder_3 {9, 15, 7, 20, 3};
    TreeNode<int>* root_3 = buildTree_3(inOrder_3, postOrder_3);
    cout << endl;
    printTree(root_3);
    return 0;
}
