class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> mp;
        
        // Count frequency of each character
        for(char ch : s) {
            mp[ch]++;
        }

        int length = 0;
        bool oddFound = false;

        for(auto it : mp) {

            // If frequency is even
            if(it.second % 2 == 0) {
                length += it.second;
            }
            else {
                // Use even part
                length += it.second - 1;

                // One odd character can be placed in center
                oddFound = true;
            }
        }

        // Add one odd character in middle
        if(oddFound)
            length++;

        return length;
    }
};