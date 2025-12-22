#include<bits/stdc++.h>
using namespace std;

int rank_return(vector<int>n2,int number)
{
    for(int i=0;i<n2.size();i++)
    {
        if(number==n2[i])
        {
            return i+1;
        }
    }

    return -1;


}

vector<int> replaceWithRank(vector<int>& arr) {
        vector<int>arr_2(arr);
        //sort our 2nd array 
        sort(arr_2.begin(),arr_2.end());
        auto it=unique(arr_2.begin(),arr_2.end());
        arr_2.erase(it, arr_2.end());

        //replacing 

        for(int i=0;i<arr.size();i++)
    {
        int position=rank_return(arr_2,arr[i]);
        swap(arr[i],position);


    }

    return arr;



    }



int main()
{


    
    vector<int>nums={40, 10, 20, 40, 30};
    replaceWithRank(nums);
    for(auto elems:nums)
    {
        cout<<elems<<"\t";

    }

    
    

    

    

    


   

   

    return 0;

}