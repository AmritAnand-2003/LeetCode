class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0;i < nums.size();i++){
            pq.push({nums[i], i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<pair<int, int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        sort(ans.begin(), ans.end(), [&](auto x1, auto x2){
            return x1.second < x2.second;
        });
        vector<int> res;
        for(auto& x : ans){
            res.push_back(x.first);
        }
        return res;
    }
};