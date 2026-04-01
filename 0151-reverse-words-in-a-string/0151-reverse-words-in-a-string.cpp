class Solution {
public:
 string reverseWords(string s) {
    reverse(s.begin(), s.end());
    
    int n = s.length();
    int i = 0, j = 0;

    while (i < n) {
        while (i < n && s[i] == ' ') i++;
        if (i >= n) break;

        j = i;
        while (j < n && s[j] != ' ') j++;

        reverse(s.begin() + i, s.begin() + j);
        i = j;
    }

    // Remove extra spaces
    string result = "";
    i = 0;
    while (i < n) {
        while (i < n && s[i] == ' ') i++;
        if (i >= n) break;

        if (!result.empty()) result += " ";

        while (i < n && s[i] != ' ') {
            result += s[i++];
        }
    }

    return result;
}
};