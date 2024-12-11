class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> freq, cur_freq, matched_words;
        for(auto x : words){
            freq[x]++;
        }
        int word_len = words[0].size(), words_len = words.size(), substring_len = word_len * words_len;
        vector<int> ans;
        int loop_range = s.size() - substring_len;
        for(int i = 0;i < loop_range + 1;i++){
            int start = i;
            bool match = true;
            cur_freq = freq;
            string cur_sub = s.substr(i, substring_len);
            if(matched_words[cur_sub] == 1){
                ans.push_back(i);
                continue;
            }
            else if(matched_words[cur_sub] == -1){
                continue;
            }
            for(int j = 0;j < words_len;j++){
                int ind = i + j * word_len;
                string cur = s.substr(ind, word_len);
                if(cur_freq[cur] > 0){
                    cur_freq[cur]--;
                }
                else{
                    match = false;
                    break;
                }
            }
            if(match){
                ans.push_back(i);
                matched_words[cur_sub] = 1;
            }
            else{
                matched_words[cur_sub] = -1;
            }
        }
        return ans;
    }
};