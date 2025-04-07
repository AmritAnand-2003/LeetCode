class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int>& nums, int ind, int target){
        if(target == 0){
            return true;
        }
        else if(target < 0){
            return false;
        }
        if(ind == nums.size()){
            return target == 0;
        }
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        return dp[ind][target] = solve(nums, ind + 1, target) || solve(nums, ind + 1, target - nums[ind]);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums){
            sum += x;
        }
        if(sum % 2 == 1){
            return false;
        }
        int tar = sum/2;
        dp.resize(nums.size(), vector<int>(tar + 1, -1));
        return solve(nums, 0, tar);
    }
};