class Solution {
public:
    //string longestPalindrome(string s) {

    string expand(string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string result = "";

        for (int i = 0; i < s.length(); i++) {
            string odd = expand(s, i, i);       // odd length
            string even = expand(s, i, i + 1);  // even length

            if (odd.length() > result.length())
                result = odd;

            if (even.length() > result.length())
                result = even;
        }

        return result;
    }
};
