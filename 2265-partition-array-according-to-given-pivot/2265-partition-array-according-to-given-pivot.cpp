class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, more;
        for(auto x : nums){
            if(x < pivot){
                less.push_back(x);
            }
            else if(x > pivot){
                more.push_back(x);
            }
        }
        int i = 0;
        while(i<less.size()){
            nums[i++] = less[i];
        }
        for(int k = 0;k < nums.size() - less.size() - more.size();k++){
            nums[i++] = pivot;
        }
        for(auto x : more){
            nums[i++] = x;
        }
        return nums;
    }
};