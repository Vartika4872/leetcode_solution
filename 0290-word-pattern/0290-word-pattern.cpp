class Solution {
public:
    bool wordPattern(string pattern, string s) {
       unordered_map<char, string> mp1;
    unordered_map<string, char> mp2;

    stringstream ss(s);
    string word;
    
    for (int i = 0; i < pattern.size(); i++) {
        if (!(ss >> word)) return false; // words < pattern
        
        char ch = pattern[i];

        if (mp1.count(ch) && mp1[ch] != word) return false;
        if (mp2.count(word) && mp2[word] != ch) return false;

        mp1[ch] = word;
        mp2[word] = ch;
    }

    // Extra words check
    if (ss >> word) return false;

    return true; 
    }
};