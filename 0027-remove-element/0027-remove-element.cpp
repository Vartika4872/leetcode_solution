class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int r = nums.size() - 1;

        while(k <= r){
            if(nums[k] == val){
                nums[k] = nums[r];
                r--;
            }
            else{
                k++;
            }
        }

        return r+1;
    }
};