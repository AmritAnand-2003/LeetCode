const int mod = 1e9 + 7;

class Solution {
public:
    void solve(int n, vector<int>& powers) {
        if(n == 0){
            return;
        }
        if(n == 1){
            powers.push_back(1);
            return;
        }
        // cout<<n<<" ";
        int pos = floor(log2(n));
        int val = 1 << pos;
        // cout<<val<<endl;
        solve(n - val, powers);
        powers.push_back(val);
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        solve(n, powers);    
        vector<int> ans;
        for(auto& q : queries){
            long cur = 1;
            for(int l = q[0]; l <= q[1];l++){
                cur = (cur * powers[l]) % mod;
            }
            ans.push_back(cur);
        }
        return ans;   
    }
};