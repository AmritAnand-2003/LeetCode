class Solution {
    private int[][] rotate(int[][] vec){
        int n = vec.length, m = vec[0].length;
        int[][] rotated = new int[m][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                rotated[m - 1 - j][i] = vec[i][j];
            }
        }
        return rotated;
    }

    private int solve(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int res = m * n;
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n - 1; j++) {
                res = Math.min(
                    res, minimumArea(grid, 0, i, 0, n - 1) +
                    minimumArea(grid, i + 1, m - 1, 0, j) +
                    minimumArea(grid, i + 1, m - 1, j + 1, n - 1)
                );
                res = Math.min(
                    res, 
                    minimumArea(grid, 0, i, 0, j) +
                    minimumArea(grid, 0, i, j + 1, n - 1) +
                    minimumArea(grid, i + 1, m - 1, 0, n - 1)
                );
            }
        }
        for(int i = 0; i < m - 2; i++) {
            for(int j = i + 1; j < m - 1; j++) {
                res = Math.min(
                    res,
                    minimumArea(grid, 0, i, 0, n - 1) +
                    minimumArea(grid, i + 1, j, 0, n - 1) +
                    minimumArea(grid, j + 1, m - 1, 0, n - 1)
                );
            }
        }
        return res;
    }

    private int minimumArea(int[][] grid, int u, int d, int l, int r) {
        int min_u = grid.length, max_d = 0, min_l = grid[0].length, max_r = 0;
        for(int i = u; i <= d;i++){
            for(int j = l; j <= r; j++) {
                if (grid[i][j] == 1) {
                    min_u = Math.min(min_u, i);
                    max_d = Math.max(max_d, i);
                    min_l = Math.min(min_l, j);
                    max_r = Math.max(max_r, j);
                }
            }
        }
        return min_u <= max_d ? (max_d - min_u + 1) * (max_r - min_l + 1): Integer.MAX_VALUE/3;
    }

    public int minimumSum(int[][] grid) {
        int[][] rgrid = rotate(grid);
        return Math.min(solve(grid), solve(rgrid));
    }
}