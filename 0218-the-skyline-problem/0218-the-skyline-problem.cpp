class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> pq({0});
        vector<pair<int, int>> points;
        for(auto b : buildings){
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }
        sort(points.begin(), points.end());
        int ongoingHeight = 0;
        for(int i = 0;i < points.size();i++){
            int curPoint = points[i].first;
            int curHeight = points[i].second;
            if(curHeight < 0){
                pq.insert(-curHeight);
            }
            else{
                pq.erase(pq.find(curHeight));
            }
            int pqTop = *pq.rbegin();
            if(ongoingHeight != pqTop){
                ongoingHeight = pqTop;
                ans.push_back({curPoint, ongoingHeight});
            }
        }
        return ans;
    }
};