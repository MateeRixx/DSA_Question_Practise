#include <bits/stdc++.h>
using namespace std;

void sort_0_1_2(vector<int> &nums)
{
    int size = nums.size();
    int low = 0;
    int mid = 0;
    int high = size - 1;

    // base case
    if (size == 1 || size == 0)
    {
        if (nums[0] == 0 || nums[0] == 1 || nums[0] == 2)
        {
            return;
        }
    }

    while (mid <=high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }

        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main()
{

    vector<int> sample;
    int times;
   

    cout << "select a desire length of your numsay:";
    cin >> times;
     sample.resize(times);

    for (int i = 0; i < times; i++)
    {
        int num;

        cout << "Enter you number:";
        cin >> num;
        sample.push_back(num);
    }

    sort_0_1_2(sample);

    for (int i = 0; i < times; i++)
    {
        cout << sample[i] << " ";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void sort_0_1_2(vector<int> &nums)
{
    int size = nums.size();
    int low = 0;
    int mid = 0;
    int high = size - 1;

    // base case
    if (size == 1 || size == 0)
    {
        if (nums[0] == 0 || nums[0] == 1 || nums[0] == 2)
        {
            return;
        }
    }

    while (mid <=high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }

        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main()
{

    vector<int> sample;
    int times;
   

    cout << "select a desire length of your numsay:";
    cin >> times;
     sample.resize(times);

    for (int i = 0; i < times; i++)
    {
        int num;

        cout << "Enter you number:";
        cin >> num;
        sample.push_back(num);
    }

    sort_0_1_2(sample);

    for (int i = 0; i < times; i++)
    {
        cout << sample[i] << " ";
    }

    return 0;
}