class Solution {
public:
    // int solve(vector<int>& days, vector<int>& costs, int dayInd){
    //     int n = days.size();
    //     if(dayInd == n){
    //         return 0;
    //     }
    //     if(dp[dayInd] != -1){
    //         return dp[dayInd];
    //     }
    //     int op1 = costs[0] + solve(days, costs, lower_bound(days.begin(), days.end(), days[dayInd] + 1) - days.begin());
    //     int op2 = costs[1] + solve(days, costs, lower_bound(days.begin(), days.end(), days[dayInd] + 7) - days.begin());
    //     int op3 = costs[2] + solve(days, costs, lower_bound(days.begin(), days.end(), days[dayInd] + 30) - days.begin());
    //     return dp[dayInd] = min({op1, op2, op3});
    // }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1);
        for(int i = n - 1;i >= 0;i--){
            int op1 = costs[0] + dp[lower_bound(days.begin(), days.end(), days[i] + 1) - days.begin()];
            int op2 = costs[1] + dp[lower_bound(days.begin(), days.end(), days[i] + 7) - days.begin()];
            int op3 = costs[2] + dp[lower_bound(days.begin(), days.end(), days[i] + 30) - days.begin()];
            dp[i] = min({op1, op2, op3});
        }
        return dp[0];
    }
};