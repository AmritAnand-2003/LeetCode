class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        int mx = 0, mn = s.size();
        for(auto& x : s){
            freq[x - 'a']++;
        }
        for(auto& val : freq){
            if(val % 2 == 0 && val != 0){
                mn = min(mn, val);
            }
            else{
                mx = max(mx, val);
            }
        }
        return mx - mn;
    }
};