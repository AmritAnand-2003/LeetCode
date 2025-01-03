class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long tsum = 0, ans = 0;
        vector<long> prefix(n);
        for(int i = 0;i < n;i++){
            prefix[i] = nums[i] + tsum;
            tsum = prefix[i];
        }
        for(int i = 0;i < n - 1;i++){
            ans += (prefix[i] >= prefix[n - 1] - prefix[i] ? 1 : 0);
            // cout<<ans<<" ";
        }
        return ans;
    }
};