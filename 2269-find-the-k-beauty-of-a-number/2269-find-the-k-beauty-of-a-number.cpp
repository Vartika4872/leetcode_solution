class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int count = 0;

        for(int i = 0; i <= s.size() - k; i++){
            int val = stoi(s.substr(i, k));

            if(val != 0 && num % val == 0){
                count++;
            }
        }
        return count;
    }
};