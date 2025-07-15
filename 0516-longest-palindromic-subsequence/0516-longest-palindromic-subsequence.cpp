class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l, int r, string& s){
        if(l > r){
            return 0;
        }
        else if(l == r){
            return 1;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        if(s[l] == s[r]){
            return dp[l][r] = 2 + solve(l + 1, r - 1, s);
        }
        return dp[l][r] = max(solve(l + 1, r, s), solve(l, r - 1, s));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        return solve(0, n - 1, s);
    }
};