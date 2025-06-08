class TrieNode{
public:
    bool isEnd;
    vector<TrieNode*> arr;
    TrieNode(){
        isEnd = false;
        arr.resize(10);
        for(int i = 0;i < 10 ;i++){
            arr[i] = NULL;
        }
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(int num){
        int digits = log10(num);
        int div = pow(10, digits);
        TrieNode* node = root;
        while(div > 0){
            int cur = num/div;
            num %= div;
            div /= 10;
            if(node->arr[cur] == NULL){
                node->arr[cur] = new TrieNode();
            }
            node = node->arr[cur];
        }
        node->isEnd = true;
    }
};

void solve(vector<int>& ans, TrieNode* node, int cur){
    if(node->isEnd){
        ans.push_back(cur);
    }
    for(int i = 0;i < 10;i++){
        if(node->arr[i] != NULL){
            int next_val = cur * 10 + i;
            solve(ans, node->arr[i], next_val);
        }
    }
}

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie *t = new Trie();
        for(int i = 1;i <= n;i++){
            t->insert(i);
        }
        vector<int> ans;
        solve(ans, t->root, 0);
        return ans;
    }
};