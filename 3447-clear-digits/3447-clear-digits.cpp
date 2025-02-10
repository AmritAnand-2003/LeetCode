class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        int pos = 0;
        for(int i = 0;i < n;i++){
            if(s[i] >= '0' && s[i] <= '9'){
                pos--;
            }
            else{
                s[pos++] = s[i];
            }
        }
        s.resize(pos);
        return s;
    }
};