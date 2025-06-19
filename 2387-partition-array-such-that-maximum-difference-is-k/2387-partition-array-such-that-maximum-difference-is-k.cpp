class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 1, cur = nums[0];
        for(auto x : nums){
            if(x > cur + k){
                count++;
                cur = x;
            }
        }
        return count;
    }
};