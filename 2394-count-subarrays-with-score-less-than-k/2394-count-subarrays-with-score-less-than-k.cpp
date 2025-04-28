class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        vector<long long> hash;
        long long ans = 0, sum = 0;
        hash.push_back(0);
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            long l = 0, h = i, cur = 0;
            while(l <= h){
                long mid = (l + h) / 2;
                if((sum - hash[mid]) * (i - mid + 1) < k){
                    cur = i - mid + 1;
                    h = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            ans += cur;
            hash.push_back(sum);
        }
        return ans;
    }
};