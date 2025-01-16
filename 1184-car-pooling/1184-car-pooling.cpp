class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> line;
        for(auto t : trips){
            line[t[1]] += t[0];
            line[t[2]] -= t[0];
        }
        int cur = 0;
        for(auto l : line){
            cur += l.second;
            if(cur > capacity){
                return false;
            }
        }
        return true;
    }
};