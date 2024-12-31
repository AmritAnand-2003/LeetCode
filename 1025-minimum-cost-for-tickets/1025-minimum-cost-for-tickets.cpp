class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& days, vector<int>& costs, int dayInd){
        int n = days.size();
        if(dayInd == n){
            return 0;
        }
        if(dp[dayInd] != -1){
            return dp[dayInd];
        }
        auto it = lower_bound(days.begin(), days.end(), days[dayInd] + 7);
        int op1 = costs[0] + solve(days, costs, lower_bound(days.begin(), days.end(), days[dayInd] + 1) - days.begin());
        int op2 = costs[1] + solve(days, costs, lower_bound(days.begin(), days.end(), days[dayInd] + 7) - days.begin());
        int op3 = costs[2] + solve(days, costs, lower_bound(days.begin(), days.end(), days[dayInd] + 30) - days.begin());
        return dp[dayInd] = min({op1, op2, op3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size() + 1, -1);
        return solve(days, costs, 0);
    }
};