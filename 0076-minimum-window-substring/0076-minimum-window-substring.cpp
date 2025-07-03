class Solution {
public:
    bool check(unordered_map<char, int>& s_freq, unordered_map<char, int>& t_freq){
        for(auto& it : t_freq){
            if(s_freq.find(it.first) == s_freq.end() || s_freq[it.first] < it.second){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> t_freq;
        unordered_map<char, int> s_freq;
        for(int i = 0;i < t.size();i++){
            t_freq[t[i]]++;
        }
        int i = 0, j = 0;
        int cur = 0, total = t_freq.size();
        int res = INT_MAX;
        pair<int, int> indices;
        while(j < s.size()){
            if(t_freq.find(s[j]) != t_freq.end()){
                s_freq[s[j]]++;
                if(t_freq[s[j]] == s_freq[s[j]]){
                    cur++;
                }
            }
            while(cur == total){
                if(j - i + 1 < res){
                    res = j - i + 1;
                    indices = {i, j};
                }
                if(s_freq.find(s[i]) != s_freq.end()){
                    s_freq[s[i]]--;
                    if(s_freq[s[i]] < t_freq[s[i]]){
                        cur--;
                    }
                }
                i++;
            }
            j++;
        }
        return (res == INT_MAX) ? "" : s.substr(indices.first, indices.second - indices.first + 1);
    }
};