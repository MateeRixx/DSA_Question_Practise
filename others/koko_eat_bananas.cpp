#include<bits/stdc++.h>
#include<cmath>
using namespace std;


//function that give some of numbers:

int sum_of_pile(vector<int>&piles ,int perhr )
{
    
    int n=piles.size();

    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+ceil(((double)piles[i]/perhr));

    }


    return ceil(sum) ;

}

//int min value of k function 

int min_k(vector<int>&piles , int h)
{
    //sorting our array to see 
    sort(piles.begin(), piles.end());

    int low=1;
    int high=piles[piles.size()-1];
    int ans;
    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(sum_of_pile(piles,mid)==h)
        {
            ans=mid;
           

        }
        else if(sum_of_pile(piles,mid)<h)
        {
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

    vector<int>nums={30,11,23,4,20};
    int hours=6;
    int k=1;

    // cout<<min_k(nums,hours,k);

    cout<<min_k(nums,hours,k);




    return 0;

}
