class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> line(1001);
        for(auto t : trips){
            line[t[1]] += t[0];
            line[t[2]] -= t[0];
        }
        int cur = 0;
        for(int i = 0;i < line.size();i++){
            cur += line[i];
            if(cur > capacity){
                return false;
            }
        }
        return true;
    }
};