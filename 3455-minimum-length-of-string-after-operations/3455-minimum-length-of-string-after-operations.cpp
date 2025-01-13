class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26);
        for(auto x : s){
            freq[x - 'a']++;
        }
        int ans = 0;
        for(auto f : freq){
            if(f){
                ans += (f % 2 == 1 ? 1 : 2);
            }
        }
        return ans;
    }
};