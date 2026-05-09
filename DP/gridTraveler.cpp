#include<bits/stdc++.h>
using namespace std;

//grid traveler 

long long  gridTraveler(int m,int n, map<pair<int,int>,long long>&dp)
{
    
    

    if(dp.find({m,n})!=dp.end())
    {
        return dp[{m,n}];

    }
    
    
    if(m==1 && n==1)
    {
        return 1;

    }
    
    else if(m==0 || n==0)
    {
        return 0;

    }

    dp[{m,n}]=(gridTraveler(m-1,n,dp)+gridTraveler(m,n-1,dp));


    return dp[{m,n}];
    



}




int main()
{

     map<pair<int,int>,long long>dp;
    cout<<gridTraveler(18,18,dp);



    return 0;

}