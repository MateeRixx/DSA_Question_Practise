#include<iostream>
#include<vector>
#include <climits>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;

int kth_largest(vector<int>arr,int kth )
{
   //since we want 2nd largest 
    int k=kth;
   //base check

   //single element 

   if(arr.size()==1)
   {
    return arr[0];

   }

    if(k>arr.size())
    {
        return INT_MIN;

    }

    if(k==0)
    {
        return INT_MIN;

    }

    if(arr.size()==0){
        return INT_MIN;

    }

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<arr.size()-1;j++){
            
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);

            }

        }


    }


    return (arr[arr.size()-k]);


}




//removing dublicates from an array 

// try to do this with the helpof sets 

vector<int> removed_dublicates(vector<int>nums)
{
    set<int>temp;
    vector<int>ans;

    for(int i=0;i<nums.size();i++)
    {
        temp.insert(nums[i]);

    }

   


    for(int numbers:temp)
    {
        ans.push_back(numbers);

    }

    return ans;


}

//area with largest perimeter and non zero area 

 int largestPerimeter(vector<int>& nums) {
         
         //base cases 

         //area condition 


         
         
         
         if(nums.size()<=2)
         {
            return 0;

         }

         
         
         
         
         
         int m; 
        int perimeter=0;
        //sorted the function 
        sort(nums.begin(),nums.end());


        for(m=nums.size()-1; m>=2 ;m--)
        {
            int S=nums[m]+nums[m-1]+nums[m-2];
            int Area=(S*(S-nums[m])*(S-nums[m-1])*(S-nums[m-2]));
            //avoider 

           
             if(((nums[m]<nums[m-1]+nums[m-2])) && Area>0)
            {
                perimeter=nums[m]+nums[m-1]+nums[m-2];
                
                return perimeter;


            }
            

           
        }

        return 0;
    }




int main()
{
    
    vector<int>nums={3,6,2,3};
    cout<<largestPerimeter(nums);


   

    return 0;

}