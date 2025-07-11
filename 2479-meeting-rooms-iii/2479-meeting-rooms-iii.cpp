class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long, int>, vector<pair<long, int>> , greater<pair<long, int>>> pq;
        int rooms = 0;
        priority_queue<int, vector<int>, greater<int>> empty_rooms;
        vector<int> freq(n);
        for(int i = 0;i < n;i++){
            empty_rooms.push(i);
        }
        for(int i = 0;i < meetings.size();i++){
            int st_time = meetings[i][0];
            while(!pq.empty() && pq.top().first <= st_time){
                int room = pq.top().second;
                // cout<<" kick "<<room<<endl;
                pq.pop();
                empty_rooms.push(room);
            }
            if(!empty_rooms.empty()){
                // cout<<" if : "<<i<<endl;
                int room = empty_rooms.top();
                empty_rooms.pop();
                pq.push({meetings[i][1], room});
                freq[room]++;
            }
            else{
                // cout<<" else : "<<i<<endl;
                auto it = pq.top();
                pq.pop();
                long dif = it.first - st_time;
                int room = it.second;
                pq.push({meetings[i][1] + dif, room});
                freq[room]++;
            }
            
        }
        int mx = 0, ans = -1;
        for(int i = 0;i < n;i++){
            if(freq[i] > mx){
                ans = i;
                mx = freq[i];
            }
            // cout<<freq[i]<<" ";
        }
        return ans;
    }
};