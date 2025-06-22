class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for(auto& x : word){
            freq[x]++;
        }
        int res = word.size();
        for(auto& it : freq){
            // cout<<it.first<<" "<<it.second<<endl;
            int cur = it.second;
            int del = 0;
            for(auto& x : freq){
                if(x.second - cur > k){
                    del += x.second - cur - k;
                }
                else if(x.second < cur){
                    del += x.second;
                }
            }
            // cout<<del<<endl;
            res = min(res, del);
        }
        return res;
    }
};