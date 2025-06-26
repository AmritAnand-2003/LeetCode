class Solution {
public:
    int solve(string& s, int& k, int ind, int len, int num){
        if(num > k){
            return -1;
        }
        if(ind == s.size()){
            return len;
        }
        int x = solve(s, k, ind + 1, len, num);
        num *= 2;
        num += (s[ind] - '0');
        int y = solve(s, k, ind + 1, len + 1, num);
        return max(x, y);
    }
    int longestSubsequence(string s, int k) {
        // return solve(s, k, 0, 0, 0);
        int len = 0, power = 0;
        long long val = 0;
        for(int i = s.size() - 1; i >= 0;i--){
            if(s[i] == '0'){
                len++;
            }
            else{
                if(power < 40 &&val + (1LL << power) <= k){
                    val += (1LL << power);
                    len++;
                }
            }
            power++;
        }
        return len;
    }
};