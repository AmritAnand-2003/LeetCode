class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> stations;
        for(int i = 0;i < routes.size(); i++){
            for(auto stop : routes[i]){
                if(stations.find(stop) == stations.end()){
                    stations[stop] = {i};
                }
                else{
                    stations[stop].push_back(i);
                }
            }
        }
        int buses_count = routes.size();
        queue<pair<int, int>> state;
        state.push({source, 0});
        unordered_set<int> busVisited, stationVisited;
        stationVisited.insert(source);
        while(!state.empty()){
            int station = state.front().first;
            int cost = state.front().second;
            if(station == target){
                return cost;
            }
            state.pop();
            for(auto b : stations[station]){
                if(busVisited.find(b) != busVisited.end()){
                    continue;
                }
                for(auto st : routes[b]){
                    if(st == target){
                        return cost + 1;
                    }
                    if(stationVisited.find(st) == stationVisited.end()){
                        state.push({st, cost + 1});
                        stationVisited.insert(st);
                    }
                }
                busVisited.insert(b);
            }
        }
        return -1;
    }
};