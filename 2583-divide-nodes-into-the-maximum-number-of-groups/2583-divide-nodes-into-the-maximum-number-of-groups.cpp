class Solution {
public:
    bool bipartite(int v, vector<vector<int>>& adj, vector<int>& col, vector<int>& component){
        if(col[v] != -1){
            return true;
        }
        queue<int> q;
        q.push(v);
        col[v] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            component.push_back(cur);
            int cur_col = col[cur];
            for(auto n : adj[cur]){
                if(col[n] == -1){
                    q.push(n);
                    col[n] = 1 - cur_col;
                }
                else if(col[n] == cur_col){
                    return false;
                }
            }
        }
        return true;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> col(n, -1);
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(auto& e : edges){
            int s = e[0] - 1, d = e[1] - 1;
            adj[s].push_back(d);
            adj[d].push_back(s);
            dist[s][d] = 1;
            dist[d][s] = 1;
        }
        int ans = 0;        
        for(int i = 0;i <n;i++){
            dist[i][i] = 0;
        }
        for(int k = 0;k < n;k++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        vector<vector<int>> components;
        for(int i = 0;i < n;i++){
            if(col[i] == -1){
                components.push_back({});
                if(!bipartite(i, adj, col, components.back())){
                    return -1;
                }
            }
        }
        int group_count = 0;
        for(auto& c : components){
            cout<<"here";
            int cur = INT_MIN;
            for(auto v : c){
                for(int i = 0;i < n;i++){
                    if(dist[v][i] != INT_MAX){
                        cur = max(cur, dist[v][i]);
                    }
                }
            }
            group_count += cur + 1;
        }
        return group_count;
    }
};