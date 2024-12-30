#define mod 1000000007
class Solution {
public:
    vector<int> dp;
    int solve(int ind, int low, int high, int zero, int one){
        if(ind > high){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        long ans = 0;
        if(ind >= low && ind <= high){
            ans++;
        }
        // string op1(zero, '0');
        // string op2(one, '1');
        int ans1 = solve(ind + zero, low, high, zero, one);
        int ans2 = solve(ind + one, low, high, zero, one);
        ans = (ans + ans1 + ans2) % mod;
        return dp[ind] = ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high + 1, -1);
        return solve(0, low, high, zero, one);
    }
};