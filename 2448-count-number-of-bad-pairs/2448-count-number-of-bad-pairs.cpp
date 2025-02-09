class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> pre_count;
        long long n = nums.size(), ans = 0;
        for(int i = 0;i < n;i++){
            ans += pre_count[nums[i] - i];
            pre_count[nums[i] - i]++;
        }
        return n * (n - 1) / 2 -  ans;
    }
};