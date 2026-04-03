#include<bits/stdc++.h>
using namespace std;

//removing dublicated 

 int removeDuplicates(vector<int>& nums)
 {
    set<int> temp_set;
    for(int i=0;i<nums.size();i++)
    {
    temp_set.insert(nums[i]);

    }

   int k=temp_set.size();
   nums.resize(k);

  nums.assign(temp_set.begin(), temp_set.end());
  for(auto number : nums) {
        cout << number << "\t";
    }
    return k;



  

 }


int main()
{

    vector<int> nums={4,4,4,5,6,3,3,3,7};
    cout<<endl;
    
    cout<<removeDuplicates(nums);
    cout<<endl;


}