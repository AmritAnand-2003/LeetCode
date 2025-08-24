class Solution {
    public int longestSubarray(int[] nums) {
        int zero = -1;
        int n = nums.length, ans = 0, cur = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] == 1){
                cur++;
            }
            else{
                cur = i - zero - 1;
                zero = i;
            }
            System.out.print(cur + " ");
            ans = Math.max(ans, cur);
        }
        if(zero == -1){
            return ans - 1;
        }
        return ans;
    }
}