#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;
    
    TreeNode* buildTree(const vector<int>& levelOrder) {
        if (levelOrder.empty() || levelOrder[0] == -1) {
            return nullptr;
        }
        
        root = new TreeNode(levelOrder[0]);
        queue<TreeNode*> q;
        q.push(root);
        
        int i = 1;
        while (i < levelOrder.size() && !q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            // Left child
            if (i < levelOrder.size() && levelOrder[i] != -1) {
                current->left = new TreeNode(levelOrder[i]);
                q.push(current->left);
            }
            i++;
            
            // Right child
            if (i < levelOrder.size() && levelOrder[i] != -1) {
                current->right = new TreeNode(levelOrder[i]);
                q.push(current->right);
            }
            i++;
        }
        
        return root;
    }
    
    bool isValidBSTHelper(TreeNode* node, long long minVal, long long maxVal) {
        if (node == nullptr) {
            return true;
        }
        
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }
        
        return isValidBSTHelper(node->left, minVal, node->val) && 
               isValidBSTHelper(node->right, node->val, maxVal);
    }
    
    void deleteTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    
public:
    BinaryTree() : root(nullptr) {}
    
    ~BinaryTree() {
        deleteTree(root);
    }
    
    void constructTree(const vector<int>& levelOrder) {
        root = buildTree(levelOrder);
    }
    
    bool isValidBST() {
        if (root == nullptr) {
            return true;
        }
        return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    int n;
    cout<<"Give  value to n:";
    cin >> n;
    
    vector<int> levelOrder(n);
    for (int i = 0; i < n; i++) {
        
        cout<<"Enter Value:"<<endl;
        cin >> levelOrder[i];
    }
    
    BinaryTree tree;
    tree.constructTree(levelOrder);
    
    if (tree.isValidBST()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}