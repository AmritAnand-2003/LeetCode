class Solution {
public:
    int dp[12][1025][2];
    int solve(int ind, int repeated, int taken, bool edge, vector<int>& num){
        if(ind < 0){
            return repeated;
        }
        if(!edge && dp[ind][taken][repeated] != -1){
            return dp[ind][taken][repeated];
        }
        int up_limit = edge ? num[ind] : 9;
        int ans = 0;
        for(int n = 0; n <= up_limit;n++){
            bool curRepeated = repeated;
            if(!curRepeated && (taken & (1 << n))){
                curRepeated = 1;
            }
            int nextTaken = (taken != 0 || n != 0) ? (taken | (1 << n)) : 0;
            ans += solve(ind - 1, curRepeated, nextTaken, (edge ? n == up_limit : false), num);
        }
        if(!edge){
            dp[ind][taken][repeated] = ans;
        }
        return ans;
    }
    int numDupDigitsAtMostN(int n) {
        memset(dp, -1, sizeof(dp));
        vector<int> num;
        while(n){
            num.push_back(n % 10);
            n /= 10;
        }
        return solve(num.size() - 1, 0, 0, true, num);
    }
};