#include<bits/stdc++.h>
using namespace std;

//test function to print our array 

void Print(vector<int>nums){
    int n=nums.size();

    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";

    }
}



int KthSmallest(vector<int>&nums , int k)
{
    int maxi=*max_element(nums.begin(),nums.end());
    int counter=0;
    int ans;



    vector<int>temp(2001,0);
    
    for(int i=1;i<nums.size();i++)
    {
        temp[nums[i]]+=1;

    }

    //searching in temp

    for(int i=0;i<temp.size();i++)
    {

        //speical case 

        if(k==1 && counter==0)
        {
            counter=1;

        }
        if(temp[i+1]==0 && counter<k)
        {
            counter++;
            ans=i;



        }
    }
  


    return ans;


}


int main()
{

    vector<int> nums={1,2};
    int k=1;

    cout<<KthSmallest(nums,k);


    



    return 0;

}
