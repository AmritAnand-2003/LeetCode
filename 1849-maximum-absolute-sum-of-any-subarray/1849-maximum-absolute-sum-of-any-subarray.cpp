class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int cur_sum1 = 0, cur_sum2 = 0, ans = 0;
        for(auto x : nums){
            cur_sum1 += x;
            cur_sum2 += x;
            if(cur_sum1 < 0){
                cur_sum1 = 0;
            }
            if(cur_sum2 > 0){
                cur_sum2 = 0;
            }
            ans = max({ans, cur_sum1, abs(cur_sum2)});
        }
        return ans;
    }
};