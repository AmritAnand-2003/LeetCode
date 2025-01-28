class Solution {
public:
    vector<int> mv = {-1, 0, 1, 0, -1};
    int dfs(vector<vector<int>>& grid, int i, int j, int& m, int& n){
        int ans = grid[i][j];
        grid[i][j] = 0;
        for(int dr = 0;dr < 4;dr++){
            int x = i + mv[dr], y = j + mv[dr + 1];
            if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] > 0){
                ans += dfs(grid, x, y, m, n);
            }
        }
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] > 0){
                    ans = max(ans, dfs(grid, i, j, m, n));
                }
            }
        }
        return ans;
    }
};