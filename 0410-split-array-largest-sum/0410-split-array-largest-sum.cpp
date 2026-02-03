class Solution {
public:
    int countSubarrays(vector<int>& nums, long long maxSum) {
        int parts = 1;
        long long curr = 0;

        for (int x : nums) {
            if (curr + x <= maxSum) {
                curr += x;
            } else {
                parts++;
                curr = x;
            }
        }
        return parts;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countSubarrays(nums, mid) > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int)low;
    }
};

