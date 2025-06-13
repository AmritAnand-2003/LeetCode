class Solution {
public:
    int set_min_candy(int ind, vector<int>& ratings, vector<int>& candies){
        int can = 1;
        if(ind > 0 && ratings[ind] > ratings[ind - 1] && candies[ind - 1] > 0){
            can = max(can, candies[ind - 1] + 1);
        }
        if(ind < ratings.size() - 1 && ratings[ind] > ratings[ind + 1] && candies[ind + 1] > 0){
            can = max(can, candies[ind + 1] + 1);
        }
        candies[ind] = can;
        return can;
    }
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0;i < n;i++){
            pq.push({ratings[i], i});
        }
        vector<int> candies(n);
        int ans = 0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            ans += set_min_candy(cur.second, ratings, candies);
        }
        return ans;
    }
};