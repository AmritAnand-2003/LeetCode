class Solution {
public:
    int possibleStringCount(string word) {
        char last = ' ';        
        int ans = 1;
        for(auto& ch : word){
            if(ch == last){
                ans++;
            }
            else{
                last = ch;
            }
        }
        return ans;
    }
};