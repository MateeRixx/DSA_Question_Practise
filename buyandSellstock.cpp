<<<<<<< HEAD
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

=======
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

>>>>>>> e3ba7b8a3b9f9a87a66525c352a369438b865a3c
}