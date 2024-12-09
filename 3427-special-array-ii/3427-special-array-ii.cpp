class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        // set<int> difParity;
        vector<int> prefix(nums.size());
        for(int i = 1;i < nums.size();i++){
            if(nums[i] % 2 == nums[i - 1] % 2){
                prefix[i] = 1;
                // cout<<i<<endl;
            }
            prefix[i] += prefix[i - 1];
        }
        vector<bool> ans(queries.size(), true);
        for(int i = 0;i < queries.size();i++){
            int s = queries[i][0], d = queries[i][1];
            if(prefix[d] != prefix[s]){
                ans[i] = false;
            }
        }
        return ans;
    }
};