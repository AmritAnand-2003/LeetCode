class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, curCount = 1;
        bool incr = true;
        for(int i = 1;i < nums.size() ;i++){
            if(nums[i] > nums[i - 1]){
                if(incr || curCount == 1){
                    curCount++;
                }
                else{
                    curCount = 2;
                }
                incr = true;
            }
            else if(nums[i] < nums[i - 1]){
                if(!incr || curCount == 1){
                    curCount++;
                }
                else{
                    curCount = 2;
                }
                incr = false;
            }
            else{
                curCount = 1;
            }
            ans = max(ans, curCount);
        }
        return ans;
    }
};