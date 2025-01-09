class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(auto x : words){
            int i = 0;
            for(i = 0;i < pref.size() && i < x.size();i++){
                if(pref[i] != x[i]){
                    break;
                }
            }
            if(i == pref.size()){
                ans++;
            }
        }
        return ans;
    }
};