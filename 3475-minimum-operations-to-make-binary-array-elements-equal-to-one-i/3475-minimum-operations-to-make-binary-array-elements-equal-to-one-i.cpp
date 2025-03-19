class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0, flips = 0;
        while(i < n - 2){
            if(nums[i] == 0){
                flips++;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
            }
            i++;
        }
        if(nums[n - 1] == 0 || nums[n - 2] == 0){
            return -1;
        }
        return flips;
    }
};