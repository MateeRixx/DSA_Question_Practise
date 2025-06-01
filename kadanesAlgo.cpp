#include<bits/stdc++.h>
using namespace std;

int max_subarray(vector<int>&arr)
{

  
   int MAX=LONG_MIN;
   int sum=0;
   
   for(int i=0;i<arr.size();i++)
   {
    sum=sum+arr[i];
    int start=i;
    

    if(sum>MAX)
    {
        MAX=sum;

    }

    if(sum<0)
    {
        sum=0;

    }
      if(MAX<0)
    {
        MAX=0;
        
    }
    
   }

  


   return MAX;




}


int main()
{

    vector<int> sample={-2,1,-3,4,-1,2,1,-5,4};
   
  

    

    cout<<max_subarray(sample);


    
    
    
    return 0;

}