#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

// Save path from root to a specific node in the tree
template <typename T>
bool getPath(TreeNode<T>* root, T key, vector<T> &path) {
    if(!root) {
        return false;
    }
    if(root->data == key) {
        path.push_back(root->data);
        return true;
    }
    bool isPresent = getPath(root->left, key, path) || getPath(root->right, key, path);
    if(isPresent) {
        path.push_back(root->data);
    }
    return isPresent;
}

template <typename T>
bool getPath_2(TreeNode<T>* root, T key, vector<T> &path) {
    if(!root) {
        return false;
    }
    path.push_back(root->data);
    if(root->data == key) {
        return true;
    }
    bool isPresentInLeft = getPath_2(root->left, key, path);
    bool isPresentInRight = getPath_2(root->right, key, path);
    bool ans = isPresentInLeft || isPresentInRight;
    if(ans == false) {
        path.pop_back();
    }
    return ans;
}

// Save all root-to-leaf paths
template <typename T>
void saveAllPath(TreeNode<T>* root, vector<T> &path, vector<string> &allPath) {
    if(!root) {
        return;
    }
    path.push_back(root->data);
    if(!root->left && !root->right) {
        string str = to_string(path.at(0));
        for(int i = 1; i < path.size(); i++) {
            str += "->" + to_string(path.at(i));
        }
        allPath.push_back(str);
        //path.pop_back();
        //return;
    }
    saveAllPath(root->left, path, allPath);
    saveAllPath(root->right, path, allPath);
    path.pop_back();
}
template <typename T>
vector<string> allPathToLeafNodes(TreeNode<T>* root) {
    if(!root) {
        return {};
    }
    vector<int> path;
    vector<string> allPath;
    saveAllPath(root, path, allPath);
    return allPath;
}
template <typename T>
void saveAllPath_2(TreeNode<T>* root, string path, vector<string> &allPath) {
    if(!root) {
        return;
    }
    if(!root->left && !root->right) {
        if(path == "") {
            allPath.push_back(path + to_string(root->data));
        } else {
            allPath.push_back(path + "->" + to_string(root->data));
        }
        return;
    }
    if(path == "") {
        saveAllPath_2(root->left, path + to_string(root->data), allPath);
        saveAllPath_2(root->right, path + to_string(root->data), allPath);
    } else {
        saveAllPath_2(root->left, path + "->" + to_string(root->data), allPath);
        saveAllPath_2(root->right, path + "->" + to_string(root->data), allPath);
    }
}
template <typename T>
vector<string> allPathToLeafNodes_2(TreeNode<T>* root) {
    if(!root) {
        return {};
    }
    string path = "";
    vector<string> allPath;
    saveAllPath_2(root, path, allPath);
    return allPath;
}

// Return all root-to-leaf paths where each path's sum equals targetSum
template <typename T>
void pathSumHelper(TreeNode<T> *root, T targetSum, vector<T> &path, vector<vector<T>> &allPath) {
    if(!root) {
        return;
    }
    path.push_back(root->data);
    if(!root->left && !root->right) {
        int sum = 0;
        for(int i = 0; i < path.size(); i++) {
            sum += path[i];
        }
        if(sum == targetSum) {
            allPath.push_back(path);
        }
    }
    pathSumHelper(root->left, targetSum, path, allPath);
    pathSumHelper(root->right, targetSum, path, allPath);
    path.pop_back();
}
template <typename T>
vector<vector<T>> pathSum(TreeNode<T> *root, T targetSum) {
    vector<int> path;
    vector<vector<int>> allPath;
    pathSumHelper(root, targetSum, path, allPath);
    return allPath;
}

// Return the maximum path sum of any path
int maxPathSumHelper(TreeNode<int>* root, int &ans) {
    if(root == NULL) {
        return 0;
    }
    int left = maxPathSumHelper(root->left, ans);
    int right = maxPathSumHelper(root->right, ans);
    int smallAns = max(root->data, root->data + max(left, right));
    ans = max(ans, max(smallAns, root->data + left + right));
    return smallAns;
}
int maxPathSum(TreeNode<int>* root) {
    int ans = INT32_MIN;
    maxPathSumHelper(root, ans);
    return ans;
}
int main() {
    // 1 2 3 4 10 7 -1 6 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // 9 3 10 5 8 -1 -1 7 -1 -1 12 4 -1 15 16 -1 -1 -1 -1 -1 -1
    TreeNode<int>* root = takeInput<int>();
    cout << endl;
    printTree(root);

    vector<int> path;
    int key = 15;
    // if(getPath(root, key, path)) {
    //     for(int i = 0; i < path.size(); i++) {
    //         cout << path.at(path.size() - 1 - i) << " ";
    //     }
    // }
    // else {
    //     cout << "No path found cuz the key is not present" << endl;
    // }
    if(getPath_2(root, key, path)) {
        cout << "Path to " << key << ": ";
        for(int i = 0; i < path.size(); i++) {
            cout << path.at(i) << " ";
        }
        cout << endl;
    }
    else {
        cout << "No path found cuz the key is not present" << endl;
    }

    vector<string> pathToLeafNodes = allPathToLeafNodes(root);
    cout << "All root-to-leaf paths: ";
    for(int i = 0; i < pathToLeafNodes.size(); i++) {
        cout << pathToLeafNodes.at(i) << " ";
    }
    cout << endl;

    vector<vector<int>> rootToLeafPaths = pathSum(root, 13);
    if(rootToLeafPaths.size()) {
        cout << "All root-to-leaf paths satisfying the target sum: ";
        for(int i = 0; i < rootToLeafPaths.size(); i++) {
            for(int j = 0; j < rootToLeafPaths[i].size(); j++) {
                cout << rootToLeafPaths[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path satisfying the target sum" << endl;
    }
    cout << "Maximum path sum of any path: " << maxPathSum(root) << endl;
    delete root;
    return 0;
}