#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> SingleNumber3(vector<int>&nums)
{
    unordered_map<int,int>hashmap;
    vector<int>ans;

    for(int i=0;i<nums.size();i++)
    {
        hashmap[nums[i]]++;
    }


  
    for(auto key:hashmap)
    {
        if(key.second==1)
        {
            ans.push_back(key.first);

        }
    }


    return ans;





}

int main()
{
    vector<int>temp={1,2,1,3,2,5};
    
    vector<int>ans=SingleNumber3(temp);

    for(int value:ans)
    {
        cout<<value<<"\t";

    }

    return 0;

}