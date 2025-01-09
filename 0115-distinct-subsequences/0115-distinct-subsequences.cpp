#define ll unsigned long long
class Solution {
public:
    
    // int solve(string s, string t, int i, int j){
    //     if(j == t.size()){
    //         return 1;
    //     }
    //     if(s.size() - i < t.size() - j){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int op1 = solve(s, t, i + 1, j);
    //     int op2 = 0;
    //     if(s[i] == t[j]){
    //         op2 = solve(s, t, i + 1, j + 1);
    //     }
    //     return dp[i][j] = op1 + op2;
    // }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<ll> cur(m + 1), dp(m + 1);
        for(int i = n;i >= 0;i--){
            for(int j = m; j >= m - n + i && j >= 0; j--){
                if(j == m){
                    cur[j] = 1;
                }
                else{
                    ll op1 = dp[j];
                    ll op2 = ((s[i] == t[j]) ? dp[j + 1] : 0);
                    cur[j] = op1 + op2;
                }
            }
            dp = cur;
        }
        return dp[0];
    }
};