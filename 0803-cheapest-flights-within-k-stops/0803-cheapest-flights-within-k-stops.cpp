class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for(int i = 0;i <= k;i++){
            vector<int> temp(dist);
            for(auto& flight : flights){
                int s = flight[0], d = flight[1], cost = flight[2];
                if(dist[s] != INT_MAX && dist[s] + cost < temp[d]){
                    temp[d] = dist[s] + cost;
                }
            }
            dist = temp;
        }
        return dist[dst] != INT_MAX ? dist[dst] : -1;
    }
};