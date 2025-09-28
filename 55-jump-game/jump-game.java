class Solution {
    int[] dp;
    private int solve(int ind, int[] nums) {
        int jump = nums[ind];
        if(jump + ind >= nums.length - 1){
            return 1;
        }
        if(jump == 0){
            return 0;
        }
        if(solve(ind + jump, nums) == 1) return dp[ind] = 1;
        return 0;
    }

    public boolean canJump(int[] nums) {
        int n = nums.length;
        int mx = 0;
        dp = new int[n];
        System.out.print(n);
        for(int i = 0; i < n; i++) {
            mx--;
            nums[i] = Math.max(nums[i], mx);
            mx = nums[i];
        }
        for(int i = 0; i < n; i++) {
            dp[i] = -1;
        }
        dp[n - 1] = 1;
        int val = solve(0, nums);
        return val == 1;
    }
}