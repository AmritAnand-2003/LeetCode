class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long out = -1, res = 0, min_idx = -1, max_idx = -1;
        for(int i = 0;i < n;i++){
            if(nums[i] < minK || nums[i] > maxK){
                out = i;
            }
            if(nums[i] == minK){
                min_idx = i;
            }
            if(nums[i] == maxK){
                max_idx = i;
            }
            if(min_idx > out && max_idx > out){
                res += max((long long)0, min(max_idx, min_idx) - out);
            }
        }
        return res;
    }
};