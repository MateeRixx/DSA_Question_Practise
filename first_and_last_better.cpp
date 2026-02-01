#include<bits/stdc++.h>
using namespace std;

 int lowerbound(vector<int>&nums , int target)
 {
    int low=0;
    int high=nums.size()-1;
    int ans=nums.size();



    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(target<=nums[mid])
        {
            if (nums[mid] == target) ans = mid;
            high = mid - 1;
            

        }
        else{
           
            low=mid+1;


        }
        
    }
    return ans;

 }

 int upperbound(vector<int>&nums , int target)
 {
    int low=0;
    int high=nums.size()-1;
    int ans=nums.size();


    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(target<nums[mid])
        {
             if (nums[mid] == target) ans = mid;
            high = mid - 1;



        }
        else{
            low=mid+1;

        }
        
    }
    return ans-1;

 }

 pair<int,int> firstandlast(vector<int>&nums,int target)
 {
    int last=upperbound(nums,target);
    int first=lowerbound(nums,target);
     pair<int,int> ans;


    if(first >=nums.size() ||  nums[first] != target ){
        ans={-1,-1};

    }
    if(last>=nums.size() || nums[last]!=target){

        ans={-1,-1};



    }
    if(nums[first]!=target || nums[last]!=target){
        ans={-1,-1};

    }

    else{
        ans={first,last};

    }
   

    return ans;

    
 }

int main()
{

    vector<int>nums={5,7,7,8,8,10};
    pair<int,int> ans;

    ans=firstandlast(nums,6);
    cout<<ans.first<<endl;
    cout<<ans.second;





    return 0;

}
