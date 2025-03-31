class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> indexes;
        for(int i = 0; i < s.size();i++){
            if(indexes.find(s[i]) == indexes.end()){
                indexes[s[i]] = {i, i};
            }
            else{
                indexes[s[i]].first = min(indexes[s[i]].first, i);
                indexes[s[i]].second = max(indexes[s[i]].second, i);
            }
        }
        // for(auto it : indexes){
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        // }
        int start = 0, end = 0;
        vector<int> ans;
        // cout<<endl;
        for(int i = 0;i < s.size();i++){
            int cur = s[i];
            int cur_end = indexes[s[i]].second;
            if(i > end){
                ans.push_back(end - start + 1);
                start = i;
                end = cur_end;
            }
            else{
                end = max(end, cur_end);
            }
        }
        ans.push_back(end - start + 1);
        return ans;
    }
};