#include <bits/stdc++.h>
using namespace std;

// fibonaci
long long  n = 0;
long long fibo(int n,map<int,long long>&dp)
{
     if (dp.find(n) != dp.end()) {
        return dp[n];
    }

    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    dp[n] = fibo(n - 1,dp) + fibo(n - 2,dp);

    return dp[n];
}

int main()
{
    map<int,long long >dp;
    cout << fibo(50,dp);

    return 0;
}