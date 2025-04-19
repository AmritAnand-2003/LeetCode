class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for(auto it = nums.begin(); it != nums.end();it++){
            auto mn_it = lower_bound(next(it), nums.end(), lower - *it);
            auto mx_it = upper_bound(next(it), nums.end(), upper - *it);
            ans += (mx_it - mn_it);
        }
        return ans;
    }
};