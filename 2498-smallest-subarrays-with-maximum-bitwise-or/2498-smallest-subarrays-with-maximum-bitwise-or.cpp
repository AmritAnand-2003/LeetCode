class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> bits(32);
        int n = nums.size();
        // vector<vector<int>> next_bit_set(n, vector<int>(32, -1));
        vector<int> next_ind(n, 1);
        int ind = -1;
        for(int i = 0;i < 32;i++){
            for(int j = n - 1;j >= 0;j--) {
                if((nums[j] & (1 << i))){
                    ind = j;
                }
                // next_bit_set[j][i] = ind;
                next_ind[j] = max(next_ind[j], ind - j + 1);
            }
        }
        return next_ind;
    }
};