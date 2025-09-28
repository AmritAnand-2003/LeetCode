class Solution {
    public boolean canJump(int[] nums) {
        int mx_reach = 0;
        for(int i = 0; i < nums.length; i++) {
            if(i > mx_reach) return false;
            mx_reach = Math.max(mx_reach, i + nums[i]);
        }
        return true;
    }
}