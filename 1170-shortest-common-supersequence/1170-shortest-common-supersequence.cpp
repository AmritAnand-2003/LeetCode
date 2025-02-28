class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // find lcs
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        for(int i = m;i>= 0;i--){
            for(int j = n;j >= 0;j--){
                if(i == m || j == n){
                    dp[i][j] = 0;
                }
                else if(str1[i] == str2[j]){
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        string ans = "";
        int ind1 = 0, ind2 = 0;
        while(ind1 < m && ind2 < n){
            if(dp[ind1][ind2] > max(dp[ind1 + 1][ind2], dp[ind1][ind2 + 1])){
                ans += str1[ind1];
                ind1++, ind2++;
            }
            else if(dp[ind1 + 1][ind2] >= dp[ind1][ind2 + 1]){ // next row greater
                ans += str1[ind1++];
            }
            else{
                ans += str2[ind2++];
            }
        }
        while(ind1 < m){
            ans += str1[ind1++];
        }
        while(ind2 < n){
            ans += str2[ind2++];
        }
        return ans;
    }
};