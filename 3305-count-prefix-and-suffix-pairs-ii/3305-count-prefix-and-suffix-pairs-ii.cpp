class TrieNode{
    public:
    unordered_map<int, TrieNode*> arr;
    int isPreSuf;
    TrieNode(){
        isPreSuf = 0;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string& a){
        TrieNode* cur = root;
        for(int i = 0;i < a.size();i++){
            int x = a[i] - 'a', y = a[a.size() - 1 - i] - 'a';
            int cur_hash = x * 100 + y;
            if(cur->arr.find(cur_hash) == cur->arr.end()){
                cur->arr[cur_hash] = new TrieNode();
            }
            // if(cur->arr[x - 'a'] == NULL){
            //     cur->arr[x - 'a'] = new TrieNode;
            // }
            // cur = cur->arr[x - 'a'];
            // if(cur->arr[y - 'a'] == NULL){
            //     cur->arr[y - 'a'] = new TrieNode;
            // }
            cur = cur->arr[cur_hash];
            cur->isPreSuf++;
        }
    }
    int search(string& a){
        TrieNode* cur = root;
        for(int i = 0;i < a.size();i++){
            int x = a[i] - 'a', y = a[a.size() - 1 - i] - 'a';
            int cur_hash = x * 100 + y;
            if(cur->arr.find(cur_hash) == cur->arr.end()){
                return 0;
            }
            cur = cur->arr[cur_hash];
            // if(cur->arr[x - 'a'] == NULL){
            //     return 0;
            // }
            // cur = cur->arr[x - 'a'];
            // if(cur->arr[y - 'a'] == NULL){
            //     return 0;
            // }
            // cur = cur->arr[y - 'a'];
        }
        return cur->isPreSuf;
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        long long ans = 0;
        Trie t;
        for(int i = n - 1;i >= 0;i--){
            ans += t.search(words[i]);
            t.insert(words[i]);
        }
        return ans;
    }
};