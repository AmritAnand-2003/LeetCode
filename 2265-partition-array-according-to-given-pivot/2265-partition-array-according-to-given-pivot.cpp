class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int i = 0;
        vector<int> more;
        for(auto x : nums){
            if(x < pivot){
                nums[i++] = x;
            }
            else if(x > pivot){
                more.push_back(x);
            }
        }
        int k = nums.size() - i - more.size();
        while(k--){
            nums[i++] = pivot;
        }
        for(auto x : more){
            nums[i++] = x;
        }
        return nums;
    }
};