class Solution {
    public int minimumArea(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int mn_row = m, mx_row = 0, mn_col = n, mx_col = 0;
        for(int i = 0;i < m;i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    mn_row = Math.min(mn_row, i);
                    mx_row = Math.max(mx_row, i);
                    mn_col = Math.min(mn_col, j);
                    mx_col = Math.max(mx_col, j);
                }
            }
        }
        int area = (mx_row - mn_row + 1) * (mx_col - mn_col + 1);
        return area;
    }
}