class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n + 1);
        for(int i = 0;i < n;i++){
            int wordSize = words[i].size();
            if(isVowel(words[i][0]) && isVowel(words[i][wordSize - 1])){
                prefixSum[i + 1] = 1;
            }
            prefixSum[i + 1] += prefixSum[i];
        }
        vector<int> sol;
        for(auto &q : queries){
            int cur = prefixSum[q[1] + 1] - prefixSum[q[0]];
            sol.push_back(cur);
        }
        return sol;
    }
};