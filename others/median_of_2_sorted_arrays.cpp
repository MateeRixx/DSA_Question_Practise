<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;


// function that will sort our arrays and merge 2 arrays 

=======
>>>>>>> 7252a779b03117a7ed088b298fced6e7630c1858
vector<int> merged_array(vector<int>&arr_1 , vector<int>&arr_2)
{
    int n1=arr_1.size();
    int n2=arr_2.size();
<<<<<<< HEAD

    //case of empty list 

=======
>>>>>>> 7252a779b03117a7ed088b298fced6e7630c1858
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
<<<<<<< HEAD

    vector<int>arr_3(n1+n2,0);
=======
    vector<int>arr_3;
    

   arr_3.reserve(arr_1.size() + arr_2.size());
>>>>>>> 7252a779b03117a7ed088b298fced6e7630c1858

   arr_3.insert(arr_3.end(), arr_1.begin(), arr_1.end());
   arr_3.insert(arr_3.end(), arr_2.begin(), arr_2.end());

<<<<<<< HEAD
=======

>>>>>>> 7252a779b03117a7ed088b298fced6e7630c1858
     sort(arr_3.begin(),arr_3.end());

     return arr_3;



}

<<<<<<< HEAD
// medians 

double medians(vector<int>&arr_1 , vector<int>&arr_2)

{
    vector<int>mergedArray=merged_array(arr_1 , arr_2);
=======

class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr_1, vector<int>& arr_2) {
        vector<int>mergedArray=merged_array(arr_1 , arr_2);
>>>>>>> 7252a779b03117a7ed088b298fced6e7630c1858
    double ans;


    
    if(mergedArray.size()%2==1)
    {
        ans=mergedArray[mergedArray.size()/2];

    }
    else{
         
        ans=(double)(mergedArray[mergedArray.size()/2]+mergedArray[(mergedArray.size()/2)-1])/2;


    }

    return ans;
<<<<<<< HEAD

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
=======
    }
};
>>>>>>> 7252a779b03117a7ed088b298fced6e7630c1858
