#include<bits/stdc++.h>
using namespace std;

int insertIndex(vector<int>&nums, int target){

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

    void  ceilandFloor(vector<int>&nums , int number)
    {
        int target=number;
        int ciel;
        int floor;

        int inserting_index=insertIndex(nums,target);

        if(nums[inserting_index]==number)
        {
            ciel=floor=inserting_index;

        }
        else{
        ciel=inserting_index-1;
        floor=inserting_index+1;
        }

        cout<<"ciel is :"<<nums[ciel]<<endl;
        cout<<"floor is :"<<nums[floor]<<endl;


        

    }

    int main()
    {

        vector<int> arr={10,20,25,30,40};
        int m=25;
        ceilandFloor(arr,m);



    }
