class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1{'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> row2{'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> row3{'z','x','c','v','b','n','m'};

        vector<string> result;

        for (string word : words) {
            string lower = word;
            for (char &c : lower) {
                c = tolower(c);
            }

            unordered_set<char>* row;

            if (row1.count(lower[0]))
                row = &row1;
            else if (row2.count(lower[0]))
                row = &row2;
            else
                row = &row3;

            bool valid = true;

            for (char c : lower) {
                if (!row->count(c)) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                result.push_back(word);
        }

        return result;
    }
};