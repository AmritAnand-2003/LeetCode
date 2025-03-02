class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> hash;
        for(auto x : nums1){
            hash[x[0]] += x[1];
        }
        for(auto x : nums2){
            hash[x[0]] += x[1];
        }
        vector<vector<int>> ans;
        for(auto it : hash){
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};