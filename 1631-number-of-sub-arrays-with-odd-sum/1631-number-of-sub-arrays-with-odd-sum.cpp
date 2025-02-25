class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1, ans = 0, mod = 1e9 + 7, sum = 0;
        for(auto x : arr){
            sum += x;
            if(sum % 2 == 0){
                ans = (ans + odd) % mod;
                even++;
            }
            else{
                ans = (ans + even) % mod;
                odd++;
            }
        }
        return ans;
    }
};