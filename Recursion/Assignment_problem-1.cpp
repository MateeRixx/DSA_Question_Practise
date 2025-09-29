#include<bits/stdc++.h>
#include<utility>
#include<vector>
using namespace std;

//function that will return sums from our array 

//another function that will take a array and starign and ending index and give sum 

int sum_of_array(vector<int>nums,int l,int r)
{
    int sum=0;
    for(int i=l-1;i<=r-1;i++)
    {
        sum=sum+nums[i];

    }

    return sum;

}

vector<int> sum_sub_array(int n, vector<int>arr,int q , vector<pair<int,int>>l_r)
{
    vector<int>ans;


    for(int i=0;i<q;i++)
    {
        ans.push_back(sum_of_array(arr,l_r[i].first,l_r[i].second));
    }

    return ans;

}

int main()
{


    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    vector<int>arr;


    //forming our array 

    for(int i=0;i<n;i++)
    {
        int number_from_user;
        cin>>number_from_user;
        arr.push_back(number_from_user);


    }

    //taking another input q for q queries 

    int q;
    cout<<"give value to q:";
    cin>>q;

    vector<pair<int,int>> queries;

    //how to stor q pair as queris in the array:
    for(int i=0;i<q;i++)
    {
        
        int l,r;

        cin>>l>>r;


        queries.push_back({l, r});



    }

    sum_sub_array(n,arr,q,queries);

    cout<<endl;
    for(auto numbers:sum_sub_array(n,arr,q,queries))
    {
        cout<<numbers<<"\t";

    }
    return 0;

}