class TrieNode {
public:
    bool isWord;
    TrieNode* child[26];
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for(auto word: wordDict) {
            TrieNode* curr = root;
            for(char c : word) {
                if(curr->child[c - 'a'] == NULL) {
                    curr->child[c - 'a'] = new TrieNode();
                }
                curr = curr->child[c - 'a'];
            }
            curr->isWord = true;
        }
        vector<bool> dp(s.length(), false);
        for(int i = 0; i < s.length(); i++) {
            if(i == 0 || dp[i - 1]) {
                TrieNode* curr = root;
                for(int j = i; j < s.length(); j++) {
                    char c = s[j];
                    if(curr->child[c - 'a'] == NULL) {
                        break;
                    }
                    curr = curr->child[c - 'a'];
                    if(curr->isWord) {
                        dp[j] = true;
                    }
                }
            }
        }
        return dp[s.length() - 1];
    }
};