class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> parent(n);
        for(int i = 0;i <n;i++){
            parent[i] = i;
            if(i != 0 && nums[i] - nums[i - 1] <= maxDiff){
                parent[i] = parent[i - 1];
            }
        }
        for(auto& q : queries){            
            if(parent[q[0]] == parent[q[1]]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};