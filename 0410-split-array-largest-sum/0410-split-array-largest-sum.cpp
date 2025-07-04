class Solution {
public:
    bool solve(int mx_sum, vector<int>& nums, int k){
        int sum = 0, group = 1;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            if(sum > mx_sum){
                group++;
                sum = nums[i];
            }
        }
        return k >= group;
    }
    int splitArray(vector<int>& nums, int k) {
        int mn = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int l = mn, h = sum;
        int ans = INT_MAX;
        while(l <= h){
            int mid = (l + h) / 2;
            // cout<<mid<<endl;
            if(solve(mid, nums, k)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};