class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        set<int> difParity;
        for(int i = 0;i < nums.size() - 1;i++){
            if(nums[i] % 2 == nums[i + 1] % 2){
                difParity.insert(i);
                // cout<<i<<endl;
            }
        }
        vector<bool> ans(queries.size(), true);
        for(int i = 0;i < queries.size();i++){
            int s = queries[i][0], d = queries[i][1];
            auto it = difParity.lower_bound(s);
            if(it != difParity.end() && *it < d){
                ans[i] = false;
            }
        }
        return ans;
    }
};