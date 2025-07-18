class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<vector<int>> num_ind;
        for(int i = 0;i < nums.size();i++){
            num_ind.push_back({nums[i], i});
        }
        priority_queue<int> mx_pq;
        priority_queue<int, vector<int>, greater<int>> mn_pq;
        vector<long long> mn_sum(3*n), mx_sum(3*n);
        long long mn_sum_val = 0, mx_sum_val = 0;
        for(int i = 0;i < 2 * n;i++){
            mn_sum_val += nums[i];
            mx_pq.push(nums[i]);
            if(mx_pq.size() > n){
                mn_sum_val -= mx_pq.top();
                mx_pq.pop();
            }
            int last_ind = 3 * n - 1 - i;
            mx_sum_val += nums[last_ind];
            mn_pq.push(nums[last_ind]);
            if(mn_pq.size() > n){
                mx_sum_val -= mn_pq.top();
                mn_pq.pop();
            }
            mn_sum[i] = mn_sum_val;
            mx_sum[last_ind] = mx_sum_val;
        }
        long long ans = LONG_MAX;
        for(int i = n - 1;i< 2* n ;i++){
            ans = min(ans, mn_sum[i] - mx_sum[i + 1]);
        }
        return ans;
    }
};