class Solution {
    public int numSubmat(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int ans = 0;
        for(int i = 0;i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i != 0 && mat[i][j] != 0){
                    mat[i][j] += mat[i - 1][j];
                }
            }
            Stack<int[]> stack = new Stack<>();
            stack.push(new int[] {-1, 0, -1});
            for(int j = 0; j < n; j++){
                int h = mat[i][j];
                while(stack.peek()[2] >= h) {
                    stack.pop();
                }
                int[] top = stack.peek();
                int k = top[0];
                int prev = top[1];
                int cur = prev + (j - k) * h;
                stack.push(new int[] {j, cur, h});
                ans += cur;
            }
        }
        return ans;
    }
}