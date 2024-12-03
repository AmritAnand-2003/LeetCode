class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int vertex, vector<int>& result){
        while(!adj[vertex].empty()){
            int next = adj[vertex].back();
            adj[vertex].pop_back();
            dfs(adj, next, result);
        }
        result.push_back(vertex);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> inDegree, outDegree;
        for(int i = 0;i < n;i++){
            int s = pairs[i][0], d = pairs[i][1];
            adj[s].push_back(d);
            outDegree[s]++;
            inDegree[d]++;
        }
        int source = pairs[0][0];
        for(auto& it : outDegree){
            // cout<<outDegree[i]<<" "<<inDegree[i]<<endl;
            int cur = it.first;
            if(outDegree[cur] == inDegree[cur] + 1){
                source = cur;
                break;
            }
        }
        // for(auto v : adj){
        //     for(auto x : v){
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> result;
        cout<<source<<endl;
        dfs(adj, source, result);
        reverse(result.begin(), result.end());
        vector<vector<int>> solution;
        for(int i = 1;i < result.size();i++){
            solution.push_back({result[i - 1], result[i]});
        }
        return solution;
    }
};