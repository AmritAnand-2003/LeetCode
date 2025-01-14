class Solution {
public:
    int dp[12][12];

    int solve(int pos, int count, bool limit, vector<int>& num){
        if(pos < 0){
            return count;
        }
        if(!limit && dp[pos][count] != -1){
            return dp[pos][count];
        }
        int ans = 0;
        int upper_bound = limit ? num[pos] : 9;
        for(int i = 0;i <= upper_bound;i++){
            ans += solve(pos - 1, count + (i == 1), (limit && (i == upper_bound)), num);
        }
        if(!limit){
            dp[pos][count] = ans;
        }
        // cout<<pos<<" "<<count<<" "<<an/s<<endl;
        return ans;
    }
    int countDigitOne(int n) {
        vector<int> num;
        while(n){
            num.push_back(n % 10);
            n /= 10;
        }
        // num.push_back(0);
        // for(auto x : num){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // reverse(num.begin(), num.end());
        memset(dp, -1, sizeof(dp));
        return solve(num.size() - 1, 0, true, num);
    }
};