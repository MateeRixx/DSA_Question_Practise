#include<bits/stdc++.h>
using namespace std;

int NoofSubArray(vector<int>&nums,int K)
{
    
    map<int,int> mpp;
    mpp[0]=1;
    int preSum=0;
    int cnt=0;

    for(int i=0;i<nums.size();i++){
        preSum=preSum+nums[i];
        int remove=preSum-K;
        cnt=cnt+mpp[remove];
        mpp[preSum]+=1;

    }
    return cnt;
    
}


int main()
{

        vector<int> sample={1,2,3,-3,1,1,1,4,2,-3};
        cout<<NoofSubArray(sample,3);


    return 0;

}
