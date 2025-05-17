class Solution {
public:
    void detect_bridges(int node, int parent, vector<bool>& vis, vector<int>& disc, vector<int>& low, vector<vector<int>>& adj, vector<vector<int>>& bridges){
        static int time = 0;
        vis[node] = true;
        disc[node] = low[node] = ++time;
        for(int& ngbr : adj[node]){
            if(ngbr == parent){
                continue;
            }
            if(!vis[ngbr]){
                detect_bridges(ngbr, node, vis, disc, low, adj, bridges);                
            }
            low[node] = min(low[node], low[ngbr]);
            if(low[ngbr] > disc[node]){
                bridges.push_back({node, ngbr});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n, false);
        vector<int> disc(n, -1), low(n, -1);
        vector<vector<int>> bridges;
        vector<vector<int>> adj(n);
        for(auto& con : connections){
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        detect_bridges(0, -1, vis, disc, low, adj, bridges);
        return bridges;
    }
};