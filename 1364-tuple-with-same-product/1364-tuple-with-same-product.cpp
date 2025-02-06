class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> prod_freq;
        for(int i = 0;i < nums.size();i++){
            for(int j = i + 1;j < nums.size();j++){
                int cur = nums[i] * nums[j];
                prod_freq[cur]++;
            }
        }
        int ans = 0;
        for(auto it : prod_freq){
            int freq = it.second;
            if(freq >= 2){
                int cur = 4 * (freq) * (freq - 1);
                ans += cur;
            }
        }
        return ans;
    }
};