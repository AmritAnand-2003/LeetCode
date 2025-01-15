class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, pair<int, int>> line;
        for(auto x : flowers){
            if(line.find(x[0]) == line.end()){
                line[x[0]] = {1, 0};
            }
            else{
                line[x[0]].first++;
            }
            if(line.find(x[1] + 1) == line.end()){
                line[x[1] + 1] = {0, 1};
            }
            else{
                line[x[1] + 1].second++;
            }
        }
        map<int, int> count;
        int cur = 0;
        for(auto it : line){
            // cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
            cur += it.second.first;
            cur -= it.second.second;
            count[it.first] = cur;
            // cout<<cur<<endl;
        }
        vector<int> ans;
        for(auto p : people){
            auto it = count.lower_bound(p + 1);
            if(it == count.begin()){
                ans.push_back(0);
            }
            else{
                it--;
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};