class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0;
        long sum = 0;
        long long ans = 0;
        for(int j = 0;j < nums.size();j++){
            sum += nums[j];
            while(i <= j && sum * (j - i + 1) >= k){
                sum -= nums[i++];
            }
            ans += (j - i + 1);
        }
        return ans;
    }
};