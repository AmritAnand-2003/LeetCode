class DisjointSet{
    public:
    vector<int> parent, sz;
    DisjointSet(int n){
        parent.resize(n, -1);
        sz.resize(n, 1);
    }

    int findParent(int s){
        int par = parent[s];
        if(par == -1){
            return s;
        }
        return parent[s] = findParent(par);
    }

    void unionBySize(int u, int v){
        int par_u = findParent(u), par_v = findParent(v);
        int sz_u = sz[par_u], sz_v = sz[par_v];
        if(sz_u > sz_v){
            parent[par_v] = par_u;
            sz[par_u] += sz_v;
        }
        else{
            parent[par_u] = par_v;
            sz[par_v] += sz_u;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(1001);
        vector<int> ans;
        for(auto e : edges){
            int u1 = ds.findParent(e[0]), u2 = ds.findParent(e[1]);
            if(u1 == u2){
                return e;
            }
            ds.unionBySize(e[0], e[1]);
        }
        return ans;
    }
};