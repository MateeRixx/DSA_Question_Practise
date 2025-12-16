#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

// Sliding Window Max APproach -1

// vector<int>Max_sliding_window(vector<int>&nums,int k)
// {
//    int *l=&nums[0];
//    int *r=&nums[k];
//    int temp=nums.size()-1;
//    vector<int>ans;

//    if (nums.empty() || k > nums.size() || k == 0)
//         return ans;
//          int windows = nums.size() - k + 1;

//    while(windows--)
//    {
//         int max=*max_element(l,r);
//         ans.push_back(max);
//         l++;
//         r++;

//    }

//    return ans;

// }

// heap

vector<int> max_sliding_window(vector<int> &nums, int k)
{
    vector<int> ans;
    if (k <= 0 || nums.empty() || k > (int)nums.size())
        return ans;
    deque<int> dq;
    for (int i = 0; i < (int)nums.size(); ++i)
    {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;

}

int main()
{

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

    vector<int> ans = max_sliding_window(nums, 3);

    for (auto items : ans)
    {
        cout << items << "\t";
    }

    return 0;
}
