class TreeAncestor {
public:
    vector<vector<int>> jump;
    TreeAncestor(int n, vector<int>& parent) {
        jump.resize(n, vector<int>(18, -1));
        vector<vector<int>> child(n);
        for(int i = 0;i < n;i++){
            if(parent[i] != -1){
                jump[i][0] = parent[i];
                child[parent[i]].push_back(i);
            }
        }
        queue<int> pending;
        pending.push(0);
        while(!pending.empty()){
            int i = pending.front();
            pending.pop();
            for(int j = 1;j < 18 && jump[i][j - 1] != -1;j++){
                jump[i][j] = jump[jump[i][j - 1]][j - 1];
            }
            for(int& c : child[i]){
                pending.push(c);
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        while(k && node != -1){
            int high_set_bit = (int)log2(k);
            node = jump[node][high_set_bit];
            k ^= (1 << high_set_bit);
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */