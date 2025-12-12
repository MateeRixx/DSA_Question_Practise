#include <bits/stdc++.h>
using namespace std;

// algo for heapify

void Max_heapify(vector<int> &nums, int i)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int largest = i;

    if (L < nums.size() && nums[L] > nums[largest])
    {
        largest = L;
    }

    if (R < nums.size() && nums[R] > nums[largest])
    {
        largest = R;
    }

    if (largest != i)
    {
        swap(nums[i], nums[largest]);
        Max_heapify(nums, largest);
    }

    //  return nums;
}

// min heapify :

void Min_heapify(vector<int> &nums, int i)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int smallest = i;

    if (L < nums.size() && nums[L] > nums[smallest])
    {
        smallest = L;
    }

    if (R < nums.size() && nums[R] > nums[smallest])
    {
        smallest = R;
    }

    if (smallest != i)
    {
        swap(nums[i], nums[smallest]);
        Min_heapify(nums, smallest);
    }

    //  return nums;
}

// try out new fucntion that are mentioned in the algo  video

// 1st Extract max

int Heap_Extract_max(vector<int> &nums)
{
    if (nums.size() < 1)
    {
        // cant extract out from a empty heap

        cout << "Heap under flow ";
    }

    int max = nums[0];

    nums[0] = nums[nums.size() - 1];
    nums.pop_back();

    Max_heapify(nums, 0);

    return max;
}

/// insert element Algorithm
void Heap_insert_element(vector<int> &nums, int value)
{
    nums.push_back(0);
    nums[nums.size() - 1] = value;
    int i = nums.size() - 1;

    while (i > 0 && nums[(i - 1) / 2] < nums[i])
    {
        swap(nums[(i - 2) / 2], nums[i]);
        i = (i - 1) / 2;
    }
}

// Decrease key algoruth m

void Heap_decerease_key(vector<int> &nums, int i, int key)
{
    if (nums[i] < key)
    {
        cout << "Wrong operation";
    }

    nums[i] = key;
    Max_heapify(nums, i);
}

// incraese key fucntion

void Heap_increase_key(vector<int> &nums, int i, int key)
{
    if (key > nums[i])
    {
        cout << "Wrong operation ";
    }

    nums[i] = key;

    while (i > 0 && nums[i / 2] < nums[i])
    {
        swap(nums[i], nums[i / 2]);
        i = i / 2;
    }
}

// build heap functions

void Build_heap(vector<int> &users_array)
{
    int hs = users_array.size();

    for (int i = floor(hs / 2) - 1; i > 0; i--)
    {
        Max_heapify(users_array, i);
    }
}

int main()
{
    vector<int> nums = {10, 20, 5, 15, 25};

    Heap_insert_element(nums, 18);

    cout << "This is before extraction\n";

    for (auto things : nums)
    {
        cout << things << "\t";
    }

    cout << endl;

    cout << Heap_Extract_max(nums);

    cout << endl;

    cout << "This is after  extraction\n";

    for (auto things : nums)
    {
        cout << things << "\t";
    }

    return 0;
}
