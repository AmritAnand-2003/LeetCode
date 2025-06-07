class Solution {
public:
    unordered_map<string, bool> mem;
    bool isScramble(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        if(mem.find(s1 + s2) != mem.end()){
            return mem[s1 + s2];
        }
        int n = s1.size();
        vector<int> freq(26);
        for(int i = 0;i < n;i++){
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }
        for(auto x : freq){
            if(x != 0){
                return false;
            }
        }
        for(int i = 1;i < n;i++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))){
                mem[s1 + s1] = true;
                return true;
            }
            if(isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))){
                mem[s1 + s1] = true;
                return true;
            }
        }
        return mem[s1 + s2] = false;
    }
};