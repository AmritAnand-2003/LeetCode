class Solution {
public:
    int solve(vector<int>& nums, int ind, int xor_val){
        if(ind == nums.size()){
            return xor_val;
        }
        int a = solve(nums, ind + 1, xor_val);
        int b = solve(nums, ind + 1, xor_val ^ nums[ind]);
        return a + b;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};