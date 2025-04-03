class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        int mxl = 0, mxr = 0;
        for(int i = 0;i < n;i++){
            left[i] = mxl;
            mxl = max(mxl, nums[i]);
            right[n - 1 - i] = mxr;
            mxr = max(mxr, nums[n - 1 - i]);
        }
        long long ans = 0;
        for(int i = 1;i < n - 1;i++){
            ans = max(ans, (long long)(left[i] - nums[i]) * right[i]);
        }
        return ans;
    }
};