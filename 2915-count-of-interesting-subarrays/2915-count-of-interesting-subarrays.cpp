class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> hash;
        long long cnt = 0, ans = 0;
        hash[0] = 1;
        for(auto x : nums){
            // cout<<x<<" "<<cnt<<endl;
            int cur = x % modulo;
            if(cur == k){
                cnt++;
            }
            cnt %= modulo;
            int find;
            if(cnt >= k){
                find = cnt - k;
            }
            else{
                find = cnt + modulo - k;
            }
            // cout<<find<<" "<<hash[find]<<endl;
            ans += hash[find];
            hash[cnt]++;
        }
        return ans;
    }
};