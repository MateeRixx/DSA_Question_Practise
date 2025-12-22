#include <bits/stdc++.h>
using namespace std;

// function that will take vector of chars as input and return an vector of pair to form queue

int leastInterval(vector<char> &tasks, int n)
{
    // sabse pehele har task ki frequency count karo
    unordered_map<char, int> freq;
    ;
    for (char task : tasks)
    {
        freq[task]++;
    }

    // map ke data se max heap bano

    priority_queue<int> maxHeap;
    for (auto &it : freq)
    {
        maxHeap.push(it.second);
    }

    // ab cooldown queue banao of pair
    queue<pair<int, int>> cq;
    // cpu ka time track karne ke liyea ek variable

    int time = 0;

    // logic--> run a loop while cq or maxHeap is not empty

    while (!maxHeap.empty() || !cq.empty())
    {
        time++;

        if (!maxHeap.empty())
        {
            // agar heap khaali nhi hai mltb usme task hai to ecexute karo
            int cnt = maxHeap.top();
            maxHeap.pop();
            cnt--; // jab top pe jo task ho jaye to minus karo

            if (cnt > 0)
            {
                cq.push({cnt, time + n});
            }
        }
        if (!cq.empty() && cq.front().second == time)
        {
            maxHeap.push(cq.front().first);
            cq.pop();
        }
    }

    // cooldown complete hua ya nhi check karo

    return time;
}

int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};

    cout << leastInterval(tasks, 2);
    return 0;
}