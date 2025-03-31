class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // vector<int> pairWeights;
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int>> minpq;
        int n = weights.size();
        for(int i = 0;i < n - 1;i++){
            int cur = weights[i] + weights[i + 1];
            pq.push(cur);
            minpq.push(cur);
            if(minpq.size() == k){
                minpq.pop();
                pq.pop();
            }
        }
        // sort(pairWeights.begin(), pairWeights.end());
        // for(auto& cur : pairWeights){
        //     pq.push(cur);
        //     minpq.push(cur);
        //     if(minpq.size() == k){
        //         minpq.pop();
        //         pq.pop();
        //     }
        // }
        long long ans_mx = 0, ans_mn = 0;
        while(!pq.empty()){
            ans_mn += pq.top();
            pq.pop();
        }
        while(!minpq.empty()){
            ans_mx += minpq.top();
            minpq.pop();
        }
        // cout<<ans_mx<<" "<<ans_mn<<endl;
        return ans_mx - ans_mn;
    }
};