int mod = 1e9 + 7;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> freq(words[0].size(), vector<int>(26));
        for(auto wrd : words){
            for(int i = 0;i < words[0].size();i++){
                freq[i][wrd[i] - 'a']++;
            }
        }
        vector<int> dp(words[0].size() + 1);
        vector<int> prev(words[0].size() + 1);
        for(int i = target.size();i >= 0;i--){
            for(int j = words[0].size(); j>= 0;j--){
                if(i == target.size()){
                    dp[j] = 1;
                }
                else if(j != words[0].size()){
                    long f = freq[j][target[i] - 'a'];
                    long cur = (f * prev[j + 1]) % mod;
                    long skip = dp[j + 1];
                    dp[j] = (cur + skip) % mod;
                }
                else{
                    dp[j] = 0;
                }
            }
            prev = dp;
        }
        return dp[0];
    }
};