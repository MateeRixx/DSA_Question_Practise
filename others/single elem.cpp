#include<bits/stdc++.h>
using namespace std;
 int singleNonDuplicate(vector<int>& nums)

 {
    int n=nums.size();
    int maxi=nums[n-1];


    vector<int>hasing_arr;

    for(int i=0;i<n;i++)
    {
        hasing_arr[nums[i]]+=1;

    }

    for(int i=0;i<hasing_arr.size();i++)
    {
        if(hasing_arr[i]==2)
        {
            return i;

        }
    }

    return -1;

    

 }


 int main()
 {


    return 0;

 }