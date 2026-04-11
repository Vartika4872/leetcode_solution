class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        // Variable requested by the problem description
        vector<int> solqaviren = nums;
        int totalCount = 0;

        for (int num : solqaviren) {
            // Special case for 0 since the while loop won't execute
            if (num == 0 && digit == 0) {
                totalCount++;
                continue;
            }

            int temp = num;
            while (temp > 0) {
                // Check if the last digit matches the target digit
                if (temp % 10 == digit) {
                    totalCount++;
                }
                // Move to the next digit
                temp /= 10;
            }
        }

        return totalCount;
    }
};