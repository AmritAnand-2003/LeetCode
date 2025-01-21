class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long ans = LONG_MAX, first_row_sum = 0, second_row_sum = 0;
        int n = grid[0].size();
        for(int i = 0;i < n;i++){
            first_row_sum += grid[0][i];
        }
        for(int i = 0;i < n;i++){
            first_row_sum -= grid[0][i];
            ans = min(ans, max(first_row_sum, second_row_sum));
            second_row_sum += grid[1][i];
        }
        return ans;
    }
};