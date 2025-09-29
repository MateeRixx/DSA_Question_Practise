#include<bits/stdc++.h>
using namespace std;


// function that will sort our arrays and merge 2 arrays 

vector<int> merged_array(vector<int>&arr_1 , vector<int>&arr_2)
{
    int n1=arr_1.size();
    int n2=arr_2.size();

    //case of empty list 

    if(n1==0 ){
        return arr_2;

    }

    if(n2==0)
    {
        return arr_1;

    }

    if(n1==0 && n2==0)
    {
        return {};

    }

    vector<int>arr_3(n1+n2,0);

   arr_3.insert(arr_3.end(), arr_1.begin(), arr_1.end());
   arr_3.insert(arr_3.end(), arr_2.begin(), arr_2.end());

     sort(arr_3.begin(),arr_3.end());

     return arr_3;



}

// medians 

double medians(vector<int>&arr_1 , vector<int>&arr_2)

{
    vector<int>mergedArray=merged_array(arr_1 , arr_2);
    double ans;


    
    if(mergedArray.size()%2==1)
    {
        ans=mergedArray[mergedArray.size()/2];

    }
    else{
         
        ans=(double)(mergedArray[mergedArray.size()/2]+mergedArray[(mergedArray.size()/2)-1])/2;


    }

    return ans;

}


int main()
{

    vector<int>arr1={};
    vector<int>arr2={1};

    vector<int>ans=merged_array(arr1,arr2);
    for(auto numbs:ans)
    {
        cout<<numbs;

    }

    





    

  
    return 0;

}