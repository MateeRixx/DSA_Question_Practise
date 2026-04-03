#include<bits/stdc++.h>
using namespace std;

//fucntion that will give summation of sub array 

int summation(vector<int>&arr , int start , int end)
{
    int sum=0;
    for(int i=start;i<=end;i++)
    {
        sum=sum+arr[i];

    }

    return ans;

}

int countPartitions(vector<int> &a, int maxSum) {
    int n = a.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + a[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += a[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}


int splitArray(vector<int>& nums, int k)
{
    int low=*max_element(nums.begin(),nums.end());
    int high=summation(nums,nums.begin(),nums.end());

    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int partitions = countPartitions(a, mid);

        if(partitions>k)
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



    return 0;

}