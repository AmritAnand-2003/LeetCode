class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int end = 0, ans = 0;
        for(auto& m : meetings){
            if(m[0] > end){
                ans += m[0] - end - 1;

            }
            end = max(end, m[1]);
        }
        ans += days - end;
        return ans;
    }
};