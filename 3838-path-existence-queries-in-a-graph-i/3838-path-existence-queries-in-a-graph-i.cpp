class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        for(auto& q : queries){
            int s = nums[q[0]], d = nums[q[1]];
            if(s > d){
                swap(s, d);
            }
            int next = s + maxDiff + 1;
            auto cur = lower_bound(nums.begin(), nums.end(), s);
            auto it = lower_bound(cur, nums.end(), next);
            it--;
            while(it != nums.end() && cur != it){
                if(*it >= d){
                    break;
                }
                cur = it;
                it = lower_bound(cur, nums.end(), *cur + maxDiff + 1);
                it--;
            }
            if(*it >= d){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};