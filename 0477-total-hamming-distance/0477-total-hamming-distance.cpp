class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> setBits(32);
        for(int i = 0;i < n;i++){
            int cur = nums[i], j = 0;
            for(int j = 0;j < 32;j++){
                if(nums[i] & (1 << j)){
                    setBits[j]++;
                }
            }
        }
        for(auto it : setBits){
            ans += (it) * (n - it);
        }
        return ans;
    }
};