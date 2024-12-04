class Solution {
public:
    vector<vector<int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[1][0] > 1 && grid[0][1] > 1){
            return -1;
        }
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        pq.push({0, 0, 0});
        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();
            int time = v[0], i = v[1], j = v[2];
            visited[i][j] = true;
            for(auto mv : moves){
                int r = i + mv[0], c = j + mv[1];
                if(r >= 0 && r < m && c >= 0 && c < n && !visited[r][c]){
                    int nextTime;
                    visited[r][c] = true;
                    int timeDif = grid[r][c] - time;
                    if(timeDif <= 0){
                        nextTime = time + 1;
                        // pq.push({time + 1, r, c});
                    }
                    else if(timeDif % 2){
                        nextTime = grid[r][c];
                        // pq.push({grid[r][c], r, c});
                    }
                    else{
                        nextTime = grid[r][c] + 1;
                        // pq.push({grid[r][c] + 1, r, c});
                    }
                    if(r == m - 1 && c == n - 1){
                        return nextTime;
                    }
                    pq.push({nextTime, r, c});
                }
            }
        }
        return -1;
    }
};