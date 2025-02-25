class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount){
        n = amount.size();
        tree.resize(n);
        for(auto& e : edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        distance_from_bob.resize(n);
        return findPaths(0, 0, 0, bob, amount);
    }

private:
    vector<vector<int>> tree;
    vector<int> distance_from_bob;
    int n;
    
    int findPaths(int source, int parent, int time, int bob, vector<int>& amount){
        int max_income = 0, max_child = INT_MIN;
        if(source == bob){
            distance_from_bob[source] = 0;
        }
        else{
            distance_from_bob[source] = n;
        }
        for(int adj : tree[source]){
            if(adj != parent){
                max_child = max(max_child, findPaths(adj, source, time + 1, bob, amount));
                distance_from_bob[source] = min(distance_from_bob[source], distance_from_bob[adj] + 1);
            }
        }
        if(distance_from_bob[source] > time){
            max_income += amount[source];
        }
        else if(distance_from_bob[source] == time){
            max_income += amount[source] / 2;
        }
        if(max_child == INT_MIN){
            return max_income;
        }
        else{
            return max_income + max_child;
        }
    }
};