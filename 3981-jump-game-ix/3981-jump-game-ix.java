class Solution {
    public int[] maxValue(int[] nums) {
        int n = nums.length;
        int[] prefix_max = new int[n], suffix_mn = new int[n];
        int[] ans = new int[n];
        int mx = 0, mn = (int)1e9;
        for(int i = 0;i < n;i++){
            mx = Math.max(mx, nums[i]);
            prefix_max[i] = mx;
            suffix_mn[n - 1 - i] = mn;
            mn = Math.min(mn, nums[n - 1 - i]);
        }
        ans[n - 1] = prefix_max[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            ans[i] = prefix_max[i];
            if(prefix_max[i] > suffix_mn[i + 1]) {
                ans[i] = ans[i + 1];
            }
        }
        return ans;
    }
}