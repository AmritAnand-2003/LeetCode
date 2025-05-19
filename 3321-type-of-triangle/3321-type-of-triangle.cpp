class Solution {
public:
    string triangleType(vector<int>& nums) {
        int sum = nums[0] + nums[1] + nums[2];
        int mn = *min_element(nums.begin(), nums.end()), mx = *max_element(nums.begin(), nums.end());
        if(mx >= sum - mx){
            return "none";
        }
        if(nums[0] == nums[1] && nums[1] == nums[2]){
            return "equilateral";
        }
        else if(nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0]){
            return "isosceles";
        }
        else{
            return "scalene";
        }
    }
};