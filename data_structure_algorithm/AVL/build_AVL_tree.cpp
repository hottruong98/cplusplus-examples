#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

template <typename T>
class TreeNode {
    public:
        T data;
        TreeNode* left;
        TreeNode* right;
        int height;
        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
            height = 1;
        }
        ~TreeNode() {
            delete left;
            delete right;
        }
};

class AVLTree {
    TreeNode<int>* root;
    int getHeight(TreeNode<int>* root);
    int getDifference(TreeNode<int>* root);
    TreeNode<int>* rotateLeft(TreeNode<int>* root);
    TreeNode<int>* rotateRight(TreeNode<int>* root);
    TreeNode<int>* balance(TreeNode<int>* root);
    TreeNode<int>* insert(TreeNode<int>* root, int data);
    TreeNode<int>* buildTree(vector<int>& input);
    void print(TreeNode<int>* root);
    // void countSmaller(TreeNode<int>* root, int *cumulativeSum, int size, int index, unordered_map<int, int> &ans);
    public:
        AVLTree() {
            root = NULL;
        }
        ~AVLTree() {
            delete root;
        }
        int getHeight() {
            return getHeight(root);
        }
        int getDifference() {
            return getDifference(root);
        }
        void insert(int data) {
            root = insert(root, data);
        }
        void build(vector<int> input) {
            root = buildTree(input);
        }
        void print() {
            print(root);
        }
        // void countSmaller(vector<int>* input, vector<int>* output) {
        //     unordered_map<int, int> ans;
        //     int height = getHeight(root);
        //     int cumulativeSum[height] = {};
        //     countSmaller(root, cumulativeSum, height, 0, ans);
        //     int size = input->size();
        //     for(int i = 0; i < size; i++) {
        //         output->push_back(ans[input->at(i)]);
        //     }
        // }
};
TreeNode<int>* AVLTree::insert(TreeNode<int>* root, int data) {
    if(root == NULL) {
        return new TreeNode<int>(data);
    }
    if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else if(data > root->data) {
        root->right = insert(root->right, data);
    }
    else {
        return root;
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    root = balance(root);
    return root;
}
TreeNode<int>* AVLTree::balance(TreeNode<int>* root) {
    int difference = getDifference(root);
    int leftDifference = getDifference(root->left);
    int rightDifference = getDifference(root->right);
    // Left > right and inserted node is on the left of left subtree
    if(difference > 1 && leftDifference > 0) {
        root = rotateRight(root);
    } 
    // Left > right and inserted node is on the right of left subtree
    else if(difference > 1 && leftDifference < 0) {
        root->left = rotateLeft(root->left); // flatten left subtree
        root = rotateRight(root);
    }
    // Left < right and inserted node is on the left of right subtree
    else if(difference < -1 && rightDifference > 0) {
        root->right = rotateRight(root->right); // flatten right subtree
        root = rotateLeft(root);
    }
    // Left < right and inserted node is on the right of right subtree
    else if(difference < -1 && rightDifference < 0) {
        root = rotateLeft(root);
    }
    else return root;
    return root;
}
int AVLTree::getHeight(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    return root->height;
}
int AVLTree::getDifference(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}
TreeNode<int>* AVLTree::buildTree(vector<int>& input) {
    TreeNode<int>* root = NULL;
    int size = input.size();
    for(int i = 0; i < size; i++) {
        root = insert(root, input[i]);
        print(root);
        cout << "-----------\n";
    } 
    return root;
}
TreeNode<int>* AVLTree::rotateLeft(TreeNode<int>* root) {
    if(root == NULL) {
        return NULL;
    }
    TreeNode<int>* rightSubtree = root->right;
    TreeNode<int>* leftRightSubtree = rightSubtree->left;

    rightSubtree->left = root;
    root->right = leftRightSubtree;

    // Update height of root because root->right changed
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    // Update height of rightSubtree because rightSubtree->left changed
    rightSubtree->height = 1 + max(getHeight(rightSubtree->left), getHeight(rightSubtree->right));
    
    return rightSubtree;
}
TreeNode<int>* AVLTree::rotateRight(TreeNode<int>* root) {
    if(root == NULL) {
        return NULL;
    }
    TreeNode<int>* leftSubtree = root->left;
    TreeNode<int>* rightLeftSubtree = leftSubtree->right;

    leftSubtree->right = root;
    root->left = rightLeftSubtree;

    // Update height of root because root->left changed
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    // Update height of leftSubtree because leftSubtree->right changed
    leftSubtree->height = 1 + max(getHeight(leftSubtree->left), getHeight(leftSubtree->right));
    
    return leftSubtree;
}
void AVLTree::print(TreeNode<int>* root) {
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

// Only applicable for AVL input order --> useless
// void AVLTree::countSmaller(TreeNode<int>* root, int *cumulativeSum, int size, int index, unordered_map<int, int> &ans) {
//     if(root == NULL) {
//         return;
//     }
//     countSmaller(root->left, cumulativeSum, size - 1, index + 1, ans);
//     cumulativeSum[index] ++;
//     for(int i = 0; i < index; i++) {
//         cumulativeSum[i] ++;
//     }
//     cout << cumulativeSum[0] << " " << cumulativeSum[1] << " " << cumulativeSum[2] << " " << cumulativeSum[3] << endl;
    
//     if(size > 1) {
//         ans[root->data] = cumulativeSum[index + 1];
//         cout << "node " << root->data << ", cumulativeSum[" << index + 1 << "] = " << cumulativeSum[index + 1] << endl;
//     }
//     else {
//         ans[root->data] = 0;
//         cout << "node " << root->data << ", cumulativeSum[" << index + 1 << "] = " << 0 << endl;
//     }
//     countSmaller(root->right, cumulativeSum, size - 1, index + 1, ans);
// }

int main() {
    vector<int> input;
    input = {1, -1, 8, -3, 0, 6, 11, 4, 7, 10, 13, 2, 5, 12, 23};
    input = {23, 12, 5, 2, 13, 10, 7, 4, 11, 6, 0, -3, 8, -1, 1};
    // input = {10, 20, 30, 40, 50, 25};
    // input = {5, 2, 6, 1};
    // input = {6, 1, 11, -1, 4, 8, 13, -3, 0, 2, 5, 7, 10, 12, 23};
    // input = {1, 0, 1, 6, 3, 5, 9, 7};
    // input = {7, 9, 5, 3, 6, 1, 0, 1};
    AVLTree myAVL;
    myAVL.build(input);
    myAVL.print();
    cout << "\n--------------------------\n";
    return 0;
}
// Time complexity:
// Function builTree:
// + Case 1: Given a self input -> normal tree insertion will return an AVL tree -> T(N) = O(N) 
// + Case 2: Given a random input -> use AVL insertion -> T(N) = O(N*log(N))
// In AVL Tree: Time complexity for insertion is O(log(N))
// We perform N insertion -> T(N) = O(N*log(N))
// ==> Worst case: T(N) = O(N*log(N))
