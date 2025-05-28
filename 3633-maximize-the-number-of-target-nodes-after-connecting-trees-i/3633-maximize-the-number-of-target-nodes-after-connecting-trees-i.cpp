class Solution {
public:
    vector<int> nodesInRange(vector<vector<int>>& edges, int k){
        int n1 = edges.size() + 1;
        vector<vector<int>> adj1(n1);
        for(auto& e : edges){
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        vector<int> count(n1, 0);
        vector<bool> vis(n1, false);
        for(int i = 0;i < n1;i++){
            queue<int> q;
            q.push(i);
            vis[i] = true;
            int dist = 0;
            while(!q.empty() && dist <= k){
                int sz = q.size();
                count[i] += sz;
                while(sz--){
                    int cur = q.front();
                    q.pop();
                    for(auto& ngbr : adj1[cur]){
                        if(!vis[ngbr]){
                            q.push(ngbr);
                            vis[ngbr] = true;
                        }
                    }
                }
                dist++;
            }
            fill(vis.begin(), vis.end(), false);
            // cout<<count[i]<<" ";
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> v1 = nodesInRange(edges1, k), v2 = nodesInRange(edges2, k - 1);
        int mx2 = *max_element(v2.begin(), v2.end());
        // cout<<endl;
        // cout<<mx2<<endl;
        for(int i = 0;i < v1.size();i++){
            v1[i] += mx2;
        }
        return v1;
    }
};