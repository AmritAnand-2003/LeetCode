class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        Arrays.sort(nums);
        int len = nums.length;
        int lower = nums[0] - k + 1;
        int ans = 1;
        for(int i = 1;i < len; i++) {
            int mn = nums[i] - k, mx = nums[i] + k;
            if(lower < mn) {
                lower = mn + 1;
                ans++;
            }
            else if (lower <= mx) {
                lower++;
                ans++;
            }
        }
        return ans;
    }
}