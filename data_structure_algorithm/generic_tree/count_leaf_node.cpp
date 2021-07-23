#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;
        TreeNode(T data) {
            this->data = data;
        }
};

// Using recurion
template <typename T>
int countLeafNode(TreeNode<T>* root) {
    if(root == NULL) {
        return 0;
    }
    if(root->children.size() == 0) {
        return 1;
    }
    int total = 0;
    for(int i = 0; i < root->children.size(); i++) {
        total += countLeafNode(root->children.at(i));      
    }
    return total;
}

// Without recursion
template <typename T>
int countLeafNode2(TreeNode<T>* root) {
    if(root == NULL) {
        return 0;
    }
    int count = 0;
    queue<TreeNode<T>*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode<T>* f = q.front();
        if(f->children.size() == 0) {
            count++;
        }
        q.pop();

        for(int i = 0; i < f->children.size(); i++) {
            q.push(f->children.at(i));
        }
    }
    return count;
}
int main() {
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* n1 = new TreeNode<int>(2);
    TreeNode<int>* n2 = new TreeNode<int>(3);
    TreeNode<int>* n3 = new TreeNode<int>(4);
    TreeNode<int>* n4 = new TreeNode<int>(5);
    TreeNode<int>* n5 = new TreeNode<int>(6);
    TreeNode<int>* n6 = new TreeNode<int>(7);
    TreeNode<int>* n7 = new TreeNode<int>(8);
    TreeNode<int>* n8 = new TreeNode<int>(9);
    root->children.push_back(n1);
    root->children.push_back(n2);
    root->children.push_back(n3);
    n1->children.push_back(n4);
    n1->children.push_back(n5);
    n2->children.push_back(n6);
    n2->children.push_back(n7);
    n7->children.push_back(n8);
    cout << countLeafNode(root) << endl;
    cout << countLeafNode2(root) << endl;
    return 0;
}