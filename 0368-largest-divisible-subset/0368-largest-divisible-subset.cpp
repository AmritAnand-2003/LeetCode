class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n);
        vector<int> prev_ind(n, -1);
        int ans = 0, ans_ind = 0;
        vector<int> sol;
        for(int i = 1;i < n;i++){
            for(int j = i - 1;j >= 0;j--){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    prev_ind[i] = j;
                }
            }
            if(ans < dp[i]){
                ans = dp[i];
                ans_ind = i;
            }
            // cout<<dp[i]<<" ";
        }
        int cur_ind = ans_ind;
        while(prev_ind[cur_ind] != -1){
            sol.push_back(nums[cur_ind]);
            cur_ind = prev_ind[cur_ind];
        }
        sol.push_back(nums[cur_ind]);
        reverse(sol.begin(), sol.end());
        return sol;
    }
};