class Solution {
    public int numSubmat(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int ans = 0;
        for(int i = 0;i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0){
                    continue;
                }
                if(i != 0){
                    mat[i][j] += mat[i - 1][j];
                }
                int cur = mat[i][j];
                for(int k = j; k >= 0; k--){
                    if(mat[i][k] == 0){
                        break;
                    }
                    cur = Math.min(cur, mat[i][k]);
                    ans += cur;
                    // System.out.print(ans + "," + cur + "," + k + " ");
                }
                // System.out.print(ans + "-" + mat[i][j] + " ");
            }
            // System.out.println();
        }
        return ans;
    }
}