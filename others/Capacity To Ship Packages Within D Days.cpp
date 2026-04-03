#include<bits/stdc++.h>
using namespace std;

//fucntion that will give summation of terms 
int summation(vector<int>&weights)
{
    int n=weights.size();

    int sum=0;

    for(int i=0;i<n;i++){
        sum+=weights[i];

    }

    return sum;

}



int min_capacity(vector<int>&weights , int d)
{

    int load=0;
    int days=1;

    for(int i=0;i<weights.size();i++)
    {
        if(weights[i]+load>d)
        {
            days+=1;
            load=weights[i];

        }
        else{
            load=load+weights[i];

        }
    }

    return days;



}

int shipWithinDays(vector<int>& weights, int days)
{
   
    int low=*max_element(weights.begin(),weights.end());
    int high=summation(weights);
    int ans=high;

    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(min_capacity(weights,mid)<=days)
        {
            ans=mid;
            high=mid-1;

        }

        else{
            low=mid+1;

        }
    }

    return ans;

}


int main()
{


    vector<int>nums={1,2,3,4,5,6,7,8,9,10};
    int days=5;

    cout<<shipWithinDays(nums,days);


    return 0;

}
