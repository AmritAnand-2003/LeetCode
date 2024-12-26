class Solution {
public:
    void solve(vector<int>& nums, int ind, int target, int& count){
        if(ind == nums.size()){
            if(target == 0){
                count++;
            }
            return;
        }
        solve(nums, ind + 1, target - nums[ind], count);
        solve(nums, ind + 1, target + nums[ind], count);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        solve(nums, 0, target, ans);
        return ans;
    }
};