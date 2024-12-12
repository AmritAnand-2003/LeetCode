class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for(auto x : gifts){
            pq.push(x);
            ans += x;
        }
        while(k--){
            int cur = pq.top();
            ans -= cur;
            pq.pop();
            int leave = floor(sqrt(cur));
            ans += leave;
            pq.push(leave);
        }
        // while(!pq.empty()){
        //     ans += pq.top();
        //     pq.pop();
        // }
        return ans;
    }
};