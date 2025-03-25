class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int m = rectangles.size();
        vector<vector<int>> yaxis, xaxis;
        map<int, pair<int, int>> linex, liney;
        for (auto r : rectangles) {
            linex[r[0]].first++;
            linex[r[2]].second++;
            liney[r[1]].first++;
            liney[r[3]].second++;
        }
        int active = 0, count = 0;
        for(auto it : linex){
            active -= it.second.second;
            if(it.second.second && active == 0){
                count++;
            }
            active += it.second.first;  
            if(count >= 3){
                return true;
            }
        }
        active = 0, count = 0;
        for (auto it : liney) {
            active -= it.second.second;
            if(it.second.second && active == 0){
                count++;
            }
            active += it.second.first;  
            if(count >= 3){
                return true;
            }
        }
        return false;
    }
};