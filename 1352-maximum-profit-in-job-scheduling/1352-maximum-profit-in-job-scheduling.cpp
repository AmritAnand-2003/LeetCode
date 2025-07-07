class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();
        for(int i = 0;i < n;i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> earning;
        int op = 0;
        for(int i = n - 1;i >= 0;i--){
            int start = jobs[i][0], end = jobs[i][1];
            op = 0;
            auto it = earning.lower_bound(start);
            if(it != earning.end()){
                op = max(op, it->second);
            }
            it = earning.lower_bound(end);
            int cur_earn = jobs[i][2];
            if(it != earning.end()){
                cur_earn += it->second;
            }
            op = max(op, cur_earn);
            earning[start] = op;
        }
        return op;
    }
};