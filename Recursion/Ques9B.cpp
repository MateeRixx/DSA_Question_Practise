#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;

class InformationGainCalculator {
private:
    double calculateEntropy(const vector<int>& labels) {
        int total = labels.size();
        if (total == 0) return 0.0;
        
        int count0 = 0;
        for (int label : labels) {
            if (label == 0) count0++;
        }
        int count1 = total - count0;
        
        double p0 = static_cast<double>(count0) / total;
        double p1 = static_cast<double>(count1) / total;
        
        double entropy = 0.0;
        if (count0 > 0) entropy -= p0 * log2(p0);
        if (count1 > 0) entropy -= p1 * log2(p1);
        
        return entropy;
    }

public:
    pair<int, double> findBestFeature(const vector<vector<int>>& features, const vector<int>& labels) {
        int n = features.size();
        int d = features[0].size();
        
        double parentEntropy = calculateEntropy(labels);
        double maxIG = -1.0;
        int bestFeature = -1;
        
        for (int j = 0; j < d; j++) {
            vector<int> leftLabels, rightLabels;
            
            for (int i = 0; i < n; i++) {
                if (features[i][j] == 0) {
                    leftLabels.push_back(labels[i]);
                } else {
                    rightLabels.push_back(labels[i]);
                }
            }
            
            double leftEntropy = calculateEntropy(leftLabels);
            double rightEntropy = calculateEntropy(rightLabels);
            
            double total = n;
            double weightedEntropy = (leftLabels.size() / total) * leftEntropy + (rightLabels.size() / total) * rightEntropy;
            double informationGain = parentEntropy - weightedEntropy;
            
            if (informationGain > maxIG) {
                maxIG = informationGain;
                bestFeature = j;
            }
        }
        
        return make_pair(bestFeature, maxIG);
    }
};

class Dataset {
private:
    vector<vector<int>> features;
    vector<int> labels;
    int n, d;

public:
    void readData() {
        cin >> n >> d;
        features.resize(n, vector<int>(d));
        labels.resize(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                cin >> features[i][j];
            }
            cin >> labels[i];
        }
    }
    
    const vector<vector<int>>& getFeatures() const { return features; }
    const vector<int>& getLabels() const { return labels; }
    int getNumFeatures() const { return d; }
    int getNumSamples() const { return n; }
};

void problem9B() {
    Dataset dataset;
    dataset.readData();
    
    InformationGainCalculator calculator;
    auto result = calculator.findBestFeature(dataset.getFeatures(), dataset.getLabels());
    
    cout << fixed << setprecision(6);
    cout << result.first << " " << result.second << endl;
}

// Main function to run either part
int main() {
   
    problem9B();
    
    return 0;
}