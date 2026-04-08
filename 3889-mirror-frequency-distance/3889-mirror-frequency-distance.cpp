class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency
        for (char c : s) {
            freq[c]++;
        }

        unordered_set<char> visited;
        int total = 0;

        // Step 2: Process each unique character
        for (auto &it : freq) {
            char c = it.first;

            if (visited.count(c)) continue;

            char mirror;

            // Determine mirror
            if (isdigit(c)) {
                mirror = '9' - (c - '0');
            } else {
                mirror = 'z' - (c - 'a');
            }

            int f1 = freq[c];
            int f2 = freq.count(mirror) ? freq[mirror] : 0;

            total += abs(f1 - f2);

            // Mark both visited
            visited.insert(c);
            visited.insert(mirror);
        }

        return total;
    }
};