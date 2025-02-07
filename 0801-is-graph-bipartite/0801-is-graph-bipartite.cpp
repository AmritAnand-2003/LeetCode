class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, int> color;
        queue<int> q;
        for(int i = 0;i < n;i++){
            if(color.find(i) == color.end()){
                color[i] = 0;
                q.push(i);
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    int curColor = color[cur];
                    int nextColor = (curColor + 1) % 2;
                    for(auto adj : graph[cur]){
                    if(color.find(adj) == color.end()){
                        q.push(adj);
                        color[adj] = nextColor;
                    }
                    else{
                        if(color[adj] != nextColor){
                            return false;
                        }
                    }
                    }
            }
            }
        }
        return true;
    }
};