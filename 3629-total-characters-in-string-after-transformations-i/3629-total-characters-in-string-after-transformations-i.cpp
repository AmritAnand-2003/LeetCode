class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<int, int> dp;
    int solve(int t){
        if(t <= 25){
            return 1;
        }
        if(dp.find(t) != dp.end()){
            return dp[t];
        }
        return solve(t - 26) + solve(t - 25);
    }
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26);
        for(auto x : s){
            freq[x - 'a']++;
        }
        int ans = 0;
        while(t--){
            vector<int> nxt(26);
            for(int i = 0;i < 25;i++){
                nxt[i + 1] = freq[i];
            }
            nxt[0] = freq[25];
            nxt[1] = (nxt[1] + freq[25]) % mod;
            freq = nxt;
        }
        for(auto& x : freq){
            ans = (ans + x) % mod;
        }
        return ans;
    }
};