class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        int t;
        while(k != 1){
            t = ceil(log2(k));
            t--;
            k = k - ((long long)1 << t);
            if(operations[t]){
                ans++;
            }
        }
        return 'a' + (ans % 26);
    }
};