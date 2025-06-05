class Solution {
public:
    bool solve(int ind, vector<int>& nums, long long& target, long long cur1){
        if(cur1 == target){
            return true;
        }
        if(ind == nums.size() || cur1 > target){
            return false;
        }
        return solve(ind + 1, nums, target, cur1) | solve(ind + 1, nums, target, cur1 * nums[ind]);
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        long long mx = *max_element(nums.begin(), nums.end());
        if(mx > target){
            return false;
        }
        unsigned long long cur = 1;
        int cnt = 0;
        for(auto& x: nums){
            cur *= x;
            if(cur % target == 0){
                cur /= target;
                cnt++;
            }
        }
        if(cnt != 2 || cur != 1){
            return false;
        }
        return solve(0, nums, target, 1);
    }
};