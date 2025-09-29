#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

// Part A: BST Insertion and Level Order Traversal
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;
    
    TreeNode* insertHelper(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        
        if (val < node->val) {
            node->left = insertHelper(node->left, val);
        } else {
            node->right = insertHelper(node->right, val);
        }
        
        return node;
    }
    
    void deleteTree(TreeNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}
    
    ~BST() {
        deleteTree(root);
    }
    
    void insert(int val) {
        root = insertHelper(root, val);
    }
    
    vector<vector<int>> levelOrderTraversal() {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                level.push_back(current->val);
                
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            
            result.push_back(level);
        }
        
        return result;
    }
};

void partA() {
    int n;
    cin >> n;
    
    BST bst;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        bst.insert(val);
    }
    
    vector<vector<int>> levels = bst.levelOrderTraversal();
    for (const auto& level : levels) {
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << " ";
        }
        cout << endl;
    }
}

// Part B: Depth-2 Greedy Tree with Gini Impurity
class DataPoint {
public:
    vector<double> features;
    int label;
    
    DataPoint(int d) : features(d) {}
};

class GiniTreeBuilder {
private:
    vector<DataPoint> data;
    int n, d;
    
    double calculateGiniImpurity(const vector<int>& indices) {
        if (indices.empty()) return 0.0;
        
        map<int, int> counts;
        for (int idx : indices) {
            counts[data[idx].label]++;
        }
        
        double impurity = 1.0;
        for (const auto& pair : counts) {
            double probability = static_cast<double>(pair.second) / indices.size();
            impurity -= probability * probability;
        }
        
        return impurity;
    }
    
    pair<int, double> findBestSplit(const vector<int>& indices) {
        int bestFeature = -1;
        double bestThreshold = 0.0;
        double bestGini = 1.0;
        
        double parentGini = calculateGiniImpurity(indices);
        
        for (int j = 0; j < d; j++) {
            // Collect all values for this feature
            vector<pair<double, int>> values;
            for (int idx : indices) {
                values.emplace_back(data[idx].features[j], data[idx].label);
            }
            sort(values.begin(), values.end());
            
            // Try all possible thresholds
            for (int i = 1; i < values.size(); i++) {
                if (values[i].first == values[i-1].first) continue;
                
                double threshold = (values[i].first + values[i-1].first) / 2.0;
                vector<int> leftIndices, rightIndices;
                
                for (int idx : indices) {
                    if (data[idx].features[j] <= threshold) {
                        leftIndices.push_back(idx);
                    } else {
                        rightIndices.push_back(idx);
                    }
                }
                
                if (leftIndices.empty() || rightIndices.empty()) continue;
                
                double leftGini = calculateGiniImpurity(leftIndices);
                double rightGini = calculateGiniImpurity(rightIndices);
                double weightedGini = (leftIndices.size() * leftGini + rightIndices.size() * rightGini) / indices.size();
                
                if (weightedGini < bestGini) {
                    bestGini = weightedGini;
                    bestFeature = j;
                    bestThreshold = threshold;
                }
            }
        }
        
        return {bestFeature, bestThreshold};
    }
    
    int predict(const DataPoint& point, int feature, double threshold, bool isLeft) {
        if (isLeft) {
            return (point.features[feature] <= threshold) ? 1 : -1;
        }
        return (point.features[feature] <= threshold) ? -1 : 1;
    }

public:
    void buildTree() {
        cin >> n >> d;
        data.resize(n, DataPoint(d));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                cin >> data[i].features[j];
            }
            cin >> data[i].label;
        }
        
        // Get all indices
        vector<int> allIndices(n);
        for (int i = 0; i < n; i++) allIndices[i] = i;
        
        // Find root split
        auto rootSplit = findBestSplit(allIndices);
        int rootFeature = rootSplit.first;
        double rootThreshold = rootSplit.second;
        
        cout << fixed << setprecision(6);
        cout << "Root split: feature " << rootFeature << " <= " << rootThreshold << endl;
        
        // Split data for left and right children
        vector<int> leftIndices, rightIndices;
        for (int i = 0; i < n; i++) {
            if (data[i].features[rootFeature] <= rootThreshold) {
                leftIndices.push_back(i);
            } else {
                rightIndices.push_back(i);
            }
        }
        
        // Find splits for left child
        if (!leftIndices.empty()) {
            auto leftSplit = findBestSplit(leftIndices);
            if (leftSplit.first != -1) {
                cout << "Left child split: feature " << leftSplit.first << " <= " << leftSplit.second << endl;
            } else {
                map<int, int> counts;
                for (int idx : leftIndices) counts[data[idx].label]++;
                int majority = max_element(counts.begin(), counts.end(), 
                    [](const pair<int, int>& a, const pair<int, int>& b) {
                        return a.second < b.second;
                    })->first;
                cout << "Left leaf: class " << majority << endl;
            }
        }
        
        // Find splits for right child
        if (!rightIndices.empty()) {
            auto rightSplit = findBestSplit(rightIndices);
            if (rightSplit.first != -1) {
                cout << "Right child split: feature " << rightSplit.first << " <= " << rightSplit.second << endl;
            } else {
                map<int, int> counts;
                for (int idx : rightIndices) counts[data[idx].label]++;
                int majority = max_element(counts.begin(), counts.end(), 
                    [](const pair<int, int>& a, const pair<int, int>& b) {
                        return a.second < b.second;
                    })->first;
                cout << "Right leaf: class " << majority << endl;
            }
        }
        
        // Calculate accuracy (simplified)
        int correct = 0;
        for (int i = 0; i < n; i++) {
            // Simple prediction based on root split only for demonstration
            int prediction = (data[i].features[rootFeature] <= rootThreshold) ? 1 : 0;
            if (prediction == data[i].label) {
                correct++;
            }
        }
        
        double accuracy = static_cast<double>(correct) / n;
        cout << "Accuracy: " << accuracy << endl;
    }
};

void partB() {
    GiniTreeBuilder treeBuilder;
    treeBuilder.buildTree();
}

int main() {
    int part;
    cin >> part;
    
    if (part == 1) {
        partA();
    } else if (part == 2) {
        partB();
    }
    
    return 0;
}