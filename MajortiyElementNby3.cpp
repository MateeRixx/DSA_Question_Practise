#include<bits/stdc++.h>
using namespace std;
vector<int> AppearNby3(vector<int>&nums)
{
    int count_1=0;
    int count_2=0;
    int element_1=INT_MIN;
    int element_2=INT_MIN;

    for(int i=0;i<nums.size();i++)
    {
        if(count_1==0 && nums[i]!=element_2)
        {
            count_1=1;
            element_1=nums[i];

        }

        else if(count_2==0 && nums[i]!=element_1)
        {
            count_2=1;
            element_2=nums[i];

        }

        else if(nums[i]==element_1){
            count_1++;

        }
        else if(nums[i]==element_2){
            count_2++;
            
        }
        else{
            count_1--;
            count_2--;

        }

        





    }

    vector<int> ls;
        count_1=0;
        count_2=0;

        for(int i=0;i<nums.size();i++)
        {
            if(element_1==nums[i])
            {
                count_1++;

            }

            
            else if(element_2==nums[i])
            {
                count_2++;
                
            }
        }

        int mini=(int)(nums.size()/3)+1;
        if(count_1>=mini)
        {
            ls.push_back(element_1);

        }

      

        if(count_2>=mini)
        {
            ls.push_back(element_2);
            
        }

        sort(ls.begin(),ls.end());


        return ls;



    





}
int main()
{

    vector<int> sample={1,1,1,1,3,2,2,2};
    int N=sample.size();
    
    for(auto numbers:AppearNby3(sample))
    {
        cout<<numbers<<" ";

    }
    


    return 0;

}