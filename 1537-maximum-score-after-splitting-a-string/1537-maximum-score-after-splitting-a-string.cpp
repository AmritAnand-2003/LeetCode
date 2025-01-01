class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> freq(n);
        int ones = 0;
        for(int i = n - 1;i >= 0;i--){
            if(s[i] == '1'){
                ones++;
            }
            freq[i] = ones;
        }
        int zeroes = 0, ans = 0;
        for(int i = 0;i < n - 1;i++){
            if(s[i] == '0'){
                zeroes++;
            }
            ans = max(ans, zeroes + freq[i + 1]);
        }
        return ans;
    }
};