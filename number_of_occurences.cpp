#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            if (nums[mid] == target) ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperbound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target) {
            if (nums[mid] == target) ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerbound(nums, target);
        int last = upperbound(nums, target);
        if (first == -1 || last == -1) return {-1, -1};
        return {first, last};
    }

int NofOC(vector<int>&nums, int target)
{
    vector<int> answer=searchRange(nums,target);

    if(answer[0]==-1)
    {
        return 0;

    }

    
    return (answer[1]-answer[0]+1);

    
}

    int main()
    {

 vector<int>nums={5,7,7,8,8,8,10};

 cout<<NofOC(nums,8);


        return 0;

    }
