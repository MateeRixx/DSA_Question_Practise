#include<bits/stdc++.h>
using namespace std;


int LongestSub(vector<int>nums){

    if(nums.size()==0)
    {
        return 0;

    }
    int longest=1;

    unordered_set<int>temp;
    for(int i=0;i<nums.size();i++)
    {
            temp.insert(nums[i]);

    }

    for(auto numbers:temp){
        if(temp.find(numbers-1)==temp.end())
        {
            int count=1;
            int x=numbers;
            while(temp.find(x+1)!=temp.end()) // not linear search 
            {
                x=x+1;
                count++;

            }
            longest=max(longest,count);


        }
    }
    return longest;
    
}

int main()
{
    vector<int> sample={102,4,100,1,101,3,2,1,1};
   
   cout<<LongestSub(sample);


   

    return 0;

}
