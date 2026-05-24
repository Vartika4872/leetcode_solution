class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26);

        // Store last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        stack<char> st;
        vector<bool> visited(26, false);

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // Skip if already present
            if (visited[ch - 'a'])
                continue;

            // Remove larger characters if they appear later
            while (!st.empty() &&
                   ch < st.top() &&
                   i < lastIndex[st.top() - 'a']) {

                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch - 'a'] = true;
        }

        // Build answer from stack
        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
