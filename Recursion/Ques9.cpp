#include <iostream>
#include <vector>
#include <queue>
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
    
    TreeNode* buildTreeFromLevelOrder(const vector<int>& levelOrder) {
        if (levelOrder.empty() || levelOrder[0] == -1) return nullptr;
        
        TreeNode* rootNode = new TreeNode(levelOrder[0]);
        queue<TreeNode*> q;
        q.push(rootNode);
        
        int i = 1;
        while (i < levelOrder.size() && !q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            if (i < levelOrder.size() && levelOrder[i] != -1) {
                current->left = new TreeNode(levelOrder[i]);
                q.push(current->left);
            }
            i++;
            
            if (i < levelOrder.size() && levelOrder[i] != -1) {
                current->right = new TreeNode(levelOrder[i]);
                q.push(current->right);
            }
            i++;
        }
        
        return rootNode;
    }

public:
    BinaryTree() : root(nullptr) {}
    
    void constructTree(const vector<int>& levelOrder) {
        root = buildTreeFromLevelOrder(levelOrder);
    }
    
    vector<int> getRightSideView() {
        vector<int> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                
                if (i == levelSize - 1) {
                    result.push_back(current->val);
                }
                
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }
        
        return result;
    }
};

void problem9A() {
    int n;
    cin >> n;
    vector<int> levelOrder(n);
    
    for (int i = 0; i < n; i++) {
        cin >> levelOrder[i];
    }
    
    BinaryTree tree;
    tree.constructTree(levelOrder);
    vector<int> rightView = tree.getRightSideView();
    
    for (int i = 0; i < rightView.size(); i++) {
        cout << rightView[i];
        if (i < rightView.size() - 1) cout << " ";
    }
    cout << endl;
}

int main()
{

problem9A();
    
    



}