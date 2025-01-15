class Compare {
public:
    bool operator()(pair<long,long> below, pair<long,long> above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second > above.second) {
            return true;
        }
 
        return false;
    }
};

class Solution {
public:
    
    int mostBooked(int n, vector<vector<int>>& meetings){
        sort(meetings.begin(),meetings.end());
        vector<int> rooms(n);
        priority_queue<pair<long,long>,vector<pair<long,long>>,Compare> pq;
        priority_queue<int,vector<int>,greater<int>> empty;
        for(int i = 0;i < n;i++){
            // pq.push({0,i});
            empty.push(i);
        }
        for(auto x : meetings){
            while(!pq.empty() && pq.top().first <= x[0]){
                empty.push(pq.top().second);
                pq.pop();
            }
            long dif = 0;
            if(empty.empty()){
                empty.push(pq.top().second);
                dif = pq.top().first - x[0];
                pq.pop();
            }
            // cout<<x[1] + dif<<"  ";
            long val = x[1] + dif;
            pq.push({val,empty.top()});
            rooms[empty.top()]++;
            empty.pop();
            // if(x[0] >= y.first){
            //     pq.push({x[1],y.second});
            // }
            // else{
            //     int dif = y.first - x[0];
            //     pq.push({x[1] + dif,y.second});
            // }
        }
        int ans = 0,ansind;
        for(int i = 0;i < n;i++){
            cout<<rooms[i]<<" ";
            if(rooms[i] > ans){
                ans = rooms[i];
                ansind = i;
            }
        }
        return ansind;
    }
};