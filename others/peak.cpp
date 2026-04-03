#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }
    return low; // or high, both are same here
}

// Example usage:
int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int peakIdx = findPeakElement(nums);
    cout << "Peak element index: " << peakIdx << endl;
    cout << "Peak element value: " << nums[peakIdx] << endl;
    return 0;
}
