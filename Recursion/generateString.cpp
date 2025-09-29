#include<bits/stdc++.h>
using namespace std;

vector<string> GenerateString(int n)
{
    vector<string> N_1 = {"0", "1"};
    if(n == 1)
    {
        return N_1;
    }

    for(int i = 2; i <= n; i++)
    {
        vector<string> temp;
        for(int j = 0; j < N_1.size(); j++)
        {
            if(N_1[j].back() == '1')
            {
                temp.push_back(N_1[j] + "0");
                temp.push_back(N_1[j] + "1");
            }
            else
            {
                temp.push_back(N_1[j] + "1");
            }
        }
        N_1 = temp;
    }
    return N_1;
}

int main()
{
    int n;
    cout << "Give value of N:";
    cin >> n;

    vector<string> ans = GenerateString(n);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
