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
        ~ TreeNode() {
            for(int i = 0; i < children.size(); i++) {
                delete children.at(i);
            }
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
        TreeNode<T>* frontNode = q.front();
        q.pop();

        cout << "Enter the number of children of " << frontNode->data << ": ";
        int numOfChildren;
        cin >> numOfChildren;

        for(int i = 0; i < numOfChildren; i++) {
            cout << "Enter data of the child number " << i + 1 << " of " << frontNode->data << ": ";
            T childData;
            cin >> childData;
            TreeNode<T>* child = new TreeNode<T>(childData);
            q.push(child);
            frontNode->children.push_back(child);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInput<int>();
    cout << endl << root->children.at(1)->data; // before delete
    delete root;
    cout << endl << root->children.at(1)->data; // after delete
    return 0;
}