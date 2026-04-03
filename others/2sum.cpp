#include<bits/stdc++.h>
using namespace std;

vector<int> maxsum2(vector<int>&nums , int target){
    int maxi=*max_element(nums.begin(),nums.end());

    int a=0;
    int b=0;
    vector<int>ans;


    vector<int>hash(maxi+1,0);

    for(int i=0;i<nums.size();i++){
        hash[nums[i]]+=1;

    }

    for(int i=0;i<hash.size();i++){
        if(hash[i]>0)
        {
            a=i;
            if(hash[target-a]>0)
            {
                b=target-a;
                return {hash[b],i};
                

            }
        }
    }




    return {};




}

int  main()
{

    vector<int> sample={1,2,3,4,5};
    int target=7;
    vector<int> ans=maxsum2(sample,target);
    for(auto numbers:ans)
    {
        cout<<numbers<<"\t";
        
    }


    return 0;

}
#include<bits/stdc++.h>
using namespace std;

vector<int> maxsum2(vector<int>&nums , int target){
    int maxi=*max_element(nums.begin(),nums.end());

    int a=0;
    int b=0;
    vector<int>ans;


    vector<int>hash(maxi+1,0);

    for(int i=0;i<nums.size();i++){
        hash[nums[i]]+=1;

    }

    for(int i=0;i<hash.size();i++){
        if(hash[i]>0)
        {
            a=i;
            if(hash[target-a]>0)
            {
                b=target-a;

            }
        }
    }

    ans={a-1,b-1};


    return ans;



}

int  main()
{

    vector<int> sample={1,2,3,4,5};
    int target=7;
    vector<int> ans=maxsum2(sample,target);
    for(auto numbers:ans)
    {
        cout<<numbers<<"\t";
        
    }


    return 0;

}