#include<bits/stdc++.h>
using namespace std;



vector<vector<int>> triplets(int n , vector<int>&nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])
        {
            continue;;

        }
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum =nums[i]+nums[j]+nums[k];
        if(sum<0)
        {
            j++;

        }
        else if(sum>0)
        {
            k--;

        }

        else{
            vector<int> temp={nums[i],nums[j],nums[k]};
            ans.push_back(temp);
            j++;
            k--;

            while(j<k && nums[j]==nums[j-1])
            {
                j++;

            }
            while(j<k && nums[k]==nums[k+1]){
                k--;

            }

        }
        }


    }

    return ans;
    
   

}
int main()
{

    vector<int>nums={-1,0,1,2,-1,-4};
  for (auto triplet : triplets(nums.size(), nums)) {
    for (int num : triplet) cout << num << " ";
    cout << endl;
}
   


    return 0;

}
vector<vector<int>> ans;
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])
        {
            continue;;

        }
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum =nums[i]+nums[j]+nums[k];
        if(sum<0)
        {
            j++;

        }
        else if(sum>0)
        {
            k--;

        }

        else{
            vector<int> temp={nums[i],nums[j],nums[k]};
            ans.push_back(temp);
            j++;
            k--;

            while(j<k && nums[j]==nums[j-1])
            {
                j++;

            }
            while(j<k && nums[k]==nums[k+1]){
                k--;

            }

        }
        }


    }

    return ans;
    
