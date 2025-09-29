#include<bits/stdc++.h>
using namespace std;


//function that will count 

int count_student(vector<int>&nums ,int pages)
{
    int student=1;
    long long pages_student=0;
    for(int i=0;i<nums.size();i++)
    {
        if(pages_student+nums[i]<=pages)
        {
            pages_student+=nums[i];

        }
        else{
            student+=1;
            pages_student=nums[i];

        }
    }

    return student;

}


//binary search function 

int findPages(vector<int>&nums,int m)
{
    int n=nums.size();

    int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(), nums.end(), 0);

    if(m>nums.size())
    {
        return -1;

    }

    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int no_of_student=count_student(nums,mid);
        if(no_of_student>m)
        {
            low=mid+1;

        }

        else{
            high=mid-1;

        }
    }

    return low;

}



int main()
{

    vector<int>nums={25,46,28,49,24};
    int m=4;


    cout<<findPages(nums,m);



    return 0;

}