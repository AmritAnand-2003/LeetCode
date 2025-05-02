class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<pair<int, int>> dist(n);
        int cur_r = -1, cur_l = -1;
        for(int i = 0;i < n;i++){
            if(dominoes[i] == 'R'){
                cur_r = i;
            }
            else if(dominoes[i] == 'L'){
                cur_r = -1;
            }
            if(dominoes[n - 1 - i] == 'L'){
                cur_l = n - 1 - i;
            }
            else if(dominoes[n - 1 - i] == 'R'){
                cur_l = -1;
            }
            dist[i].first = cur_r;
            dist[n - 1 - i].second = cur_l;
        }
        for(int i = 0;i < n;i++){
            if(dominoes[i] != 'R' && dominoes[i] != 'L'){
                if(dist[i].first != -1 && dist[i].second != -1){
                    if(i - dist[i].first > dist[i].second - i){
                        dominoes[i] = 'L';
                    }
                    else if(i - dist[i].first < dist[i].second - i){
                        dominoes[i] = 'R';
                    }
                }
                else if(dist[i].first != -1){
                    dominoes[i] = 'R';
                }
                else if(dist[i].second != -1){
                    dominoes[i] = 'L';
                }
            }
        }
        return dominoes;
    }
};