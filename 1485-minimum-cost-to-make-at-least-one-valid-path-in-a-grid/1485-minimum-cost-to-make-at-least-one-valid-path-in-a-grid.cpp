class Solution {
public:
    bool inside(int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return false;
        }
        return true;
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<vector<int>> dq;
        dq.push_front({0, 0, 0});
        vis[0][0] = true;
        dist[0][0] = 0;
        while(!dq.empty()){
            auto cur = dq.front();
            dq.pop_front();
            int x = cur[0], y = cur[1], curCost = cur[2];
            vis[x][y] = true;
            if(x == m - 1 && y == n - 1){
                return curCost;
            }
            for(int i = 0;i < mov.size();i++){
                int nextx = x + mov[i][0], nexty = y + mov[i][1];
                if(inside(nextx, nexty, m, n) && !vis[nextx][nexty]){
                    if(grid[x][y] == i + 1){
                        if(curCost < dist[nextx][nexty]){
                            dq.push_front({nextx, nexty, curCost});
                            dist[nextx][nexty] = curCost;
                        }
                    }
                    else if(curCost + 1 < dist[nextx][nexty]){
                        dq.push_back({nextx, nexty, curCost + 1});
                        dist[nextx][nexty] = curCost + 1;
                    }
                }
            }
        }
        return -1;
    }
};