class Solution {
public:
    int count(vector<int>& tops, vector<int>& bottoms, int val){
        int count1 = 0, count2 = 0;
        for(int i = 0;i < tops.size();i++){
            if(count1 != -1){
                if(tops[i] != val && bottoms[i] == val){
                    count1++;
                }
                else if(tops[i] != val){
                    return -1;
                }
                if(bottoms[i] != val && tops[i] == val){
                    count2++;
                }
            }
        }
        return min(count1, count2);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans1 = count(tops, bottoms, tops[0]);
        int ans2 = count(tops, bottoms, bottoms[0]);
        // cout<<ans1<<" "<<ans2<<endl;
        int ans = (ans1 != -1 && ans2 != -1) ? min(ans1, ans2) : max(ans1, ans2);
        return ans;
    }
};