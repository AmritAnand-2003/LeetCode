class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long cur = 0;
        vector<bool> ans(nums.size(), false);
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            cur *= 2;
            cur += x;
            if(cur == 0 || cur % 5 == 0){
                ans[i] = true;
            }
            cur %= 5;
        }
        return ans;
    }
};