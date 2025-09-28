class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        for(int i = n - 1; i >= 2; i--) {
            int cur_val = nums[i];
            int other_side_sum = nums[i - 1] + nums[i - 2];
            if(other_side_sum > cur_val) {
                return cur_val + other_side_sum;
            }
        }
        return 0;
    }
}