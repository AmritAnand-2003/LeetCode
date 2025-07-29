class Solution {
public:
    bool is_subsequence(string& s, string& b) {
        int i = 0, j = 0;
        for(i = 0;i < s.size() && j < b.size();i++){
            if(s[i] == b[j]){
                j++;
            }
        }
        return j == b.size();
    }

    int numMatchingSubseq(string& s, vector<string>& words) {
        int ans = 0;
        unordered_map<string, bool> cache;
        for(auto& word : words) {
            if(word.size() <= s.size()){
                if(cache.find(word) != cache.end()){
                    ans += cache[word];
                }
                else{
                    cache[word] = is_subsequence(s, word);
                    ans += cache[word];
                }
            }
        }
        return ans;
    }
};