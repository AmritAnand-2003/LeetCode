class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        unordered_map<int, int> bit_ind;
        int left = 0, ans = 1;
        for(int i = 0;i < nums.size();i++){
            int val = nums[i], pos = 1;
            while(val){
                if(val & 1){
                    if(bit_ind.find(pos) != bit_ind.end()){
                        left = max(left, bit_ind[pos] + 1);
                    }
                    bit_ind[pos] = i;
                }
                val >>= 1;
                pos++;
            }
            ans = max(ans, i - left + 1);
            // cout<<left<<" "<<i<<" "<<(i - left + 1)<<endl;
        }
        return ans;
    }
};