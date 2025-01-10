class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> univ;
        for(auto s : words2){
            unordered_map<char, int> temp;
            for(auto c : s){
                temp[c]++;
                univ[c] = max(univ[c], temp[c]);
            }
        }
        vector<string> sol;
        for(auto s : words1){
            unordered_map<char, int> temp = univ;
            for(int i = 0;i < s.size();i++){
                if(temp.find(s[i]) != temp.end()){
                    temp[s[i]]--;
                    if(temp[s[i]] == 0){
                        temp.erase(s[i]);
                    }
                }
            }
            if(temp.empty()){
                sol.push_back(s);
            }
        }
        return sol;
    }
};