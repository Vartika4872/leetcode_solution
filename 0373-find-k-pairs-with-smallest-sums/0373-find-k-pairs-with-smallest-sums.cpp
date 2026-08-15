class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<vector<int>> ans;

        if(nums1.empty() || nums2.empty() || k==0)
            return ans;

        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        int n1 = nums1.size();
        int n2 = nums2.size();

        for(int i = 0; i < min(n1, k); i++){
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(k-- && !pq.empty()){

            auto cur = pq.top();
            pq.pop();

            int sum = cur[0];
            int i = cur[1];
            int j = cur[2];

            ans.push_back({nums1[i], nums2[j]});

            if(j + 1 < n2){
                pq.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }

        return ans;
    }
};