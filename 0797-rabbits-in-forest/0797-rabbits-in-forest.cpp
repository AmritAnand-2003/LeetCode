class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> hash;
        for(auto& x : answers){
            hash[x + 1]++;
        }
        int ans = 0;
        for(auto& it : hash){
            int fir = it.first, sec = it.second;
            ans += (it.second / it.first) * it.first;
            ans += (it.second % it.first) != 0 ? it.first : 0;
        }
        return ans;
    }
};