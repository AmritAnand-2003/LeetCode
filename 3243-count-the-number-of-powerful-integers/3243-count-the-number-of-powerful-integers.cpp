class Solution {
public:
    long long dp[20][2];
    long long solve(const string& x, int index, int tight, int limit, string& s){
        if(index == x.size()){
            return 1;
        }
        if(dp[index][tight] != -1){
            return dp[index][tight];
        }
        long long answer = 0;
        int up_limit = tight ? x[index] - '0' : 9;
        int suffixStartIdx = x.size() - s.size();
        if(index >= suffixStartIdx){
            int idx = index - suffixStartIdx;
            int digit = s[idx] - '0';
            if(digit <= up_limit && digit <= limit){
                answer += solve(x, index + 1, tight && (digit == up_limit), limit, s);
            }
        }
        else{
            for(int digit = 0; digit <= up_limit && digit <= limit; digit++){
                answer += solve(x, index + 1, tight && (digit == up_limit), limit, s);
            }
        }
        return dp[index][tight] = answer;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        memset(dp, -1, sizeof(dp));
        if(stoll(s) > finish){
            return 0;
        }
        long long powerfulUptoFinsh = solve(to_string(finish), 0, true, limit, s);
        memset(dp, -1, sizeof(dp));
        long long powerfulUptoStart = (start > stoll(s)) ? solve(to_string(start - 1), 0, true, limit, s) : 0;
        // cout<<powerfulUptoFinsh<<" "<<powerfulUptoStart<<endl;
        return powerfulUptoFinsh - powerfulUptoStart;
    }
};