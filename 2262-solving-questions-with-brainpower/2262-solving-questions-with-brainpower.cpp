class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        unordered_map<int, long long> ans;
        for(int i = n - 1; i>= 0;i--){
            ans[i] = questions[i][0] + ans[i + questions[i][1] + 1];
            ans[i] = max(ans[i], ans[i + 1]);
        }
        return ans[0];
    }
};