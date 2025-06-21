class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        map<int, vector<vector<int>>> sweepLine;
        int currY = rectangles[0][1];
        for(vector<int> temp: rectangles){
            sweepLine[temp[1]].push_back({0, temp[0], temp[2]});
            sweepLine[temp[3]].push_back({1, temp[0], temp[2]});
            currY = min(currY, temp[1]);
        }
        long long ans = 0;
        long long mod = 1e9+7;
        multiset<pair<int, int>> active;
        for(auto& temp: sweepLine){
            int y = temp.first;
            vector<vector<int>> horizon_array = temp.second;
            int curr_x = -1;
            long long hor_x = 0;
            for(auto& act: active){
                curr_x = max(curr_x, act.first);
                hor_x += max(act.second - curr_x, 0);
                curr_x = max(curr_x, act.second);
            }
            ans = (ans +(((y - currY) % mod) * (hor_x % mod))% mod) % mod;
            currY = y;
            for(auto t : horizon_array){
                if(t[0] == 0){
                    active.insert({t[1], t[2]});
                }
                else{
                    active.erase(active.find({t[1], t[2]}));
                }
            }
        }
        return ans;
    }
};