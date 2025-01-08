class Solution {
public:
    bool check(string& a, string& b){
        if(a.size() > b.size()){
            return false;
        }
        int n = a.size();
        for(int i = 0;i < n;i++){
            if(a[i] != b[i]){
                return false;
            }
            if(a[i] != b[b.size() - n + i]){
                return false;
            }
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0;i < words.size() - 1;i++){
            for(int j = i + 1;j < words.size();j++){
                ans += check(words[i], words[j]);
            }
        }
        return ans;
    }
};