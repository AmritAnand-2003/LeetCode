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

    int depthOfComponent(vector<vector<int>>& adj, vector<int>& component){
        int max_depth = 0;
        queue<int> q;
        vector<int> dist(adj.size(), -1);
        for(auto s : component){
            dist.assign(adj.size(), -1);
            q.push(s);
            dist[s] = 0;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(auto nbr : adj[cur]){
                    if(dist[nbr] == -1){
                        dist[nbr] = dist[cur] + 1;
                        max_depth = max(max_depth, dist[nbr]);
                        q.push(nbr);
                    }
                }
            }
        }
        return max_depth + 1;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> col(n, -1);
        for(auto& e : edges){
            int s = e[0] - 1, d = e[1] - 1;
            adj[s].push_back(d);
            adj[d].push_back(s);
        }
        int ans = 0;        
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
            group_count += depthOfComponent(adj, c);
        }
        return group_count;
    }
};