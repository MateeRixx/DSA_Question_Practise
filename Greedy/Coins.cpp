#include <bits/stdc++.h>
using namespace std;

int coins_required(int V)
{
    vector<int> denominaton = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    int count = 0;
    for (int i = denominaton.size() - 1; i >= 0; i--)
    {
        while (denominaton[i] <= V)
        {
            V = V - denominaton[i];
            count++;
        }
    }

    return count;
}

    int main()
    {

        int V = 70;
        int result = coins_required(V);
        cout << result;

        return 0;
    }