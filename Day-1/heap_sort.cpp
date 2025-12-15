#include <bits/stdc++.h>
using namespace std;

void Max_heapify(vector<int> &nums, int i, int heapSize)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int largest = i;

    if (L < heapSize && nums[L] > nums[largest])
        largest = L;

    if (R < heapSize && nums[R] > nums[largest])
        largest = R;

    if (largest != i)
    {
        swap(nums[i], nums[largest]);
        Max_heapify(nums, largest, heapSize);
    }
}

void Heap_sort(vector<int> &nums)
{
    int n = nums.size();

    // 1️⃣ Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Max_heapify(nums, i, n);
    }

    // 2️⃣ Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(nums[0], nums[i]);
        Max_heapify(nums, 0, i);
    }
}

int main()
{
    vector<int> nums = {6, 5, 3, 2, 8, 10, 9};
    Heap_sort(nums);

    for (auto val : nums)
        cout << val << " ";

    return 0;
}
