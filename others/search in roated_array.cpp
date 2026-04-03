#include<bits/stdc++.h>
using namespace std;

int linear_search(vector<int>&nums ,int start, int end, int target)
{
    for(int i=start;i<=end;i++)
    {
        if(nums[i]==target)
        {
            return i;

        }
    }

    return -1;

}

int search_in_rotation(vector<int>&nums , int target)
{
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=-1;


    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(nums[mid]==target)
        {
            
            return mid;



        }
        else if (nums[low]<=nums[mid])
        {
            //means left part is sorted and he have to look for left half 

            if(nums[low]<=target && target<nums[mid])
            {
                high=mid-1;

            }
            else{
                low=mid+1;

            }
            
    }

   //right half is sorted 
   else{
    if(nums[mid]<target && target<=nums[high])
    {
        low=mid+1;
        
    }
    else{
        high=mid-1;

    }
   }

   

}
     return -1;

}


int main()
{

    vector<int>nums={7,8,9,1,2,3,4,5,6};
    int target=1;

    cout<<search_in_rotation(nums,target);




    return 0;

}
