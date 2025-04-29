class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx_num = *max_element(nums.begin(), nums.end()), count = 0;
        vector<int> idxs;
        long long ans = 0;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == mx_num){
                count++;
                idxs.push_back(i);
            }
            if(count >= k){
                ans += (idxs[idxs.size() - k] + 1);
            }
        }
        return ans;
    }
};