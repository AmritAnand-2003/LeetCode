class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        if(a[1] != b[1]){
            return a[1] < b[1];
        }
        return a[0] > b[0]; 
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<vector<int>> v;
        int n = profits.size();
        for(int i = 0;i < n;i++){
            v.push_back({profits[i], capital[i]});
        }
        sort(v.begin(), v.end(), comp);
        int ind = 0;
        for(int i = 0;i < k;i++){
            while(ind < n && v[ind][1] <= w){
                pq.push(v[ind][0]);
                // cout<<v[ind][0]<<" "<<v[ind][1]<<endl;
                ind++;
            }
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
            else{
                break;
            }
        }
        return w;
    }
};