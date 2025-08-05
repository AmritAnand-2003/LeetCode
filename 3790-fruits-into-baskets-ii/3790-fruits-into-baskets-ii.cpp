class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int cnt = n;
        for(auto& f : fruits) {
            for(int i = 0;i < n;i++){
                if(baskets[i] >= f){
                    baskets[i] = -1;
                    cnt--;
                    break;
                }
            }
        }
        return cnt;
    }
};