class Solution {
    public int strangePrinter(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        for(int[] in : dp){
            Arrays.fill(in, -1);
        }
        return Util(0, n - 1, s, dp);
    }

    private int Util(int i, int j, String s, int[][] dp) {
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int firstLetter = s.charAt(i);
        int answer = 1 + Util(i + 1, j, s, dp);
        for(int k = i + 1; k <= j; k++){
            if(s.charAt(k) == s.charAt(i)){
                answer = Math.min(answer, Util(i, k - 1, s, dp) + Util(k + 1, j, s, dp));
            }
        }
        return dp[i][j] = answer;
    }
}