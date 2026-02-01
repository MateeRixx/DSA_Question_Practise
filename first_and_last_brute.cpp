#include<bits/stdc++.h>
using namespace std;

pair<int,int> firstandlast(vector<int>&nums,int target)
{
    int first=-1;
    int last=-1;
    pair<int,int> ans;

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==target){
           
            if(first==-1){
                first=i;

            }

            last=i;


            
            

        }

         if(nums[i]==target && first !=-1)
        {
            last=i;

        }

        
    }
    ans={first,last};


    return  ans;

}

int main()
{

    vector<int>nums={2,4,6,8,8,8,11,13};
    pair<int,int> ans;

    ans=firstandlast(nums,14);
    cout<<ans.first<<endl;
    cout<<ans.second;





    return 0;

}
