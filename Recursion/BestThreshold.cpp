#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <map>
#include <utility>

using namespace std;

class SplitFinder {
private:
    double calculateGiniImpurity(const vector<int>& labels) {
        if (labels.empty()) {
            return 0.0;
        }
        
        map<int, int> classCounts;
        for (int label : labels) {
            classCounts[label]++;
        }
        
        double impurity = 1.0;
        for (const auto& pair : classCounts) {
            double probability = static_cast<double>(pair.second) / labels.size();
            impurity -= probability * probability;
        }
        
        return impurity;
    }

public:
    pair<double, double> findBestSplit(const vector<double>& features, const vector<int>& labels) {
        if (features.size() != labels.size() || features.size() < 2) {
            return make_pair(numeric_limits<double>::quiet_NaN(), -1.0);
        }
        
        // Create indices and sort by feature values
        vector<size_t> indices(features.size());
        for (size_t i = 0; i < indices.size(); ++i) {
            indices[i] = i;
        }
        
        sort(indices.begin(), indices.end(), [&](size_t a, size_t b) {
            return features[a] < features[b];
        });
        
        double bestThreshold = numeric_limits<double>::quiet_NaN();
        double bestGain = -1.0;
        double parentImpurity = calculateGiniImpurity(labels);
        
        // Iterate through possible thresholds
        for (size_t i = 1; i < indices.size(); ++i) {
            // Skip duplicate feature values
            if (features[indices[i]] == features[indices[i - 1]]) {
                continue;
            }
            
            double threshold = (features[indices[i]] + features[indices[i - 1]]) / 2.0;
            
            // Split the data
            vector<int> leftLabels, rightLabels;
            for (size_t j = 0; j < indices.size(); ++j) {
                if (features[indices[j]] <= threshold) {
                    leftLabels.push_back(labels[indices[j]]);
                } else {
                    rightLabels.push_back(labels[indices[j]]);
                }
            }
            
            // Skip trivial splits
            if (leftLabels.size() < 2 || rightLabels.size() < 2) {
                continue;
            }
            
            // Calculate weighted impurity
            double leftImpurity = calculateGiniImpurity(leftLabels);
            double rightImpurity = calculateGiniImpurity(rightLabels);
            double weightedImpurity = (leftLabels.size() * leftImpurity + rightLabels.size() * rightImpurity) / labels.size();
            
            // Calculate information gain
            double gain = parentImpurity - weightedImpurity;
            
            // Update best split
            if (gain > bestGain) {
                bestGain = gain;
                bestThreshold = threshold;
            }
        }
        
        return make_pair(bestThreshold, bestGain);
    }
};

int main() {
    SplitFinder splitFinder;
    
    // Example 1: Simple binary classification
    vector<double> features = {3.0, 1.0, 2.0, 4.0, 1.0, 5.0, 2.0, 3.5, 4.5};
    vector<int> labels = {0, 0, 0, 1, 0, 1, 1, 1, 1};
    
    auto result = splitFinder.findBestSplit(features, labels);
    cout << "Example 1 - Perfect Separation:" << endl;
    cout << "Best threshold: " << result.first << endl;
    cout << "Information Gain: " << result.second << endl;
    cout << endl;
    
    // Example 2: More complex case
    vector<double> features2 = {1.2, 2.3, 3.1, 4.5, 5.8, 6.2, 7.9, 8.4, 9.1, 10.5};
    vector<int> labels2 = {0, 0, 0, 1, 1, 1, 0, 0, 1, 1};
    
    auto result2 = splitFinder.findBestSplit(features2, labels2);
    cout << "Example 2 - Complex Case:" << endl;
    cout << "Best threshold: " << result2.first << endl;
    cout << "Information Gain: " << result2.second << endl;
    cout << endl;
    
    // Example 3: Regression (using variance instead of Gini)
    // Note: This would require a different impurity measure
    
    return 0;
}