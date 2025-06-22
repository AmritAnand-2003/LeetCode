class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i = 0;
        while(i + k <= s.size()){
            string cur = s.substr(i, k);
            i+= k;
            ans.push_back(cur);
        }
        string rem = s.substr(i);
        if(rem.size()){
            while(rem.size() < k){
                rem.push_back(fill);
            }
            ans.push_back(rem);
        }
        return ans;
    }
};