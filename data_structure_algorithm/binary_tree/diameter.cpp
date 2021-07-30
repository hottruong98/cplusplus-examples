#include <iostream>
#include <vector>
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
    int level = 0;
    while(!q.empty()) {
        cout << "Level " << level << ": ";
        int sizeOfEachLevel = q.size();
        for(int i = 0; i < sizeOfEachLevel; i++) {
            TreeNode<T>* node = q.front();
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

template <typename T>
TreeNode<T>* takeInput() {
    queue<TreeNode<T>*> q;
    cout << "Enter root data: ";
    T rootData;
    cin >> rootData;
    TreeNode<T>* root = new TreeNode<T>(rootData);
    q.push(root);
    
    while(!q.empty()) {
        int sizeOfEachLevel = q.size();
        for(int i = 0; i < sizeOfEachLevel; i++) {
            TreeNode<T>* node = q.front();
            q.pop();

            cout << "Enter left data of " << node->data << ": ";
            T leftData;
            cin >> leftData;
            if(leftData != -1) {
                node->left = new TreeNode<T>(leftData);
                q.push(node->left);
            }

            cout << "Enter right data of " << node->data << ": ";
            T rightData;
            cin >> rightData;
            if(rightData != -1) {
                node->right = new TreeNode<T>(rightData);
                q.push(node->right);
            }
        }
    }
    return root;
}

template <typename T>
int getHeight(TreeNode<T>* root) {
    if(root == nullptr) {
        return 0;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
// Return the maximum distance between any two nodes
// T(N) = O(N*logN) in balanced tree, and O(N^2) in only-left/right subtree (worst case)
template <typename T>
int getDiameter(TreeNode<T>* root) {
    if(root == nullptr) {
        return 0;
    }
    int option1 = getHeight(root->left) + getHeight(root->right); //case 1: pass root
    int option2 = getDiameter(root->left); //case 2: in left subtree
    int option3 = getDiameter(root->right); // case 3: in right subtree
    return max(option1, max(option2, option3));
}

template <typename T>
pair<int, int> getHeightDiameter(TreeNode<T>* root) {
    if(root == NULL) {
        pair<int, int> hd;
        hd.first = 0;
        hd.second = 0;
        return hd;
    }
    pair<int, int> leftHeightDiameter = getHeightDiameter(root->left);
    pair<int, int> rightHeightDiameter = getHeightDiameter(root->right);

    int leftHeight = leftHeightDiameter.first;
    int rightHeight = rightHeightDiameter.first;

    int leftDiameter = leftHeightDiameter.second;
    int rightDiameter = rightHeightDiameter.second;

    int height = 1 + max(leftHeight, rightHeight);
    int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));

    pair<int, int> hd;
    hd.first = height;
    hd.second = diameter;
    return hd;
}
// T(N) = O(N)
template <typename T>
int getDiameter_2(TreeNode<T>* root) {
    pair<int, int> hd = getHeightDiameter(root);
    return hd.second;
}

int main() {
    // 1 2 3 4 5 7 -1 6 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // 9 3 10 5 8 -1 -1 7 -1 -1 12 4 -1 15 16 -1 -1 -1 -1 -1 -1
    TreeNode<int>* root = takeInput<int>();
    cout << endl;
    printTree(root);
    cout << "Diameter of tree is " << getDiameter_2(root) << endl;
    return 0;
}