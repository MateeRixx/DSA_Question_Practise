#include<bits/stdc++.h>
using namespace std;

void zero_to_end(vector<int>&nums)
{
   int i , j;

    while( i<nums.size())
    {
        if(nums[i]==0)
        {
            j=i;
            break;
            

        }

        else{
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                i++;
                j++;

            }
        }

        
    }
    

        
    }

    






int main()
{

          
    vector<int> arr={1,0,0,3,2};
    int size=arr.size();

    zero_to_end(arr);
    

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";

    }

    return 0;

}