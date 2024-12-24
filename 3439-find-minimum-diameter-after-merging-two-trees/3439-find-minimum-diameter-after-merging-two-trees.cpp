class Solution {
public:
    int height(int node, vector<vector<int>>& adj, int par, int& diameter){
        priority_queue<int, vector<int>, greater<int>> heights;
        int mxheight = 0;
        for(auto neigh : adj[node]){
            if(neigh != par){
                int h = height(neigh, adj, node, diameter) + 1;
                heights.push(h);
                if(heights.size() > 2){
                    heights.pop();
                }
            }
        }
        int curDiameter = 0;
        while(!heights.empty()){
            curDiameter += heights.top();
             mxheight = max(mxheight, heights.top());
            heights.pop();
        }
        diameter = max(diameter, curDiameter);
        return mxheight;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int nodes1 = edges1.size() + 1, nodes2 = edges2.size() + 1;
        vector<vector<int>> adj1(nodes1), adj2(nodes2);
        for(auto edge : edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto edge : edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        int d1 = 0, d2 = 0;
        height(0, adj1, -1, d1);
        height(0, adj2, -1, d2);
        int completeDiam = (d1 + 1)/2 + (d2 + 1)/2 + 1;
        return max({d1, d2, completeDiam});
    }
};