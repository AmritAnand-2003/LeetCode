class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        while(j < n){
            if(nums[j] == 0){
                j++;
            }
            else if(j != n - 1 && nums[j] == nums[j + 1]){
                nums[j] *= 2;
                nums[j + 1] = 0;
                swap(nums[i++], nums[j++]);
                j++;
            }
            else{
                swap(nums[i++], nums[j++]);
            }
        }
        return nums;
    }
};