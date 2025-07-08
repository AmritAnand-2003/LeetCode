class Solution {
public:
    vector<vector<int>> dp;
    // int solve(vector<vector<int>>& events, int k, int ind){
    //     if(ind == events.size() || k == 0){
    //         return 0;
    //     }
    //     if(dp[ind][k] != -1){
    //         return dp[ind][k];
    //     }
    //     int op = solve(events, k, ind + 1);
    //     auto it = lower_bound(events.begin(), events.end(), events[ind][1] + 1,
    //     [](const vector<int>& event, int val) {
    //         return event[0] < val;
    //     });
    //     auto next_ind = it - events.begin();
    //     op = max(op, solve(events, k - 1, next_ind) + events[ind][2]);
    //     return dp[ind][k] = op;
    // }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        dp.resize(events.size() + 1, vector<int>(k + 1));
        for(int cur_ind = n - 1;cur_ind >= 0;cur_ind--){
            for(int j = 1;j <= k;j++){
                auto it = lower_bound(events.begin(), events.end(), events[cur_ind][1] + 1,[](const vector<int>& event, int val) {
                    return event[0] < val;
                });
                int next_ind = it - events.begin();
                dp[cur_ind][j] = max(dp[cur_ind + 1][j], dp[next_ind][j - 1] + events[cur_ind][2]);
            }
        }
        return dp[0][k];
    }

};