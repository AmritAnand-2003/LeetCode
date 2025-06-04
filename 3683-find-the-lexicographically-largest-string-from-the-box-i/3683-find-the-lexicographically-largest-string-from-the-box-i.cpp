class Solution {
public:
    string large_lexi(string& a, string& b){
        int m = a.size(), n = b.size();
        for(int i = 0, j = 0; i< m && j < n;i++, j++){
            if(a[i] > b[i]){
                return a;
            }
            else if(a[i] < b[i]){
                return b;
            }
        }
        return a.size() > b.size() ? a : b;
    }
    string answerString(string word, int numFriends) {
        if(numFriends == 1){
            return word;
        }
        char max_char = *max_element(word.begin(), word.end());
        string ans = "";
        int ans_len = word.size() - numFriends + 1;
        for(int i = 0; i < word.size(); i++){
            ans = max(ans, word.substr(i, ans_len));
        }
        // cout<<large_lexi("n", "nn");
        return ans;
    }
};