class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        for(auto x : nums){
            pq.push(x);
        }
        int ans = 0;
        while(pq.top() < k){
            long num1 = pq.top();
            pq.pop();
            long num2 = pq.top();
            pq.pop();
            pq.push(num1 * 2 + num2);
            ans++;
        }
        return ans;
    }
};