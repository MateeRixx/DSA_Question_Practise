#include<bits/stdc++.h>
using namespace std;

//secondryfunction 

bool  no_of_flowers_avail(vector<int>&BloomDay,int mid,int m ,int k)

{
    //this function will tell us that how many flower we have on any particular day we called it mid 

    int counter=0;
    int no_of_bouquotes=0;

    for(int i=0;i<BloomDay.size();i++)
    {
        if(BloomDay[i]<=mid)
        {
            counter++;

        }
        else{
            no_of_bouquotes+=counter/k;
            counter=0;

        }

       
    }

    no_of_bouquotes+=no_of_bouquotes/k;

     if(no_of_bouquotes>m)
     {
        return true;

     }

     else{
        false;

     }



}


//

int min_no_day(vector<int>&BloomDay,int k ,int m)
{
    // k <--- no of flowers that 1 bouqute need to have 
    // M<--- number of bouquets that we need to make 

    sort(BloomDay.begin(),BloomDay.end());

    //base case of -1


        
    
    int low=*min_element(BloomDay.begin(),BloomDay.end());
    int high=*max_element(BloomDay.begin(),BloomDay.end());
    int ans=high;

    if(BloomDay.size()<m*k)
        {
            ans=-1;

       
       
         }

    while(low<=high){
        int mid=low+(high-low)/2;

        if(no_of_flowers_avail(BloomDay,mid,m,k)==false)
        {
            low=mid+1;

        }
        else{
            ans=mid;

        }
    }


    return ans;


    
        

}


int main()
{

    vector<int>nums={7,7,7,7,12,7,7};
    int k=3;
    int  m=2;

    cout<<min_no_day(nums,k,m);


    

    return 0;



}