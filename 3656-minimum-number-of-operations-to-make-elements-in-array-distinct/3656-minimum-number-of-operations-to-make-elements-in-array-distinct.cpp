class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        int ind = -1;
        for(int i = nums.size() - 1;i >= 0;i--){
            if(freq[nums[i]] > 0){
                break;
            }
            freq[nums[i]]++;
            ind = i;
        }
        int ans = 0;
        if(ind != -1){
            ans = ceil((float)ind/3);
        }
        return ans;
    }
};