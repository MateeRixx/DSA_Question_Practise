#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int>&nums , int low , int high , int number)
{
    int mid=low+(high-low)/2;

    if(low>high)
    {
        return -1;

    }

    if(nums[mid]==number)
    {
        return mid;

    }
    else if (number>nums[mid])
    {
       return BinarySearch(nums,mid+1,high,number);

    }
    else if(number<nums[mid])
    {
        return BinarySearch(nums,low,mid-1,number);

    }

   


    
}




int main()
{

    vector<int> nums={4,5,6,7,9,12,16,17};
    int n=nums.size();
    int Number=19;
    int index=BinarySearch(nums,0,n-1,Number);

    if(index==-1)
    {
        cout<<"Number not present:";

    }
    cout<<"your number is at index:"<<index;

    cout<<endl;
    cout<<nums[index];




    return 0;

}