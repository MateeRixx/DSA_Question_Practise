#include <bits/stdc++.h>
using namespace std;

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

void Heap_insert_element(vector<int> &nums, int value)
{
    nums.push_back(0);
    nums[nums.size() - 1] = value;
    int i = nums.size() - 1;

    while (i > 0 && nums[(i - 1) / 2] < nums[i])
    {
        swap(nums[(i - 1) / 2], nums[i]);
        i = (i - 1) / 2;
    }
}

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

// fucntion to build heap:
void Build_heap(vector<int> &users_array)
{
    int hs = users_array.size();

    for (int i = floor(hs / 2) - 1; i >= 0; i--)
    {
        Max_heapify(users_array, i);
    }
}

int Last_stone_weight(vector<int> &stones)
{
    if (stones.size() == 0) return 0;

    Build_heap(stones);  // build max heap

    while (stones.size() > 1)
    {
        int y = Heap_Extract_max(stones);
        int x = Heap_Extract_max(stones);

        if (y != x)
        {
            Heap_insert_element(stones, y - x);
        }
    }

    return stones.empty() ? 0 : stones[0];
}



// print fucntin

void print(vector<int> &stones)
{
    for (auto elems : stones)
    {
        cout << elems << "\t";
    }
}

int main()
{

    vector<int> stones = {2, 7, 4, 1, 8, 1};

    cout<<Last_stone_weight(stones);
    // Build_heap(stones);

    // while (stones.size() > 0)
    // {
    //     cout << "The current max heap status is:" << endl;
    //     print(stones);
    //     cout << endl;

    //     int y = Heap_Extract_max(stones);
    //     int x = Heap_Extract_max(stones);

    //     if (x == y)
    //     {
    //         cout << "Since both are equal both are already destroyed while extrction" << endl;
    //         cout << "See the heap:" << endl;
    //         print(stones);
    //         cout << endl;
    //     }

    //     if (x != y)
    //     {
    //         // there for x is already removed need to push back y after updating
    //         y = y - x;
    //         Heap_insert_element(stones, y);
    //         cout << "Now check the heap :" << endl;
    //         print(stones);
    //     }

    //     cout << endl;
    // }

   // need to check the heap insrt element

        return 0;
}