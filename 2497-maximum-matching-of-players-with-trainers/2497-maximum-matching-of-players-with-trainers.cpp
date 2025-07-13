class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans = 0;
        int i = 0, j = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        while(i < players.size() && j < trainers.size()){
            while(j < trainers.size() && players[i] > trainers[j]){
                j++;
            }
            if(j < trainers.size()){
                ans++;
                i++;
                j++;
            }
        }
        return ans;
    }
};