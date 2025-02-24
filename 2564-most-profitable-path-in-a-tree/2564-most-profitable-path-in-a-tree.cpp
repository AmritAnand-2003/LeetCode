class Solution {
public:
    vector<int> path(int cur_v, int par, vector<vector<int>>& graph, vector<int>& cur_path){
        if(cur_v == 0){
            return cur_path;
        }
        for(auto ngbr: graph[cur_v]){
            if(ngbr != par){
                cur_path.push_back(ngbr);
                auto p = path(ngbr, cur_v, graph, cur_path);
                if(!p.empty()){
                    return p;
                }
                cur_path.pop_back();
            }
        }
        return {};
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> graph(n);
        for(auto& e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> cur = {bob};
        vector<int> p = path(bob, -1, graph, cur);
        map<int, int> bob_path;
        for(int i = 0;i < p.size();i++){
            int cur_v = p[i];
            bob_path[cur_v] = i;
        }
        queue<pair<int, int>> pending;
        int time = 0, ans = INT_MIN;
        vector<bool> vis(n, false);
        pending.push({0, 0});
        vis[0] = true;
        while(!pending.empty()){
            int sz = pending.size();
            while(sz--){
                int node = pending.front().first;
                int income = pending.front().second;
                pending.pop();
                if(bob_path.find(node) != bob_path.end()){
                    if(bob_path[node] == time){
                        income += amount[node]/2;
                    }
                    else if(bob_path[node] > time){
                        income += amount[node];
                    }
                }
                else{
                    income += amount[node];
                }
                for(auto ngbr: graph[node]){
                    if(!vis[ngbr]){
                        pending.push({ngbr, income});
                        vis[ngbr] = true;
                    }
                }
                if(graph[node].size() == 1 && node != 0){
                    ans = max(ans, income);
                }
            }
            time++;
        }
        return ans;
    }
};