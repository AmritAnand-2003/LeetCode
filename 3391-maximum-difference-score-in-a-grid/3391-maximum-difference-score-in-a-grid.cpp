class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> score(m + 1, vector<int>(n + 1, INT_MIN));
        int ans = INT_MIN;
        for(int i = m - 1;i >= 0;i--){
            for(int j = n - 1;j >= 0;j--){
                if(i == m - 1 && j == n - 1){
                    continue;
                }
                else if(i == m - 1){
                    score[i][j] = max(score[i][j + 1], grid[i][j + 1]);
                }
                else if(j == n - 1){
                    score[i][j] = max(score[i + 1][j], grid[i + 1][j]);
                }
                else{
                    score[i][j] = max({score[i + 1][j], score[i][j + 1], grid[i + 1][j], grid[i][j + 1]});

                }
                // cout<<grid[i][j]<<" ";
                ans = max(ans, score[i][j] - grid[i][j]);
                // cout<<score[i][j]<<endl;
            }
        }
        return ans;
    }
};