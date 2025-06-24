class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;;
        int last_ind = -1, n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[i] == key){
                for(int j = max(i - k, last_ind + 1); j < min(i + k + 1, n);j++){
                    ans.push_back(j);
                }
                last_ind = i + k;
            }
        }
        return ans;
    }
};