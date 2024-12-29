int mod = 1e9 + 7;

class Solution {
public:
vector<vector<int>> dp;
    int solve(vector<string>& words, string& target, int i, int j){
        if(i == target.size()){
            return 1;
        }
        if(j == words[0].size()){
            return 0;
        }
        if(target.size() - i > words[0].size() - j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        for(int ind = 0;ind < words.size();ind++){
            if(words[ind][j] == target[i]){
                ans = (ans + solve(words, target, i + 1, j + 1)) % mod;
            }
        }
        ans = (ans + solve(words, target, i, j + 1)) % mod ;
        return dp[i][j] = ans;
    }
    int numWays(vector<string>& words, string target) {
        dp.resize(target.size(), vector<int>(words[0].size(), -1));
        return solve(words, target, 0, 0);
    }
};