#include<bits/stdc++.h>
using namespace std;

int profit(vector<int>&rates)
{
    int size=rates.size();
    int mini=rates[0];
    int profit=0;
    for(int i=1;i<size;i++)
    {
        int cost=rates[i]-mini;
         profit=max(profit,cost);
        mini=min(mini,rates[i]);

    }

    return profit;
    
}

int  main(){


    vector<int> stock_rates;


    return 0;

}