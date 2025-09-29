#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <iomanip>

using namespace std;

// Part A: Build Tree from Preorder & Inorder
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeFromPreIn(vector<int>& preorder, vector<int>& inorder, 
                            int preStart, int preEnd, int inStart, int inEnd,
                            unordered_map<int, int>& inorderMap) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;
    
    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);
    
    int rootIndex = inorderMap[rootVal];
    int leftSize = rootIndex - inStart;
    
    root->left = buildTreeFromPreIn(preorder, inorder, preStart + 1, preStart + leftSize,
                                   inStart, rootIndex - 1, inorderMap);
    root->right = buildTreeFromPreIn(preorder, inorder, preStart + leftSize + 1, preEnd,
                                    rootIndex + 1, inEnd, inorderMap);
    
    return root;
}

vector<int> levelOrderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        result.push_back(current->val);
        
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    
    return result;
}

void partA() {
    int n;
    
    cin >> n;
    
    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < n; i++) {
        inorderMap[inorder[i]] = i;
    }
    
    TreeNode* root = buildTreeFromPreIn(preorder, inorder, 0, n-1, 0, n-1, inorderMap);
    vector<int> levelOrder = levelOrderTraversal(root);
    
    for (int val : levelOrder) {
        cout << val << " ";
    }
    cout << endl;
}

// Part B: Information Gain for Categorical Split
double calculateEntropy(const vector<int>& counts) {
    int total = 0;
    for (int count : counts) total += count;
    if (total == 0) return 0.0;
    
    double entropy = 0.0;
    for (int count : counts) {
        if (count > 0) {
            double p = (double)count / total;
            entropy -= p * log2(p);
        }
    }
    return entropy;
}

void partB() {
    int C, K;
    cin >> C >> K;
    
    vector<vector<int>> counts(K, vector<int>(C));
    vector<int> parentCounts(C, 0);
    int totalSamples = 0;
    
    for (int k = 0; k < K; k++) {
        for (int c = 0; c < C; c++) {
            cin >> counts[k][c];
            parentCounts[c] += counts[k][c];
            totalSamples += counts[k][c];
        }
    }
    
    double parentEntropy = calculateEntropy(parentCounts);
    double weightedChildEntropy = 0.0;
    
    for (int k = 0; k < K; k++) {
        int categoryTotal = 0;
        for (int c = 0; c < C; c++) {
            categoryTotal += counts[k][c];
        }
        if (categoryTotal > 0) {
            double childEntropy = calculateEntropy(counts[k]);
            weightedChildEntropy += ((double)categoryTotal / totalSamples) * childEntropy;
        }
    }
    
    double informationGain = parentEntropy - weightedChildEntropy;
    cout << fixed << setprecision(6) << informationGain << endl;
}

int main() {
    int part;
    cout<<"Enter 1 for Building Tree from Preorder and 2 for Information Gain";
    cin >> part;
    
    if (part == 1) {
        partA();
    } else if (part == 2) {
        partB();
    }
    
    return 0;
}