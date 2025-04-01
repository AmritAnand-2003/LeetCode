class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> ans(200001);
        for(int i = questions.size() - 1; i>= 0;i--){
            ans[i] = max(questions[i][0] + ans[i + questions[i][1] + 1], ans[i + 1]);
        }
        return ans[0];
    }
};