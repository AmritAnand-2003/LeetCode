class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int rem = grid[0][0] % x;
        for(auto& v : grid){
            for(auto& y : v){
                nums.push_back(y);
                if(y % x != rem){
                    return -1;
                }
            }
        }
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int target = nums[sz/2], ans = 0;
        for(int i = 0;i < sz;i++){
            ans += abs(nums[i] - target) / x;
        }
        return ans;
    }
};