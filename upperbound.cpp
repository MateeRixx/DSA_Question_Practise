#include<bits/stdc++.h>
using namespace std;

int Upperbound(vector<int>&nums,int target)
{
    int low=0;
    int high=nums.size()-1;
    int ans=nums.size();

    while(low<=high)
    {
        int mid=low+(high-low)/2;
        
        
         if(nums[mid]>target) // it is the only point of difference for lower bound we had >= 
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


    vector<int>nums={2,3,6,7,8,8,11,11,11,12};
    int Target;
    cout<<"Give value to your target:";
    cin>>Target;

    cout<<Upperbound(nums,Target);



    return 0;

}