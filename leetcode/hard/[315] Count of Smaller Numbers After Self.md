## **Problem**:
> You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

### Example 1:
> **Input**: nums = [5,2,6,1]
> 
> **Output**: [2,1,1,0]
> 
> **Explanation**:
> To the right of 5 there are 2 smaller elements (2 and 1).
> To the right of 2 there is only 1 smaller element (1).
> To the right of 6 there is 1 smaller element (1).
> To the right of 1 there is 0 smaller element.

### Example 2:
> **Input**: nums = [-1]
> 
> **Output**: [0]

### Example 3:
> **Input**: nums = [-1,-1]
> 
> **Output**: [0,0]

### Constraints:
> 1 &le; nums.length &le; 105
> 
> -104 &le; nums[i] &le; 104

### Idea:
> Using AVL Tree: Insert data from the right of given input array. While inserting or traverse the old AVL Tree, calculate the number of smaller elements by taking advantage of the property of an AVL Tree (left value < right value). If the inserted node's value > the current node's value, then left subtree of the current node will definitely contain all elements that are on the right side and smaller than the inserted node's value in the given input array.
### My code:
Add necessary lib
```
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;
```
Create an AVL Tree node type with additional properties:
- frequency (the number of time that a value appears while inserting new node),
- leftSize (the number of nodes on the left of current node including their frequency), 
- rightSize (the number of nodes on the left).
```
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
```
The solution class inherits from the AVL class 
```
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
```
Pick input data from right to left, insert to the current AVL tree and calculate the number of smaller elements inserted before it.
If the new data is greater than the root data, it is also greater than nodes on the left size of root
```
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
```
After inserting a new node, check if the tree is balanced at current node. If it isn't:
At any node:
- If right height > left height by more than 1, that node is called the unbalanced node:
    - If the inserted node is on the right of the right subtree of the unbalanced node, just rotate the tree to the left at the unbalanced node.
    - If the inserted node is on the left of the right subtree of the unbalanced node, before rotating the unbalanced node to the left, we must perform a right-rotation operation on the right child of the unbalanced node. Otherwise, the tree will be unbalanced again because the new left height will be instead greater than the new right height by more than 1.
- If left height is greater than right height by more than 1:
    - If the inserted node is on the left of the left subtree of the unbalanced node, just rotate the tree to the right at the unbalanced node.
    - If the inserted node is on the right of the left subtree of the unbalanced node, before rotating the unbalanced node to the right, we must perform a left-rotation operation on the left child of the unbalanced node. Otherwise, the tree will be unbalanced again because the new right height will be instead greater than the new left height by more than 1.

```
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
```
Rotate the tree to the left at current node (counterclockwise order)
```
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
```
Rotate the tree to the right at current node (clockwise order)
```
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
```
Get height of the current node
```
int Solution::getHeight(AVLNode* root) {
    if(root == NULL) {
        return 0;
    }
    return root->height;
}
```
Calculate the difference between the left height and the right height at current node
```
int Solution::getDifference(AVLNode* root) {
    if(root == NULL) {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}
```
Example test cases:
```
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
```