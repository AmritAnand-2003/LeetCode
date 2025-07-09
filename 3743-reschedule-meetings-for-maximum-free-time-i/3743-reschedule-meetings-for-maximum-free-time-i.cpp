class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime){
        vector<vector<int>> events;
        int n = startTime.size();
        for(int i = 0;i < n;i++){
            events.push_back({startTime[i], endTime[i]});
        }
        sort(events.begin(), events.end());
        vector<int> options;
        int prev = 0;
        for(auto& x : events){
            options.push_back(x[0] - prev);
            prev = x[1];
        }
        options.push_back(eventTime - prev);
        int start = 0, ans = 0, cur_ans = 0;
        for(int i = 0;i < options.size();i++){
            cur_ans += options[i];
            if(i >= k + 1){
                cur_ans -= options[i - k - 1];
            }
            ans = max(ans, cur_ans);
        }
        return ans;
    }
};