class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> inDegree(n);
        vector<vector<int>> adj(n);
        for(auto& x : edges){
            adj[x[0]].push_back(x[1]);
            inDegree[x[1]]++;
        }
        vector<vector<int>> cnt(colors.size(), vector<int>(26));
        queue<int> q;
        for(int i = 0; i < n;i++){
            if(inDegree[i] == 0){
                q.push(i);
                cnt[i][colors[i] - 'a'] = 1;
            }
        }
        int ans = 0, seen = 0;
        while(q.size()){
            int cur = q.front();
            q.pop();
            int val = *max_element(begin(cnt[cur]), end(cnt[cur]));
            ans = max(ans, val);
            ++seen;
            for(int ngbr: adj[cur]){
                for(int i = 0; i < 26; ++i){
                    cnt[ngbr][i] = max(cnt[ngbr][i], cnt[cur][i] + (i == colors[ngbr] - 'a'));
                }
                if(--inDegree[ngbr] == 0){
                    q.push(ngbr);
                }
            }
        }
        return seen < colors.size() ? -1 : ans;
    }
};