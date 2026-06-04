class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();

        for(int i = 1; i <= n/2; i++){
            if(num[0] == '0' && i > 1) break;

            for(int j = 1; max(i,j) <= n -i - j; j++){
                if(num[i] == '0' && j > 1) break;

                long long first = stoll(num.substr(0, i));
                long long second = stoll(num.substr(i, j));

                int start = i + j;

                while(start < n){
                    long long sum = first + second;
                    string sumStr = to_string(sum);

                    if(num.substr(start, sumStr.size()) != sumStr)
                    break;

                    start += sumStr.size();
                    first = second;
                    second = sum;
                }
                if(start == n)
                return true;
            }
        }
        return false;
    }
};