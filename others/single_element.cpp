class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=1;
    int high=nums.size()-2;
    
    int index;
    int ans;

    

    //base of single size 
  if(nums.size() == 1)
    return nums[0];
    if(nums[0] != nums[1])
    return nums[0];
    // checking the first element where we dont have left index

   

     // checking the last element where we dont have right index

    if(nums[nums.size()-1]!=nums[nums.size()-2])
    {
        index=nums.size()-2;
        ans=nums[index];

        return ans;


    }

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
        {
            index=mid;
            ans=nums[mid];
            return ans;
            


        }

        else if(nums[mid]==nums[mid-1] && mid%2==1 || (mid %2==0 && nums[mid]==nums[mid+1]) )
        {
            //element is on the right and we have to eliminate our left half 

            low=mid+1;

        }

        else{
            // must be in the other half 

            high=mid-1;

        }
    }


    

 

  return -1;
    }
};
