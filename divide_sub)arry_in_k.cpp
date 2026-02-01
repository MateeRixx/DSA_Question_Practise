int summation(vector<int>&arr , int start , int end)
{
    int sum=0;
    for(int i=start;i<=end;i++)
    {
        sum=sum+arr[i];

    }

    return sum;

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




class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
     int high = accumulate(nums.begin(), nums.end(), 0);

    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int partitions = countPartitions(nums, mid);

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
};
