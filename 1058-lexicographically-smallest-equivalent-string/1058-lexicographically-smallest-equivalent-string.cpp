class DisjointSet{
    public:
    vector<int> par;
    DisjointSet(int n){
        par.resize(n);
        for(int i = 0; i < n;i++){
            par[i] = i;
        }
    }

    int findPar(int u){
        if(u == par[u]){
            return u;
        }
        return par[u] = findPar(par[u]);
    }

    void unionByMin(int u, int v){
        int par_u = findPar(u);
        int par_v = findPar(v);
        if(par_v < par_u){
            par[par_u] = par_v;
        }
        else{
            par[par_v] = par_u;
        }
    }
};


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr){
        DisjointSet st(26);
        for(int i = 0;i < s1.size(); i++){
            st.unionByMin(s1[i] - 'a', s2[i] - 'a');
        }
        string ans;
        for(auto& x : baseStr){
            ans += (st.findPar(x - 'a') + 'a');
            // cout<<st.findPar(x - 'a') + 'a'<<" ";
        }
        return ans;
    }
};