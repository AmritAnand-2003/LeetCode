class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long ans = 0, cur_len = 0;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] == 0){
                cur_len++;
            }
            else{
                cur_len = 0;
            }
            ans += cur_len;
        }
        return ans;
    }
}