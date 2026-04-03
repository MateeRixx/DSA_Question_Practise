#include<bits/stdc++.h>
using namespace std;

int mini_in_array(vector<int>&nums)
{
    int low=0;
    int high=nums.size();
    int ans=INT_MAX;
    int mini=INT_MIN;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(nums[low]<=nums[mid])
        {
            //means left half is sorted 
            mini=nums[low];
            if(ans>=mini)
            {
                ans=mini;

            }

            low=mid+1;

        }
        else if(nums[mid]<=nums[high])
        {
            //means right half is sorted 

            mini=nums[mid];
            if(ans>mini)
            {
                ans=mini;

            }

            high=mid-1;


        }

       


    }

    return ans;

}


int main()
{

    vector<int>nums={11,13,15,17};

    cout<<mini_in_array(nums);


    return 0;

}
