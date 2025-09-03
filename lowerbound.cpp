#include<bits/stdc++.h>
using namespace std;


int lowerbound(vector<int> &nums , int target)
{
    sort(nums.begin(),nums.end());

    int low=0;
    int high=nums.size()-1;
    
    int ans=nums.size();

    while(low<=high)
    {
        int mid=low+(high-low)/2;
       

        if(nums[mid]>=target)
        {
            ans=mid;
            high=mid-1;


        }

       
        else{
            low=mid+1;


        }
    }

    return ans;


}


int main()
{

    vector<int>nums={2,3,5,8,12,19};
    int target=6;

    cout<<lowerbound(nums,target);




    return 0;

}