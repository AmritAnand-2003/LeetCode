class Solution {
public:
    int sumNum(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> sum_hash;
        int ans = -1;
        for(auto x : nums){
            int x_sum = sumNum(x);
            if(sum_hash.find(x_sum) != sum_hash.end()){
                ans = max(ans, x + sum_hash[x_sum]);
            }
            sum_hash[x_sum] = max(sum_hash[x_sum], x);
        }
        return ans;
    }
};