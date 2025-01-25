class Solution {
public:
    bool isCycle(int node, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& dfsVis){
        vis[node] = true;
        dfsVis[node] = true;
        for(auto neigh : graph[node]){
            if(!vis[neigh]){
                if(isCycle(neigh, graph, vis, dfsVis)){
                    return true;
                }
            }
            else if(dfsVis[neigh]){
                return true;
            }
        }
        dfsVis[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n), dfsVis(n);
        for(int i = 0;i < n;i++){
            if(!vis[i]){
                isCycle(i, graph, vis, dfsVis);
            }
        }
        vector<int> safe;
        for(int i = 0;i < n;i++){
            if(!dfsVis[i]){
                safe.push_back(i);
            }
        }
        return safe;
    }
};