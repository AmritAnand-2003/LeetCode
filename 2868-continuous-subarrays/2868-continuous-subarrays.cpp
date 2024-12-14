class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        queue<pair<int, int>> q;
        deque<pair<int, int>> maxmq, minmq;
        int left = 0;
        long long ans = 0;
        int maxm_ind = 0, minm_ind = 0;
        for(int i = 0;i < n;i++){
            // cout<<nums[i]<<" ";
            // while(!maxmq.empty() && (maxmq.front().second < left || maxmq.front().first - nums[i] > 2 )){
            //     left = max(left, maxmq.front().second + 1);
            //     maxmq.pop_front();
            // }
            // while(!minmq.empty() && (minmq.front().second < left || nums[i] - minmq.front().first) > 2){
            //     left = max(left, minmq.front().second + 1);
            //     minmq.pop_front();
            // }
            while(!maxmq.empty() && nums[i] > maxmq.back().first){
                maxmq.pop_back();
            }
            while(!minmq.empty() && minmq.back().first > nums[i]){
                minmq.pop_back();
            }
            maxmq.push_back({nums[i], i});
            minmq.push_back({nums[i], i});
            while(!maxmq.empty() && !minmq.empty() && abs(maxmq.front().first - minmq.front().first) > 2){
                if(maxmq.front().second > minmq.front().second){
                    left = max(left, minmq.front().second + 1);
                    minmq.pop_front();
                }
                else{
                    left = max(left, maxmq.front().second + 1);
                    maxmq.pop_front();
                }
            }
            ans += (i - left) + 1;
            // cout<<left<<" "<<maxmq.front().first<<" "<<minmq.front().first<<endl;
        }
        return ans;
    }
};