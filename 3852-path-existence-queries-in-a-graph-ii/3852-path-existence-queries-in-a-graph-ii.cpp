class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> reach(n, -1);
        vector<pair<int, int>> valIdx(n);
        for(int i = 0;i < n;i++){
            valIdx[i] = {nums[i], i};
        }
        sort(valIdx.begin(), valIdx.end());
        vector<int> pos(n);
        for(int i = 0;i < n;i++){
            pos[valIdx[i].second] = i;
        }
        for(int i = 0;i < n;i++){
            if(i != 0 && valIdx[i].first - valIdx[i - 1].first <= maxDiff){
                reach[i] = reach[i - 1];
            }
            else{
                reach[i] = i;
            }
        }
        int l = 0;
        int jump[n + 1][18];
        for(int r = 0;r < n;r++){
            while(valIdx[r].first - valIdx[l].first > maxDiff){
                jump[l][0] = r - 1;
                l++;
            }
        }
        while(l < n){
            jump[l][0] = n - 1;
            l++;
        }
        for(int j = 1;j < 18;j++){
            for(int i = 0;i < n;i++){
                jump[i][j] = jump[jump[i][j - 1]][j - 1];
            }
        }
        vector<int> res;
        for(auto& q : queries){
            int a = pos[q[0]], b = pos[q[1]];
            if(a > b){
                swap(a, b);
            }
            cout<<reach[a]<<" "<<reach[b]<<endl;
            if(a == b){
                res.push_back(0);
                continue;
            }
            if(reach[a] != reach[b]){
                res.push_back(-1);
                continue;
            }
            int cnt = 0;
            for(int j = 17; j >= 0; j--){
                if(jump[a][j] < b){
                    a = jump[a][j];
                    cnt += (1 << j);
                }
            }
            res.push_back(cnt + 1);
        }
        return res;
    }
};