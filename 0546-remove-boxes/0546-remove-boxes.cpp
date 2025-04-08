class Solution {
public:
    int dp[101][101][101];
    int solve(vector<int>& boxes, int l, int r, int streak){
        if(l > r){
            return 0;
        }
        if(dp[l][r][streak] != -1){
            return dp[l][r][streak];
        }
        int streak_cur = streak, ind = l;
        while(ind + 1 <= r && boxes[ind + 1] == boxes[l]){
            streak_cur++;
            ind++;
        }
        int ans = (streak_cur + 1) * (streak_cur + 1) + solve(boxes, ind + 1, r, 0);
        for(int i = ind + 2;i <= r;i++){
            if(boxes[i] == boxes[l]){
                ans = max(ans, solve(boxes, ind + 1, i - 1, 0) + solve(boxes, i, r, streak_cur + 1));
            }
        }
        // cout<<l<<" "<<r<<" "<<streak<<" "<<ans<<endl;
        return dp[l][r][streak] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(dp, -1, sizeof(dp));
        return solve(boxes, 0, n - 1, 0);
    }
};