#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void problem8A() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Using min-heap to get k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : arr) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    reverse(result.begin(), result.end());
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;
}


void problem8B() {
    int n;
    cin >> n;
    vector<double> xValues(n);
    
    for (int i = 0; i < n; i++) {
        cin >> xValues[i];
    }
    
    double t;
    int s;
    cin >> t >> s;
    
    for (double x : xValues) {
        if (s * (x - t) <= 0) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}


int main()
{


    int input;
    cout<<"Enter 1 for TASK-A and 2 for TASK-B:";
    cin>>input;


    if(input==1)
    {
        problem8A();


    }

    else if (input==2)
    {
        problem8B();

    }

    else{
        cout<<-1;

    }

    return 0;


}