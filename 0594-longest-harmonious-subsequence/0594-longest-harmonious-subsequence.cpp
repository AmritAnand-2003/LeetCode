class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> hash;
        for(auto& x : nums){
            hash[x]++;
        }
        for(auto& it : hash){
            if(hash.find(it.first - 1) != hash.end()){
                ans = max(ans, it.second + hash[it.first - 1]);
            }
        }
        return ans;
    }
};