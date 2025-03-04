class Solution {
private:
    vector<int> dp;
public:
    bool solve(int n, long long& mask){
        // cout<<n<<" "<<mask<<endl;
        if(n == 0){
            return true;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int power = 1;
        for(int i = 0;i <= 14;i++){
            if(power > n){
                break;
            }
            // cout<<" checking "<<power<<" "<<(1 << i)<<" "<<(power & (1 << i))<<endl;
            if((mask & (1 << i)) == 0){
                // cout<<"inside "<<n<<" "<<power<<endl;
                // options[i] = false;
                mask |= (1 << i);
                if(solve(n - power, mask) == true){
                    return dp[n] = true;
                }
                mask &= ~(1 << i);
                // options[i] = true;
            }
            power *= 3;
        }
        return dp[n] = false;
    }
    bool checkPowersOfThree(int n) {
        vector<bool> options(15, true);
        long long mask = 0;
        dp.resize(n + 1, -1);
        return solve(n, mask);
    }
};