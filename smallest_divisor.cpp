#include<bits/stdc++.h>
using namespace std;

//function that will give us summation divided by number 

int sum_by_div_func(vector<int>&nums,int den)
{
    float sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum=sum+ceil((double)nums[i]/den);

    }

    return ceil(sum);

}

int smallest_divisor(vector<int>&nums,int k)
{
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    int ans=high;
    

    // 
    if(nums.size()>k)
    {
        return -1;
        
    }



    while(low<=high)
    {
        int mid=low+(high-low)/2;
         


        if(sum_by_div_func(nums,mid)<=k)
        {
          ans=mid;
          high=mid-1;

          




        }

        

        else{
           

            low=mid+1;
            

        }
    }

    return ans ;

}


int main()
{

    vector<int>nums={1,10,3,10,2};
    int den=3;
    int threshold=2;

    cout<<smallest_divisor(nums,threshold);



   



    return 0;

<<<<<<< HEAD
}
=======
}
>>>>>>> 7252a779b03117a7ed088b298fced6e7630c1858
