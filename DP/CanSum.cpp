#include <bits/stdc++.h>
using namespace std;

bool Cansum(int number, vector<int> sqn,map<pair<int,vector<int>>,bool>dp)
{
   
    if(dp.find({number,sqn})!=dp.end()){
        return dp[{number,sqn}];
        
    }
    if (number == 0)
    {
        return true;
    }

    for (int i = 0; i < sqn.size(); i++)
    {
        int remainder = number - sqn[i];

        if(remainder<0) return false;

     if(Cansum(remainder, sqn,dp)==true)
            
        {
            dp[{number,sqn}]=true;
        }
    }

   dp[{number,sqn}]=false;

   return dp[{number,sqn}];
   
}

int main()
{

    map<pair<int,vector<int>>,bool>dp;
    int number = 8;
    vector<int> sqn = {2,3,5};

    cout << Cansum(number, sqn,dp);

    return 0;
}
