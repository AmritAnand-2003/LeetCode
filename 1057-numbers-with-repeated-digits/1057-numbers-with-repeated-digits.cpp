class Solution {
public:
    int dp[12][1025][2];
    int solve(int ind, int taken, bool edge, vector<int>& num){
        if(ind < 0){
            return taken > 1 ? 1 : 0;
        }
        if(dp[ind][taken][edge] != -1){
            return dp[ind][taken][edge];
        }
        int up_limit = edge ? num[ind] : 9;
        int ans = 0;
        for(int n = 0; n <= up_limit;n++){
            if((taken & (1 << n)) == 0){
                int nextTaken = (taken != 0 || n != 0) ? (taken | (1 << n)) : 0;
                ans += solve(ind - 1, nextTaken, (edge ? n == up_limit : false), num);
            }
        }
        return dp[ind][taken][edge] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        int temp = n;
        memset(dp, -1, sizeof(dp));
        vector<int> num;
        while(temp){
            num.push_back(temp % 10);
            temp /= 10;
        }
        int rep = solve(num.size() - 1, 0, true, num);
        return n - rep;
    }
};