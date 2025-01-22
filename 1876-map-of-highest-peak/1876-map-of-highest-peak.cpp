class Solution {
public:
    bool inside(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(isWater[i][j] == 0){
                    for(auto mv : mov){
                        int x = i + mv[0], y = j + mv[1];
                        if(inside(x, y, m, n) && isWater[x][y] == 1){
                            q.push({i, j});
                            height[i][j] = 1;
                            break;
                        }
                    }
                }
                else{
                    height[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int i = cur.first, j = cur.second;
            for(auto mv : mov){
                int x = i + mv[0], y = j + mv[1];
                if(inside(x, y, m, n) && height[x][y] == -1){
                    height[x][y] = height[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
        // for(int i = 0;i < m;i++){
        //     for(int j = 0;j < n;j++){
        //         if(height[i][j]){
        //             int mn_val = INT_MAX;
        //             for(auto mv : mov){
        //                 int x = i + mv[0], y = j + mv[1];
        //                 if(inside(x, y, m, n)){
        //                     mn_val = min(mn_val, height[x][y]);
        //                 }
        //             }
        //             height[i][j] = mn_val + 1;
        //         }
        //     }
        // }

        return height;
    }
};