#include<iostream>
#include<vector>
using namespace std;


vector<int> singleNumber(vector<int>& nums){

    vector<int>ans;
    int ones=0;
    int twos=0;

    for(int i=0;i<nums.size();i++)
    {
        ones=(ones^nums[i]) & (~twos);
        ans.push_back(ones);
        ones=0;

        twos=(twos^nums[i])&(~ones);


    }

    return ans;

}





int main()
{
    vector<int>nums=

    return 0;

}