class Solution {
public:
    int solve(vector<int>& nums, int ind, int last_ind, bool even){
        if(ind >= nums.size()){
            return 1;
        }
        int dif = abs(nums[ind] - nums[last_ind]);
        bool flag = dif % 2;
        if(flag == even){
            return 1 + solve(nums, ind + 1, ind, even);
        }
        else{
            return solve(nums, ind + 1, last_ind, even);
        }

    }
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int first_even = n, first_odd = n;
        for(int i = 0;i < n;i++){
            if(nums[i] % 2 == 0){
                if(first_even == n){
                    first_even = i;
                }
            }
            else{
                if(first_odd == n){
                    first_odd = i;
                }
            }
        }
        int ans = 1;
        ans = max({ans, solve(nums, first_even + 1, first_even, true), solve(nums, first_even + 1, first_even, false), solve(nums, first_odd + 1, first_odd, true), solve(nums, first_odd + 1, first_odd, false)});
        return ans;
    }
};