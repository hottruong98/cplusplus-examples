#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

class AVLNode {
    public:
        int val;
        AVLNode* left;
        AVLNode* right;
        int height;
        int leftSize;
        int rightSize;
        int frequency;
        AVLNode() {
            height = 0;
            leftSize = 0;
            rightSize = 0;
            frequency = 0;
        };
        AVLNode(int val) {
            this->val = val;
            left = NULL;
            right = NULL;
            height = 1;
            leftSize = 0;
            rightSize = 0;
            frequency = 1;
        };
        ~AVLNode() {};
};

class Solution: public AVLNode {
    public:
        bool isRepeat = false;
        int getHeight(AVLNode* root);
        int getDifference(AVLNode* root);
        AVLNode* rotateLeft(AVLNode* root);
        AVLNode* rotateRight(AVLNode* root);
        AVLNode* balance(AVLNode* root);
        AVLNode* insert(AVLNode* root, int data, int &counter, vector<int> &output, int index);
        vector<int> countSmaller(vector<int>& nums) {
            int size = nums.size();
            vector<int> output(size, 0);
            AVLNode* root = NULL;
            int counter = 0;
            for(int index = size - 1; index >= 0; index--) {
                root = insert(root, nums[index], counter, output, index);
                isRepeat = false;
            }
            return output;
        }
};
AVLNode* Solution::insert(AVLNode* root, int data, int &counter, vector<int> &output, int index) {
    if(root == NULL) {
        AVLNode* node = new AVLNode(data);
        output[index] = counter;
        counter = 0;
        return node;
    }
    if(data < root->val) {
        root->leftSize++;
        root->left = insert(root->left, data, counter, output, index);
    }
    else if(data > root->val) {
        root->rightSize++;
        counter += root->leftSize + 1 * root->frequency;
        root->right = insert(root->right, data, counter, output, index);
    }
    else {
        root->frequency++;
        isRepeat = true;
        output[index] = counter + root->leftSize;
        counter = 0;
        return root;
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    root = balance(root);
    return root;
}
AVLNode* Solution::balance(AVLNode* root) {
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
    else {
        return root;
    }
    return root;
}
AVLNode* Solution::rotateLeft(AVLNode* root) {
    if(root == NULL) {
        return NULL;
    }
    AVLNode* rightSubtree = root->right;
    AVLNode* leftRightSubtree = rightSubtree->left;
    
    root->right = leftRightSubtree;
    root->rightSize = rightSubtree->leftSize;
    rightSubtree->left = root;
    rightSubtree->leftSize = root->leftSize + root->rightSize + 1 * root->frequency;

    // Update height of root because root->right changed
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    // Update height of rightSubtree because rightSubtree->left changed
    rightSubtree->height = 1 + max(getHeight(rightSubtree->left), getHeight(rightSubtree->right));
    
    return rightSubtree;
}
AVLNode* Solution::rotateRight(AVLNode* root) {
    if(root == NULL) {
        return NULL;
    }
    AVLNode* leftSubtree = root->left;
    AVLNode* rightLeftSubtree = leftSubtree->right;

    root->left = rightLeftSubtree;
    root->leftSize = leftSubtree->rightSize;
    leftSubtree->right = root;
    leftSubtree->rightSize = root->leftSize + root->rightSize + 1 * root->frequency;

    // Update height of root because root->left changed
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    // Update height of leftSubtree because leftSubtree->right changed
    leftSubtree->height = 1 + max(getHeight(leftSubtree->left), getHeight(leftSubtree->right));
    
    return leftSubtree;
}

int Solution::getHeight(AVLNode* root) {
    if(root == NULL) {
        return 0;
    }
    return root->height;
}
int Solution::getDifference(AVLNode* root) {
    if(root == NULL) {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}
int main() {
    vector<int> nums = {1, -1, 8, -3, 0, 6, 11, 4, 7, 10, 13, 2, 5, 12, 23};
    nums = {-1, 5, 2, 1, 0, 2, -3, -1};
    nums = {1, 3, 1, 1, 0, 2, 9, 7, 3, 5, -1, 8, 11, 3, 2, 1, 4, 1, 3, 5, 17, 10, 12, 24, 0, 23, 15, -8, 0};
    vector<int> output;
    Solution mySolution;
    output = mySolution.countSmaller(nums);
    int size = output.size();
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}
// Average runtime on Leetcode: 300 ms
// Average memory on Leetcode: 85 MB
// Time complexity: T(n) = n.log(n)