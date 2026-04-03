int sum_of_pile(vector<int>&piles, int perhr) {
    int n = piles.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (piles[i] + perhr - 1) / perhr; // integer ceil
    }
    return sum;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (sum_of_pile(piles, mid) <= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
