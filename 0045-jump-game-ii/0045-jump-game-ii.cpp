class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int i){
        if(i >= nums.size() - 1){
            return 0;
        }
        if(dp[i] != -2){
            return dp[i];
        }
        int ans = INT_MAX;
        for(int j = 1;j <= nums[i] && i + j < nums.size();j++){
            int val = solve(nums, i + j);
            if(val != -1){
                ans = min(ans, 1 + val);
            }
        }
        return dp[i] = ans == INT_MAX ? -1 : ans;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size(), -2);
        return solve(nums, 0);
    }
};