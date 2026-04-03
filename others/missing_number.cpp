#include<bits/stdc++.h>
using namespace std;

//function of linear search 

// bool Lsearch(vector<int> &arr , int Number)
// {
//     for(int i=0;i<arr.size();i++)
//     {
//         if(arr[i]==Number){
//             return true;

//         }
       
//     }
     
//      return false;
            

        
// }

// int missing_number(vector<int>&arr,int N)
// {
//     int temp=1;
//     while(temp<=N)
//     {
//         if(Lsearch(arr,temp)==true)
//         {
//             temp++;

            

//         }

//         else{
//             return temp;

//         }
//     }
    

   

// }

//optimal:using hashing
 int missingNumber(vector<int>& nums) {
        int range=nums.size();
        int ans=0;

        vector<int>temp (range+1,0);

        for(int i=0;i<nums.size();i++)
        {
            temp[nums[i]]+=1;

        }

        for(int i=0;i<=nums.size();i++)
        {
            if(temp[i]==0)
            
            return i;


        }

        return -1;
        
    }



int main()
{

    vector<int> sample={0,1,2,4};
    
    
    cout<<missingNumber(sample);


    return 0;

}