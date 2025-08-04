class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Longest subaaray with 2 distinct values
        int start = 0;
        unordered_map<int, int> last_ind;
        int ans = 1;
        for(int i = 0;i < fruits.size();i++){
            last_ind[fruits[i]] = i;
            if(last_ind.size() > 2){
                int mn_key, mn_val = i;
                for(auto& it : last_ind){
                    if(it.second < mn_val){
                        mn_val = it.second;
                        mn_key = it.first;
                    }
                }
                start = last_ind[mn_key] + 1;
                last_ind.erase(mn_key);
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};