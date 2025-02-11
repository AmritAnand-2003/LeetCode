class Solution {
public:
    string removeOccurrences(string s, string part) {
        int cur = 0, part_len = part.size();
        for(int i = 0;i < s.size();i++){
            s[cur++] = s[i];
            while(cur >= part_len && s.substr(cur - part_len, part_len) == part){
                cur -= part_len;
            }
        }
        s.resize(cur);
        return s;
    }
};