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

template <typename T>
TreeNode<T>* takeInput() {
    cout << "Enter root data: ";
    T rootData;
    cin >> rootData;
    TreeNode<T>* root = new TreeNode<T>(rootData);
    queue<TreeNode<T>*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode<T>* f = q.front();
        q.pop();
        
        cout << "Enter the number of children of " << f->data << ": ";
        int numOfChildren;
        cin >> numOfChildren;
        for(int i = 0; i < numOfChildren; i++) {
            cout << "Enter data of child number " << i + 1 << " of " << f->data << ": ";
            T childData;
            cin >> childData;
            TreeNode<T>* child = new TreeNode<T>(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}

template <typename T>
void printTree(TreeNode<T>* root) {
    if(root == NULL) {
        return;
    }
    queue<TreeNode<T>*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode<T>* f = q.front();
        cout << f->data << ": ";
        q.pop();
        for(int i = 0; i < f->children.size(); i++) {
            cout << f->children.at(i)->data << " ";
            q.push(f->children.at(i));
        }
        cout << endl;
    }
}
int main() {
    TreeNode<int>* root = takeInput<int>();
    printTree(root);
    return 0;
}
