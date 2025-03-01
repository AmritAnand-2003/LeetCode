class Solution {
private:
    vector<int> mov_r = {1, -1, 0, 0}, mov_c = {0, 0, 1, -1};
public:
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int cur = 0;
        for(int k = 0;k < 4;k++){
            int x = mov_r[k] + i, y = mov_c[k] + j;
            if(x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > matrix[i][j]){
                cur = max(cur, dfs(matrix, x, y, dp));
            }
        }
        return dp[i][j] = cur + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(dp[i][j] == -1){
                    ans = max(ans, dfs(matrix, i, j, dp));
                }
            }
        }
        return ans;
    }
};