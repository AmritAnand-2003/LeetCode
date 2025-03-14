class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hash;
        for(auto s : strs){
            string t = s;
            sort(t.begin(), t.end());
            hash[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it : hash){
            ans.push_back(it.second);
        }
        return ans;
    }
};