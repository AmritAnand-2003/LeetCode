class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<int>> adj1(n, vector<int>(n, INT_MAX));
        for(auto& x : edges){
            adj1[x[0]][x[1]] = min(adj1[x[0]][x[1]], x[2]);
            adj1[x[1]][x[0]] = min(adj1[x[1]][x[0]], x[2]);
        }
        vector<vector<vector<int>>> adj(n);
        for(int i= 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(adj1[i][j] != INT_MAX){
                    adj[i].push_back({j, adj1[i][j], passingFees[j]});
                }
            }
        }
        vector<vector<int>> cost(n, vector<int>(maxTime + 1, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({passingFees[0], 0, 0}); // cost, node, time
        cost[0][0] = passingFees[0]; // node, time -> fees
        unordered_map<int, int> vis;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int u = cur[1]; // vertex
            int cur_time = cur[2]; // time
            for(auto& ngbr : adj[u]){
                int i = ngbr[0];
                if(ngbr[1] != INT_MAX){
                    int v_time = ngbr[1] + cur_time;
                    if(vis.find(i) != vis.end() && v_time >= vis[i]){
                        continue;
                    }
                    vis[i] = v_time;
                    if(v_time <= maxTime && cost[i][v_time] > cost[u][cur_time] + passingFees[i]){
                        cost[i][v_time] = cost[u][cur_time] + passingFees[i];
                        pq.push({cost[i][v_time], i, v_time});
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(auto& c : cost[n - 1]){
            ans = min(ans, c);
        }
        return ans != INT_MAX ? ans : -1;
    }
};