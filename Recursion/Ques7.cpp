#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

// Part A: Range Minimum Query using Segment Tree
class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    void buildTree(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node + 1, start, mid);
            buildTree(arr, 2 * node + 2, mid + 1, end);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int queryRange(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return INT_MAX;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMin = queryRange(2 * node + 1, start, mid, l, r);
        int rightMin = queryRange(2 * node + 2, mid + 1, end, l, r);
        return min(leftMin, rightMin);
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
    }
    
    int query(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }
};

void partA() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    SegmentTree st(arr);
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << endl;
    }
}

// Part B: Majority Class
void partB() {
    int n;
    cin >> n;
    
    int count0 = 0, count1 = 0;
    for (int i = 0; i < n; i++) {
        int label;
        cin >> label;
        if (label == 0) {
            count0++;
        } else {
            count1++;
        }
    }
    
    if (count1 > count0) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
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