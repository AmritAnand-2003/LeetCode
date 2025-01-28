class Solution {
public:
    bool inside(int x, int y, int m, int n){
        if(x >= 0 && y >= 0 && x < m && y < n){
            return true;
        }
        return false;
    }
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& mov, int i, int j){
        int m = grid.size(), n = grid[0].size();
        int ans = grid[i][j];
        grid[i][j] = 0;
        for(auto mv : mov){
            int x = i + mv[0], y = j + mv[1];
            if(inside(x, y, m, n) && grid[x][y] > 0){
                ans += dfs(grid, mov, x, y);
            }
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j]){
                    int cur = dfs(grid, mov, i, j);
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};