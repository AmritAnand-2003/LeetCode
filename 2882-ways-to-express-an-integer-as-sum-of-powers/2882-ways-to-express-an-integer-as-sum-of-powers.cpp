class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    int intRoot(int n, int x) {
        int lo = 1, hi = n, ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long p = 1;
            bool overflow = false;

            // Compute mid^x, break if it exceeds n
            for (int i = 0; i < x; i++) {
                if (p > n / mid) { // prevents overflow
                    overflow = true;
                    break;
                }
                p *= mid;
            }
            if (!overflow && p <= n) {
                ans = mid;      // mid is a valid base
                lo = mid + 1;   // try bigger
            } else {
                hi = mid - 1;   // try smaller
            }
        }
        return ans;
    }

    int solve(int n, int x, int high) {
        if(n == 0){
            return 1;
        }
        if(high == 0){
            return 0;
        }
        if(dp[n][high] != -1){
            return dp[n][high];
        }
        // cout<<n<<" "<<x<<endl;
        int val = intRoot(n, x);
        // cout<<val<<endl;
        int ans = 0;
        for(int i = 1 ;i <= min(val, high);i++){
            ans = (ans + solve(n - pow(i, x), x, i - 1)) % mod;
        }
        return dp[n][high] = ans;
    }
    int numberOfWays(int n, int x) {
        int h = intRoot(n, x);
        dp.resize(n + 1, vector<int>(h + 1, -1));
        return solve(n, x, h);
    }
};