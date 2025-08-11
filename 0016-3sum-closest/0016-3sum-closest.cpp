class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0;i < n - 2;i++) {
            int l = i + 1, h = n - 1;
            int tar = target - nums[i];
            while(l < h){
                int sum = nums[l] + nums[h];
                if(ans == INT_MAX || abs(sum + nums[i] - target) < abs(ans - target)){
                    ans = sum + nums[i];
                }
                if(sum > tar){
                    h--;
                }
                else if(sum < tar){
                    l++;
                }
                else{
                    return target;
                }
            }
        }
        return ans;
    }
};