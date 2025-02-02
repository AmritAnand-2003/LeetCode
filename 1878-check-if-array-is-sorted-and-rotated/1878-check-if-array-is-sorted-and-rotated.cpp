class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool pivot = false;
        for(int i = 1;i <= nums.size();i++){
            if(!pivot){
                if(nums[i % n] < nums[i - 1]){
                    pivot = true;
                }
            }
            else{
                if(nums[i % n] < nums[i - 1]){
                    return false;
                }
            }
        }
        return true;
    }
};